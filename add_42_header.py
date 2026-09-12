#!/usr/bin/env python3

import argparse
import os
import pwd
import re
import subprocess
import sys
from datetime import datetime
from pathlib import Path


DEFAULT_EXTS = {".cpp", ".hpp", ".h", ".hh", ".cc", ".c"}
DEFAULT_FILES = {"Makefile"}
DEFAULT_EMAIL = "sanferna@student.42madrid.com"

BORDER_LINE = "/* ************************************************************************** */"
INNER_WIDTH = len(BORDER_LINE) - len("/* ") - len(" */")

FILE_SUFFIX = "  :+:      :+:    :+:  "
BY_SUFFIX = " +#+  +:+       +#+       "
CREATED_SUFFIX = "  #+#    #+#            "
UPDATED_SUFFIX = " ###   ########.fr      "

NAME_WIDTH = INNER_WIDTH - len("  ") - len(FILE_SUFFIX)
BY_WIDTH = INNER_WIDTH - len("  ") - len(BY_SUFFIX)
CREATED_WIDTH = INNER_WIDTH - len("  ") - len(CREATED_SUFFIX)
UPDATED_WIDTH = INNER_WIDTH - len("  ") - len(UPDATED_SUFFIX)


def run_git_command(repo_root: Path, *args: str) -> str:
    try:
        result = subprocess.run(
            ["git", "-C", str(repo_root), *args],
            capture_output=True,
            text=True,
            check=False,
        )

        if result.returncode == 0:
            return result.stdout.strip()

    except Exception:
        pass

    return ""


def get_git_identity(repo_root: Path) -> tuple[str, str]:
    author = run_git_command(repo_root, "config", "user.name")
    email = run_git_command(repo_root, "config", "user.email")

    if not author:
        author = (
            os.environ.get("USER")
            or os.environ.get("USERNAME")
            or "unknown"
        )

    return author, email


def get_fs_owner(path: Path) -> str:
    try:
        return pwd.getpwuid(path.stat().st_uid).pw_name
    except Exception:
        return (
            os.environ.get("USER")
            or os.environ.get("USERNAME")
            or "unknown"
        )


def format_git_timestamp(value: str) -> str:
    if not value:
        return ""

    value = value.strip()

    if value.endswith("Z"):
        value = value[:-1] + "+00:00"

    try:
        dt = datetime.fromisoformat(value)
        return dt.strftime("%Y/%m/%d %H:%M:%S")
    except ValueError:
        return value


def get_git_file_date(repo_root: Path, rel_path: str) -> str:
    value = run_git_command(
        repo_root,
        "log",
        "-1",
        "--format=%aI",
        "--",
        rel_path,
    )

    if not value:
        value = run_git_command(
            repo_root,
            "log",
            "-1",
            "--format=%cI",
            "--",
            rel_path,
        )

    return format_git_timestamp(value)


def get_fs_timestamp(path: Path) -> str:
    """Return the filesystem modification time (mtime)."""
    try:
        return datetime.fromtimestamp(
            path.stat().st_mtime
        ).strftime("%Y/%m/%d %H:%M:%S")

    except OSError:
        return datetime.now().strftime("%Y/%m/%d %H:%M:%S")


def get_fs_created_timestamp(path: Path) -> str:
    """
    Return the filesystem birth/creation time.

    The metadata is read before the file is opened for writing.
    Linux does not expose birth time consistently through Python,
    so we use stat(1)'s %W when available.
    """

    try:
        result = subprocess.run(
            ["stat", "-c", "%W", "--", str(path)],
            capture_output=True,
            text=True,
            check=True,
        )

        value = result.stdout.strip()

        if not value:
            return ""

        birth_time = int(value)

        # 0 and -1 mean that the filesystem does not provide
        # a valid birth time.
        if birth_time <= 0:
            return ""

        return datetime.fromtimestamp(
            birth_time
        ).strftime("%Y/%m/%d %H:%M:%S")

    except (
        OSError,
        ValueError,
        subprocess.SubprocessError,
    ):
        return ""


def should_process_file(
    path: Path,
    allowed_exts: set[str],
    explicit_files: set[str],
) -> bool:

    if path.is_dir():
        return False

    file_name = path.name.lower()

    explicit_lower = {
        name.lower()
        for name in explicit_files
    }

    if file_name in explicit_lower:
        return True

    return path.suffix.lower() in allowed_exts


def find_files(
    root: Path,
    allowed_exts: set[str],
    explicit_files: set[str],
) -> list[Path]:

    skip_dirs = {
        ".git",
        ".svn",
        "build",
        "cmake-build-debug",
        "cmake-build-release",
        "__pycache__",
    }

    targets: list[Path] = []

    for path in root.rglob("*"):

        if path.is_dir():
            if path.name in skip_dirs:
                continue

            continue

        if should_process_file(
            path,
            allowed_exts,
            explicit_files,
        ):
            targets.append(path)

    return sorted(targets)


def extract_existing_created(content: str) -> str:
    """
    Extract the Created timestamp from an existing 42 header.

    Example:
        Created: 2026/09/12 17:45:43 by sanferna

    Returns:
        '2026/09/12 17:45:43'
    """

    marker = "/* ************************************************************************** */"

    lines = content.lstrip("\ufeff").splitlines()

    start_idx = next(
        (
            idx
            for idx, line in enumerate(lines)
            if line.strip() == marker
        ),
        None,
    )

    if start_idx is None:
        return ""

    end_idx = next(
        (
            idx
            for idx in range(start_idx + 1, len(lines))
            if lines[idx].strip() == marker
        ),
        None,
    )

    if end_idx is None:
        return ""

    header = "\n".join(
        lines[start_idx:end_idx + 1]
    )

    match = re.search(
        r"Created:\s*(.*?)\s+by\s+",
        header,
    )

    if not match:
        return ""

    return match.group(1).strip()


def strip_existing_header(content: str) -> tuple[str, str]:
    """
    Remove an existing 42 header while preserving the source content.

    Returns:
        (content_without_header, existing_created_date)
    """

    marker = "/* ************************************************************************** */"

    bom = "\ufeff" if content.startswith("\ufeff") else ""
    body = content[len(bom):]

    start_idx = body.find(marker)

    if start_idx == -1:
        return content, ""

    end_idx = body.find(
        marker,
        start_idx + len(marker),
    )

    if end_idx == -1:
        return content, ""

    header_end = end_idx + len(marker)

    header = body[start_idx:header_end]

    match = re.search(
        r"Created:\s*(.*?)\s+by\s+",
        header,
    )

    existing_created = (
        match.group(1).strip()
        if match
        else ""
    )

    # Content after the old header.
    rest = body[header_end:]

    # Remove the newline immediately after the old header.
    if rest.startswith("\r\n"):
        rest = rest[2:]
    elif rest.startswith("\n"):
        rest = rest[1:]
    elif rest.startswith("\r"):
        rest = rest[1:]

    # Remove additional blank lines introduced by the old header.
    rest = rest.lstrip("\r\n")

    # The new header ends with one newline.
    # Add one more newline to create the standard blank line.
    if rest:
        rest = "\n" + rest

    return bom + rest, existing_created

def pad_field(value: str, width: int) -> str:
    return value[:width].ljust(width)


def format_comment(content: str) -> str:
    content = content[:INNER_WIDTH]

    return f"/* {content:<{INNER_WIDTH}} */"


def build_header(
    file_path: Path,
    author: str,
    email: str,
    created: str,
    updated: str,
    git_mode: bool,
) -> str:

    file_name = pad_field(
        file_path.name,
        NAME_WIDTH,
    )

    effective_email = email or DEFAULT_EMAIL

    by_text = f"By: {author}"

    if effective_email:
        by_text = f"By: {author} <{effective_email}>"

    author_field = pad_field(
        by_text,
        BY_WIDTH,
    )

    created_text = pad_field(
        f"Created: {created} by {author}",
        CREATED_WIDTH,
    )

    updated_text = pad_field(
        f"Updated: {updated} by {author}",
        UPDATED_WIDTH,
    )

    lines = [
        BORDER_LINE,
        format_comment(""),
        format_comment(
            "                                                       :::      ::::::::  "
        ),
        format_comment(
            f"  {file_name}{FILE_SUFFIX}"
        ),
        format_comment(
            "                                                   +:+ +:+         +:+      "
        ),
        format_comment(
            f"  {author_field}{BY_SUFFIX}"
        ),
        format_comment(
            "                                                +#+#+#+#+#+   +#+           "
        ),
        format_comment(
            f"  {created_text}{CREATED_SUFFIX}"
        ),
        format_comment(
            f"  {updated_text}{UPDATED_SUFFIX}"
        ),
        format_comment(""),
        BORDER_LINE,
        "",
    ]

    for line in lines:
        if line:
            assert len(line) == len(BORDER_LINE), (
                f"Header width mismatch: "
                f"{len(line)} != {len(BORDER_LINE)} :: {line!r}"
            )

    return "\n".join(lines) + "\n"


def main() -> int:

    parser = argparse.ArgumentParser(
        description=(
            "Insert a 42-style header into source files "
            "in a project tree."
        )
    )

    parser.add_argument(
        "folder",
        help="Root folder to scan",
    )

    parser.add_argument(
        "--ext",
        nargs="+",
        default=[
            ".cpp",
            ".hpp",
            ".h",
            ".hh",
            ".cc",
            ".c",
        ],
        help="File extensions to include",
    )

    parser.add_argument(
        "--files",
        nargs="+",
        default=["Makefile"],
        help="Specific file names to include",
    )

    parser.add_argument(
        "--git-mode",
        action="store_true",
        help=(
            "Use Git metadata for author and Updated date"
        ),
    )

    parser.add_argument(
        "--dry-run",
        action="store_true",
        help=(
            "Show files that would be modified "
            "without changing them"
        ),
    )

    args = parser.parse_args()

    root = Path(args.folder).resolve()

    if not root.exists() or not root.is_dir():
        print(
            f"Error: {root} is not a valid directory.",
            file=sys.stderr,
        )
        return 1

    allowed_exts = {
        ext.lower()
        for ext in args.ext
    }

    explicit_files = set(args.files)

    files = find_files(
        root,
        allowed_exts,
        explicit_files,
    )

    if not files:
        print("No matching files found.")
        return 0

    for path in files:

        rel_path = path.relative_to(root).as_posix()

        try:
            original = path.read_text(
                encoding="utf-8"
            )

        except UnicodeDecodeError:

            try:
                original = path.read_text(
                    encoding="latin-1"
                )

            except Exception:
                print(
                    f"Skipping unreadable file: {rel_path}",
                    file=sys.stderr,
                )
                continue

        except OSError as exc:
            print(
                f"Skipping unreadable file {rel_path}: {exc}",
                file=sys.stderr,
            )
            continue

        # ---------------------------------------------------------
        # Remove old header, but preserve its Created date.
        # ---------------------------------------------------------

        cleaned, existing_created = strip_existing_header(
            original
        )

        # ---------------------------------------------------------
        # Author
        # ---------------------------------------------------------

        if args.git_mode:
            author, email = get_git_identity(root)
        else:
            author = get_fs_owner(path)
            email = DEFAULT_EMAIL

        # ---------------------------------------------------------
        # Created
        #
        # If the file already had a header, preserve its Created
        # date. Otherwise use the filesystem Birth time.
        # ---------------------------------------------------------

        if existing_created:
            created = existing_created
        else:
            created = get_fs_created_timestamp(path)

            # If the filesystem doesn't expose Birth time,
            # leave it empty instead of lying and using mtime.
            if not created:
                created = "unknown"

        # ---------------------------------------------------------
        # Updated
        #
        # Normal mode:
        #     filesystem mtime
        #
        # Git mode:
        #     latest Git commit affecting the file
        # ---------------------------------------------------------

        if args.git_mode:
            updated = (
                get_git_file_date(root, rel_path)
                or get_fs_timestamp(path)
            )
        else:
            updated = get_fs_timestamp(path)

        # ---------------------------------------------------------
        # Build new content
        # ---------------------------------------------------------

        new_header = build_header(
            path,
            author,
            email,
            created,
            updated,
            args.git_mode,
        )

        new_content = new_header + cleaned

        # ---------------------------------------------------------
        # Don't touch files that haven't changed.
        # ---------------------------------------------------------

        if new_content == original:
            continue

        if args.dry_run:
            print(
                f"[dry-run] {rel_path}"
            )
            continue

        # ---------------------------------------------------------
        # Write file
        # ---------------------------------------------------------

        try:
            path.write_text(
                new_content,
                encoding="utf-8",
            )

            print(
                f"Updated: {rel_path}"
            )

        except Exception as exc:
            print(
                f"Error updating {rel_path}: {exc}",
                file=sys.stderr,
            )

    return 0


if __name__ == "__main__":
    raise SystemExit(main())

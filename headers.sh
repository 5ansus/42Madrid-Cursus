#!/bin/bash

DIR="${1:-.}"

while IFS= read -r -d '' file; do
    echo "→ $file"

    vim -n "$file" \
        -c "Sanferna" \
        -c "write" \
        -c "quit" < /dev/tty

done < <(
    find "$DIR" -type f \( \
        -name "*.c" -o \
        -name "*.h" -o \
        -name "*.cc" -o \
        -name "*.hh" -o \
        -name "*.cpp" -o \
        -name "*.hpp" -o \
        -name "Makefile" \
    \) -print0
)

*This project has been created as part of the 42 curriculum by sanferna.*

# NetPractice 🌐

## Description

NetPractice is a networking fundamentals project that teaches TCP/IP addressing and network configuration through hands-on practice. The goal is to understand how networks function by solving 10 progressively challenging exercises where you configure small-scale networks to make them operational.

Each exercise presents a non-functioning network diagram with missing or incorrect configurations. Your task is to fill in IP addresses, subnet masks, and routing information until the network meets its objectives. The project uses a browser-based simulation interface, so all practice is done in a safe, virtual environment.

By completing this project, you'll develop practical skills in:
- Calculating and applying subnet masks
- Configuring IP addresses within proper network ranges
- Setting up default gateways and routing tables
- Understanding how routers and switches interact
- Troubleshooting network connectivity issues

## Instructions

### Running the Training Interface

1. Download the project files from the 42 intra page
2. Extract the files to a directory of your choice
3. Navigate to the extracted folder in your terminal
4. Run the launch script:
   ```bash
   ./run.sh
   ```

This will start a local web server and automatically open the training interface in your default browser.

**Alternative method** (if `run.sh` doesn't work):
```bash
python3 -m http.server 49242
```
Then manually navigate to `http://localhost:49242` in your web browser.

### Using the Interface

Once the interface opens:

- **Training Mode**: Enter your 42 login to access your personal configuration and progress
- **Evaluation Mode**: Use this tab to generate random configurations for practice or peer evaluations

### Completing Levels

For each of the 10 levels:

1. Study the network diagram and objectives displayed at the top
2. Modify the unshaded fields to configure IP addresses, subnet masks, and routing
3. Click **[Check again]** to validate your configuration
4. Review the logs at the bottom if your configuration is incorrect - they provide helpful error messages
5. Once successful, click **[Get my config]** to download your configuration file
6. Save the downloaded file with a clear name (e.g., `level1.json`, `level2.json`, etc.)
7. Click the button to proceed to the next level

⚠️ **Important**: Export your configuration after completing each level before moving on!

### Submission Requirements

Your repository must contain:
- This `README.md` file at the root
- **10 exported configuration files** (one per level) placed at the repository root
- Configuration files should be named clearly (e.g., `level1.json` through `level10.json`)

Commit and push all files to your Git repository for evaluation.

## Resources

### Networking Concepts Studied

This project covers essential networking fundamentals:

- **TCP/IP Addressing**: Understanding IPv4 addresses, their structure, and how devices use them to communicate
- **Subnet Masks**: How subnet masks define network boundaries and separate network/host portions of an IP address
- **CIDR Notation**: Compact representation of IP addresses and their associated routing prefix (e.g., `/24`, `/30`)
- **Default Gateway**: The router IP address that devices use to send traffic outside their local network
- **Routers**: Layer 3 devices that forward packets between different networks based on IP addresses
- **Switches**: Layer 2 devices that forward frames within the same network based on MAC addresses
- **OSI Model**: Understanding the network layer (Layer 3) where IP addressing and routing operate
- **Network vs Host Addresses**: Identifying network addresses, broadcast addresses, and usable host ranges
- **Routing Tables**: How routers determine the next hop for packet forwarding

### Learning Resources

- [Subnet Calculator](https://www.cidr-calc.com/) - Helpful tool for calculating subnet ranges
- [YouTube tutorial](https://www.youtube.com/watch?v=HQUw0CfQWAM) - Complete guide

### AI Usage

AI tools (GitHub Copilot) were used in the following ways:

- **README structure**: Assistance with organizing and formatting this documentation file

All network configurations were solved manually through understanding the concepts - AI was not used to directly solve the exercises.

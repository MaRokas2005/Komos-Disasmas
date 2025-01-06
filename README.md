# Tasm disassembler

[![Contributors](https://img.shields.io/badge/contributors-1-orange.svg)](#)

## Table of Contents
- [About](#about)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Configuration](#dosbox-x-configuration)
- [Usage](#usage)
- [Debugging](#debuging)
- [Contributing](#contributing)
- [Contact](#contact)

---

## About

**Tasm disassembler** is a project designed to disassemble executable code file and output assembly code. Works only with small executable files.
It simplifies tasks like reading hexadecimal numbers.

---

## Features
- **Feature 1:** Have help menu.
- **Feature 2:** Disassemble executable files.

---

## Getting Started

### Prerequisites
Make sure you have the following installed:
- **Assembler:** TASM (Turbo Assembler)
- **Emulator:** Dosbox-x or any DOS emulator

### Installation
Clone this repository and navigate to the project directory:
```bash
git clone https://github.com/MaRokas2005/Komos-Disasmas.git
cd Komos-Disasmas
```

### DOSBox-X Configuration
1. **Configuration**
```bash
   mount R path/to/the/project/Komos-Disasmas
   R:
   path R:\tasm\bin
```

## Usage
1. **Open DOSBox-X or any other emulator.**

2. **Build the project:**
```bash
tasm disasm.asm
tlink disasm.obj
```

3. **Run the executable with Dosbox-x:**
```bash
disasm.exe input.exe output.asm
```

---

## Debugging
1. **Open DOSBox-X or any other emulator.**
2. **Run the Assembler Code:**
   ```bash
   tasm /zi /S disasm.asm
   tlink /v disasm.obj
   ```
3. **Run the Program in Dosbox-x:**
   ```bash
   td disasm.exe input.exe output.asm
   ```

---

## Contributing

Contributions are welcome! Here's how you can help:
1. Fork the repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add new feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a Pull Request.

---

## Contact

For questions or feedback:
- **Name:** Rokas Braidokas
- **Email:** rokasbraidokas@gmail.com
- **GitHub:** [MaRokas2005](https://github.com/MaRokas2005)
- **LinkedIn:** [Rokas Braidokas](https://www.linkedin.com/in/rokas-braidokas/)

---

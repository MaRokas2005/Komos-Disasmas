pressAnyKeyMessage              db  "Press any key to continue...", "$"
clearLine                       db  13, "                               ", 13, "$"
slashQuestionHelp       db "/?", 0
slashHLowerHelp         db "/h", 0
slashHUpperHelp         db "/H", 0
hyphenHLowerHelp        db "-h", 0
hyphenHUpperHelp        db "-H", 0
hyphenHyphenHelpHelp    db "--help", 0

_help           db  "HELP -- HELP -- HELP -- HELP -- HELP -- HELP -- HELP -- HELP -- HELP -- HELP", 13, 10, 13, 10, "$"
_name           db  "NAME", 13, 10
                db  "       disasm - Disassemble executable code files", 13, 10
                db  "       and output assembly code.", 13, 10, 13, 10, "$"
_synopsis       db  "SYNOPSIS", 13, 10
                db  "       disasm INPUT_FILE OUTPUT_FILE", 13, 10, 13, 10
                db  "       disasm /?", 13, 10, 13, 10
                db  "       disasm /h", 13, 10, 13, 10
                db  "       disasm /H", 13, 10, 13, 10
                db  "       disasm -h", 13, 10, 13, 10
                db  "       disasm -H", 13, 10, 13, 10
                db  "       disasm --help", 13, 10, 13, 10, "$"
_description    db  "DESCRIPTION", 13, 10
                db  "       disasm reads a binary file or machine code and disassembles", 13, 10
                db  "       it into human-readable assembly language. The disassembled code", 13, 10
                db  "       is written to the specified OUTPUT_FILE for further analysis", 13, 10
                db  "       or debugging.", 13, 10, 13, 10, "$"
_example        db  "EXAMPLES", 13, 10
                db  "       Example:", 13, 10
                db  "              To disassemble 'prog.exe' and save the output to 'prog.asm':", 13, 10
                db  "                  disasm prog.exe prog.asm", 13, 10
                db  "              This will convert the binary into assembly code and", 13, 10
                db  "              write it into 'prog.asm'.", 13, 10, 13, 10, "$"
_options        db  "OPTIONS", 13, 10
                db  "       INPUT_FILE", 13, 10
                db  "              Specifies the path to the executable code file.", 13, 10
                db  "       OUTPUT_FILE", 13, 10
                db  "              Specifies the path where the disassembled code will be saved.", 13, 10
                db  "       /?, /h, /H, -h, -H, --help", 13, 10
                db  "              Displays this help message.", 13, 10, 13, 10, "$"
_notes          db  "NOTES", 13, 10
                db  "       - The INPUT_FILE must be a executable code file, typically compiled", 13, 10
                db  "          from an assembler or other binary generator.", 13, 10
                db  "       - The OUTPUT_FILE should specify the path for saving the disassembled", 13, 10
                db  "          code, which will be written in TASM-compatible syntax.", 13, 10
                db  "       - The disassembler attempts to identify labels, jumps,", 13, 10
                db  "          and function calls,but accuracy depends on the input binary.", 13, 10
                db  "       - Ensure the binary is compatible with 8086 or 16-bit x86 architectures.", 13, 10, 13, 10, "$"
_examples       db  "EXAMPLES", 13, 10
                db  "       To disassemble a file named 'code.exe'", 13, 10
                db  "        into a readable assembly file 'output.asm':", 13, 10
                db  "              disasm code.bin output.asm", 13, 10, 13, 10
                db  "       To view help about the tool:", 13, 10
                db  "              disasm --help", 13, 10, 13, 10, "$"
_author         db  "AUTHOR", 13, 10
                db  "       Written by Rokas Braidokas from SE 1 course 2 group.", 13, 10, 13, 10, "$"
_copyright      db  "COPYRIGHT", 13, 10
                db  "       Copyright 2024 VU.", 13, 10, "$"
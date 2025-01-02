LOCALS @@
.MODEL SMALL
.STACK 100h

.DATA
    inputName       db  255 dup("$")
    outputName      db  255 dup("$")
    inputHandle     dw  0
    outputHandle    dw  0
    inputBuffer     db  300 dup(0)
    newline         db  0dh, 0ah
    outputBuffer    db  300 dup(0)
    lineLength      db  0
    filePointer     dw  2   dup(0)

    debugMessage    db  "Debug message", 0dh, 0ah, "$"
    
    slashQuestionHelp       db "/?", 0
    slashHLowerHelp         db "/h", 0
    slashHUpperHelp         db "/H", 0
    hyphenHLowerHelp        db "-h", 0
    hyphenHUpperHelp        db "-H", 0
    hyphenHyphenHelpHelp    db "--help", 0

    pressAnyKeyMessage              db  "Press any key to continue...", "$"
    clearLine                       db  13, "                               ", 13, "$"
    errorMessage                    db  10, "ERROR: $"
    unsuccesfulFileOpenMessage      db  "Failed to open file!", 13, 10, 10, "$"
    unsuccesfulFileCreateMessage    db  "Failed to create file!", 13, 10, 10, "$"
    unsuccesfulFileReadMessage      db  "Failed to read file!", 13, 10, 10, "$"
    unsuccesfulFileWriteMessage     db  "Failed to write to file!", 13, 10, 10, "$"
    noParametersMessage             db  "Parameters are not specified!", 13, 10, 10, "$"
    tooManyParametersMessage        db  "Too many parameters!", 13, 10, 10, "$"
    invalidLineLengthMessage        db  "Invalid line length! Can't have symbols or number equal to zero!!!", 13, 10, 10, "$"
    tooBigNumberMessage             db  "Line length is too big! Should be 255 or less!!!", 13, 10, 10, "$"
    
    _help           db  "HELP -- HELP -- HELP -- HELP -- HELP -- HELP -- HELP -- HELP -- HELP -- HELP", 13, 10, 13, 10, "$" 
    _name           db  "NAME", 13, 10
                    db  "       antra - Split text file into lines of specified maximum length", 13, 10
                    db  "       and write to a new file.", 13, 10, 13, 10, "$"
    _synopsis       db  "SYNOPSIS", 13, 10
                    db  "       antra INPUT_FILE MAX_LINE_LENGTH OUTPUT_FILE", 13, 10, 13, 10
                    db  "       antra /?", 13, 10, 13, 10
                    db  "       antra /h", 13, 10, 13, 10
                    db  "       antra /H", 13, 10, 13, 10
                    db  "       antra -h", 13, 10, 13, 10
                    db  "       antra -H", 13, 10, 13, 10
                    db  "       antra --help", 13, 10, 13, 10, "$"
    _description    db  "DESCRIPTION", 13, 10
                    db  "       antra reads the contents of INPUT_FILE and splits its text", 13, 10
                    db  "       into lines, ensuring each line does not exceed MAX_LINE_LENGTH", 13, 10
                    db  "       characters. The output is written to OUTPUT_FILE, with each", 13, 10
                    db  "       line formatted according to the specified length.", 13, 10, 13, 10, "$"
    _example        db  "       Example:", 13, 10
                    db  "              If 'duom.txt' contains a long block of text, running:", 13, 10
                    db  "                  antra duom.txt 80 rez.txt", 13, 10
                    db  "              will create 'rez.txt', where each line is no longer", 13, 10
                    db  "              than 80 characters, based on the input text in 'duom.txt'.", 13, 10, 13, 10, "$"
    _options        db  "OPTIONS", 13, 10
                    db  "       INPUT_FILE", 13, 10
                    db  "              Specifies the path to the file containing", 13, 10
                    db  "              the text to be processed.", 13, 10
                    db  "       MAX_LINE_LENGTH", 13, 10
                    db  "              Specifies the maximum allowed length of each line", 13, 10
                    db  "              in characters. Lines will be wrapped at this length.", 13, 10
                    db  "       OUTPUT_FILE", 13, 10
                    db  "              Specifies the path to the file where the output", 13, 10
                    db  "              (formatted text) will be saved.", 13, 10, 13, 10, "$"
    _notes          db  "NOTES", 13, 10
                    db  "       - The program reads the input text file and breaks lines", 13, 10
                    db  "         based on the specified character limit, if possible.", 13, 10
                    db  "       - The input and output file paths should be provided with a", 13, 10
                    db  "         maximum of 255 characters in length.", 13, 10
                    db  "       - The MAX_LINE_LENGTH should be a positive integer, typically", 13, 10
                    db  "         not greater than 255s.", 13, 10, 13, 10, "$"
    _examples       db  "EXAMPLES", 13, 10
                    db  "       To format 'duom.txt' with lines up to 80 characters in length", 13, 10
                    db  "       and save it to 'rez.txt':", 13, 10, 13, 10
                    db  "              antra duom.txt 80 rez.txt", 13, 10, 13, 10
                    db  "       To format a different file, 'input.txt', with lines up to 100", 13, 10
                    db  "       characters in length:", 13, 10, 13, 10
                    db  "              antra input.txt 100 output.txt", 13, 10, 13, 10, "$"
    _author         db  "AUTHOR", 13, 10
                    db  "       Written by Rokas Braidokas.", 13, 10, 13, 10, "$"
    _copyright      db  "COPYRIGHT", 13, 10
                    db  "       Copyright 2024 VU.", 13, 10, "$"

.CODE
    ;***************************************************;
    ;                   DEBUG MESSAGE                   ;
    ;***************************************************;
    debug PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, debugMessage
        int     21h
        call    askForMore

        pop     dx
        pop     ax
        ret
    debug ENDP

    ;***************************************************;
    ;                    END PROGRAM                    ;
    ;***************************************************;
    endProgram PROC
        mov     ah, 3Eh
        mov     bx, inputHandle
        int     21h
        mov     bx, outputHandle
        int     21h

        mov     ax, 4C00h
        int     21h
    endProgram ENDP

    ;***************************************************;
    ;               UNSUCCESFUL FILE OPEN               ;
    ;         run when file open is unsuccesful         ;
    ;***************************************************;
    unsuccesfulFileOpen PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, errorMessage
        int     21h
        lea     dx, unsuccesfulFileOpenMessage
        int     21h

        pop     dx
        pop     ax
        ret
    unsuccesfulFileOpen ENDP

    ;***************************************************;
    ;              UNSUCCESFUL FILE CREATE              ;
    ;        run when file create is unsuccesful        ;
    ;***************************************************;
    unsuccesfulFileCreate PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, errorMessage
        int     21h
        lea     dx, unsuccesfulFileCreateMessage
        int     21h
        
        pop     dx
        pop     ax
        ret
    unsuccesfulFileCreate ENDP

    ;***************************************************;
    ;               UNSUCCESFUL FILE READ               ;
    ;         run when file read is unsuccesful         ;
    ;***************************************************;
    unsuccesfulFileRead PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, errorMessage
        int     21h
        lea     dx, unsuccesfulFileReadMessage
        int     21h
        
        pop     dx
        pop     ax
        ret
    unsuccesfulFileRead ENDP

    ;***************************************************;
    ;               UNSUCCESFUL FILE WRITE              ;
    ;         run when file write is unsuccesful        ;
    ;***************************************************;
    unsuccesfulFileWrite PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, errorMessage
        int     21h
        lea     dx, unsuccesfulFileWriteMessage
        int     21h
        
        pop     dx
        pop     ax
        ret
    unsuccesfulFileWrite ENDP

    ;***************************************************;
    ;                   NO PARAMETERS                   ;
    ;          run when no parameters are given         ;
    ;***************************************************;
    noParameters PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, errorMessage
        int     21h
        lea     dx, noParametersMessage
        int     21h
        
        pop     dx
        pop     ax
        ret
    noParameters ENDP

    ;***************************************************;
    ;                TOO MUCH PARAMETERS                ;
    ;       run when too much parameters are given      ;
    ;***************************************************;
    tooManyParameters PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, errorMessage
        int     21h
        lea     dx, tooManyParametersMessage
        int     21h
        
        pop     dx
        pop     ax
        ret
    tooManyParameters ENDP

    ;***************************************************;
    ;                INVALID LINE LENGTH                ;
    ;     run when line length is not a positive int    ;
    ;***************************************************;
    invalidLineLength PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, errorMessage
        int     21h
        lea     dx, invalidLineLengthMessage
        int     21h
        
        pop     dx
        pop     ax
        ret
    invalidLineLength ENDP

    ;***************************************************;
    ;                   TOO BIG NUMBER                  ;
    ;     run when line length is too big of a number   ;
    ;***************************************************;
    tooBigNumber PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, errorMessage
        int     21h
        lea     dx, tooBigNumberMessage
        int     21h
        
        pop     dx
        pop     ax
        ret
    tooBigNumber ENDP

    ;***************************************************;
    ;                    ASK FOR MORE                   ;
    ;***************************************************;
    askForMore  PROC
        push    ax
        push    dx

        ; Asking to press any key...
        mov     ah, 09h
        lea     dx, pressAnyKeyMessage
        int     21h
        mov     ah, 08h
        int     21h
        
        ; Clearing the line
        mov     ah, 09h
        lea     dx, clearLine
        int     21h

        pop     dx
        pop     ax
        ret
    askForMore ENDP

    ;***************************************************;
    ;                    DISPLAY HELP                   ;
    ;***************************************************;
    displayHelp PROC
        push    ax
        push    dx

        mov     ah, 09h
        lea     dx, _help
        int     21h
        
        lea     dx, _name
        int     21h

        call    askForMore

        lea     dx, _synopsis
        int     21h

        call    askForMore

        lea     dx, _description
        int     21h

        call    askForMore

        lea     dx, _example
        int     21h

        call    askForMore

        lea     dx, _options
        int     21h

        call    askForMore

        lea     dx, _notes
        int     21h

        call    askForMore

        lea     dx, _examples
        int     21h

        call    askForMore

        lea     dx, _author
        int     21h

        call    askForMore

        lea     dx, _copyright
        int     21h

        pop     dx
        pop     ax
        ret
    displayHelp ENDP

    ;***************************************************;
    ;                  IS DA QUESTION?                  ;
    ;***************************************************;
    isQuestion PROC
        push    ax
        push    di
        push    si

        @@compareLoop:
            mov     al, es:[di]
            cmp     al, byte ptr [si]
            jne     @@notNeeded
            inc     si
            inc     di
            cmp     byte ptr [si], 0
            je      @@checkIfOtherAlsoEnded
            cmp     byte ptr es:[di], 0
            je      @@notNeeded
            jmp     @@compareLoop
        
        @@checkIfOtherAlsoEnded:
        cmp     byte ptr es:[di], 0
        je      @@needed
        cmp     byte ptr es:[di], 0dh
        je      @@needed
        cmp     byte ptr es:[di], 20h
        je      @@needed
        jmp     @@notNeeded
        
        @@needed:
        mov     bx, 1
        
        @@notNeeded:
        pop     si
        pop     di
        pop     ax
        ret
    isQuestion ENDP

    ;***************************************************;
    ;                CHECK IF HELP NEEDED               ;
    ;***************************************************;
    checkIfHelp PROC
        push    si
        push    di

        lea     si, slashQuestionHelp
        call    isQuestion
        cmp     bx, 1
        je      @@needed

        lea     si, slashHLowerHelp
        call    isQuestion
        cmp     bx, 1
        je      @@needed

        lea     si, slashHUpperHelp
        call    isQuestion
        cmp     bx, 1
        je      @@needed

        lea     si, hyphenHLowerHelp
        call    isQuestion
        cmp     bx, 1
        je      @@needed

        lea     si, hyphenHUpperHelp
        call    isQuestion
        cmp     bx, 1
        je      @@needed

        lea     si, hyphenHyphenHelpHelp
        call    isQuestion
        cmp     bx, 1

        @@needed:
        pop     di
        pop     si
        ret
    checkIfHelp ENDP

    ;***************************************************;
    ;                    CREATE FILE                    ;
    ;***************************************************;
    createFile PROC
        push    ax
        push    cx
        push    dx

        mov     ah, 3Ch
        xor     cx, cx
        lea     dx, outputName
        int     21h

        jnc     @@continue
        call    unsuccesfulFileCreate
        call    displayHelp
        call    endProgram
        @@continue:
        mov     outputHandle, ax

        pop     dx
        pop     cx
        pop     ax
        ret
    createFile ENDP

    ;***************************************************;
    ;                    SKIP SPACES                    ;
    ;***************************************************;
    skipSpaces PROC
        @@skipSpace:	
            mov     al, es:[di]
            cmp     al, 20h
            je      @@increaseDI
            ret
        @@increaseDI:
        inc     di
        jmp     @@skipSpace
        ret
    skipSpaces ENDP

    ;***************************************************;
    ;                GET DATA FILE HANDLE               ;
    ;***************************************************;
    getDataFileHandle PROC
        push    ax
        push    dx

        mov     ax, 3D00h
        lea     dx, inputName
        int     21h

        jnc     @@continue
        call    unsuccesfulFileOpen
        call    displayHelp
        call    endProgram
        @@continue:
        mov     inputHandle, ax

        pop     dx
        pop     ax
        ret
    getDataFileHandle ENDP

    ;***************************************************;
    ;                GET REZ FILE HANDLE                ;
    ;***************************************************;
    getRezFileHandle PROC
        push    ax
        push    dx

        call    createFile

        pop     dx
        pop     ax
        ret
    getRezFileHandle ENDP

    ;***************************************************;
    ;                  GET FILE NAME                    ;
    ;***************************************************;
    getFileName PROC
        push    ax
        
        ; Check if we have qoutes
        mov     al, es:[di]
        cmp     al, 22h
        jne     @@continue
        mov     bx, 1
        mov     [si], al
        inc     si
        inc     di
        @@continue:

        @@readFileName:
            mov     al, es:[di]
            
            cmp     al, 0
            je      @@done

            cmp     al, 0dh
            je      @@done

            cmp     al, 22h
            je      @@qoute

            cmp     al, 20h
            jne     @@notOneOrSpace
            cmp     bx, 1
            jne     @@done

            @@notOneOrSpace:

            mov     [si], al

            inc     di
            inc     si
            jmp     @@readFileName
        
        @@qoute:
        inc     di
        mov     [si], al

        @@done:
        inc     si
        mov     byte ptr [si], 0

        pop     ax
        ret
    getFileName ENDP

    ;***************************************************;
    ;                GET LINE LENGTH                    ;
    ;***************************************************;
    getLineLength PROC
        push    ax
        push    bx
        push    cx
        push    dx

        xor     ax, ax
        mov     bx, 10
        xor     cx, cx

        @@readASymbol:
        mov     cl, es:[di]
        inc     di

        cmp     cl, 0
        je      @@check
        cmp     cl, 20h
        je      @@check
        cmp     cl, 0dh
        je      @@check

        cmp     cl, 30h
        jb      @@invalidSymbols
        cmp     cl, 39h
        ja      @@invalidSymbols

        mul     bx
        cmp     ax, 255
        ja      @@tooBigNumber

        sub     cl, 30h
        add     ax, cx
        cmp     ax, 255
        ja      @@tooBigNumber

        jmp     @@readASymbol

        @@invalidSymbols:
        call    invalidLineLength
        call    displayHelp
        call    endProgram

        @@tooBigNumber:
        call    tooBigNumber
        call    displayHelp
        call    endProgram

        @@check:
        cmp     al, 0
        jne     @@done
        call    invalidLineLength

        @@done:
        mov     lineLength, al

        pop     dx
        pop     cx
        pop     bx
        pop     ax
        ret
    getLineLength ENDP

    ;***************************************************;
    ;                   GET PARAMETERS                  ;
    ;***************************************************;
    getParameters PROC
        push    ax
        push    bx
        push    cx
        push    dx
        push    si
        push    di

        mov     al, es:[80h]
	    cmp     al, 0
        jne     @@continue
        call    noParameters
        call    displayHelp
        call    endProgram
        @@continue:

        mov     di, 81h
        call    skipSpaces

        ; Just checking if help is needed
        call    checkIfHelp
        cmp     bx, 1
        jne     @@continue2
        call    displayHelp
        call    endProgram
        @@continue2:

        ; Getting input file name
        lea     si, inputName
        call    getFileName
        call    skipSpaces

        ; Getting line length
        lea     si, lineLength
        call    getLineLength
        call    skipSpaces
        
        ; Getting output file name
        lea     si, outputName
        call    getFileName

        ; Checking if there are any more parameters
        call    skipSpaces
        xor     ax, ax
        mov     al, byte ptr es:[80h]
        add     ax, 81h
        cmp     ax, di
        je      @@noneParametersLeft
        call    tooManyParameters
        call    displayHelp
        call    endProgram

        @@noneParametersLeft:

        pop     di
        pop     si
        pop     dx
        pop     cx
        pop     bx
        pop     ax
        ret
    getParameters ENDP

    ;***************************************************;
    ;                  FIX THE POINTER                  ;
    ;***************************************************;
    fixThePointer PROC
        push    ax
        push    bx
        push    cx
        push    dx
        push    si

        lea     si, filePointer
        mov     cx, [si]
        mov     dx, [si+2]

        add     dl, ah
        adc     dh, 0
        adc     cx, 0

        mov     ax, 4200h
        mov     bx, inputHandle
        int     21h

        mov     [si], dx
        mov     [si+2], ax

        pop     si
        pop     dx
        pop     cx
        pop     bx
        pop     ax
        ret
    fixThePointer ENDP

    ;***************************************************;
    ;                    FLUSH BUFFER                   ;
    ;***************************************************;
    flushBuffer PROC
        push    ax
        push    bx
        push    cx
        push    dx
        push    di

        xor     cx, cx
        mov     cl, ah
        lea     dx, outputBuffer
        mov     ah, 40h

        cmp     bh, 0
        je      @@firstLine

        add     cx, 2
        sub     dx, 2

        @@firstLine:

        
        mov     bx, outputHandle
        int     21h
        jc      @@error
        jmp     @@done

        @@error:
        call    unsuccesfulFileWrite
        call    endProgram

        @@done:


        pop     di
        pop     dx
        pop     cx
        pop     bx
        pop     ax
        ret
    flushBuffer ENDP

    ;***************************************************;
    ;                    PROCESS FILE                   ;
    ;***************************************************;
    processFile PROC
        push    ax
        push    bx
        push    cx
        push    dx
        push    si
        push    di

        @@readNextChunk:
        mov     ah, 3Fh
        push    bx
        mov     bx, inputHandle
        lea     dx, inputBuffer
        xor     cx, cx
        mov     cl, lineLength
        int     21h
        pop     bx
        jc      @@error
        cmp     ax, 0
        je      @@finish

        lea     si, inputBuffer
        lea     di, outputBuffer
        mov     bl, al

        @@processChunk:
            mov     al, [si]

            cmp     al, 0
            jne     @@continue
            call    flushBuffer
            mov     bh, 1
            jmp     @@finish
            @@continue:

            cmp     al, 0dh
            jne     @@continue2
            call    flushBuffer
            add     ah, 2
            call    fixThePointer
            mov     bh, 1
            jmp     @@readNextChunk
            @@continue2:

            mov     [di], al
            inc     si
            inc     di
            inc     ah

            cmp     ah, bl
            jne     @@continue3
            call    flushBuffer
            mov     bh, 1
            call    fixThePointer
            jmp     @@readNextChunk
            @@continue3:


        loop    @@processChunk

        
        @@finish:
        pop     di
        pop     si
        pop     dx
        pop     cx
        pop     bx
        pop     ax
        ret
        
        @@error:
        call    unsuccesfulFileRead
        call    endProgram
    processFile ENDP


    ;***************************************************;
    ;                      ZE MAIN                      ;
    ;***************************************************;
    main:
        mov     ax, @data
        mov     ds, ax

        mov     di, 81h
        
        call    getParameters
        
        call    getDataFileHandle
        call    getRezFileHandle

        call    processFile

        call    endProgram
        
    end main
END
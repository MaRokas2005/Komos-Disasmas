;***************************************************;
;                   DEBUG MESSAGE                   ;
;***************************************************;
debug PROC
    push    ax
    push    bx
    push    cx
    push    dx
    push    si
    push    di

    mov     ah, 09h
    lea     dx, debugMessage
    int     21h
    call    askForMore
    
    pop     di
    pop     si
    pop     dx
    pop     cx
    pop     bx
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
;                  NOT EXE FILE                     ;
;         run when file is not an executable        ;
;***************************************************;
notExeFile PROC
    push    ax
    push    dx

    mov     ah, 09h
    lea     dx, errorMessage
    int     21h
    lea     dx, notExeFileMessage
    int     21h

    pop     dx
    pop     ax
    ret
notExeFile ENDP

;***************************************************;
;                  NOT TLINKER EXE                  ;
;         run when file is not a tlinker exe        ;
;***************************************************;
notTlinkerExe PROC
    push    ax
    push    dx

    mov     ah, 09h
    lea     dx, errorMessage
    int     21h
    lea     dx, notTlinkerExeMessage
    int     21h

    pop     dx
    pop     ax
    ret
notTlinkerExe ENDP

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
    ; FOR DEBUGING PURPOSES IT WAS COMMENTED
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

checkIfExe PROC
    push    ax
    push    bx
    push    cx
    push    dx

    mov     ax, 4200h
    mov     bx, inputHandle
    xor     cx, cx
    xor     dx, dx
    int     21h

    jc      @@error

    mov     ah, 3Fh
    mov     cx, 2
    lea     dx, inputBuffer
    int     21h

    jc      @@error


    cmp     byte ptr[inputBuffer], 4Dh
    jne     @@notExeFile
    cmp     byte ptr [inputBuffer+1], 5Ah
    jne     @@notExeFile

    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret

    @@notExeFile:
    call    notExeFile

    @@error:
    call    displayHelp
    call    endProgram
checkIfExe ENDP

checkIfTlinkerExe PROC
    push    ax
    push    bx
    push    cx
    push    dx

    mov     ax, 4200h
    mov     bx, inputHandle
    mov     cx, 0
    mov     dx, 1Eh
    int     21h

    mov     ah, 3Fh
    mov     cx, 1
    lea     dx, inputBuffer
    int     21h

    jc      @@error

    cmp     byte ptr [inputBuffer], 0FBh
    jne     @@notTlinkerExe
    
    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret

    @@notTlinkerExe:
    call    notTlinkerExe

    @@error:
    call    displayHelp
    call    endProgram
checkIfTlinkerExe ENDP
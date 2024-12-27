;***************************************************;
;               Printing output buffer              ;
;***************************************************;
printOutputBuffer PROC
    push    ax
    push    bx
    push    cx
    push    dx

    mov     ah, 40h
    mov     bx, outputHandle
    mov     cx, word ptr outputLength
    lea     dx, outputBuffer
    int     21h

    lea     di, outputBuffer
    mov     word ptr outputLength, 0

    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret
printOutputBuffer ENDP

;***************************************************;
;    getting byte to al and incrementing pointers   ;
;***************************************************;
getByte PROC
    lodsb
    add     word ptr usedBytes, 1
    add     word ptr byteInFile, 1
    adc     word ptr byteInFile + 2, 0
    ret
getByte ENDP

;***************************************************;
;    getting word to ax and incrementing pointers   ;
;***************************************************;
getWord PROC
    lodsw
    add     word ptr usedBytes, 2
    add     word ptr byteInFile, 2
    adc     word ptr byteInFile + 2, 0
    ret
getWord ENDP

;***************************************************;
;                 load text to buffer               ;
;             si - pointer to input text            ;
;           di - pointer to output buffer           ;
;***************************************************;
loadTextToBuffer PROC
    push    ax
    @@copy_start:
        lodsb
        cmp     al, 0
        je      @@done
        stosb
        inc     word ptr outputLength
        jmp     @@copy_start
    
    @@done:
    pop     ax
    ret
loadTextToBuffer ENDP

;***************************************************;
;               load newline to buffer              ;
;***************************************************;
loadNewline PROC
    push    si
    lea     si, newline
    call    loadTextToBuffer
    pop     si
    ret
loadNewline ENDP

;***************************************************;
;               load comment to buffer              ;
;***************************************************;
loadComment PROC
    push    si
    lea     si, komment
    call    loadTextToBuffer
    pop     si
    ret
loadComment ENDP

;***************************************************;
;           load comma and space to buffer          ;
;***************************************************;
loadCommaSpace PROC
    push    si
    lea     si, commaSpace
    call    loadTextToBuffer
    pop     si
    ret
loadCommaSpace ENDP

;;testing
loadScanning PROC
    push    si
    lea     si, scannning
    call    loadTextToBuffer
    pop     si
    ret
loadScanning ENDP
load_test_code PROC
    push    si
    lea     si, test_code
    call    loadTextToBuffer
    pop     si
    ret
load_test_code ENDP
load_test_data PROC
    push    si
    lea     si, test_data
    call    loadTextToBuffer
    pop     si
    ret
load_test_data ENDP
load_test_used PROC
    push    si
    lea     si, test_used
    call    loadTextToBuffer
    pop     si
    ret
load_test_used ENDP
load_test_curr PROC
    push    si
    lea     si, test_curr
    call    loadTextToBuffer
    pop     si
    ret
load_test_curr ENDP
load_test_si PROC
    push    si
    lea     si, test_si
    call    loadTextToBuffer
    pop     si
    ret
load_test_si ENDP

;***************************************************;
;                print byte to buffer               ;
;***************************************************;
fixScanPointer PROC
    push    ax
    push    bx
    push    cx
    push    dx

    mov     ax, 4200h
    mov     bx, inputHandle
    mov     cx, word ptr [byteInFile + 2]
    mov     dx, word ptr [byteInFile]
    int     21h

    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret
fixScanPointer ENDP

;***************************************************;
;           scan 300 bytes of code segment          ;
;***************************************************;
scanCodeSegment PROC
    push    bx
    push    cx
    push    dx

    mov     ah, 3fh
    mov     bx, inputHandle
    mov     cx, 300
    lea     dx, inputBuffer
    int     21h

    jc      @@error

    mov     word ptr usedBytes, 0

    call    loadScanning
    call    loadNewline
    call    printOutputBuffer

    pop     dx
    pop     cx
    pop     bx
    ret
    @@error:
    call    unsuccesfulFileRead
    call    endProgram
scanCodeSegment ENDP

;***************************************************;
;    Printing the start of the disassembled code    ;
;***************************************************;
printStart PROC
    push    ax
    push    bx
    push    cx
    push    dx
    push    si
    push    di
    push    es

    mov     ax, seg outputBuffer
    mov     es, ax

    lea     di, outputBuffer
    mov     word ptr outputLength, 0

    lea     si, segModel
    call    loadTextToBuffer

    lea     si, newline
    call    loadTextToBuffer

    lea     si, segStack
    call    loadTextToBuffer

    mov     al, 20h
    inc     word ptr outputLength
    stosb

    @@stack_size:

    mov     dx, stackSize
    call    printWord

    lea     si, newline
    call    loadTextToBuffer
    lea     si, newline
    call    loadTextToBuffer

    @@data:

    lea     si, segData
    call    loadTextToBuffer
    lea     si, newline
    call    loadTextToBuffer

    @@print:
    call    printOutputBuffer

    pop     es
    pop     di
    pop     si
    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret
printStart ENDP

;***************************************************;
;               Printing data segment               ;
;***************************************************;
printDataSegment PROC
    push    ax
    push    bx
    push    cx
    push    dx
    push    si
    push    di
    push    es

    ; Move input handle pointer to data segment start
    mov     ax, 4200h
    mov     bx, inputHandle
    mov     dx, word ptr [dataSegmentStart]
    mov     cx, word ptr [dataSegmentStart + 2]
    int     21h

    mov     ax, seg outputBuffer
    mov     es, ax

    
 
    @@read_and_print:
        ; check if I am not in code segment
        mov     ax, 4201h
        mov     bx, inputHandle
        xor     cx, cx
        xor     dx, dx
        int     21h

        jc      @@error_temp

        cmp     ax, word ptr [codeSegmentOffset]
        je      @@done

        ; read from file
        mov     ah, 3fh
        mov     bx, inputHandle
        mov     cx, 10h
        lea     dx, inputBuffer
        int     21h

        jc      @@error

        cmp     ax, 0h
        je      @@done

        mov     cx, ax

        ; writing to buffer
        lea     si, tagDB
        lea     di, outputBuffer
        mov     word ptr outputLength, 0
        jmp     @@copy_db

        @@error_temp:
        jmp     @@error


        @@copy_db:
            lodsb
            cmp     al, 0
            je      @@done_db
            stosb
            inc     word ptr outputLength
            jmp     @@copy_db
        
        @@done_db:
        
        lea     si, inputBuffer

        ; print first byte
        mov     dl, byte ptr [si]
        inc     si
        inc     dh
        call    printByte
        dec     cx
        cmp     cx, 0h
        je      @@loop_done

        @@loop_print:
            mov     al, ","
            stosb
            inc     word ptr outputLength
            mov     al, " "
            stosb
            inc     word ptr outputLength

            mov     dl, byte ptr [si]
            inc     si
            call    printByte
            loop    @@loop_print
        
        @@loop_done:
        lea     si, newline
        call    loadTextToBuffer

        call    printOutputBuffer
        

        jmp     @@read_and_print

    @@done:

    pop     es
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
printDataSegment ENDP

;***************************************************;
;               Printing code segment               ;
;***************************************************;
printCodeSegment PROC
    push    ax
    push    bx
    push    cx
    push    dx
    push    si
    push    di
    push    es

    ;;call debug

    mov     ax, seg outputBuffer
    mov     es, ax

    mov     word ptr outputLength, 0
    lea     di, outputBuffer
    lea     si, segCode
    call    loadTextToBuffer
    lea     si, newline
    call    loadTextToBuffer

    call    printOutputBuffer


    mov     ax, word ptr codeSegmentOffset
    mov     word ptr byteInFile, ax
 
    @@read_and_print:
        cmp     word ptr usedBytes, 0ffh
        jb      @@write
        ; scan 300 bytes of code segment
        call    fixScanPointer
        call    scanCodeSegment
        cmp     ax, 0
        je      @@done
        lea     si, inputBuffer
        @@write:
        ; check if I am not in data segment
        mov     ax, word ptr byteInFile
        cmp     ax, word ptr dataSegmentStart
        jne     @@continue
        mov     ax, word ptr [byteInFile + 2]
        cmp     ax, word ptr [dataSegmentStart + 2]
        jae      @@done

        @@continue:
        ;; testing
        push dx
        call load_test_code
        mov dx, word ptr [byteInFile+2]
        call printWord
        mov dx, word ptr byteInFile
        call printWord
        call loadNewline
        call load_test_data
        mov dx, word ptr [dataSegmentStart+2]
        call printWord
        mov dx, word ptr dataSegmentStart
        call printWord
        call loadNewline
        call load_test_used
        mov dx, word ptr usedBytes
        call printWord
        call loadNewline
        mov dx, si
        call load_test_si
        call printWord
        call loadNewline
        pop dx
        ;; end testing

        call    getByte
        call    load_test_curr
        mov     dl, al
        call    printByte
        call    loadNewline

        ; call    printOutputBuffer
        call    OPCODE_00h
        call    loadNewline
        call    loadNewline
        call    printOutputBuffer

        jmp     @@read_and_print

    @@error_temp:
    jmp     @@error

    @@done:
    call    printOutputBuffer

    pop     es
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
printCodeSegment ENDP

printEnd PROC
    push    ax
    push    bx
    push    cx
    push    dx
    push    si
    push    di
    push    es

    mov     ax, seg outputBuffer
    mov     es, ax

    lea     di, outputBuffer
    mov     word ptr outputLength, 0

    lea     si, segEnd
    call    loadTextToBuffer

    lea     si, newline
    call    printOutputBuffer

    pop     es
    pop     di
    pop     si
    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret
printEnd ENDP
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

    lea     si, segModel
    lea     di, outputBuffer
    mov     word ptr outputLength, 0

    @@copy_model:
        lodsb
        cmp     al, 0
        je      @@done_model
        stosb
        inc     word ptr outputLength
        jmp     @@copy_model
    
    @@done_model:
    mov     al, 0dh
    stosb
    inc     word ptr outputLength
    mov     al, 0ah
    stosb
    inc     word ptr outputLength

    lea     si, segStack

    @@copy_stack:
        lodsb
        cmp     al, 0
        je      @@done_stack
        stosb
        inc     word ptr outputLength
        jmp     @@copy_stack

    @@done_stack:
    mov     al, 20h
    inc     word ptr outputLength
    stosb

    @@stack_size:

    mov     dx, stackSize
    call    printWord

    mov     al, 0dh
    stosb
    inc     word ptr outputLength
    mov     al, 0ah
    stosb
    inc     word ptr outputLength
    mov     al, 0dh
    stosb
    inc     word ptr outputLength
    mov     al, 0ah
    stosb
    inc     word ptr outputLength

    @@data:

    lea     si, segData

    @@copy_data:
        lodsb
        cmp     al, 0
        je      @@done_data
        stosb
        inc     word ptr outputLength
        jmp     @@copy_data
    
    @@done_data:
    mov     al, 0dh
    stosb
    inc     word ptr outputLength
    mov     al, 0ah
    stosb
    inc     word ptr outputLength

    @@print:
    mov     ah, 40h
    mov     bx, outputHandle
    mov     cx, word ptr outputLength
    lea     dx, outputBuffer
    int     21h

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

    call debug

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
        mov     al, 0dh
        stosb
        inc     word ptr outputLength
        mov     al, 0ah
        stosb
        inc     word ptr outputLength

        mov     ah, 40h
        mov     bx, outputHandle
        mov     cx, word ptr outputLength
        lea     dx, outputBuffer
        int     21h
        

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

    call debug

    ; Move input handle pointer to code segment start
    mov     ax, 4200h
    mov     bx, inputHandle
    mov     dx, word ptr [codeSegmentOffset]
    mov     cx, word ptr [codeSegmentOffset + 2]
    int     21h

    mov     ax, seg outputBuffer
    mov     es, ax

    
 
    @@read_and_print:
        ; check if I am not in data segment
        mov     ax, 4201h
        mov     bx, inputHandle
        xor     cx, cx
        xor     dx, dx
        int     21h

        jc      @@error_temp

        cmp     ax, word ptr [dataSegmentOffset]
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

    ret
printCodeSegment ENDP
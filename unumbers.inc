printByte PROC
    push    ax
    push    bx

    mov     bl, dl
    shr     bl, 04h
    cmp     bl, 09h
    ja      @@byte_a_f_1
    add     bl, 30h
    jmp     @@byte_done_1
    @@byte_a_f_1:
    add     bl, 57h
    @@byte_done_1:
    mov     al, 30h
    stosb
    inc     word ptr outputLength
    mov     al, bl
    stosb
    inc     word ptr outputLength

    mov     bl, dl
    shl     bl, 04h
    shr     bl, 04h
    cmp     bl, 09h
    ja      @@byte_a_f_2
    add     bl, 30h
    jmp     @@byte_done_2
    @@byte_a_f_2:
    add     bl, 57h
    @@byte_done_2:
    mov     al, bl
    stosb
    inc     word ptr outputLength

    mov     al, "h"
    stosb
    inc     word ptr outputLength

    pop     bx
    pop     ax
    ret
printByte ENDP

printWord PROC
    ; checking if the word is '@data'
    push    ax ; get word from buffer using lodsw
    push    bx ; 0 - not the '@data', 1 - is the '@data'
    push    cx ; number of relocations
    push    dx ; for calculations of relocation address
    push    si ; load effective address of buffer

    ; mov ah, 1
    ; int 21h
    
    lea     si, relocationBuffer
    xor     bx, bx
    mov     cx, word ptr numberOfRelocations
    
    @@loop_checking:
        lodsw
        mov     dx, ax
        lodsw
        shl     ax, 4
        add     dx, ax
        add     dx, word ptr headerSize
        inc     dx
        inc     dx
        cmp     dx, word ptr byteInFile
        jne     @@not_done_checking
        mov     bl, 1
        jmp     @@done_checking
        @@not_done_checking:
        loop    @@loop_checking

    @@done_checking:
    cmp     bl, 0
    je      @@continue
    lea     si, tagData
    call    loadTextToBuffer
    pop     si
    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret

    @@continue:
    pop     si
    pop     dx
    pop     cx

    mov     bx, dx
    shr     bx, 0ch
    cmp     bx, 09h
    ja      @@word_a_f_1
    add     bx, 30h
    jmp     @@word_done_1
    @@word_a_f_1:
    add     bx, 57h
    @@word_done_1:
    mov     al, 30h
    stosb
    inc     word ptr outputLength
    mov     al, bl
    stosb
    inc     word ptr outputLength

    mov     bx, dx
    shl     bx, 04h
    shr     bx, 0ch
    cmp     bx, 09h
    ja      @@word_a_f_2
    add     bx, 30h
    jmp     @@word_done_2
    @@word_a_f_2:
    add     bx, 57h
    @@word_done_2:
    mov     al, bl
    stosb
    inc     word ptr outputLength

    mov     bx, dx
    shl     bx, 08h
    shr     bx, 0ch
    cmp     bx, 09h
    ja      @@word_a_f_3
    add     bx, 30h
    jmp     @@word_done_3
    @@word_a_f_3:
    add     bx, 57h
    @@word_done_3:
    mov     al, bl
    stosb
    inc     word ptr outputLength

    mov     bx, dx
    shl     bx, 0ch
    shr     bx, 0ch
    cmp     bx, 09h
    ja      @@word_a_f_4
    add     bx, 30h
    jmp     @@word_done_4
    @@word_a_f_4:
    add     bx, 57h
    @@word_done_4:
    mov     al, bl
    stosb
    inc     word ptr outputLength

    mov     al, "h"
    stosb
    inc     word ptr outputLength

    pop     bx
    pop     ax
    ret
printWord ENDP

printMCByte PROC
    push    ax
    push    bx

    mov     bl, dl
    shr     bl, 04h
    cmp     bl, 09h
    ja      @@byte_a_f_1
    add     bl, 30h
    jmp     @@byte_done_1
    @@byte_a_f_1:
    add     bl, 57h
    @@byte_done_1:
    mov     al, bl
    stosb
    inc     word ptr outputLength

    mov     bl, dl
    shl     bl, 04h
    shr     bl, 04h
    cmp     bl, 09h
    ja      @@byte_a_f_2
    add     bl, 30h
    jmp     @@byte_done_2
    @@byte_a_f_2:
    add     bl, 57h
    @@byte_done_2:
    mov     al, bl
    stosb
    inc     word ptr outputLength

    pop     bx
    pop     ax
    ret
printMCByte ENDP
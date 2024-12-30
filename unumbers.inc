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
    push    ax
    push    bx ; 0 - not the '@data', 1 - is the '@data'
    push    cx
    push    dx
    push    si

    lea     si, relocationBuffer
    xor     bx, bx
    mov     cx, word ptr numberOfRelocations
    mov     dx, 


    pop     si
    pop     dx
    pop     cx
    pop     bx
    pop     ax

    cmp     bl, 0
    je      @@continue
    ret

    @@continue:
    push    ax
    push    bx

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

;***************************************************;
;                  get mod reg r/m                  ;
;                 dl = mod reg r/m                  ;
;***************************************************;
getModRegRM PROC
    push    bx

    mov     bl, dl
    and     bl, 7h
    mov     opcodeRM, bl

    mov     bl, dl
    shr     bl, 3
    and     bl, 7h
    mov     opcodeReg, bl

    mov     bl, dl
    shr     bl, 6
    and     bl, 3h
    mov     opcodeMod, bl

    pop     bx
    ret
getModRegRM ENDP

OPCODE_00h PROC
    mov     bl, al
    xor     bl, 00h
    cmp     bl, 00h
    jne     @@continue
        ret
        call    OPCODE_01h
        ret
    
    @@continue:
    push    ax
    push    bx



    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_00h ENDP

OPCODE_01h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 01h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_02h
    jmp     @@done

    @@continue:
    

    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_01h ENDP

OPCODE_02h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 02h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_03h
    jmp     @@done

    @@continue:
    

    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_02h ENDP

OPCODE_03h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 03h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_04h
    jmp     @@done

    @@continue:
    

    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_03h ENDP

OPCODE_04h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 04h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_05h
    jmp     @@done

    @@continue:
    

    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_04h ENDP

OPCODE_05h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 05h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_06h
    jmp     @@done

    @@continue:
    

    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_05h ENDP

OPCODE_06h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 06h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_07h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_06h ENDP

OPCODE_07h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 07h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_08h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_07h ENDP

OPCODE_08h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 08h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_09h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_08h ENDP

OPCODE_09h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 09h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_0ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_09h ENDP

OPCODE_0ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_0bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_0ah ENDP

OPCODE_0bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_0ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_0bh ENDP

OPCODE_0ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_0dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_0ch ENDP

OPCODE_0dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_0eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_0dh ENDP

OPCODE_0eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_0fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_0eh ENDP

OPCODE_0fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_10h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_0fh ENDP

OPCODE_10h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 10h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_11h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_10h ENDP

OPCODE_11h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 11h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_12h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_11h ENDP

OPCODE_12h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 12h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_13h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_12h ENDP

OPCODE_13h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 13h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_14h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_13h ENDP

OPCODE_14h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 14h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_15h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_14h ENDP

OPCODE_15h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 15h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_16h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_15h ENDP

OPCODE_16h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 16h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_17h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_16h ENDP

OPCODE_17h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 17h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_18h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_17h ENDP

OPCODE_18h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 18h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_19h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_18h ENDP

OPCODE_19h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 19h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_1ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_19h ENDP

OPCODE_1ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 1ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_1bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_1ah ENDP

OPCODE_1bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 1bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_1ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_1bh ENDP

OPCODE_1ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 1ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_1dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_1ch ENDP

OPCODE_1dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 1dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_1eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_1dh ENDP

OPCODE_1eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 1eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_1fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_1eh ENDP

OPCODE_1fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 1fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_20h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_1fh ENDP

OPCODE_20h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 20h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_21h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_20h ENDP

OPCODE_21h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 21h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_22h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_21h ENDP

OPCODE_22h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 22h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_23h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_22h ENDP

OPCODE_23h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 23h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_24h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_23h ENDP

OPCODE_24h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 24h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_25h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_24h ENDP

OPCODE_25h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 25h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_26h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_25h ENDP

OPCODE_26h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 26h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_27h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_26h ENDP

OPCODE_27h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 27h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_28h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_27h ENDP

OPCODE_28h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 28h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_29h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_28h ENDP

OPCODE_29h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 29h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_2ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_29h ENDP

OPCODE_2ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 2ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_2bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_2ah ENDP

OPCODE_2bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 2bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_2ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_2bh ENDP

OPCODE_2ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 2ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_2dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_2ch ENDP

OPCODE_2dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 2dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_2eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_2dh ENDP

OPCODE_2eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 2eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_2fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_2eh ENDP

OPCODE_2fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 2fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_30h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_2fh ENDP

OPCODE_30h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 30h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_31h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_30h ENDP

OPCODE_31h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 31h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_32h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_31h ENDP

OPCODE_32h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 32h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_33h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_32h ENDP

OPCODE_33h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 33h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_34h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_33h ENDP

OPCODE_34h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 34h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_35h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_34h ENDP

OPCODE_35h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 35h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_36h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_35h ENDP

OPCODE_36h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 36h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_37h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_36h ENDP

OPCODE_37h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 37h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_38h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_37h ENDP

OPCODE_38h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 38h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_39h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_38h ENDP

OPCODE_39h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 39h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_3ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_39h ENDP

OPCODE_3ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 3ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_3bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_3ah ENDP

OPCODE_3bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 3bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_3ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_3bh ENDP

OPCODE_3ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 3ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_3dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_3ch ENDP

OPCODE_3dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 3dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_3eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_3dh ENDP

OPCODE_3eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 3eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_3fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_3eh ENDP

OPCODE_3fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 3fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_40h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_3fh ENDP

OPCODE_40h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 40h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_41h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_40h ENDP

OPCODE_41h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 41h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_42h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_41h ENDP

OPCODE_42h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 42h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_43h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_42h ENDP

OPCODE_43h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 43h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_44h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_43h ENDP

OPCODE_44h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 44h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_45h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_44h ENDP

OPCODE_45h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 45h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_46h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_45h ENDP

OPCODE_46h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 46h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_47h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_46h ENDP

OPCODE_47h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 47h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_48h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_47h ENDP

OPCODE_48h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 48h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_49h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_48h ENDP

OPCODE_49h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 49h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_4ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_49h ENDP

OPCODE_4ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 4ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_4bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_4ah ENDP

OPCODE_4bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 4bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_4ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_4bh ENDP

OPCODE_4ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 4ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_4dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_4ch ENDP

OPCODE_4dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 4dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_4eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_4dh ENDP

OPCODE_4eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 4eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_4fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_4eh ENDP

OPCODE_4fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 4fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_50h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_4fh ENDP

OPCODE_50h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 50h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_51h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_50h ENDP

OPCODE_51h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 51h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_52h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_51h ENDP

OPCODE_52h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 52h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_53h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_52h ENDP

OPCODE_53h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 53h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_54h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_53h ENDP

OPCODE_54h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 54h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_55h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_54h ENDP

OPCODE_55h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 55h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_56h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_55h ENDP

OPCODE_56h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 56h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_57h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_56h ENDP

OPCODE_57h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 57h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_58h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_57h ENDP

OPCODE_58h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 58h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_59h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_58h ENDP

OPCODE_59h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 59h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_5ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_59h ENDP

OPCODE_5ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 5ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_5bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_5ah ENDP

OPCODE_5bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 5bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_5ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_5bh ENDP

OPCODE_5ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 5ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_5dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_5ch ENDP

OPCODE_5dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 5dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_5eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_5dh ENDP

OPCODE_5eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 5eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_5fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_5eh ENDP

OPCODE_5fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 5fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_60h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_5fh ENDP

OPCODE_60h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 60h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_61h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_60h ENDP

OPCODE_61h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 61h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_62h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_61h ENDP

OPCODE_62h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 62h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_63h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_62h ENDP

OPCODE_63h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 63h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_64h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_63h ENDP

OPCODE_64h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 64h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_65h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_64h ENDP

OPCODE_65h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 65h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_66h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_65h ENDP

OPCODE_66h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 66h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_67h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_66h ENDP

OPCODE_67h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 67h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_68h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_67h ENDP

OPCODE_68h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 68h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_69h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_68h ENDP

OPCODE_69h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 69h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_6ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_69h ENDP

OPCODE_6ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 6ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_6bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_6ah ENDP

OPCODE_6bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 6bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_6ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_6bh ENDP

OPCODE_6ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 6ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_6dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_6ch ENDP

OPCODE_6dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 6dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_6eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_6dh ENDP

OPCODE_6eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 6eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_6fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_6eh ENDP

OPCODE_6fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 6fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_70h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_6fh ENDP

OPCODE_70h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 70h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_71h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_70h ENDP

OPCODE_71h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 71h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_72h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_71h ENDP

OPCODE_72h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 72h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_73h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_72h ENDP

OPCODE_73h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 73h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_74h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_73h ENDP

OPCODE_74h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 74h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_75h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_74h ENDP

OPCODE_75h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 75h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_76h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_75h ENDP

OPCODE_76h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 76h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_77h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_76h ENDP

OPCODE_77h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 77h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_78h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_77h ENDP

OPCODE_78h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 78h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_79h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_78h ENDP

OPCODE_79h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 79h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_7ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_79h ENDP

OPCODE_7ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 7ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_7bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_7ah ENDP

OPCODE_7bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 7bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_7ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_7bh ENDP

OPCODE_7ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 7ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_7dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_7ch ENDP

OPCODE_7dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 7dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_7eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_7dh ENDP

OPCODE_7eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 7eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_7fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_7eh ENDP

OPCODE_7fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 7fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_80h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_7fh ENDP

OPCODE_80h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 80h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_81h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_80h ENDP

OPCODE_81h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 81h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_82h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_81h ENDP

OPCODE_82h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 82h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_83h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_82h ENDP

OPCODE_83h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 83h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_84h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_83h ENDP

OPCODE_84h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 84h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_85h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_84h ENDP

OPCODE_85h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 85h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_86h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_85h ENDP

OPCODE_86h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 86h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_87h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_86h ENDP

OPCODE_87h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 87h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_88h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_87h ENDP

OPCODE_88h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 88h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_89h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_88h ENDP

OPCODE_89h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 89h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_8ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_89h ENDP

OPCODE_8ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 8ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_8bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_8ah ENDP

OPCODE_8bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 8bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_8ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_8bh ENDP

OPCODE_8ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 8ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_8dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_8ch ENDP

OPCODE_8dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 8dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_8eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_8dh ENDP

OPCODE_8eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 8eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_8fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_8eh ENDP

OPCODE_8fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 8fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_90h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_8fh ENDP

OPCODE_90h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 90h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_91h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_90h ENDP

OPCODE_91h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 91h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_92h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_91h ENDP

OPCODE_92h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 92h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_93h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_92h ENDP

OPCODE_93h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 93h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_94h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_93h ENDP

OPCODE_94h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 94h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_95h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_94h ENDP

OPCODE_95h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 95h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_96h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_95h ENDP

OPCODE_96h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 96h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_97h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_96h ENDP

OPCODE_97h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 97h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_98h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_97h ENDP

OPCODE_98h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 98h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_99h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_98h ENDP

OPCODE_99h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 99h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_9ah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_99h ENDP

OPCODE_9ah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 9ah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_9bh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_9ah ENDP

OPCODE_9bh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 9bh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_9ch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_9bh ENDP

OPCODE_9ch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 9ch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_9dh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_9ch ENDP

OPCODE_9dh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 9dh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_9eh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_9dh ENDP

OPCODE_9eh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 9eh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_9fh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_9eh ENDP

OPCODE_9fh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 9fh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a0h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_9fh ENDP

OPCODE_a0h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a0h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a1h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a0h ENDP

OPCODE_a1h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a1h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a2h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a1h ENDP

OPCODE_a2h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a2h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a3h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a2h ENDP

OPCODE_a3h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a3h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a4h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a3h ENDP

OPCODE_a4h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a4h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a5h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a4h ENDP

OPCODE_a5h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a5h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a6h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a5h ENDP

OPCODE_a6h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a6h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a7h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a6h ENDP

OPCODE_a7h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a7h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a8h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a7h ENDP

OPCODE_a8h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a8h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_a9h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a8h ENDP

OPCODE_a9h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0a9h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_aah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_a9h ENDP

OPCODE_aah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0aah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_abh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_aah ENDP

OPCODE_abh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0abh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_ach
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_abh ENDP

OPCODE_ach PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0ach
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_adh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_ach ENDP

OPCODE_adh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0adh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_aeh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_adh ENDP

OPCODE_aeh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0aeh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_afh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_aeh ENDP

OPCODE_afh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0afh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b0h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_afh ENDP

OPCODE_b0h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b0h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b1h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b0h ENDP

OPCODE_b1h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b1h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b2h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b1h ENDP

OPCODE_b2h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b2h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b3h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b2h ENDP

OPCODE_b3h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b3h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b4h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b3h ENDP

OPCODE_b4h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b4h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b5h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b4h ENDP

OPCODE_b5h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b5h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b6h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b5h ENDP

OPCODE_b6h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b6h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b7h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b6h ENDP

OPCODE_b7h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b7h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b8h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b7h ENDP

OPCODE_b8h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b8h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_b9h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b8h ENDP

OPCODE_b9h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0b9h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_bah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_b9h ENDP

OPCODE_bah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0bah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_bbh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_bah ENDP

OPCODE_bbh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0bbh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_bch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_bbh ENDP

OPCODE_bch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0bch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_bdh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_bch ENDP

OPCODE_bdh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0bdh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_beh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_bdh ENDP

OPCODE_beh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0beh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_bfh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_beh ENDP

OPCODE_bfh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0bfh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c0h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_bfh ENDP

OPCODE_c0h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c0h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c1h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c0h ENDP

OPCODE_c1h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c1h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c2h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c1h ENDP

OPCODE_c2h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c2h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c3h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c2h ENDP

OPCODE_c3h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c3h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c4h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c3h ENDP

OPCODE_c4h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c4h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c5h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c4h ENDP

OPCODE_c5h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c5h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c6h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c5h ENDP

OPCODE_c6h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c6h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c7h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c6h ENDP

OPCODE_c7h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c7h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c8h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c7h ENDP

OPCODE_c8h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c8h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_c9h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c8h ENDP

OPCODE_c9h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0c9h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_cah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_c9h ENDP

OPCODE_cah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0cah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_cbh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_cah ENDP

OPCODE_cbh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0cbh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_cch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_cbh ENDP

OPCODE_cch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0cch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_cdh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_cch ENDP

OPCODE_cdh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0cdh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_ceh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_cdh ENDP

OPCODE_ceh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0ceh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_cfh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_ceh ENDP

OPCODE_cfh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0cfh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d0h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_cfh ENDP

OPCODE_d0h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d0h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d1h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d0h ENDP

OPCODE_d1h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d1h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d2h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d1h ENDP

OPCODE_d2h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d2h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d3h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d2h ENDP

OPCODE_d3h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d3h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d4h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d3h ENDP

OPCODE_d4h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d4h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d5h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d4h ENDP

OPCODE_d5h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d5h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d6h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d5h ENDP

OPCODE_d6h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d6h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d7h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d6h ENDP

OPCODE_d7h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d7h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d8h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d7h ENDP

OPCODE_d8h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d8h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_d9h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d8h ENDP

OPCODE_d9h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0d9h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_dah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_d9h ENDP

OPCODE_dah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0dah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_dbh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_dah ENDP

OPCODE_dbh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0dbh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_dch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_dbh ENDP

OPCODE_dch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0dch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_ddh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_dch ENDP

OPCODE_ddh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0ddh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_deh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_ddh ENDP

OPCODE_deh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0deh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_dfh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_deh ENDP

OPCODE_dfh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0dfh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e0h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_dfh ENDP

OPCODE_e0h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e0h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e1h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e0h ENDP

OPCODE_e1h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e1h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e2h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e1h ENDP

OPCODE_e2h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e2h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e3h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e2h ENDP

OPCODE_e3h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e3h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e4h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e3h ENDP

OPCODE_e4h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e4h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e5h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e4h ENDP

OPCODE_e5h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e5h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e6h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e5h ENDP

OPCODE_e6h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e6h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e7h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e6h ENDP

OPCODE_e7h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e7h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e8h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e7h ENDP

OPCODE_e8h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e8h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_e9h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e8h ENDP

OPCODE_e9h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0e9h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_eah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_e9h ENDP

OPCODE_eah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0eah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_ebh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_eah ENDP

OPCODE_ebh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0ebh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_ech
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_ebh ENDP

OPCODE_ech PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0ech
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_edh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_ech ENDP

OPCODE_edh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0edh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_eeh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_edh ENDP

OPCODE_eeh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0eeh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_efh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_eeh ENDP

OPCODE_efh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0efh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f0h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_efh ENDP

OPCODE_f0h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f0h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f1h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f0h ENDP

OPCODE_f1h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f1h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f2h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f1h ENDP

OPCODE_f2h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f2h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f3h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f2h ENDP

OPCODE_f3h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f3h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f4h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f3h ENDP

OPCODE_f4h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f4h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f5h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f4h ENDP

OPCODE_f5h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f5h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f6h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f5h ENDP

OPCODE_f6h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f6h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f7h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f6h ENDP

OPCODE_f7h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f7h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f8h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f7h ENDP

OPCODE_f8h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f8h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_f9h
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f8h ENDP

OPCODE_f9h PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0f9h
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_fah
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_f9h ENDP

OPCODE_fah PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0fah
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_fbh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_fah ENDP

OPCODE_fbh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0fbh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_fch
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_fbh ENDP

OPCODE_fch PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0fch
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_fdh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_fch ENDP

OPCODE_fdh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0fdh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_feh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_fdh ENDP

OPCODE_feh PROC
    push    ax
    push    bx

    mov     bl, al
    xor     bl, 0feh
    cmp     bl, 00h
    jne     @@continue
    call    OPCODE_ffh
    jmp     @@done

    @@continue:


    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_feh ENDP

OPCODE_ffh PROC
    push    ax
    push    bx




    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_ffh ENDP

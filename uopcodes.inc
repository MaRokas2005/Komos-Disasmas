;***************************************************;
;                  get mod reg r/m                  ;
;                 al = mod reg r/m                  ;
;***************************************************;
getModRegRM PROC
    push    bx

    mov     bl, al
    and     bl, 7h
    mov     opcodeRM, bl

    mov     bl, al
    shr     bl, 3
    and     bl, 7h
    mov     opcodeReg, bl

    mov     bl, al
    shr     bl, 6
    and     bl, 3h
    mov     opcodeMod, bl

    pop     bx
    ret
getModRegRM ENDP

loadPtr PROC
    push    si
    cmp     dl, 0
    jne     @@16bits
    lea     si, tagByte
    jmp     @@continue
    @@16bits:
    lea     si, tagWord
    @@continue:
    call    loadTextToBuffer
    pop     si
    ret
loadPtr ENDP

loadTagStart PROC
    push    ax
    push    si

    @@checking_prefix:
    cmp     byte ptr prefix, 0ffh
    je      @@dont_have_prefix
    xor     ax, ax
    mov     al, byte ptr prefix
    shl     al, 3
    shr     al, 6
    
    lea     si, tagSegES
    shl     ax, 3
    add     si, ax
    jmp     @@continue_2

    @@dont_have_prefix:
    lea     si, tagStart

    @@continue_2:
    call    loadTextToBuffer

    pop     si
    pop     ax
    ret
loadTagStart ENDP

loadTagClose PROC
    push    si
    lea     si, tagClose
    call    loadTextToBuffer
    pop     si

    @@reset_prefix:
    mov     byte ptr prefix, 0ffh
    ret
loadTagClose ENDP

;***************************************************;
;                  load mod reg r/m                 ;
;                     dl - w bit                    ;
;               bl - loadPtr is needed              ;
;***************************************************;
loadModRM PROC
    push    ax
    push    bx
    push    cx
    push    dx

    cmp     byte ptr opcodeMod, 3h
    je      @@mod_11_temp

    cmp     bl, 0
    je      @@continue_1
    call    loadPtr

    @@continue_1:
    call    loadTagStart
    
    xor     ax, ax
    mov     al, byte ptr opcodeRM
    shl     ax, 4
    cmp     byte ptr opcodeMod, 0h
    jne     @@continue_3

    @@mod_00:
    cmp     byte ptr opcodeRM, 6h
    je      @@mod_00_110

    push    si
    lea     si, mod_00_000
    add     si, ax
    call    loadTextToBuffer
    pop     si
    jmp     @@continue_4

    @@mod_00_110:
    call    getWord
    mov     dx, ax
    call    printWord
    jmp     @@continue_4

    @@mod_11_temp:
    jmp     @@mod_11

    @@continue_3:
    push    si
    lea     si, mod_01_10_000
    add     si, ax
    call    loadTextToBuffer
    pop     si

    cmp     byte ptr opcodeMod, 1h
    jne     @@mod_10

    @@mod_01:
    call    getByte
    mov     dl, al
    call    printByte
    jmp     @@continue_4

    @@mod_10:
    call    getWord
    mov     dx, ax
    call    printWord
    @@continue_4:
    
    call    loadTagClose
    jmp     @@done

    @@mod_11:
    mov     bl, byte ptr opcodeReg
    mov     al, byte ptr opcodeRM
    mov     byte ptr opcodeReg, al
    call    loadReg
    mov     byte ptr opcodeReg, bl

    @@done:
    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret
loadModRM ENDP

;***************************************************;
;                 load reg to buffer                ;
;                     dl - w bit                    ;
;***************************************************;
loadReg PROC
    push    ax
    push    bx
    push    cx
    push    dx
    push    si

    cmp     dl, 1
    je      @@reg_large

    @@reg_small:
    lea     si, reg_al
    jmp     @@continue

    @@reg_large:
    lea     si, reg_ax

    @@continue:
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 2
    add     si, bx
    call    loadTextToBuffer

    pop     si
    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret
loadReg ENDP

;***************************************************;
;   w = 0 => byte                                   ;
;   add - reg1 to reg2                              ;
;   add - reg to mem                                ;
;***************************************************;
OPCODE_00h PROC
    cmp     al, 00h
    je      @@continue
        call    OPCODE_01h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_add
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_00h ENDP

;***************************************************;
;   w = 1 => word                                   ;
;   add - reg1 to reg2                              ;
;   add - reg to mem                                ;
;***************************************************;
OPCODE_01h PROC
    cmp     al, 01h
    je      @@continue
        call    OPCODE_02h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_add
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_01h ENDP

OPCODE_02h PROC
    cmp     al, 02h
    je      @@continue
        call    OPCODE_03h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_add
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_02h ENDP

OPCODE_03h PROC
    cmp     al, 03h
    je      @@continue
        call    OPCODE_04h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_add
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_03h ENDP

OPCODE_04h PROC
    cmp     al, 04h
    je      @@continue
        call    OPCODE_05h
        ret
    
    @@continue:
    push    si
    lea     si, ins_add
    call    loadTextToBuffer

    lea     si, reg_al
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_04h ENDP

OPCODE_05h PROC
    cmp     al, 05h
    je      @@continue
        call    OPCODE_06h
        ret
    
    @@continue:
    push    si
    lea     si, ins_add
    call    loadTextToBuffer

    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_05h ENDP

OPCODE_06h PROC
    cmp     al, 06h
    je      @@continue
        call    OPCODE_07h
        ret
    
    @@continue:
    push    si

    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_es
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_06h ENDP

OPCODE_07h PROC
    cmp     al, 07h
    je      @@continue
        call    OPCODE_08h
        ret
    
    @@continue:
    push    si

    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_es
    call    loadTextToBuffer
    
    @@done:
    pop     si
    ret
OPCODE_07h ENDP

OPCODE_08h PROC
    cmp     al, 08h
    je      @@continue
        call    OPCODE_09h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_or
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_08h ENDP

OPCODE_09h PROC
    cmp     al, 09h
    je      @@continue
        call    OPCODE_0ah
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_or
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_09h ENDP

OPCODE_0ah PROC
    cmp     al, 0ah
    je      @@continue
        call    OPCODE_0bh
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_or
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_0ah ENDP

OPCODE_0bh PROC
    cmp     al, 0bh
    je      @@continue
        call    OPCODE_0ch
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_or
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_0bh ENDP

OPCODE_0ch PROC
    cmp     al, 0ch
    je      @@continue
        call    OPCODE_0dh
        ret
    
    @@continue:
    push    si
    lea     si, ins_or
    call    loadTextToBuffer

    lea     si, reg_al
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_0ch ENDP

OPCODE_0dh PROC
    cmp     al, 0dh
    je      @@continue
        call    OPCODE_0eh
        ret
    
    @@continue:
    push    si
    lea     si, ins_or
    call    loadTextToBuffer

    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_0dh ENDP

OPCODE_0eh PROC
    cmp     al, 0eh
    je      @@continue
        call    OPCODE_0fh
        ret
    
    @@continue:
    push    si

    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_cs
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_0eh ENDP

OPCODE_0fh PROC
    cmp     al, 0fh
    je      @@continue
        call    OPCODE_10h
        ret
    
    @@continue:
    push    si

    call loadNewline
    lea si, ins_unknown
    call loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_0fh ENDP

OPCODE_10h PROC
    cmp     al, 10h
    je      @@continue
        call    OPCODE_11h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_adc
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_10h ENDP

OPCODE_11h PROC
    cmp     al, 11h
    je      @@continue
        call    OPCODE_12h
        ret

    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_adc
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_11h ENDP

OPCODE_12h PROC
    cmp     al, 12h
    je      @@continue
        call    OPCODE_13h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_adc
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_12h ENDP

OPCODE_13h PROC
    cmp     al, 13h
    je      @@continue
        call    OPCODE_14h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_adc
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_13h ENDP

OPCODE_14h PROC
    cmp     al, 14h
    je      @@continue
        call    OPCODE_15h
        ret
    
    @@continue:
    push    si
    lea     si, ins_adc
    call    loadTextToBuffer

    lea     si, reg_al
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_14h ENDP

OPCODE_15h PROC
    cmp     al, 15h
    je      @@continue
        call    OPCODE_16h
        ret
    
    @@continue:
    push    si
    lea     si, ins_adc
    call    loadTextToBuffer

    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_15h ENDP

OPCODE_16h PROC
    cmp     al, 16h
    je      @@continue
        call    OPCODE_17h
        ret
    
    @@continue:
    push    si

    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_ss
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_16h ENDP

OPCODE_17h PROC
    cmp     al, 17h
    je      @@continue
        call    OPCODE_18h
        ret
    
    @@continue:
    push    si

    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_ss
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_17h ENDP

OPCODE_18h PROC
    cmp     al, 18h
    je      @@continue
        call    OPCODE_19h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_sbb
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_18h ENDP

OPCODE_19h PROC
    cmp     al, 19h
    je      @@continue
        call    OPCODE_1ah
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_sbb
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_19h ENDP

OPCODE_1ah PROC
    cmp     al, 1ah
    je      @@continue
        call    OPCODE_1bh
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_sbb
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_1ah ENDP

OPCODE_1bh PROC
    cmp     al, 1bh
    je      @@continue
        call    OPCODE_1ch
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_sbb
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_1bh ENDP

OPCODE_1ch PROC
    cmp     al, 1ch
    je      @@continue
        call    OPCODE_1dh
        ret
    
    @@continue:
    push    si
    lea     si, ins_sbb
    call    loadTextToBuffer

    lea     si, reg_al
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_1ch ENDP

OPCODE_1dh PROC
    cmp     al, 1dh
    je      @@continue
        call    OPCODE_1eh
        ret
    
    @@continue:
    push    si
    lea     si, ins_sbb
    call    loadTextToBuffer

    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_1dh ENDP

OPCODE_1eh PROC
    cmp     al, 1eh
    je      @@continue
        call    OPCODE_1fh
        ret
    
    @@continue:
    push    si

    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_ds
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_1eh ENDP

OPCODE_1fh PROC
    cmp     al, 1fh
    je      @@continue
        call    OPCODE_20h
        ret
    
    @@continue:
    push    si

    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_ds
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_1fh ENDP

OPCODE_20h PROC
    cmp     al, 20h
    je      @@continue
        call    OPCODE_21h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_and
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_20h ENDP

OPCODE_21h PROC
    cmp     al, 21h
    je      @@continue
        call    OPCODE_22h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_and
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_21h ENDP

OPCODE_22h PROC
    cmp     al, 22h
    je      @@continue
        call    OPCODE_23h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_and
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_22h ENDP

OPCODE_23h PROC
    cmp     al, 23h
    je      @@continue
        call    OPCODE_24h
        ret
    
    @@continue:
    push    ax
    push    bx

    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_and
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_23h ENDP

OPCODE_24h PROC
    cmp     al, 24h
    je      @@continue
        call    OPCODE_25h
        ret
    
    @@continue:
    push    si
    lea     si, ins_and
    call    loadTextToBuffer

    lea     si, reg_al
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_24h ENDP

OPCODE_25h PROC
    cmp     al, 25h
    je      @@continue
        call    OPCODE_26h
        ret
    
    @@continue:
    push    si
    lea     si, ins_and
    call    loadTextToBuffer

    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_25h ENDP

OPCODE_26h PROC
    cmp     al, 26h
    je      @@continue
        call    OPCODE_27h
        ret
    
    @@continue:
    mov     byte ptr prefix, al

    @@done:
    ret
OPCODE_26h ENDP

OPCODE_27h PROC
    cmp     al, 27h
    je      @@continue
        call    OPCODE_28h
        ret
    
    @@continue:
    push    si
    lea     si, ins_daa
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_27h ENDP

OPCODE_28h PROC
    cmp     al, 28h
    je      @@continue
        call    OPCODE_29h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_sub
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_28h ENDP

OPCODE_29h PROC
    cmp     al, 29h
    je      @@continue
        call    OPCODE_2ah
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_sub
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_29h ENDP

OPCODE_2ah PROC
    cmp     al, 2ah
    je      @@continue
        call    OPCODE_2bh
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_sub
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_2ah ENDP

OPCODE_2bh PROC
    cmp     al, 2bh
    je      @@continue
        call    OPCODE_2ch
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_sub
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    pop     bx
    pop     ax
    ret
OPCODE_2bh ENDP

OPCODE_2ch PROC
    cmp     bl, 2ch
    je      @@continue
        call    OPCODE_2dh
        ret
    
    @@continue:
    push    si
    lea     si, ins_sub
    call    loadTextToBuffer

    lea     si, reg_al
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_2ch ENDP

OPCODE_2dh PROC
    cmp     al, 2dh
    je      @@continue
        call    OPCODE_2eh
        ret
    
    @@continue:
    push    si
    lea     si, ins_sub
    call    loadTextToBuffer

    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_2dh ENDP

OPCODE_2eh PROC
    cmp     al, 2eh
    je      @@continue
        call    OPCODE_2fh
        ret
    
    @@continue:
    mov     byte ptr prefix, al

    @@done:
    ret
OPCODE_2eh ENDP

OPCODE_2fh PROC
    cmp     al, 2fh
    je      @@continue
        call    OPCODE_30h
        ret
    
    @@continue:
    push    si
    lea     si, ins_das
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_2fh ENDP

OPCODE_30h PROC
    cmp     al, 30h
    je      @@continue
        call    OPCODE_31h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_xor
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_30h ENDP

OPCODE_31h PROC
    cmp     al, 31h
    je      @@continue
        call    OPCODE_32h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_add
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_31h ENDP

OPCODE_32h PROC
    cmp     al, 32h
    je      @@continue
        call    OPCODE_33h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_xor
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_32h ENDP

OPCODE_33h PROC
    cmp     al, 33h
    je      @@continue
        call    OPCODE_34h
        ret
    
    @@continue:

    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_xor
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_33h ENDP

OPCODE_34h PROC
    cmp     al, 34h
    je      @@continue
        call    OPCODE_35h
        ret
    
    @@continue:
    push    si
    lea     si, ins_xor
    call    loadTextToBuffer

    lea     si, reg_al
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_34h ENDP

OPCODE_35h PROC
    cmp     al, 35h
    je      @@continue
        call    OPCODE_36h
        ret
    
    @@continue:
    push    si
    lea     si, ins_xor
    call    loadTextToBuffer

    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_35h ENDP

OPCODE_36h PROC
    cmp     al, 36h
    je      @@continue
        call    OPCODE_37h
        ret
    
    @@continue:
    mov     byte ptr prefix, al

    @@done:
    ret
OPCODE_36h ENDP

OPCODE_37h PROC
    cmp     al, 37h
    je      @@continue
        call    OPCODE_38h
        ret
    
    @@continue:
    push    si
    lea     si, ins_aaa
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_37h ENDP

OPCODE_38h PROC
    cmp     al, 38h
    je      @@continue
        call    OPCODE_39h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_cmp
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_38h ENDP

OPCODE_39h PROC
    cmp     al, 39h
    je      @@continue
        call    OPCODE_3ah
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_cmp
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_39h ENDP

OPCODE_3ah PROC
    cmp     al, 3ah
    je      @@continue
        call    OPCODE_3bh
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_cmp
    call    loadTextToBuffer
    pop     si
    mov     dl, 0h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_3ah ENDP

OPCODE_3bh PROC
    cmp     al, 3bh
    je      @@continue
        call    OPCODE_3ch
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    ;;test
    call loadComment
    mov dl, byte ptr opcodeMod
    call printByte
    mov dl, byte ptr opcodeReg
    call printByte
    mov dl, byte ptr opcodeRM
    call printByte
    call loadNewline
    ;;end
    push    si
    lea     si, ins_cmp
    call    loadTextToBuffer
    pop     si
    mov     dl, 1h
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_3bh ENDP

OPCODE_3ch PROC
    cmp     al, 3ch
    je      @@continue
        call    OPCODE_3dh
        ret
    
    @@continue:
    push    si
    lea     si, ins_cmp
    call    loadTextToBuffer

    lea     si, reg_al
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_3ch ENDP

OPCODE_3dh PROC
    cmp     al, 3dh
    je      @@continue
        call    OPCODE_3eh
        ret
    
    @@continue:
    push    si
    lea     si, ins_cmp
    call    loadTextToBuffer

    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    pop     si

    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_3dh ENDP

OPCODE_3eh PROC
    cmp     al, 3eh
    je      @@continue
        call    OPCODE_3fh
        ret
    
    @@continue:
    mov     byte ptr prefix, al

    @@done:
    ret
OPCODE_3eh ENDP

OPCODE_3fh PROC
    cmp     al, 3fh
    je      @@continue
        call    OPCODE_40h
        ret
    
    @@continue:
    push    si
    lea     si, ins_aas
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_3fh ENDP

OPCODE_40h PROC
    cmp     al, 40h
    je      @@continue
        call    OPCODE_41h
        ret
    
    @@continue:
    push    si
    lea     si, ins_inc
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_40h ENDP

OPCODE_41h PROC
    cmp     al, 41h
    je      @@continue
        call    OPCODE_42h
        ret
    
    @@continue:
    push    si
    lea     si, ins_inc
    call    loadTextToBuffer
    lea     si, reg_cx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_41h ENDP

OPCODE_42h PROC
    cmp     al, 42h
    je      @@continue
        call    OPCODE_43h
        ret
    
    @@continue:
    push    si
    lea     si, ins_inc
    call    loadTextToBuffer
    lea     si, reg_dx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_42h ENDP

OPCODE_43h PROC
    cmp     al, 43h
    je      @@continue
        call    OPCODE_44h
        ret
    
    @@continue:
    push    si
    lea     si, ins_inc
    call    loadTextToBuffer
    lea     si, reg_bx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_43h ENDP

OPCODE_44h PROC
    cmp     al, 44h
    je      @@continue
        call    OPCODE_45h
        ret
    
    @@continue:
    push    si
    lea     si, ins_inc
    call    loadTextToBuffer
    lea     si, reg_sp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_44h ENDP

OPCODE_45h PROC
    cmp     al, 45h
    je      @@continue
        call    OPCODE_46h
        ret
    
    @@continue:
    push    si
    lea     si, ins_inc
    call    loadTextToBuffer
    lea     si, reg_bp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_45h ENDP

OPCODE_46h PROC
    cmp     al, 46h
    je      @@continue
        call    OPCODE_47h
        ret
    
    @@continue:
    push    si
    lea     si, ins_inc
    call    loadTextToBuffer
    lea     si, reg_si
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_46h ENDP

OPCODE_47h PROC
    cmp     al, 47h
    je      @@continue
        call    OPCODE_48h
        ret
    
    @@continue:
    push    si
    lea     si, ins_inc
    call    loadTextToBuffer
    lea     si, reg_di
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_47h ENDP

OPCODE_48h PROC
    cmp     al, 48h
    je      @@continue
        call    OPCODE_49h
        ret
    
    @@continue:
    push    si
    lea     si, ins_dec
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_48h ENDP

OPCODE_49h PROC
    cmp     al, 49h
    je      @@continue
        call    OPCODE_4ah
        ret
    
    @@continue:
    push    si
    lea     si, ins_dec
    call    loadTextToBuffer
    lea     si, reg_cx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_49h ENDP

OPCODE_4ah PROC
    cmp     al, 4ah
    je      @@continue
        call    OPCODE_4bh
        ret
    
    @@continue:
    push    si
    lea     si, ins_dec
    call    loadTextToBuffer
    lea     si, reg_dx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_4ah ENDP

OPCODE_4bh PROC
    cmp     al, 4bh
    je      @@continue
        call    OPCODE_4ch
        ret
    
    @@continue:
    push    si
    lea     si, ins_dec
    call    loadTextToBuffer
    lea     si, reg_bx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_4bh ENDP

OPCODE_4ch PROC
    cmp     al, 4ch
    je      @@continue
        call    OPCODE_4dh
        ret
    
    @@continue:
    push    si
    lea     si, ins_dec
    call    loadTextToBuffer
    lea     si, reg_sp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_4ch ENDP

OPCODE_4dh PROC
    cmp     al, 4dh
    je      @@continue
        call    OPCODE_4eh
        ret
    
    @@continue:
    push    si
    lea     si, ins_dec
    call    loadTextToBuffer
    lea     si, reg_bp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_4dh ENDP

OPCODE_4eh PROC
    cmp     al, 4eh
    je      @@continue
        call    OPCODE_4fh
        ret
    
    @@continue:
    push    si
    lea     si, ins_dec
    call    loadTextToBuffer
    lea     si, reg_si
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_4eh ENDP

OPCODE_4fh PROC
    cmp     al, 4fh
    je      @@continue
        call    OPCODE_50h
        ret
    
    @@continue:
    push    si
    lea     si, ins_dec
    call    loadTextToBuffer
    lea     si, reg_di
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_4fh ENDP

OPCODE_50h PROC
    cmp     al, 50h
    je      @@continue
        call    OPCODE_51h
        ret
    
    @@continue:
    push    si
    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_50h ENDP

OPCODE_51h PROC
    cmp     al, 51h
    je      @@continue
        call    OPCODE_52h
        ret
    
    @@continue:
    push    si
    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_cx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_51h ENDP

OPCODE_52h PROC
    cmp     al, 52h
    je      @@continue
        call    OPCODE_53h
        ret
    
    @@continue:
    push    si
    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_dx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_52h ENDP

OPCODE_53h PROC
    cmp     al, 53h
    je      @@continue
        call    OPCODE_54h
        ret
    
    @@continue:
    push    si
    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_bx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_53h ENDP

OPCODE_54h PROC
    cmp     al, 54h
    je      @@continue
        call    OPCODE_55h
        ret
    
    @@continue:
    push    si
    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_sp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_54h ENDP

OPCODE_55h PROC
    cmp     al, 55h
    je      @@continue
        call    OPCODE_56h
        ret
    
    @@continue:
    push    si
    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_bp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_55h ENDP

OPCODE_56h PROC
    cmp     al, 56h
    je      @@continue
        call    OPCODE_57h
        ret
    
    @@continue:
    push    si
    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_si
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_56h ENDP

OPCODE_57h PROC
    cmp     al, 57h
    je      @@continue
        call    OPCODE_58h
        ret
    
    @@continue:
    push    si
    lea     si, ins_push
    call    loadTextToBuffer
    lea     si, reg_di
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_57h ENDP

OPCODE_58h PROC
    cmp     al, 58h
    je      @@continue
        call    OPCODE_59h
        ret
    
    @@continue:
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_58h ENDP

OPCODE_59h PROC
    cmp     al, 59h
    je      @@continue
        call    OPCODE_5ah
        ret
    
    @@continue:
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_cx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_59h ENDP

OPCODE_5ah PROC
    cmp     al, 5ah
    je      @@continue
        call    OPCODE_5bh
        ret
    
    @@continue:
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_dx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_5ah ENDP

OPCODE_5bh PROC
    cmp     al, 5bh
    je      @@continue
        call    OPCODE_5ch
        ret
    
    @@continue:
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_bx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_5bh ENDP

OPCODE_5ch PROC
    cmp     al, 5ch
    je      @@continue
        call    OPCODE_5dh
        ret
    
    @@continue:
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_sp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_5ch ENDP

OPCODE_5dh PROC
    cmp     al, 5dh
    je      @@continue
        call    OPCODE_5eh
        ret
    
    @@continue:
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_bp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_5dh ENDP

OPCODE_5eh PROC
    cmp     al, 5eh
    je      @@continue
        call    OPCODE_5fh
        ret
    
    @@continue:
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_si
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_5eh ENDP

OPCODE_5fh PROC
    cmp     al, 5fh
    je      @@continue
        call    OPCODE_60h
        ret
    
    @@continue:
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    lea     si, reg_di
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_5fh ENDP

OPCODE_60h PROC
    cmp     al, 60h
    je      @@continue
        call    OPCODE_61h
        ret
    
    @@continue:
    push    si
    lea     si, ins_pusha
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_60h ENDP

OPCODE_61h PROC
    cmp     al, 61h
    je      @@continue
        call    OPCODE_62h
        ret
    
    @@continue:
    push    si
    lea     si, ins_popa
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_61h ENDP

OPCODE_62h PROC
    cmp     al, 62h
    je      @@continue
        call    OPCODE_63h
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_62h ENDP

OPCODE_63h PROC
    cmp     al, 63h
    je      @@continue
        call    OPCODE_64h
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_63h ENDP

OPCODE_64h PROC
    cmp     al, 64h
    je      @@continue
        call    OPCODE_65h
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_64h ENDP

OPCODE_65h PROC
    cmp     al, 65h
    je      @@continue
        call    OPCODE_66h
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_65h ENDP

OPCODE_66h PROC
    cmp     al, 66h
    je      @@continue
        call    OPCODE_67h
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_66h ENDP

OPCODE_67h PROC
    cmp     al, 67h
    je      @@continue
        call    OPCODE_68h
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_67h ENDP

OPCODE_68h PROC
    cmp     al, 68h
    je      @@continue
        call    OPCODE_69h
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_68h ENDP

OPCODE_69h PROC
    cmp     al, 69h
    je      @@continue
        call    OPCODE_6ah
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_69h ENDP

OPCODE_6ah PROC
    cmp     al, 6ah
    je      @@continue
        call    OPCODE_6bh
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_6ah ENDP

OPCODE_6bh PROC
    cmp     al, 6bh
    je      @@continue
        call    OPCODE_6ch
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_6bh ENDP

OPCODE_6ch PROC
    cmp     al, 6ch
    je      @@continue
        call    OPCODE_6dh
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_6ch ENDP

OPCODE_6dh PROC
    cmp     al, 6dh
    je      @@continue
        call    OPCODE_6eh
        ret
    
    @@continue:
    push    si
    call    loadNewline
    lea     si, ins_unknown
    call    loadTextToBuffer

    @@done:
    pop     si
    ret
OPCODE_6dh ENDP

OPCODE_6eh PROC
    cmp     al, 6eh
    je      @@continue
        call    OPCODE_6fh
        ret
    
    @@continue:
    push    si
    lea     si, ins_outsb
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_6eh ENDP

OPCODE_6fh PROC
    cmp     al, 6fh
    je      @@continue
        call    OPCODE_70h
        ret
    
    @@continue:
    push    si
    lea     si, ins_outsw
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_6fh ENDP

OPCODE_70h PROC
    cmp     al, 70h
    je      @@continue
        call    OPCODE_71h
        ret
    
    @@continue:
    push    si
    lea     si, ins_jo
    call    loadTextToBuffer
    pop     si

    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_70h ENDP

OPCODE_71h PROC
    cmp     al, 71h
    je      @@continue
        call    OPCODE_72h
        ret
    
    @@continue:
    push    si
    lea     si, ins_jno
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_71h ENDP

OPCODE_72h PROC
    cmp     al, 72h
    je      @@continue
        call    OPCODE_73h
        ret
    
    @@continue:
    push    si
    lea     si, ins_jb
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_72h ENDP

OPCODE_73h PROC
    cmp     al, 73h
    je      @@continue
        call    OPCODE_74h
        ret
    
    @@continue:
    push    si
    lea     si, ins_jae
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_73h ENDP

OPCODE_74h PROC
    cmp     al, 74h
    je      @@continue
        call    OPCODE_75h
        ret
    
    @@continue:
    push    si
    lea     si, ins_je
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_74h ENDP

OPCODE_75h PROC
    cmp     al, 75h
    je      @@continue
        call    OPCODE_76h
        ret
    
    @@continue:
    push    si
    lea     si, ins_jne
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_75h ENDP

OPCODE_76h PROC
    cmp     al, 76h
    je      @@continue
        call    OPCODE_77h
        ret
    
    @@continue:
    push    si
    lea     si, ins_jbe
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_76h ENDP

OPCODE_77h PROC
    cmp     al, 77h
    je      @@continue
        call    OPCODE_78h
        ret
    
    @@continue:
    push    si
    lea     si, ins_ja
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_77h ENDP

OPCODE_78h PROC
    cmp     al, 78h
    je      @@continue
        call    OPCODE_79h
        ret
    
    @@continue:
    push    si
    lea     si, ins_js
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_78h ENDP

OPCODE_79h PROC
    cmp     al, 79h
    je      @@continue
        call    OPCODE_7ah
        ret
    
    @@continue:
    push    si
    lea     si, ins_jns
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_79h ENDP

OPCODE_7ah PROC
    cmp     al, 7ah
    je      @@continue
        call    OPCODE_7bh
        ret
    
    @@continue:
    push    si
    lea     si, ins_jp
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_7ah ENDP

OPCODE_7bh PROC
    cmp     al, 7bh
    je      @@continue
        call    OPCODE_7ch
        ret
    
    @@continue:
    push    si
    lea     si, ins_jnp
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_7bh ENDP

OPCODE_7ch PROC
    cmp     al, 7ch
    je      @@continue
        call    OPCODE_7dh
        ret
    
    @@continue:
    push    si
    lea     si, ins_jl
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_7ch ENDP

OPCODE_7dh PROC
    cmp     al, 7dh
    je      @@continue
        call    OPCODE_7eh
        ret
    
    @@continue:
    push    si
    lea     si, ins_jge
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_7dh ENDP

OPCODE_7eh PROC
    cmp     al, 7eh
    je      @@continue
        call    OPCODE_7fh
        ret
    
    @@continue:
    push    si
    lea     si, ins_jle
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_7eh ENDP

OPCODE_7fh PROC
    cmp     al, 7fh
    je      @@continue
        call    OPCODE_80h
        ret
    
    @@continue:
    push    si
    lea     si, ins_jg
    call    loadTextToBuffer
    pop     si
    
    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_7fh ENDP

OPCODE_80h PROC
    cmp     al, 80h
    je      @@continue
        call    OPCODE_81h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_add
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 0
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_80h ENDP

OPCODE_81h PROC
    cmp     al, 81h
    je      @@continue
        call    OPCODE_82h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_add
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 1
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_81h ENDP

OPCODE_82h PROC
    cmp     al, 82h
    je      @@continue
        call    OPCODE_83h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_add
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 0
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_82h ENDP

OPCODE_83h PROC
    cmp     al, 83h
    je      @@continue
        call    OPCODE_84h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_add
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 1
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    getByte
    cbw
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_83h ENDP

OPCODE_84h PROC
    cmp     al, 84h
    je      @@continue
        call    OPCODE_85h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_test
    call    loadTextToBuffer
    pop     si

    mov     dl, 0
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_84h ENDP

OPCODE_85h PROC
    cmp     al, 85h
    je      @@continue
        call    OPCODE_86h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_test
    call    loadTextToBuffer
    pop     si

    mov     dl, 1
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_85h ENDP

OPCODE_86h PROC
    cmp     al, 86h
    je      @@continue
        call    OPCODE_87h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    pop     si

    mov     dl, 0
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_86h ENDP

OPCODE_87h PROC
    cmp     al, 87h
    je      @@continue
        call    OPCODE_88h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    pop     si

    mov     dl, 1
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM
    
    @@done:
    ret
OPCODE_87h ENDP

OPCODE_88h PROC
    cmp     al, 88h
    je      @@continue
        call    OPCODE_89h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    pop     si

    mov     dl, 0
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadReg

    @@done:
    ret
OPCODE_88h ENDP

OPCODE_89h PROC
    cmp     al, 89h
    je      @@continue
        call    OPCODE_8ah
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    pop     si

    mov     dl, 1
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_89h ENDP

OPCODE_8ah PROC
    cmp     al, 8ah
    je      @@continue
        call    OPCODE_8bh
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    pop     si

    mov     dl, 0
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_8ah ENDP

OPCODE_8bh PROC
    cmp     al, 8bh
    je      @@continue
        call    OPCODE_8ch
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    pop     si

    mov     dl, 1
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_8bh ENDP

OPCODE_8ch PROC
    cmp     al, 8ch
    je      @@continue
        call    OPCODE_8dh
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer

    mov     bl, al
    shl     bl, 3
    shr     bl, 6
    shl     bl, 2

    mov     dl, 1
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    lea     si, reg_es
    add     si, bx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_8ch ENDP

OPCODE_8dh PROC
    cmp     al, 8dh
    je      @@continue
        call    OPCODE_8eh
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_lea
    call    loadTextToBuffer
    pop     si

    mov     dl, 1
    call    loadReg
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_8dh ENDP

OPCODE_8eh PROC
    cmp     al, 8eh
    je      @@continue
        call    OPCODE_8fh
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer

    mov     bl, al
    shl     bl, 3
    shr     bl, 6
    shl     bl, 2

    mov     dl, 1
    lea     si, reg_es
    add     si, bx
    call    loadTextToBuffer
    pop     si
    call    loadCommaSpace
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_8eh ENDP

OPCODE_8fh PROC
    cmp     al, 8fh
    je      @@continue
        call    OPCODE_90h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    push    si
    lea     si, ins_pop
    call    loadTextToBuffer
    pop     si

    mov     dl, 1
    mov     bl, 1
    call    loadModRM

    @@done:
    ret
OPCODE_8fh ENDP

OPCODE_90h PROC
    cmp     al, 90h
    je      @@continue
        call    OPCODE_91h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_nop
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_90h ENDP

OPCODE_91h PROC
    cmp     al, 91h
    je      @@continue
        call    OPCODE_92h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    lea     si, reg_cx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_91h ENDP

OPCODE_92h PROC
    cmp     al, 92h
    je      @@continue
        call    OPCODE_93h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    lea     si, reg_dx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_92h ENDP

OPCODE_93h PROC
    cmp     al, 93h
    je      @@continue
        call    OPCODE_94h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    lea     si, reg_bx
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_93h ENDP

OPCODE_94h PROC
    cmp     al, 94h
    je      @@continue
        call    OPCODE_95h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    lea     si, reg_sp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_94h ENDP

OPCODE_95h PROC
    cmp     al, 95h
    je      @@continue
        call    OPCODE_96h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    lea     si, reg_bp
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_95h ENDP

OPCODE_96h PROC
    cmp     al, 96h
    je      @@continue
        call    OPCODE_97h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    lea     si, reg_si
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_96h ENDP

OPCODE_97h PROC
    cmp     al, 97h
    je      @@continue
        call    OPCODE_98h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_xchg
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    call    loadCommaSpace
    lea     si, reg_di
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_97h ENDP

OPCODE_98h PROC
    cmp     al, 98h
    je      @@continue
        call    OPCODE_99h
        ret
    
    @@continue:    
    push    si
    lea     si, ins_cbw
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_98h ENDP

OPCODE_99h PROC
    cmp     al, 99h
    je      @@continue
        call    OPCODE_9ah
        ret
    
    @@continue:
    push    si
    lea     si, ins_cwd
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_99h ENDP

OPCODE_9ah PROC
    cmp     al, 9ah
    je      @@continue
        call    OPCODE_9bh
        ret
    
    @@continue:
    push    si
    call    loadComment
    lea     si, ins_call
    call    loadTextToBuffer
    call    loadNewline
    call    loadTextToBuffer
    call    getWord
    push    ax
    call    getWord
    lea     si, ins_push
    call    loadTextToBuffer
    call    printWord
    pop     ax
    call    loadTextToBuffer
    call    printWord
    lea     si, ins_retf
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_9ah ENDP

OPCODE_9bh PROC
    cmp     al, 9bh
    je      @@continue
        call    OPCODE_9ch
        ret
    
    @@continue:
    push    si
    lea     si, ins_wait
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_9bh ENDP

OPCODE_9ch PROC
    cmp     al, 9ch
    je      @@continue
        call    OPCODE_9dh
        ret
    
    @@continue:
    push    si
    lea     si, ins_pushf
    call    loadTextToBuffer
    pop     si
    
    @@done:
    ret
OPCODE_9ch ENDP

OPCODE_9dh PROC
    cmp     al, 9dh
    je      @@continue
        call    OPCODE_9eh
        ret
    
    @@continue:
    push    si
    lea     si, ins_popf
    call    loadTextToBuffer
    pop     si
    
    @@done:
    ret
OPCODE_9dh ENDP

OPCODE_9eh PROC
    cmp     al, 9eh
    je      @@continue
        call    OPCODE_9fh
        ret
    
    @@continue:
    push    si
    lea     si, ins_sahf
    call    loadTextToBuffer
    pop     si
    
    @@done:
    ret
OPCODE_9eh ENDP

OPCODE_9fh PROC
    cmp     al, 9fh
    je      @@continue
        call    OPCODE_a0h
        ret
    
    @@continue:
    push    si
    lea     si, ins_lahf
    call    loadTextToBuffer
    pop     si
    
    @@done:
    ret
OPCODE_9fh ENDP

OPCODE_a0h PROC
    cmp     al, 0a0h
    je      @@continue
        call    OPCODE_a1h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_al
    call    loadTextToBuffer
    pop     si

    mov     dl, 0
    call    loadCommaSpace
    call    loadPtr
    call    loadTagStart
    call    getWord
    call    printWord
    call    loadTagClose

    @@done:
    ret
OPCODE_a0h ENDP

OPCODE_a1h PROC
    cmp     al, 0a1h
    je      @@continue
        call    OPCODE_a2h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    mov     dl, 1
    call    loadCommaSpace
    call    loadPtr
    call    loadTagStart
    call    getWord
    call    printWord
    call    loadTagClose

    @@done:
    ret
OPCODE_a1h ENDP

OPCODE_a2h PROC
    cmp     al, 0a2h
    je      @@continue
        call    OPCODE_a3h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    pop     si

    mov     dl, 0
    call    loadPtr
    call    loadTagStart
    call    getWord
    call    printWord
    call    loadTagClose
    call    loadCommaSpace
    push    si
    lea     si, reg_al
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_a2h ENDP

OPCODE_a3h PROC
    cmp     al, 0a3h
    je      @@continue
        call    OPCODE_a4h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    pop     si

    mov     dl, 1
    call    loadPtr
    call    loadTagStart
    call    getWord
    call    printWord
    call    loadTagClose
    call    loadCommaSpace
    push    si
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_a3h ENDP

OPCODE_a4h PROC
    cmp     al, 0a4h
    je      @@continue
        call    OPCODE_a5h
        ret
    
    @@continue:
    push    si
    lea     si, ins_movsb
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_a4h ENDP

OPCODE_a5h PROC
    cmp     al, 0a5h
    je      @@continue
        call    OPCODE_a6h
        ret
    
    @@continue:
    push    si
    lea     si, ins_movsw
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_a5h ENDP

OPCODE_a6h PROC
    cmp     al, 0a6h
    je      @@continue
        call    OPCODE_a7h
        ret
    
    @@continue:
    push    si
    lea     si, ins_cmpsb
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_a6h ENDP

OPCODE_a7h PROC
    cmp     al, 0a7h
    je      @@continue
        call    OPCODE_a8h
        ret
    
    @@continue:
    push    si
    lea     si, ins_cmpsw
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_a7h ENDP

OPCODE_a8h PROC
    cmp     al, 0a8h
    je      @@continue
        call    OPCODE_a9h
        ret
    
    @@continue:
    push    si
    lea     si, ins_test
    call    loadTextToBuffer
    lea     si, reg_al
    call    loadTextToBuffer
    pop     si
    
    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_a8h ENDP

OPCODE_a9h PROC
    cmp     al, 0a9h
    je      @@continue
        call    OPCODE_aah
        ret
    
    @@continue:
    push    si
    lea     si, ins_test
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si
    
    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_a9h ENDP

OPCODE_aah PROC
    cmp     al, 0aah
    je      @@continue
        call    OPCODE_abh
        ret
    
    @@continue:
    push    si
    lea     si, ins_stosb
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_aah ENDP

OPCODE_abh PROC
    cmp     al, 0abh
    je      @@continue
        call    OPCODE_ach
        ret
    
    @@continue:
    push    si
    lea     si, ins_stosw
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_abh ENDP

OPCODE_ach PROC
    cmp     al, 0ach
    je      @@continue
        call    OPCODE_adh
        ret
    
    @@continue:
    push    si
    lea     si, ins_lodsb
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_ach ENDP

OPCODE_adh PROC
    cmp     al, 0adh
    je      @@continue
        call    OPCODE_aeh
        ret
    
    @@continue:
    push    si
    lea     si, ins_lodsw
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_adh ENDP

OPCODE_aeh PROC
    cmp     al, 0aeh
    je      @@continue
        call    OPCODE_afh
        ret
    
    @@continue:
    push    si
    lea     si, ins_scasb
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_aeh ENDP

OPCODE_afh PROC
    cmp     al, 0afh
    je      @@continue
        call    OPCODE_b0h
        ret
    
    @@continue:
    push    si
    lea     si, ins_scasw
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_afh ENDP

OPCODE_b0h PROC
    cmp     al, 0b0h
    je      @@continue
        call    OPCODE_b1h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_al
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_b0h ENDP

OPCODE_b1h PROC
    cmp     al, 0b1h
    je      @@continue
        call    OPCODE_b2h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_cl
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_b1h ENDP

OPCODE_b2h PROC
    cmp     al, 0b2h
    je      @@continue
        call    OPCODE_b3h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_dl
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_b2h ENDP

OPCODE_b3h PROC
    cmp     al, 0b3h
    je      @@continue
        call    OPCODE_b4h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_bl
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_b3h ENDP

OPCODE_b4h PROC
    cmp     al, 0b4h
    je      @@continue
        call    OPCODE_b5h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_ah
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_b4h ENDP

OPCODE_b5h PROC
    cmp     al, 0b5h
    je      @@continue
        call    OPCODE_b6h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_ch
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_b5h ENDP

OPCODE_b6h PROC
    cmp     al, 0b6h
    je      @@continue
        call    OPCODE_b7h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_dh
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_b6h ENDP

OPCODE_b7h PROC
    cmp     al, 0b7h
    je      @@continue
        call    OPCODE_b8h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_bh
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_b7h ENDP

OPCODE_b8h PROC
    cmp     al, 0b8h
    je      @@continue
        call    OPCODE_b9h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_b8h ENDP

OPCODE_b9h PROC
    cmp     al, 0b9h
    je      @@continue
        call    OPCODE_bah
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_cx
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_b9h ENDP

OPCODE_bah PROC
    cmp     al, 0bah
    je      @@continue
        call    OPCODE_bbh
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_dx
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_bah ENDP

OPCODE_bbh PROC
    cmp     al, 0bbh
    je      @@continue
        call    OPCODE_bch
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_bx
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_bbh ENDP

OPCODE_bch PROC
    cmp     al, 0bch
    je      @@continue
        call    OPCODE_bdh
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_sp
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_bch ENDP

OPCODE_bdh PROC
    cmp     al, 0bdh
    je      @@continue
        call    OPCODE_beh
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_bp
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_bdh ENDP

OPCODE_beh PROC
    cmp     al, 0beh
    je      @@continue
        call    OPCODE_bfh
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_si
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_beh ENDP

OPCODE_bfh PROC
    cmp     al, 0bfh
    je      @@continue
        call    OPCODE_c0h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    lea     si, reg_di
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_bfh ENDP

OPCODE_c0h PROC
    cmp     al, 0c0h
    je      @@continue
        call    OPCODE_c1h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_rol
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 0
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_c0h ENDP

OPCODE_c1h PROC
    cmp     al, 0c1h
    je      @@continue
        call    OPCODE_c2h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_rol
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 1
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_c1h ENDP

OPCODE_c2h PROC
    cmp     al, 0c2h
    je      @@continue
        call    OPCODE_c3h
        ret
    
    @@continue:
    push    si
    lea     si, ins_ret
    call    loadTextToBuffer
    pop     si
    
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_c2h ENDP

OPCODE_c3h PROC
    cmp     al, 0c3h
    je      @@continue
        call    OPCODE_c4h
        ret
    
    @@continue:
    push    si
    lea     si, ins_ret
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_c3h ENDP

OPCODE_c4h PROC
    cmp     al, 0c4h
    je      @@continue
        call    OPCODE_c5h
        ret
    
    @@continue:
    push    si
    lea     si, ins_les
    call    loadTextToBuffer
    pop     si

    call    getByte
    call    getModRegRM

    mov     dl, 1
    call    loadReg
    call    loadCommaSpace
    mov     bl, 0
    call    loadModRM

    @@done:
    ret
OPCODE_c4h ENDP

OPCODE_c5h PROC
    cmp     al, 0c5h
    je      @@continue
        call    OPCODE_c6h
        ret
    
    @@continue:
    push    si
    lea     si, ins_lds
    call    loadTextToBuffer
    pop     si

    call    getByte
    call    getModRegRM

    mov     dl, 1
    call    loadReg
    call    loadCommaSpace
    mov     bl, 0
    call    loadModRM

    @@done:
    ret
OPCODE_c5h ENDP

OPCODE_c6h PROC
    cmp     al, 0c6h
    je      @@continue
        call    OPCODE_c7h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    pop     si

    call    getByte
    call    getModRegRM

    mov     dl, 0
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_c6h ENDP

OPCODE_c7h PROC
    cmp     al, 0c7h
    je      @@continue
        call    OPCODE_c8h
        ret
    
    @@continue:
    push    si
    lea     si, ins_mov
    call    loadTextToBuffer
    pop     si

    call    getByte
    call    getModRegRM

    mov     dl, 1
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_c7h ENDP

OPCODE_c8h PROC
    cmp     al, 0c8h
    je      @@continue
        call    OPCODE_c9h
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_c8h ENDP

OPCODE_c9h PROC
    cmp     al, 0c9h
    je      @@continue
        call    OPCODE_cah
        ret
    
    @@continue:
    push    si
    lea     si, ins_leave
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_c9h ENDP

OPCODE_cah PROC
    cmp     al, 0cah
    je      @@continue
        call    OPCODE_cbh
        ret
    
    @@continue:
    push    si
    lea     si, ins_retf
    call    loadTextToBuffer
    pop     si
    
    call    getWord
    mov     dx, ax
    call    printWord

    @@done:
    ret
OPCODE_cah ENDP

OPCODE_cbh PROC
    cmp     al, 0cbh
    je      @@continue
        call    OPCODE_cch
        ret
    
    @@continue:
    push    si
    lea     si, ins_retf
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_cbh ENDP

OPCODE_cch PROC
    cmp     al, 0cch
    je      @@continue
        call    OPCODE_cdh
        ret
    
    @@continue:
    push    si
    lea     si, ins_int3
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_cch ENDP

OPCODE_cdh PROC
    cmp     al, 0cdh
    je      @@continue
        call    OPCODE_ceh
        ret
    
    @@continue:
    push    si
    lea     si, ins_int
    call    loadTextToBuffer
    pop     si

    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_cdh ENDP

OPCODE_ceh PROC
    cmp     al, 0ceh
    je      @@continue
        call    OPCODE_cfh
        ret
    
    @@continue:
    push    si
    lea     si, ins_into
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_ceh ENDP

OPCODE_cfh PROC
    cmp     al, 0cfh
    je      @@continue
        call    OPCODE_d0h
        ret
    
    @@continue:
    push    si
    lea     si, ins_iret
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_cfh ENDP

OPCODE_d0h PROC
    cmp     al, 0d0h
    je      @@continue
        call    OPCODE_d1h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_rol
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 0
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadOne

    @@done:
    ret
OPCODE_d0h ENDP

OPCODE_d1h PROC
    cmp     al, 0d1h
    je      @@continue
        call    OPCODE_d2h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_rol
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 1
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    call    loadOne

    @@done:
    ret
OPCODE_d1h ENDP

OPCODE_d2h PROC
    cmp     al, 0d2h
    je      @@continue
        call    OPCODE_d3h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_rol
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 0
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    push    si
    lea     si, reg_cl
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_d2h ENDP

OPCODE_d3h PROC
    cmp     al, 0d3h
    je      @@continue
        call    OPCODE_d4h
        ret
    
    @@continue:
    call    getByte
    call    getModRegRM
    
    xor     bx, bx
    mov     bl, byte ptr opcodeReg
    shl     bx, 4
    push    si
    lea     si, ins_rol
    add     si, bx
    call    loadTextToBuffer
    pop     si
    
    mov     dl, 1
    mov     bl, 1
    call    loadModRM
    call    loadCommaSpace
    push    si
    lea     si, reg_cl
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_d3h ENDP

OPCODE_d4h PROC
    cmp     al, 0d4h
    je      @@continue
        call    OPCODE_d5h
        ret
    
    @@continue:
    call    getByte
    
    push    si
    lea     si, ins_aam
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_d4h ENDP

OPCODE_d5h PROC
    cmp     al, 0d5h
    je      @@continue
        call    OPCODE_d6h
        ret
    
    @@continue:
    call    getByte
    
    push    si
    lea     si, ins_aad
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_d5h ENDP

OPCODE_d6h PROC
    cmp     al, 0d6h
    je      @@continue
        call    OPCODE_d7h
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_d6h ENDP

OPCODE_d7h PROC
    cmp     al, 0d7h
    je      @@continue
        call    OPCODE_d8h
        ret
    
    @@continue:
    push    si
    lea     si, ins_xlatb
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_d7h ENDP

OPCODE_d8h PROC
    cmp     al, 0d8h
    je      @@continue
        call    OPCODE_d9h
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_d8h ENDP

OPCODE_d9h PROC
    cmp     al, 0d9h
    je      @@continue
        call    OPCODE_dah
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_d9h ENDP

OPCODE_dah PROC
    cmp     al, 0dah
    je      @@continue
        call    OPCODE_dbh
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_dah ENDP

OPCODE_dbh PROC
    cmp     al, 0dbh
    je      @@continue
        call    OPCODE_dch
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_dbh ENDP

OPCODE_dch PROC
    cmp     al, 0dch
    je      @@continue
        call    OPCODE_ddh
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_dch ENDP

OPCODE_ddh PROC
    cmp     al, 0ddh
    je      @@continue
        call    OPCODE_deh
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_ddh ENDP

OPCODE_deh PROC
    cmp     al, 0deh
    je      @@continue
        call    OPCODE_dfh
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_deh ENDP

OPCODE_dfh PROC
    cmp     al, 0dfh
    je      @@continue
        call    OPCODE_e0h
        ret
    
    @@continue:
    push    si
    lea     si, ins_unknown
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_dfh ENDP

OPCODE_e0h PROC
    cmp     al, 0e0h
    je      @@continue
        call    OPCODE_e1h
        ret
    
    @@continue:
    push    si
    lea     si, ins_loopne
    call    loadTextToBuffer
    pop     si

    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_e0h ENDP

OPCODE_e1h PROC
    cmp     al, 0e1h
    je      @@continue
        call    OPCODE_e2h
        ret
    
    @@continue:
    push    si
    lea     si, ins_loope
    call    loadTextToBuffer
    pop     si

    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_e1h ENDP

OPCODE_e2h PROC
    cmp     al, 0e2h
    je      @@continue
        call    OPCODE_e3h
        ret
    
    @@continue:
    push    si
    lea     si, ins_loop
    call    loadTextToBuffer
    pop     si

    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_e2h ENDP

OPCODE_e3h PROC
    cmp     al, 0e3h
    je      @@continue
        call    OPCODE_e4h
        ret
    
    @@continue:
    push    si
    lea     si, ins_jcxz
    call    loadTextToBuffer
    pop     si

    mov     dx, 2
    call    loadPointer

    @@done:
    ret
OPCODE_e3h ENDP

OPCODE_e4h PROC
    cmp     al, 0e4h
    je      @@continue
        call    OPCODE_e5h
        ret
    
    @@continue:
    push    si
    lea     si, ins_in
    call    loadTextToBuffer
    lea     si, reg_al
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_e4h ENDP

OPCODE_e5h PROC
    cmp     al, 0e5h
    je      @@continue
        call    OPCODE_e6h
        ret
    
    @@continue:
    push    si
    lea     si, ins_in
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_e5h ENDP

OPCODE_e6h PROC
    cmp     al, 0e6h
    je      @@continue
        call    OPCODE_e7h
        ret
    
    @@continue:
    push    si
    lea     si, ins_out
    call    loadTextToBuffer
    pop     si

    call    getByte
    mov     dl, al
    call    printByte
    call    loadCommaSpace
    push    si
    lea     si, reg_al
    call    loadTextToBuffer
    pop     si

    @@done:
    ret
OPCODE_e6h ENDP

OPCODE_e7h PROC
    cmp     al, 0e7h
    je      @@continue
        call    OPCODE_e8h
        ret
    
    @@continue:
    push    si
    lea     si, ins_out
    call    loadTextToBuffer
    lea     si, reg_ax
    call    loadTextToBuffer
    pop     si

    call    loadCommaSpace
    call    getByte
    mov     dl, al
    call    printByte

    @@done:
    ret
OPCODE_e7h ENDP

OPCODE_e8h PROC
    cmp     al, 0e8h
    je      @@continue
        call    OPCODE_e9h
        ret
    
    @@continue:
    push    si
    lea     si, ins_call
    call    loadTextToBuffer
    pop     si

    call    loadPlace
    call    getWord
    mov     dx, word ptr byteInFile
    add     dx, ax
    call printWord

    @@done:
    ret
OPCODE_e8h ENDP

OPCODE_e9h PROC
    cmp     al, 0e9h
    je      @@continue
        call    OPCODE_eah
        ret
    
    @@continue:
    push    si
    lea     si, ins_jmp
    call    loadTextToBuffer
    pop     si

    call    getWord
    mov     dx, word ptr byteInFile
    add     dx, ax
    add     dx, 3
    call    printWord

    @@done:
    ret
OPCODE_e9h ENDP

OPCODE_eah PROC
    cmp     al, 0eah
    je      @@continue
        push si
        lea si, ins_unknown
        call loadTextToBuffer
        pop si
        ret
        call    OPCODE_ebh
        ret
    
    @@continue:
    push    si
    lea     si, ins_jmp
    call    loadTextToBuffer
    pop     si

    call    getWord
    mov     dx, word ptr byteInFile
    add     dx, ax
    add     dx, 3
    call    printWord

    @@done:
    ret
OPCODE_eah ENDP

OPCODE_ebh PROC
    push    ax
    push    bx

    mov     bl, al
    cmp     bl, 0ebh
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0ech
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0edh
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0eeh
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0efh
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f0h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f1h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f2h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f3h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f4h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f5h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f6h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f7h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f8h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0f9h
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0fah
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0fbh
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0fch
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0fdh
    cmp     bl, 00h
    je      @@continue
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
    cmp     bl, 0feh
    cmp     bl, 00h
    je      @@continue
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

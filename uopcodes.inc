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
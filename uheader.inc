;***************************************************;
;                GET HEADER 28 BYTES                ;
;***************************************************;
getHeader28Bytes PROC
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
    mov     cx, 28
    lea     dx, inputBuffer
    int     21h

    jc      @@error

    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret

    @@error:
    call    displayHelp
    call    endProgram
getHeader28Bytes ENDP

;***************************************************;
;               GET PARAMS FROM HEADER              ;
;***************************************************;
getParamsFromHeader PROC
    push    ax
    push    bx
    push    si

    lea     si, inputBuffer

    ; Get number of relocations
    mov     ax, [si + 06h]
    mov     numberOfRelocations, ax

    ; Get header size
    mov     ax, [si + 08h]
    shl     ax, 4
    mov     headerSize, ax

    ; Get stack size
    mov     bx, [si + 10h]
    mov     stackSize, bx

    ; Get starting ip adress
    mov     bx, [si + 14h]
    add     bx, ax
    mov     startingIPAddress, bx

    ; Get code segment offset
    mov     bx, [si + 16h]
    shl     bx, 4
    add     bx, ax
    mov     codeSegmentOffset, bx

    ; Get relocation table offset
    mov     bx, [si + 18h]
    mov     relocationTableOffset, bx

    pop     si
    pop     bx
    pop     ax
    ret
getParamsFromHeader ENDP

;***************************************************;
;                 GET TAG DATA PLACE                ;
;***************************************************;
getTagDataPlace PROC
    push    ax
    push    bx
    push    cx
    push    dx

    mov     ax, 4200h
    mov     bx, inputHandle
    xor     cx, cx
    mov     dx, word ptr relocationTableOffset
    int     21h
    jc      @@error

    mov     ah, 3Fh
    mov     cx, 4
    lea     dx, inputBuffer
    int     21h
    jc      @@error

    mov     ax, word ptr [inputBuffer]
    mov     bx, word ptr [inputBuffer + 2]
    xor     dx, dx

    ; first shift
    shl     bx, 1
    rcl     dx, 1
    ; second shift
    shl     bx, 1
    rcl     dx, 1
    ; third shift
    shl     bx, 1
    rcl     dx, 1
    ; fourth shift
    shl     bx, 1
    rcl     dx, 1

    add     bx, ax
    adc     dx, 0h

    mov     ax, headerSize
    add     bx, ax
    adc     dx, 0h

    ; dx:bx = data tag byte
    mov     word ptr [dataTagByte], bx
    mov     word ptr [dataTagByte + 2], dx

    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret

    @@error:
    call    displayHelp
    call    endProgram
getTagDataPlace ENDP

;***************************************************;
;               GET DATA SEGMENT START              ;
;***************************************************;
getDataSegmentStart PROC
    push    ax
    push    bx
    push    cx
    push    dx

    mov     ax, 4200h
    mov     bx, inputHandle
    ; dx:cx - double word
    mov     dx, word ptr [dataTagByte]
    mov     cx, word ptr [dataTagByte + 2]
    int     21h

    jc      @@error

    mov     ah, 3Fh
    mov     cx, 2
    lea     dx, inputBuffer
    int     21h

    jc      @@error

    xor     dx, dx
    mov     ax, word ptr [inputBuffer]
    
    ; first shift
    shl     ax, 1
    rcl     dx, 1

    ; second shift
    shl     ax, 1
    rcl     dx, 1

    ; third shift
    shl     ax, 1
    rcl     dx, 1

    ; fourth shift
    shl     ax, 1
    rcl     dx, 1

    add     ax, headerSize
    adc     dx, 0h

    mov     word ptr [dataSegmentStart], ax
    mov     word ptr [dataSegmentStart + 2], dx

    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret

    @@error:
    call    displayHelp
    call    endProgram
getDataSegmentStart ENDP

getRelocations PROC
    push    ax
    push    bx
    push    cx
    push    dx

    mov     ax, 4200h
    mov     bx, inputHandle
    xor     cx, cx
    mov     dx, word ptr relocationTableOffset
    int     21h
    jc      @@error

    mov     ah, 3Fh
    mov     cx, word ptr numberOfRelocations
    shl     cx, 2
    lea     dx, relocationBuffer
    int     21h
    jc      @@error
    mov     ah, 01
    int     21h

    pop     dx
    pop     cx
    pop     bx
    pop     ax
    ret

    @@error:
    call    displayHelp
    call    endProgram
getRelocations ENDP
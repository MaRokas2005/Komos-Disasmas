LOCALS @@
.MODEL SMALL
.STACK 100h

.DATA
    inputName       db  255 dup("$")
    outputName      db  255 dup("$")
    inputHandle     dw  0
    outputHandle    dw  0
    inputBuffer     db  300 dup(0)
    newline         db  0dh, 0ah, 0
    outputBuffer    db  300 dup(0)
    outputLength    dw  0
    filePointer     dw  2   dup(0)
    
    headerSize              dw  0
    stackSize               dw  0
    codeSegmentOffset       dw  0
    relocationTableOffset   dw  0

    dataTagByte             dd  0
    byteInFile              dd  0 ;current
    dataSegmentStart        dd  0

    prefix      db  0

    tagDB       db  "    db  ", 0
    tagData     db  "@data", 0
    tagByte     db  "byte ptr ", 0
    tagWord     db  "word ptr ", 0
    tagDWord    db  "dword ptr ", 0

    segModel    db  ".MODEL SMALL", 0
    segStack    db  ".STACK ", 0
    segData     db  ".DATA", 0 
    segCode     db  ".CODE", 0
    segEnd      db  "END", 0

    include     dmessage.inc
    include     dhelp.inc

.CODE
    include     ufile.inc
    include     uheader.inc
    include     udisasm.inc
    include     unumbers.inc
    include     uopcodes.inc

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

        ; @@readNextChunk:
        ; mov     ah, 3Fh
        ; push    bx
        ; mov     bx, inputHandle
        ; lea     dx, inputBuffer
        ; xor     cx, cx
        ; mov     cl, lineLength
        ; int     21h
        ; pop     bx
        ; jc      @@error
        ; cmp     ax, 0
        ; je      @@finish

        ; lea     si, inputBuffer
        ; lea     di, outputBuffer
        ; mov     bl, al

        ; @@processChunk:
        ;     mov     al, [si]

        ;     cmp     al, 0
        ;     jne     @@continue
        ;     call    flushBuffer
        ;     mov     bh, 1
        ;     jmp     @@finish
        ;     @@continue:

        ;     cmp     al, 0dh
        ;     jne     @@continue2
        ;     call    flushBuffer
        ;     add     ah, 2
        ;     call    fixThePointer
        ;     mov     bh, 1
        ;     jmp     @@readNextChunk
        ;     @@continue2:

        ;     mov     [di], al
        ;     inc     si
        ;     inc     di
        ;     inc     ah

        ;     cmp     ah, bl
        ;     jne     @@continue3
        ;     call    flushBuffer
        ;     mov     bh, 1
        ;     call    fixThePointer
        ;     jmp     @@readNextChunk
        ;     @@continue3:


        ; loop    @@processChunk

        
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

        call    checkIfExe
        ;call    checkIfTlinkerExe

        call    getRezFileHandle

        call    getHeader28Bytes
        call    getParamsFromHeader
        call    getTagDataPlace
        call    getDataSegmentStart

        call    printStart
        call    printDataSegment
        call    printCodeSegment

        ; call    processFile

        call    endProgram
        
    end main
END
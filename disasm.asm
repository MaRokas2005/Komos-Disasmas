LOCALS @@
.MODEL SMALL
.STACK 100h

.DATA
    inputName       db  255 dup("$")
    outputName      db  255 dup("$")
    inputHandle     dw  0
    outputHandle    dw  0
    inputBuffer     db  300 dup(0)
    outputBuffer    db  300 dup(0)
    outputLength    dw  0
    newline         db  0dh, 0ah, 0
    komment         db  "; ", 0     ; I can not use comment, because maybe it is reserved word
    commaSpace      db  ", ", 0
    usedBytes       dw  0
    
    headerSize              dw  0
    stackSize               dw  0
    codeSegmentOffset       dw  0
    relocationTableOffset   dw  0

    dataTagByte             dd  0
    byteInFile              dd  0   ; current
    dataSegmentStart        dd  0

    opcodeMod   db  0
    opcodeReg   db  0
    opcodeRM    db  0

    prefix      db  0ffh    ; 0ffh = no prefix

    tagDB       db  "    db  ", 0
    tagData     db  "@data", 0
    tagByte     db  "byte ptr ", 0
    tagWord     db  "word ptr ", 0
    tagSegES    db  "es:[ ", 0
    tagSegDS    db  "ds:[ ", 0
    tagSegSS    db  "ss:[ ", 0
    tagSegCS    db  "cs:[ ", 0
    tagStart    db  "[ ", 0
    tagClose    db  " ]", 0
    tagSegOFF   dw  offset tagSegES, offset tagSegDS, offset tagSegSS, offset tagSegCS
    ; tagDWord    db  "dword ptr ", 0

    segModel    db  ".MODEL SMALL", 0
    segStack    db  ".STACK ", 0
    segData     db  ".DATA", 0 
    segCode     db  ".CODE", 0
    segEnd      db  "END", 0

    include     dmessage.inc
    include     dhelp.inc
    include     dopcodes.inc

.CODE
    include     ufile.inc
    include     uheader.inc
    include     udisasm.inc
    include     unumbers.inc
    include     uopcodes.inc

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

        call    endProgram
        
    end main
END
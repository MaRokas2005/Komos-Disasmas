.MODEL small

.STACK 100h

.DATA
    nulis       DB  "nulis$",0
    vienas      DB  "vienas$",0
    du          DB  "du$",0
    trys        DB  "trys$",0
    keturi      DB  "keturi$",0
    penki       DB  "penki$",0
    sesi        DB  "sesi$",0
    septyni     DB  "septyni$",0
    astuoni     DB  "astuoni$",0
    devyni      DB  "devyni$",0

    msgInput    DB  "Iveskite simboliu eilute: $"
    msgOutput   DB  "Ivesta simboliu eilute su pakeistais skaiciais i zodzius: $"
    msgIlgisStr DB  " (ilgis $"
    msgIlgisEnd DB  ")$"
    msgNewLine  DB  10,13,"$"

    inputBuffer DB  255 DUP("$")

.CODE
    ; Load string address to dx before calling print
    printStr PROC
        push    ax

        mov     ah,09h
        int     21h

        pop     ax
        RET
    printStr ENDP

    printNum PROC
        push ax
        
        cmp     al,'0'
        je      printZero

        cmp     al,'1'
        je      printOne

        cmp     al,'2'
        je      printTwo

        cmp     al,'3'
        je      printThree

        cmp     al,'4'
        je      printFour

        cmp     al,'5'
        je      printFive

        cmp     al,'6'
        je      printSix

        cmp     al,'7'
        je      printSeven

        cmp     al,'8'
        je      printEight

        cmp     al,'9'
        je      printNine

        jmp      notDigit

        notDigit:
            mov     ah,02h
            mov     dl,al
            int     21h
            jmp     endas
        printZero:
            lea     dx,nulis
            call    printStr
            jmp     endas
        printOne:
            lea     dx,vienas
            call    printStr
            jmp     endas
        printTwo:
            lea     dx,du
            call    printStr
            jmp     endas
        printThree:
            lea     dx,trys
            call    printStr
            jmp     endas
        printFour:
            lea     dx,keturi
            call    printStr
            jmp     endas
        printFive:
            lea     dx,penki
            call    printStr
            jmp     endas
        printSix:
            lea     dx,sesi
            call    printStr
            jmp     endas
        printSeven:
            lea     dx,septyni
            call    printStr
            jmp     endas
        printEight:
            lea     dx,astuoni
            call    printStr
            jmp     endas
        printNine:
            lea     dx,devyni
            call    printStr
            jmp     endas
        endas:

        pop ax
        RET
    printNum ENDP
    
    PrintIlgis MACRO number
        LOCAL convert,print

        push    ax
        push    bx
        push    cx
        push    dx

        xor     cx,cx
        mov     ax,number
        mov     bx,10


        convert:
            xor     dx,dx
            div     bx
            push    dx
            inc     cx
            cmp     al,0
            jne     convert
        
        xor     dx,dx
        lea     dx,msgIlgisStr
        call    printStr

        print:
            pop     dx
            add     dx,'0'
            mov     ah,02h
            int     21h
            loop    print

        lea     dx,msgIlgisEnd
        call    printStr

        pop     dx
        pop     cx
        pop     bx
        pop     ax
    ENDM


    main:
        ; Set data segment
        mov     ax,@data
        mov     ds,ax
        mov     es,ax


        ; Print msgInput
        lea     dx,msgInput
        call    printStr

        ; Read input
        lea     dx,inputBuffer
        mov     ah,0Ah
        int     21h

        ; Print new line
        lea     dx,msgNewLine
        call    printStr

        ; Print msgOutput
        lea     dx,msgOutput
        call    printStr

        ; Print answer
        xor     cx,cx
        xor     bx,bx
        mov     cl,inputBuffer[1]
        mov     si,offset inputBuffer+2

        printChar:
            mov     al, [si]
            inc     si
            call    printNum
            loop    printChar

        xor     ax,ax
        mov     al,inputBuffer[1]
        PrintIlgis  ax

        exit:
            mov     ah,4ch
            int     21h
    end main    
END
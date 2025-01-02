.MODEL SMALL
.STACK  00100h

.DATA
    db  06eh, 075h, 06ch, 069h, 073h, 024h, 000h, 076h, 069h, 065h, 06eh, 061h, 073h, 024h, 000h, 064h
    db  075h, 024h, 000h, 074h, 072h, 079h, 073h, 024h, 000h, 06bh, 065h, 074h, 075h, 072h, 069h, 024h
    db  000h, 070h, 065h, 06eh, 06bh, 069h, 024h, 000h, 073h, 065h, 073h, 069h, 024h, 000h, 073h, 065h
    db  070h, 074h, 079h, 06eh, 069h, 024h, 000h, 061h, 073h, 074h, 075h, 06fh, 06eh, 069h, 024h, 000h
    db  064h, 065h, 076h, 079h, 06eh, 069h, 024h, 000h, 049h, 076h, 065h, 073h, 06bh, 069h, 074h, 065h
    db  020h, 073h, 069h, 06dh, 062h, 06fh, 06ch, 069h, 075h, 020h, 065h, 069h, 06ch, 075h, 074h, 065h
    db  03ah, 020h, 024h, 049h, 076h, 065h, 073h, 074h, 061h, 020h, 073h, 069h, 06dh, 062h, 06fh, 06ch
    db  069h, 075h, 020h, 065h, 069h, 06ch, 075h, 074h, 065h, 020h, 073h, 075h, 020h, 070h, 061h, 06bh
    db  065h, 069h, 073h, 074h, 061h, 069h, 073h, 020h, 073h, 06bh, 061h, 069h, 063h, 069h, 061h, 069h
    db  073h, 020h, 069h, 020h, 07ah, 06fh, 064h, 07ah, 069h, 075h, 073h, 03ah, 020h, 024h, 020h, 028h
    db  069h, 06ch, 067h, 069h, 073h, 020h, 024h, 029h, 024h, 00ah, 00dh, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
    db  024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h, 024h
.CODE
;;  SCANNING...
place_00200h:       push    ax
place_00201h:       mov     ah, 009h
place_00203h:       int     021h
place_00205h:       pop     ax
place_00206h:       ret     
place_00207h:       push    ax
place_00208h:       cmp     al, 030h
place_0020ah:       je      place_0023ch
place_0020ch:       cmp     al, 031h
place_0020eh:       je      place_00245h
place_00210h:       cmp     al, 032h
place_00212h:       je      place_0024eh
place_00214h:       cmp     al, 033h
place_00216h:       je      place_00257h
place_00218h:       cmp     al, 034h
place_0021ah:       je      place_00260h
place_0021ch:       cmp     al, 035h
place_0021eh:       je      place_00269h
place_00220h:       cmp     al, 036h
place_00222h:       je      place_00272h
place_00224h:       cmp     al, 037h
place_00226h:       je      place_0027bh
place_00228h:       cmp     al, 038h
place_0022ah:       je      place_00284h
place_0022ch:       cmp     al, 039h
place_0022eh:       je      place_0028dh
place_00230h:       jmp     place_00233h
place_00232h:       nop     
place_00233h:       mov     ah, 002h
place_00235h:       mov     dl, al
place_00237h:       int     021h
place_00239h:       jmp     place_00296h
place_0023bh:       nop     
place_0023ch:       mov     dx, 00000h
place_0023fh:       call    place_00200h
place_00242h:       jmp     place_00296h
place_00244h:       nop     
place_00245h:       mov     dx, 00007h
place_00248h:       call    place_00200h
place_0024bh:       jmp     place_00296h
place_0024dh:       nop     
place_0024eh:       mov     dx, 0000fh
place_00251h:       call    place_00200h
place_00254h:       jmp     place_00296h
place_00256h:       nop     
place_00257h:       mov     dx, 00013h
place_0025ah:       call    place_00200h
place_0025dh:       jmp     place_00296h
place_0025fh:       nop     
place_00260h:       mov     dx, 00019h
place_00263h:       call    place_00200h
place_00266h:       jmp     place_00296h
place_00268h:       nop     
place_00269h:       mov     dx, 00021h
place_0026ch:       call    place_00200h
place_0026fh:       jmp     place_00296h
place_00271h:       nop     
place_00272h:       mov     dx, 00028h
place_00275h:       call    place_00200h
place_00278h:       jmp     place_00296h
place_0027ah:       nop     
place_0027bh:       mov     dx, 0002eh
place_0027eh:       call    place_00200h
place_00281h:       jmp     place_00296h
place_00283h:       nop     
place_00284h:       mov     dx, 00037h
place_00287h:       call    place_00200h
place_0028ah:       jmp     place_00296h
place_0028ch:       nop     
place_0028dh:       mov     dx, 00040h
place_00290h:       call    place_00200h
place_00293h:       jmp     place_00296h
place_00295h:       nop     
place_00296h:       pop     ax
place_00297h:       ret     
START:
place_00298h:       mov     ax, @data
place_0029bh:       mov     ds, ax
place_0029dh:       mov     es, ax
place_0029fh:       mov     dx, 00048h
place_002a2h:       call    place_00200h
place_002a5h:       mov     dx, 000ach
place_002a8h:       mov     ah, 00ah
place_002aah:       int     021h
place_002ach:       mov     dx, 000a9h
place_002afh:       call    place_00200h
place_002b2h:       mov     dx, 00063h
place_002b5h:       call    place_00200h
place_002b8h:       xor     cx, cx
place_002bah:       xor     bx, bx
place_002bch:       mov     cl, byte ptr ds:[ 000adh ]
place_002c0h:       mov     si, 000aeh
place_002c3h:       mov     al, byte ptr ds:[ si ]
place_002c5h:       inc     si
place_002c6h:       call    place_00207h
place_002c9h:       loop    place_002c3h
place_002cbh:       xor     ax, ax
place_002cdh:       mov     al, byte ptr ds:[ 00200h ]
place_002d0h:       push    ax
place_002d1h:       push    bx
place_002d2h:       push    cx
place_002d3h:       push    dx
place_002d4h:       xor     cx, cx
place_002d6h:       mov     ax, ax
place_002d8h:       mov     bx, 0000ah
place_002dbh:       xor     dx, dx
place_002ddh:       div     bx
place_002dfh:       push    dx
place_002e0h:       inc     cx
place_002e1h:       cmp     al, 000h
place_002e3h:       jne     place_002dbh
place_002e5h:       xor     dx, dx
place_002e7h:       mov     dx, 0009eh
place_002eah:       call    place_00200h
place_002edh:       pop     dx
place_002eeh:       add     dx, 00030h
place_002f1h:       mov     ah, 002h
place_002f3h:       int     021h
place_002f5h:       loop    place_002edh
place_002f7h:       mov     dx, 000a7h
place_002fah:       call    place_00200h
place_002fdh:       pop     dx
place_002feh:       pop     cx
;;  SCANNING...
place_002ffh:       pop     bx
place_00300h:       pop     ax
place_00301h:       mov     ah, 04ch
place_00303h:       int     021h
place_00305h:       add     byte ptr ds:[ bx + si ], al
place_00307h:       add     byte ptr ds:[ bx + si ], al
place_00309h:       add     byte ptr ds:[ bx + si ], al
place_0030bh:       add     byte ptr ds:[ bx + si ], al
place_0030dh:       add     byte ptr ds:[ bx + si ], al
END START
END
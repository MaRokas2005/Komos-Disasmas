.MODEL SMALL
.STACK  00100h

.DATA
.CODE
;;  SCANNING...
place_00200h:
    push    axplace_00201h:
    push    dxplace_00202h:
    mov     ah, 009hplace_00204h:
    mov     dx, 00461hplace_00207h:
    int     021hplace_00209h:
    call    place_002aahplace_0020ch:
    pop     dxplace_0020dh:
    pop     axplace_0020eh:
    ret     place_0020fh:
    mov     ah, 03ehplace_00211h:
    mov     bx, word ptr ds:[ 001feh ]place_00215h:
    int     021hplace_00217h:
    mov     bx, word ptr ds:[ 00200h ]place_0021bh:
    int     021hplace_0021dh:
    mov     ax, 04c00hplace_00220h:
    int     021hplace_00222h:
    push    axplace_00223h:
    push    dxplace_00224h:
    mov     ah, 009hplace_00226h:
    mov     dx, 004c6hplace_00229h:
    int     021hplace_0022bh:
    mov     dx, 004cfhplace_0022eh:
    int     021hplace_00230h:
    pop     dxplace_00231h:
    pop     axplace_00232h:
    ret     place_00233h:
    push    axplace_00234h:
    push    dxplace_00235h:
    mov     ah, 009hplace_00237h:
    mov     dx, 004c6hplace_0023ah:
    int     021hplace_0023ch:
    mov     dx, 004e7hplace_0023fh:
    int     021hplace_00241h:
    pop     dxplace_00242h:
    pop     axplace_00243h:
    ret     place_00244h:
    push    axplace_00245h:
    push    dxplace_00246h:
    mov     ah, 009hplace_00248h:
    mov     dx, 004c6hplace_0024bh:
    int     021hplace_0024dh:
    mov     dx, 00501hplace_00250h:
    int     021hplace_00252h:
    pop     dxplace_00253h:
    pop     axplace_00254h:
    ret     place_00255h:
    push    axplace_00256h:
    push    dxplace_00257h:
    mov     ah, 009hplace_00259h:
    mov     dx, 004c6hplace_0025ch:
    int     021hplace_0025eh:
    mov     dx, 00519hplace_00261h:
    int     021hplace_00263h:
    pop     dxplace_00264h:
    pop     axplace_00265h:
    ret     place_00266h:
    push    axplace_00267h:
    push    dxplace_00268h:
    mov     ah, 009hplace_0026ah:
    mov     dx, 004c6hplace_0026dh:
    int     021hplace_0026fh:
    mov     dx, 00535hplace_00272h:
    int     021hplace_00274h:
    pop     dxplace_00275h:
    pop     axplace_00276h:
    ret     place_00277h:
    push    axplace_00278h:
    push    dxplace_00279h:
    mov     ah, 009hplace_0027bh:
    mov     dx, 004c6hplace_0027eh:
    int     021hplace_00280h:
    mov     dx, 00556hplace_00283h:
    int     021hplace_00285h:
    pop     dxplace_00286h:
    pop     axplace_00287h:
    ret     place_00288h:
    push    axplace_00289h:
    push    dxplace_0028ah:
    mov     ah, 009hplace_0028ch:
    mov     dx, 004c6hplace_0028fh:
    int     021hplace_00291h:
    mov     dx, 0056ehplace_00294h:
    int     021hplace_00296h:
    pop     dxplace_00297h:
    pop     axplace_00298h:
    ret     place_00299h:
    push    axplace_0029ah:
    push    dxplace_0029bh:
    mov     ah, 009hplace_0029dh:
    mov     dx, 004c6hplace_002a0h:
    int     021hplace_002a2h:
    mov     dx, 005b4hplace_002a5h:
    int     021hplace_002a7h:
    pop     dxplace_002a8h:
    pop     axplace_002a9h:
    ret     place_002aah:
    push    axplace_002abh:
    push    dxplace_002ach:
    mov     ah, 009hplace_002aeh:
    mov     dx, 00487hplace_002b1h:
    int     021hplace_002b3h:
    mov     ah, 008hplace_002b5h:
    int     021hplace_002b7h:
    mov     ah, 009hplace_002b9h:
    mov     dx, 004a4hplace_002bch:
    int     021hplace_002beh:
    pop     dxplace_002bfh:
    pop     axplace_002c0h:
    ret     place_002c1h:
    push    axplace_002c2h:
    push    dxplace_002c3h:
    mov     ah, 009hplace_002c5h:
    mov     dx, 005e8hplace_002c8h:
    int     021hplace_002cah:
    mov     dx, 00639hplace_002cdh:
    int     021hplace_002cfh:
    call    place_002aahplace_002d2h:
    mov     dx, 006aahplace_002d5h:
    int     021hplace_002d7h:
    call    place_002aahplace_002dah:
    mov     dx, 00762hplace_002ddh:
    int     021hplace_002dfh:
    call    place_002aahplace_002e2h:
    mov     dx, 0087ahplace_002e5h:
    int     021hplace_002e7h:
    call    place_002aahplace_002eah:
    mov     dx, 0098dhplace_002edh:
    int     021hplace_002efh:
    call    place_002aahplace_002f2h:
    mov     dx, 00b2dhplace_002f5h:
    int     021hplace_002f7h:
    call    place_002aahplace_002fah:
    mov     dx, 00c91hplace_002fdh:
    int     021h;;  SCANNING...
place_002ffh:
    call    place_002aahplace_00302h:
    mov     dx, 00dc7hplace_00305h:
    int     021hplace_00307h:
    call    place_002aahplace_0030ah:
    mov     dx, 00df6hplace_0030dh:
    int     021hplace_0030fh:
    pop     dxplace_00310h:
    pop     axplace_00311h:
    ret     place_00312h:
    push    axplace_00313h:
    push    diplace_00314h:
    push    siplace_00315h:
    mov     al, byte ptr es:[ di ]place_00318h:
    cmp     al, byte ptr ds:[ si ]place_0031ah:
    jne     place_00344hplace_0031ch:
    inc     siplace_0031dh:
    inc     diplace_0031eh:
    cmp     byte ptr ds:[ si ], 000hplace_00321h:
    je      place_0032bhplace_00323h:
    cmp     byte ptr es:[ di ], 000hplace_00327h:
    je      place_00344hplace_00329h:
    jmp     place_00315hplace_0032bh:
    cmp     byte ptr es:[ di ], 000hplace_0032fh:
    je      place_00341hplace_00331h:
    cmp     byte ptr es:[ di ], 00dhplace_00335h:
    je      place_00341hplace_00337h:
    cmp     byte ptr es:[ di ], 020hplace_0033bh:
    je      place_00341hplace_0033dh:
    jmp     place_00344hplace_0033fh:
    nop     place_00340h:
    nop     place_00341h:
    mov     bx, 00001hplace_00344h:
    pop     siplace_00345h:
    pop     diplace_00346h:
    pop     axplace_00347h:
    ret     place_00348h:
    push    siplace_00349h:
    push    diplace_0034ah:
    mov     si, 00471hplace_0034dh:
    call    place_00312hplace_00350h:
    cmp     bx, 00001hplace_00353h:
    je      place_0038ahplace_00355h:
    mov     si, 00474hplace_00358h:
    call    place_00312hplace_0035bh:
    cmp     bx, 00001hplace_0035eh:
    je      place_0038ahplace_00360h:
    mov     si, 00477hplace_00363h:
    call    place_00312hplace_00366h:
    cmp     bx, 00001hplace_00369h:
    je      place_0038ahplace_0036bh:
    mov     si, 0047ahplace_0036eh:
    call    place_00312hplace_00371h:
    cmp     bx, 00001hplace_00374h:
    je      place_0038ahplace_00376h:
    mov     si, 0047dhplace_00379h:
    call    place_00312hplace_0037ch:
    cmp     bx, 00001hplace_0037fh:
    je      place_0038ahplace_00381h:
    mov     si, 00480hplace_00384h:
    call    place_00312hplace_00387h:
    cmp     bx, 00001hplace_0038ah:
    pop     diplace_0038bh:
    pop     siplace_0038ch:
    ret     place_0038dh:
    push    axplace_0038eh:
    push    cxplace_0038fh:
    push    dxplace_00390h:
    mov     ah, 03chplace_00392h:
    xor     cx, cxplace_00394h:
    mov     dx, 000ffhplace_00397h:
    int     021hplace_00399h:
    jae     place_003a4hplace_0039bh:
    call    place_00233hplace_0039eh:
    call    place_002c1hplace_003a1h:
    call    place_0020fhplace_003a4h:
    mov     word ptr ds:[ 00201h ], axplace_003a7h:
    pop     dxplace_003a8h:
    pop     cxplace_003a9h:
    pop     axplace_003aah:
    ret     place_003abh:
    mov     al, byte ptr es:[ di ]place_003aeh:
    cmp     al, 020hplace_003b0h:
    je      place_003b3hplace_003b2h:
    ret     place_003b3h:
    inc     diplace_003b4h:
    jmp     place_003abhplace_003b6h:
    ret     place_003b7h:
    push    axplace_003b8h:
    push    dxplace_003b9h:
    mov     ax, 03d00hplace_003bch:
    mov     dx, 00000hplace_003bfh:
    int     021hplace_003c1h:
    jae     place_003cchplace_003c3h:
    call    place_00222hplace_003c6h:
    call    place_002c1hplace_003c9h:
    call    place_0020fhplace_003cch:
    mov     word ptr ds:[ 00201h ], axplace_003cfh:
    pop     dxplace_003d0h:
    pop     axplace_003d1h:
    ret     place_003d2h:
    push    axplace_003d3h:
    push    dxplace_003d4h:
    call    place_0038dhplace_003d7h:
    pop     dxplace_003d8h:
    pop     axplace_003d9h:
    ret     place_003dah:
    push    axplace_003dbh:
    mov     al, byte ptr es:[ di ]place_003deh:
    cmp     al, 022hplace_003e0h:
    jne     place_003e9hplace_003e2h:
    mov     bx, 00001hplace_003e5h:
    mov     byte ptr ds:[ si ], alplace_003e7h:
    inc     siplace_003e8h:
    inc     diplace_003e9h:
    mov     al, byte ptr es:[ di ]place_003ech:
    cmp     al, 000hplace_003eeh:
    je      place_0040ahplace_003f0h:
    cmp     al, 00dhplace_003f2h:
    je      place_0040ahplace_003f4h:
    cmp     al, 022hplace_003f6h:
    je      place_00407hplace_003f8h:
    cmp     al, 020hplace_003fah:
    jne     place_00401hplace_003fch:
    cmp     bx, 00001h;;  SCANNING...
place_003ffh:
    jne     place_0040ahplace_00401h:
    mov     byte ptr ds:[ si ], alplace_00403h:
    inc     diplace_00404h:
    inc     siplace_00405h:
    jmp     place_003e9hplace_00407h:
    inc     diplace_00408h:
    mov     byte ptr ds:[ si ], alplace_0040ah:
    inc     siplace_0040bh:
    mov     byte ptr ds:[ si ], 000hplace_0040eh:
    pop     axplace_0040fh:
    ret     place_00410h:
    push    axplace_00411h:
    push    bxplace_00412h:
    push    cxplace_00413h:
    push    dxplace_00414h:
    xor     ax, axplace_00416h:
    mov     bx, 0000ahplace_00419h:
    xor     cx, cxplace_0041bh:
    mov     cl, byte ptr es:[ di ]place_0041eh:
    inc     diplace_0041fh:
    cmp     cl, 000hplace_00422h:
    je      place_0045dhplace_00424h:
    cmp     cl, 020hplace_00427h:
    je      place_0045dhplace_00429h:
    cmp     cl, 00dhplace_0042ch:
    je      place_0045dhplace_0042eh:
    cmp     cl, 030hplace_00431h:
    jb      place_0044bhplace_00433h:
    cmp     cl, 039hplace_00436h:
    ja      place_0044bhplace_00438h:
    mul     bxplace_0043ah:
    cmp     ax, 000ffhplace_0043dh:
    ja      place_00454hplace_0043fh:
    sub     cl, 030hplace_00442h:
    add     ax, cxplace_00444h:
    cmp     ax, 000ffhplace_00447h:
    ja      place_00454hplace_00449h:
    jmp     place_0041bhplace_0044bh:
    call    place_00288hplace_0044eh:
    call    place_002c1hplace_00451h:
    call    place_0020fhplace_00454h:
    call    place_00299hplace_00457h:
    call    place_002c1hplace_0045ah:
    call    place_0020fhplace_0045dh:
    cmp     al, 000hplace_0045fh:
    jne     place_00464hplace_00461h:
    call    place_00288hplace_00464h:
    mov     byte ptr ds:[ 00200h ], alplace_00467h:
    pop     dxplace_00468h:
    pop     cxplace_00469h:
    pop     bxplace_0046ah:
    pop     axplace_0046bh:
    ret     place_0046ch:
    push    axplace_0046dh:
    push    bxplace_0046eh:
    push    cxplace_0046fh:
    push    dxplace_00470h:
    push    siplace_00471h:
    push    diplace_00472h:
    mov     al, byte ptr es:[ 00200h ]place_00476h:
    cmp     al, 000hplace_00478h:
    jne     place_00483hplace_0047ah:
    call    place_00266hplace_0047dh:
    call    place_002c1hplace_00480h:
    call    place_0020fhplace_00483h:
    mov     di, 00081hplace_00486h:
    call    place_003abhplace_00489h:
    call    place_00348hplace_0048ch:
    cmp     bx, 00001hplace_0048fh:
    jne     place_00497hplace_00491h:
    call    place_002c1hplace_00494h:
    call    place_0020fhplace_00497h:
    mov     si, 00000hplace_0049ah:
    call    place_003dahplace_0049dh:
    call    place_003abhplace_004a0h:
    mov     si, 0045chplace_004a3h:
    call    place_00410hplace_004a6h:
    call    place_003abhplace_004a9h:
    mov     si, 000ffhplace_004ach:
    call    place_003dahplace_004afh:
    call    place_003abhplace_004b2h:
    xor     ax, axplace_004b4h:
    mov     al, byte ptr es:[ 00300h ]place_004b8h:
    add     ax, 00081hplace_004bbh:
    cmp     ax, diplace_004bdh:
    je      place_004c8hplace_004bfh:
    call    place_00277hplace_004c2h:
    call    place_002c1hplace_004c5h:
    call    place_0020fhplace_004c8h:
    pop     diplace_004c9h:
    pop     siplace_004cah:
    pop     dxplace_004cbh:
    pop     cxplace_004cch:
    pop     bxplace_004cdh:
    pop     axplace_004ceh:
    ret     place_004cfh:
    push    axplace_004d0h:
    push    bxplace_004d1h:
    push    cxplace_004d2h:
    push    dxplace_004d3h:
    push    siplace_004d4h:
    mov     si, 0045dhplace_004d7h:
    mov     cx, word ptr ds:[ si ]place_004d9h:
    mov     dx, word ptr ds:[ si + 002h ]place_004dch:
    add     dl, ahplace_004deh:
    adc     dh, 000hplace_004e1h:
    adc     cx, 00000hplace_004e4h:
    mov     ax, 04200hplace_004e7h:
    mov     bx, word ptr ds:[ 001feh ]place_004ebh:
    int     021hplace_004edh:
    mov     dx, word ptr ds:[ si ]place_004efh:
    mov     ax, word ptr ds:[ si + 002h ]place_004f2h:
    pop     siplace_004f3h:
    pop     dxplace_004f4h:
    pop     cxplace_004f5h:
    pop     bxplace_004f6h:
    pop     axplace_004f7h:
    ret     place_004f8h:
    push    axplace_004f9h:
    push    bxplace_004fah:
    push    cxplace_004fbh:
    push    dxplace_004fch:
    push    diplace_004fdh:
    xor     cx, cx;;  SCANNING...
place_004ffh:
    mov     cl, ahplace_00501h:
    mov     dx, 00330hplace_00504h:
    mov     ah, 040hplace_00506h:
    cmp     bh, 000hplace_00509h:
    je      place_00511hplace_0050bh:
    add     cx, 00002hplace_0050eh:
    sub     dx, 00002hplace_00511h:
    mov     bx, word ptr ds:[ 00200h ]place_00515h:
    int     021hplace_00517h:
    jb      place_0051dhplace_00519h:
    jmp     place_00523hplace_0051bh:
    nop     place_0051ch:
    nop     place_0051dh:
    call    place_00255hplace_00520h:
    call    place_0020fhplace_00523h:
    pop     diplace_00524h:
    pop     dxplace_00525h:
    pop     cxplace_00526h:
    pop     bxplace_00527h:
    pop     axplace_00528h:
    ret     place_00529h:
    push    axplace_0052ah:
    push    bxplace_0052bh:
    push    cxplace_0052ch:
    push    dxplace_0052dh:
    push    siplace_0052eh:
    push    diplace_0052fh:
    mov     ah, 03fhplace_00531h:
    push    bxplace_00532h:
    mov     bx, word ptr ds:[ 001feh ]place_00536h:
    mov     dx, 00202hplace_00539h:
    xor     cx, cxplace_0053bh:
    mov     cl, byte ptr ds:[ 0045ch ]place_0053fh:
    int     021hplace_00541h:
    pop     bxplace_00542h:
    jb      place_0058ehplace_00544h:
    cmp     ax, 00000hplace_00547h:
    je      place_00587hplace_00549h:
    mov     si, 00202hplace_0054ch:
    mov     di, 00330hplace_0054fh:
    mov     bl, alplace_00551h:
    mov     al, byte ptr ds:[ si ]place_00553h:
    cmp     al, 000hplace_00555h:
    jne     place_00560hplace_00557h:
    call    place_004f8hplace_0055ah:
    mov     bh, 001hplace_0055ch:
    jmp     place_00587hplace_0055eh:
    nop     place_0055fh:
    nop     place_00560h:
    cmp     al, 00dhplace_00562h:
    jne     place_00571hplace_00564h:
    call    place_004f8hplace_00567h:
    add     ah, 002hplace_0056ah:
    call    place_004cfhplace_0056dh:
    mov     bh, 001hplace_0056fh:
    jmp     place_0052fhplace_00571h:
    mov     byte ptr ds:[ di ], alplace_00573h:
    inc     siplace_00574h:
    inc     diplace_00575h:
    inc     ahplace_00577h:
    cmp     ah, blplace_00579h:
    jne     place_00585hplace_0057bh:
    call    place_004f8hplace_0057eh:
    mov     bh, 001hplace_00580h:
    call    place_004cfhplace_00583h:
    jmp     place_0052fhplace_00585h:
    loop    place_00551hplace_00587h:
    pop     diplace_00588h:
    pop     siplace_00589h:
    pop     dxplace_0058ah:
    pop     cxplace_0058bh:
    pop     bxplace_0058ch:
    pop     axplace_0058dh:
    ret     place_0058eh:
    call    place_00244hplace_00591h:
    call    place_0020fhplace_00594h:
    mov     ax, 0003bhplace_00597h:
    mov     ds, axplace_00599h:
    mov     di, 00081hplace_0059ch:
    call    place_0046chplace_0059fh:
    call    place_003b7hplace_005a2h:
    call    place_003d2hplace_005a5h:
    call    place_00529hplace_005a8h:
    call    place_0020fhplace_005abh:
    add     byte ptr ds:[ bx + si ], alplace_005adh:
    add     byte ptr ds:[ bx + si ], alplace_005afh:
    add     byte ptr ds:[ bx + si ], alplace_005b1h:
    add     byte ptr ds:[ bx + si ], alplace_005b3h:
    add     byte ptr ds:[ bx + si ], alplace_005b5h:
    add     byte ptr ds:[ bx + si ], alplace_005b7h:
    add     byte ptr ds:[ bx + si ], alplace_005b9h:
    add     byte ptr ds:[ bx + si ], alplace_005bbh:
    add     byte ptr ds:[ bx + si ], alplace_005bdh:
    add     byte ptr ds:[ bx + si ], alplace_005bfh:
    add     byte ptr ds:[ si ], ahplace_005c1h:
    and     al, 024hplace_005c3h:
    and     al, 024hplace_005c5h:
    and     al, 024hplace_005c7h:
    and     al, 024hplace_005c9h:
    and     al, 024hplace_005cbh:
    and     al, 024hplace_005cdh:
    and     al, 024hplace_005cfh:
    and     al, 024hplace_005d1h:
    and     al, 024hplace_005d3h:
    and     al, 024hplace_005d5h:
    and     al, 024hplace_005d7h:
    and     al, 024hplace_005d9h:
    and     al, 024hplace_005dbh:
    and     al, 024hplace_005ddh:
    and     al, 024hplace_005dfh:
    and     al, 024hplace_005e1h:
    and     al, 024hplace_005e3h:
    and     al, 024hplace_005e5h:
    and     al, 024hplace_005e7h:
    and     al, 024hplace_005e9h:
    and     al, 024hplace_005ebh:
    and     al, 024hplace_005edh:
    and     al, 024hplace_005efh:
    and     al, 024hplace_005f1h:
    and     al, 024hplace_005f3h:
    and     al, 024hplace_005f5h:
    and     al, 024hplace_005f7h:
    and     al, 024hplace_005f9h:
    and     al, 024hplace_005fbh:
    and     al, 024hplace_005fdh:
    and     al, 024h;;  SCANNING...
place_005ffh:
    and     al, 024hplace_00601h:
    and     al, 024hplace_00603h:
    and     al, 024hplace_00605h:
    and     al, 024hplace_00607h:
    and     al, 024hplace_00609h:
    and     al, 024hplace_0060bh:
    and     al, 024hplace_0060dh:
    and     al, 024hplace_0060fh:
    and     al, 024hplace_00611h:
    and     al, 024hplace_00613h:
    and     al, 024hplace_00615h:
    and     al, 024hplace_00617h:
    and     al, 024hplace_00619h:
    and     al, 024hplace_0061bh:
    and     al, 024hplace_0061dh:
    and     al, 024hplace_0061fh:
    and     al, 024hplace_00621h:
    and     al, 024hplace_00623h:
    and     al, 024hplace_00625h:
    and     al, 024hplace_00627h:
    and     al, 024hplace_00629h:
    and     al, 024hplace_0062bh:
    and     al, 024hplace_0062dh:
    and     al, 024hplace_0062fh:
    and     al, 024hplace_00631h:
    and     al, 024hplace_00633h:
    and     al, 024hplace_00635h:
    and     al, 024hplace_00637h:
    and     al, 024hplace_00639h:
    and     al, 024hplace_0063bh:
    and     al, 024hplace_0063dh:
    and     al, 024hplace_0063fh:
    and     al, 024hplace_00641h:
    and     al, 024hplace_00643h:
    and     al, 024hplace_00645h:
    and     al, 024hplace_00647h:
    and     al, 024hplace_00649h:
    and     al, 024hplace_0064bh:
    and     al, 024hplace_0064dh:
    and     al, 024hplace_0064fh:
    and     al, 024hplace_00651h:
    and     al, 024hplace_00653h:
    and     al, 024hplace_00655h:
    and     al, 024hplace_00657h:
    and     al, 024hplace_00659h:
    and     al, 024hplace_0065bh:
    and     al, 024hplace_0065dh:
    and     al, 024hplace_0065fh:
    and     al, 024hplace_00661h:
    and     al, 024hplace_00663h:
    and     al, 024hplace_00665h:
    and     al, 024hplace_00667h:
    and     al, 024hplace_00669h:
    and     al, 024hplace_0066bh:
    and     al, 024hplace_0066dh:
    and     al, 024hplace_0066fh:
    and     al, 024hplace_00671h:
    and     al, 024hplace_00673h:
    and     al, 024hplace_00675h:
    and     al, 024hplace_00677h:
    and     al, 024hplace_00679h:
    and     al, 024hplace_0067bh:
    and     al, 024hplace_0067dh:
    and     al, 024hplace_0067fh:
    and     al, 024hplace_00681h:
    and     al, 024hplace_00683h:
    and     al, 024hplace_00685h:
    and     al, 024hplace_00687h:
    and     al, 024hplace_00689h:
    and     al, 024hplace_0068bh:
    and     al, 024hplace_0068dh:
    and     al, 024hplace_0068fh:
    and     al, 024hplace_00691h:
    and     al, 024hplace_00693h:
    and     al, 024hplace_00695h:
    and     al, 024hplace_00697h:
    and     al, 024hplace_00699h:
    and     al, 024hplace_0069bh:
    and     al, 024hplace_0069dh:
    and     al, 024hplace_0069fh:
    and     al, 024hplace_006a1h:
    and     al, 024hplace_006a3h:
    and     al, 024hplace_006a5h:
    and     al, 024hplace_006a7h:
    and     al, 024hplace_006a9h:
    and     al, 024hplace_006abh:
    and     al, 024hplace_006adh:
    and     al, 024hplace_006afh:
    and     al, 024hplace_006b1h:
    and     al, 024hplace_006b3h:
    and     al, 024hplace_006b5h:
    and     al, 024hplace_006b7h:
    and     al, 024hplace_006b9h:
    and     al, 024hplace_006bbh:
    and     al, 024hplace_006bdh:
    and     al, 024hplace_006bfh:
    and     al, 024hplace_006c1h:
    and     al, 024hplace_006c3h:
    and     al, 024hplace_006c5h:
    and     al, 024hplace_006c7h:
    and     al, 024hplace_006c9h:
    and     al, 024hplace_006cbh:
    and     al, 024hplace_006cdh:
    and     al, 024hplace_006cfh:
    and     al, 024hplace_006d1h:
    and     al, 024hplace_006d3h:
    and     al, 024hplace_006d5h:
    and     al, 024hplace_006d7h:
    and     al, 024hplace_006d9h:
    and     al, 024hplace_006dbh:
    and     al, 024hplace_006ddh:
    and     al, 024hplace_006dfh:
    and     al, 024hplace_006e1h:
    and     al, 024hplace_006e3h:
    and     al, 024hplace_006e5h:
    and     al, 024hplace_006e7h:
    and     al, 024hplace_006e9h:
    and     al, 024hplace_006ebh:
    and     al, 024hplace_006edh:
    and     al, 024hplace_006efh:
    and     al, 024hplace_006f1h:
    and     al, 024hplace_006f3h:
    and     al, 024hplace_006f5h:
    and     al, 024hplace_006f7h:
    and     al, 024hplace_006f9h:
    and     al, 024hplace_006fbh:
    and     al, 024hplace_006fdh:
    and     al, 024h;;  SCANNING...
place_006ffh:
    and     al, 024hplace_00701h:
    and     al, 024hplace_00703h:
    and     al, 024hplace_00705h:
    and     al, 024hplace_00707h:
    and     al, 024hplace_00709h:
    and     al, 024hplace_0070bh:
    and     al, 024hplace_0070dh:
    and     al, 024hplace_0070fh:
    and     al, 024hplace_00711h:
    and     al, 024hplace_00713h:
    and     al, 024hplace_00715h:
    and     al, 024hplace_00717h:
    and     al, 024hplace_00719h:
    and     al, 024hplace_0071bh:
    and     al, 024hplace_0071dh:
    and     al, 024hplace_0071fh:
    and     al, 024hplace_00721h:
    and     al, 024hplace_00723h:
    and     al, 024hplace_00725h:
    and     al, 024hplace_00727h:
    and     al, 024hplace_00729h:
    and     al, 024hplace_0072bh:
    and     al, 024hplace_0072dh:
    and     al, 024hplace_0072fh:
    and     al, 024hplace_00731h:
    and     al, 024hplace_00733h:
    and     al, 024hplace_00735h:
    and     al, 024hplace_00737h:
    and     al, 024hplace_00739h:
    and     al, 024hplace_0073bh:
    and     al, 024hplace_0073dh:
    and     al, 024hplace_0073fh:
    and     al, 024hplace_00741h:
    and     al, 024hplace_00743h:
    and     al, 024hplace_00745h:
    and     al, 024hplace_00747h:
    and     al, 024hplace_00749h:
    and     al, 024hplace_0074bh:
    and     al, 024hplace_0074dh:
    and     al, 024hplace_0074fh:
    and     al, 024hplace_00751h:
    and     al, 024hplace_00753h:
    and     al, 024hplace_00755h:
    and     al, 024hplace_00757h:
    and     al, 024hplace_00759h:
    and     al, 024hplace_0075bh:
    and     al, 024hplace_0075dh:
    and     al, 024hplace_0075fh:
    and     al, 024hplace_00761h:
    and     al, 024hplace_00763h:
    and     al, 024hplace_00765h:
    and     al, 024hplace_00767h:
    and     al, 024hplace_00769h:
    and     al, 024hplace_0076bh:
    and     al, 024hplace_0076dh:
    and     al, 024hplace_0076fh:
    and     al, 024hplace_00771h:
    and     al, 024hplace_00773h:
    and     al, 024hplace_00775h:
    and     al, 024hplace_00777h:
    and     al, 024hplace_00779h:
    and     al, 024hplace_0077bh:
    and     al, 024hplace_0077dh:
    and     al, 024hplace_0077fh:
    and     al, 024hplace_00781h:
    and     al, 024hplace_00783h:
    and     al, 024hplace_00785h:
    and     al, 024hplace_00787h:
    and     al, 024hplace_00789h:
    and     al, 024hplace_0078bh:
    and     al, 024hplace_0078dh:
    and     al, 024hplace_0078fh:
    and     al, 024hplace_00791h:
    and     al, 024hplace_00793h:
    and     al, 024hplace_00795h:
    and     al, 024hplace_00797h:
    and     al, 024hplace_00799h:
    and     al, 024hplace_0079bh:
    and     al, 024hplace_0079dh:
    and     al, 024hplace_0079fh:
    and     al, 024hplace_007a1h:
    and     al, 024hplace_007a3h:
    and     al, 024hplace_007a5h:
    and     al, 024hplace_007a7h:
    and     al, 024hplace_007a9h:
    and     al, 024hplace_007abh:
    and     al, 024hplace_007adh:
    and     al, 024hplace_007afh:
    and     al, 024hplace_007b1h:
    and     al, 024hplace_007b3h:
    and     al, 024hplace_007b5h:
    and     al, 024hplace_007b7h:
    and     al, 024hplace_007b9h:
    and     al, 024hplace_007bbh:
    and     al, 024hplace_007bdh:
    and     al, 000hplace_007bfh:
    add     byte ptr ds:[ bx + si ], alplace_007c1h:
    add     byte ptr ds:[ bx + si ], alplace_007c3h:
    add     byte ptr ds:[ bx + si ], alplace_007c5h:
    add     byte ptr ds:[ bx + si ], alplace_007c7h:
    add     byte ptr ds:[ bx + si ], alplace_007c9h:
    add     byte ptr ds:[ bx + si ], alplace_007cbh:
    add     byte ptr ds:[ bx + si ], alplace_007cdh:
    add     byte ptr ds:[ bx + si ], alplace_007cfh:
    add     byte ptr ds:[ bx + si ], alplace_007d1h:
    add     byte ptr ds:[ bx + si ], alplace_007d3h:
    add     byte ptr ds:[ bx + si ], alplace_007d5h:
    add     byte ptr ds:[ bx + si ], alplace_007d7h:
    add     byte ptr ds:[ bx + si ], alplace_007d9h:
    add     byte ptr ds:[ bx + si ], alplace_007dbh:
    add     byte ptr ds:[ bx + si ], alplace_007ddh:
    add     byte ptr ds:[ bx + si ], alplace_007dfh:
    add     byte ptr ds:[ bx + si ], alplace_007e1h:
    add     byte ptr ds:[ bx + si ], alplace_007e3h:
    add     byte ptr ds:[ bx + si ], alplace_007e5h:
    add     byte ptr ds:[ bx + si ], alplace_007e7h:
    add     byte ptr ds:[ bx + si ], alplace_007e9h:
    add     byte ptr ds:[ bx + si ], alplace_007ebh:
    add     byte ptr ds:[ bx + si ], alplace_007edh:
    add     byte ptr ds:[ bx + si ], alplace_007efh:
    add     byte ptr ds:[ bx + si ], alplace_007f1h:
    add     byte ptr ds:[ bx + si ], alplace_007f3h:
    add     byte ptr ds:[ bx + si ], alplace_007f5h:
    add     byte ptr ds:[ bx + si ], alplace_007f7h:
    add     byte ptr ds:[ bx + si ], alplace_007f9h:
    add     byte ptr ds:[ bx + si ], alplace_007fbh:
    add     byte ptr ds:[ bx + si ], alplace_007fdh:
    add     byte ptr ds:[ bx + si ], al;;  SCANNING...
place_007ffh:
    add     byte ptr ds:[ bx + si ], alplace_00801h:
    add     byte ptr ds:[ bx + si ], alplace_00803h:
    add     byte ptr ds:[ bx + si ], alplace_00805h:
    add     byte ptr ds:[ bx + si ], alplace_00807h:
    add     byte ptr ds:[ bx + si ], alplace_00809h:
    add     byte ptr ds:[ bx + si ], alplace_0080bh:
    add     byte ptr ds:[ bx + si ], alplace_0080dh:
    add     byte ptr ds:[ bx + si ], alplace_0080fh:
    add     byte ptr ds:[ bx + si ], alplace_00811h:
    add     byte ptr ds:[ bx + si ], alplace_00813h:
    add     byte ptr ds:[ bx + si ], alplace_00815h:
    add     byte ptr ds:[ bx + si ], alplace_00817h:
    add     byte ptr ds:[ bx + si ], alplace_00819h:
    add     byte ptr ds:[ bx + si ], alplace_0081bh:
    add     byte ptr ds:[ bx + si ], alplace_0081dh:
    add     byte ptr ds:[ bx + si ], alplace_0081fh:
    add     byte ptr ds:[ bx + si ], alplace_00821h:
    add     byte ptr ds:[ bx + si ], alplace_00823h:
    add     byte ptr ds:[ bx + si ], alplace_00825h:
    add     byte ptr ds:[ bx + si ], alplace_00827h:
    add     byte ptr ds:[ bx + si ], alplace_00829h:
    add     byte ptr ds:[ bx + si ], alplace_0082bh:
    add     byte ptr ds:[ bx + si ], alplace_0082dh:
    add     byte ptr ds:[ bx + si ], alplace_0082fh:
    add     byte ptr ds:[ bx + si ], alplace_00831h:
    add     byte ptr ds:[ bx + si ], alplace_00833h:
    add     byte ptr ds:[ bx + si ], alplace_00835h:
    add     byte ptr ds:[ bx + si ], alplace_00837h:
    add     byte ptr ds:[ bx + si ], alplace_00839h:
    add     byte ptr ds:[ bx + si ], alplace_0083bh:
    add     byte ptr ds:[ bx + si ], alplace_0083dh:
    add     byte ptr ds:[ bx + si ], alplace_0083fh:
    add     byte ptr ds:[ bx + si ], alplace_00841h:
    add     byte ptr ds:[ bx + si ], alplace_00843h:
    add     byte ptr ds:[ bx + si ], alplace_00845h:
    add     byte ptr ds:[ bx + si ], alplace_00847h:
    add     byte ptr ds:[ bx + si ], alplace_00849h:
    add     byte ptr ds:[ bx + si ], alplace_0084bh:
    add     byte ptr ds:[ bx + si ], alplace_0084dh:
    add     byte ptr ds:[ bx + si ], alplace_0084fh:
    add     byte ptr ds:[ bx + si ], alplace_00851h:
    add     byte ptr ds:[ bx + si ], alplace_00853h:
    add     byte ptr ds:[ bx + si ], alplace_00855h:
    add     byte ptr ds:[ bx + si ], alplace_00857h:
    add     byte ptr ds:[ bx + si ], alplace_00859h:
    add     byte ptr ds:[ bx + si ], alplace_0085bh:
    add     byte ptr ds:[ bx + si ], alplace_0085dh:
    add     byte ptr ds:[ bx + si ], alplace_0085fh:
    add     byte ptr ds:[ bx + si ], alplace_00861h:
    add     byte ptr ds:[ bx + si ], alplace_00863h:
    add     byte ptr ds:[ bx + si ], alplace_00865h:
    add     byte ptr ds:[ bx + si ], alplace_00867h:
    add     byte ptr ds:[ bx + si ], alplace_00869h:
    add     byte ptr ds:[ bx + si ], alplace_0086bh:
    add     byte ptr ds:[ bx + si ], alplace_0086dh:
    add     byte ptr ds:[ bx + si ], alplace_0086fh:
    add     byte ptr ds:[ bx + si ], alplace_00871h:
    add     byte ptr ds:[ bx + si ], alplace_00873h:
    add     byte ptr ds:[ bx + si ], alplace_00875h:
    add     byte ptr ds:[ bx + si ], alplace_00877h:
    add     byte ptr ds:[ bx + si ], alplace_00879h:
    add     byte ptr ds:[ bx + si ], alplace_0087bh:
    add     byte ptr ds:[ bx + si ], alplace_0087dh:
    add     byte ptr ds:[ bx + si ], alplace_0087fh:
    add     byte ptr ds:[ bx + si ], alplace_00881h:
    add     byte ptr ds:[ bx + si ], alplace_00883h:
    add     byte ptr ds:[ bx + si ], alplace_00885h:
    add     byte ptr ds:[ bx + si ], alplace_00887h:
    add     byte ptr ds:[ bx + si ], alplace_00889h:
    add     byte ptr ds:[ bx + si ], alplace_0088bh:
    add     byte ptr ds:[ bx + si ], alplace_0088dh:
    add     byte ptr ds:[ bx + si ], alplace_0088fh:
    add     byte ptr ds:[ bx + si ], alplace_00891h:
    add     byte ptr ds:[ bx + si ], alplace_00893h:
    add     byte ptr ds:[ bx + si ], alplace_00895h:
    add     byte ptr ds:[ bx + si ], alplace_00897h:
    add     byte ptr ds:[ bx + si ], alplace_00899h:
    add     byte ptr ds:[ bx + si ], alplace_0089bh:
    add     byte ptr ds:[ bx + si ], alplace_0089dh:
    add     byte ptr ds:[ bx + si ], alplace_0089fh:
    add     byte ptr ds:[ bx + si ], alplace_008a1h:
    add     byte ptr ds:[ bx + si ], alplace_008a3h:
    add     byte ptr ds:[ bx + si ], alplace_008a5h:
    add     byte ptr ds:[ bx + si ], alplace_008a7h:
    add     byte ptr ds:[ bx + si ], alplace_008a9h:
    add     byte ptr ds:[ bx + si ], alplace_008abh:
    add     byte ptr ds:[ bx + si ], alplace_008adh:
    add     byte ptr ds:[ bx + si ], alplace_008afh:
    add     byte ptr ds:[ bx + si ], alplace_008b1h:
    add     byte ptr ds:[ bx + si ], alplace_008b3h:
    add     byte ptr ds:[ bx + si ], alplace_008b5h:
    add     byte ptr ds:[ bx + si ], alplace_008b7h:
    add     byte ptr ds:[ bx + si ], alplace_008b9h:
    add     byte ptr ds:[ bx + si ], alplace_008bbh:
    add     byte ptr ds:[ bx + si ], alplace_008bdh:
    add     byte ptr ds:[ bx + si ], alplace_008bfh:
    add     byte ptr ds:[ bx + si ], alplace_008c1h:
    add     byte ptr ds:[ bx + si ], alplace_008c3h:
    add     byte ptr ds:[ bx + si ], alplace_008c5h:
    add     byte ptr ds:[ bx + si ], alplace_008c7h:
    add     byte ptr ds:[ bx + si ], alplace_008c9h:
    add     byte ptr ds:[ bx + si ], alplace_008cbh:
    add     byte ptr ds:[ bx + si ], alplace_008cdh:
    add     byte ptr ds:[ bx + si ], alplace_008cfh:
    add     byte ptr ds:[ bx + si ], alplace_008d1h:
    add     byte ptr ds:[ bx + si ], alplace_008d3h:
    add     byte ptr ds:[ bx + si ], alplace_008d5h:
    add     byte ptr ds:[ bx + si ], alplace_008d7h:
    add     byte ptr ds:[ bx + si ], alplace_008d9h:
    add     byte ptr ds:[ bx + si ], alplace_008dbh:
    add     byte ptr ds:[ bx + si ], alplace_008ddh:
    add     byte ptr ds:[ bx + si ], alplace_008dfh:
    add     byte ptr ds:[ bx + si ], alplace_008e1h:
    add     byte ptr ds:[ bx + si ], alplace_008e3h:
    add     byte ptr ds:[ bx + si ], alplace_008e5h:
    add     byte ptr ds:[ bx + si ], alplace_008e7h:
    add     byte ptr ds:[ bx + si ], alplace_008e9h:
    add     byte ptr ds:[ bx + si ], alplace_008ebh:
    add     byte ptr ds:[ bx + si ], alplace_008edh:
    add     byte ptr ds:[ di ], clplace_008efh:
    or      al, byte ptr ds:[ bx + si ]place_008f1h:
    add     byte ptr ds:[ bx + si ], alplace_008f3h:
    add     byte ptr ds:[ bx + si ], alplace_008f5h:
    add     byte ptr ds:[ bx + si ], alplace_008f7h:
    add     byte ptr ds:[ bx + si ], alplace_008f9h:
    add     byte ptr ds:[ bx + si ], alplace_008fbh:
    add     byte ptr ds:[ bx + si ], alplace_008fdh:
    add     byte ptr ds:[ bx + si ], al;;  SCANNING...
place_008ffh:
    add     byte ptr ds:[ bx + si ], alplace_00901h:
    add     byte ptr ds:[ bx + si ], alplace_00903h:
    add     byte ptr ds:[ bx + si ], alplace_00905h:
    add     byte ptr ds:[ bx + si ], alplace_00907h:
    add     byte ptr ds:[ bx + si ], alplace_00909h:
    add     byte ptr ds:[ bx + si ], alplace_0090bh:
    add     byte ptr ds:[ bx + si ], alplace_0090dh:
    add     byte ptr ds:[ bx + si ], alplace_0090fh:
    add     byte ptr ds:[ bx + si ], alplace_00911h:
    add     byte ptr ds:[ bx + si ], alplace_00913h:
    add     byte ptr ds:[ bx + si ], alplace_00915h:
    add     byte ptr ds:[ bx + si ], alplace_00917h:
    add     byte ptr ds:[ bx + si ], alplace_00919h:
    add     byte ptr ds:[ bx + si ], alplace_0091bh:
    add     byte ptr ds:[ bx + si ], alplace_0091dh:
    add     byte ptr ds:[ bx + si ], alplace_0091fh:
    add     byte ptr ds:[ bx + si ], alplace_00921h:
    add     byte ptr ds:[ bx + si ], alplace_00923h:
    add     byte ptr ds:[ bx + si ], alplace_00925h:
    add     byte ptr ds:[ bx + si ], alplace_00927h:
    add     byte ptr ds:[ bx + si ], alplace_00929h:
    add     byte ptr ds:[ bx + si ], alplace_0092bh:
    add     byte ptr ds:[ bx + si ], alplace_0092dh:
    add     byte ptr ds:[ bx + si ], alplace_0092fh:
    add     byte ptr ds:[ bx + si ], alplace_00931h:
    add     byte ptr ds:[ bx + si ], alplace_00933h:
    add     byte ptr ds:[ bx + si ], alplace_00935h:
    add     byte ptr ds:[ bx + si ], alplace_00937h:
    add     byte ptr ds:[ bx + si ], alplace_00939h:
    add     byte ptr ds:[ bx + si ], alplace_0093bh:
    add     byte ptr ds:[ bx + si ], alplace_0093dh:
    add     byte ptr ds:[ bx + si ], alplace_0093fh:
    add     byte ptr ds:[ bx + si ], alplace_00941h:
    add     byte ptr ds:[ bx + si ], alplace_00943h:
    add     byte ptr ds:[ bx + si ], alplace_00945h:
    add     byte ptr ds:[ bx + si ], alplace_00947h:
    add     byte ptr ds:[ bx + si ], alplace_00949h:
    add     byte ptr ds:[ bx + si ], alplace_0094bh:
    add     byte ptr ds:[ bx + si ], alplace_0094dh:
    add     byte ptr ds:[ bx + si ], alplace_0094fh:
    add     byte ptr ds:[ bx + si ], alplace_00951h:
    add     byte ptr ds:[ bx + si ], alplace_00953h:
    add     byte ptr ds:[ bx + si ], alplace_00955h:
    add     byte ptr ds:[ bx + si ], alplace_00957h:
    add     byte ptr ds:[ bx + si ], alplace_00959h:
    add     byte ptr ds:[ bx + si ], alplace_0095bh:
    add     byte ptr ds:[ bx + si ], alplace_0095dh:
    add     byte ptr ds:[ bx + si ], alplace_0095fh:
    add     byte ptr ds:[ bx + si ], alplace_00961h:
    add     byte ptr ds:[ bx + si ], alplace_00963h:
    add     byte ptr ds:[ bx + si ], alplace_00965h:
    add     byte ptr ds:[ bx + si ], alplace_00967h:
    add     byte ptr ds:[ bx + si ], alplace_00969h:
    add     byte ptr ds:[ bx + si ], alplace_0096bh:
    add     byte ptr ds:[ bx + si ], alplace_0096dh:
    add     byte ptr ds:[ bx + si ], alplace_0096fh:
    add     byte ptr ds:[ bx + si ], alplace_00971h:
    add     byte ptr ds:[ bx + si ], alplace_00973h:
    add     byte ptr ds:[ bx + si ], alplace_00975h:
    add     byte ptr ds:[ bx + si ], alplace_00977h:
    add     byte ptr ds:[ bx + si ], alplace_00979h:
    add     byte ptr ds:[ bx + si ], alplace_0097bh:
    add     byte ptr ds:[ bx + si ], alplace_0097dh:
    add     byte ptr ds:[ bx + si ], alplace_0097fh:
    add     byte ptr ds:[ bx + si ], alplace_00981h:
    add     byte ptr ds:[ bx + si ], alplace_00983h:
    add     byte ptr ds:[ bx + si ], alplace_00985h:
    add     byte ptr ds:[ bx + si ], alplace_00987h:
    add     byte ptr ds:[ bx + si ], alplace_00989h:
    add     byte ptr ds:[ bx + si ], alplace_0098bh:
    add     byte ptr ds:[ bx + si ], alplace_0098dh:
    add     byte ptr ds:[ bx + si ], alplace_0098fh:
    add     byte ptr ds:[ bx + si ], alplace_00991h:
    add     byte ptr ds:[ bx + si ], alplace_00993h:
    add     byte ptr ds:[ bx + si ], alplace_00995h:
    add     byte ptr ds:[ bx + si ], alplace_00997h:
    add     byte ptr ds:[ bx + si ], alplace_00999h:
    add     byte ptr ds:[ bx + si ], alplace_0099bh:
    add     byte ptr ds:[ bx + si ], alplace_0099dh:
    add     byte ptr ds:[ bx + si ], alplace_0099fh:
    add     byte ptr ds:[ bx + si ], alplace_009a1h:
    add     byte ptr ds:[ bx + si ], alplace_009a3h:
    add     byte ptr ds:[ bx + si ], alplace_009a5h:
    add     byte ptr ds:[ bx + si ], alplace_009a7h:
    add     byte ptr ds:[ bx + si ], alplace_009a9h:
    add     byte ptr ds:[ bx + si ], alplace_009abh:
    add     byte ptr ds:[ bx + si ], alplace_009adh:
    add     byte ptr ds:[ bx + si ], alplace_009afh:
    add     byte ptr ds:[ bx + si ], alplace_009b1h:
    add     byte ptr ds:[ bx + si ], alplace_009b3h:
    add     byte ptr ds:[ bx + si ], alplace_009b5h:
    add     byte ptr ds:[ bx + si ], alplace_009b7h:
    add     byte ptr ds:[ bx + si ], alplace_009b9h:
    add     byte ptr ds:[ bx + si ], alplace_009bbh:
    add     byte ptr ds:[ bx + si ], alplace_009bdh:
    add     byte ptr ds:[ bx + si ], alplace_009bfh:
    add     byte ptr ds:[ bx + si ], alplace_009c1h:
    add     byte ptr ds:[ bx + si ], alplace_009c3h:
    add     byte ptr ds:[ bx + si ], alplace_009c5h:
    add     byte ptr ds:[ bx + si ], alplace_009c7h:
    add     byte ptr ds:[ bx + si ], alplace_009c9h:
    add     byte ptr ds:[ bx + si ], alplace_009cbh:
    add     byte ptr ds:[ bx + si ], alplace_009cdh:
    add     byte ptr ds:[ bx + si ], alplace_009cfh:
    add     byte ptr ds:[ bx + si ], alplace_009d1h:
    add     byte ptr ds:[ bx + si ], alplace_009d3h:
    add     byte ptr ds:[ bx + si ], alplace_009d5h:
    add     byte ptr ds:[ bx + si ], alplace_009d7h:
    add     byte ptr ds:[ bx + si ], alplace_009d9h:
    add     byte ptr ds:[ bx + si ], alplace_009dbh:
    add     byte ptr ds:[ bx + si ], alplace_009ddh:
    add     byte ptr ds:[ bx + si ], alplace_009dfh:
    add     byte ptr ds:[ bx + si ], alplace_009e1h:
    add     byte ptr ds:[ bx + si ], alplace_009e3h:
    add     byte ptr ds:[ bx + si ], alplace_009e5h:
    add     byte ptr ds:[ bx + si ], alplace_009e7h:
    add     byte ptr ds:[ bx + si ], alplace_009e9h:
    add     byte ptr ds:[ bx + si ], alplace_009ebh:
    add     byte ptr ds:[ bx + si ], alplace_009edh:
    add     byte ptr ds:[ bx + si ], alplace_009efh:
    add     byte ptr ds:[ bx + si ], alplace_009f1h:
    add     byte ptr ds:[ bx + si ], alplace_009f3h:
    add     byte ptr ds:[ bx + si ], alplace_009f5h:
    add     byte ptr ds:[ bx + si ], alplace_009f7h:
    add     byte ptr ds:[ bx + si ], alplace_009f9h:
    add     byte ptr ds:[ bx + si ], alplace_009fbh:
    add     byte ptr ds:[ bx + si ], alplace_009fdh:
    add     byte ptr ds:[ bx + si ], al;;  SCANNING...
place_009ffh:
    add     byte ptr ds:[ bx + si ], alplace_00a01h:
    add     byte ptr ds:[ bx + si ], alplace_00a03h:
    add     byte ptr ds:[ bx + si ], alplace_00a05h:
    add     byte ptr ds:[ bx + si ], alplace_00a07h:
    add     byte ptr ds:[ bx + si ], alplace_00a09h:
    add     byte ptr ds:[ bx + si ], alplace_00a0bh:
    add     byte ptr ds:[ bx + si ], alplace_00a0dh:
    add     byte ptr ds:[ bx + si ], alplace_00a0fh:
    add     byte ptr ds:[ bx + si ], alplace_00a11h:
    add     byte ptr ds:[ bx + si ], alplace_00a13h:
    add     byte ptr ds:[ bx + si ], alplace_00a15h:
    add     byte ptr ds:[ bx + si ], alplace_00a17h:
    add     byte ptr ds:[ bx + si ], alplace_00a19h:
    add     byte ptr ds:[ bx + si ], alplace_00a1bh:
    add     byte ptr ds:[ bx + si ], alplace_00a1dh:
    add     byte ptr ds:[ bx + si ], alplace_00a1fh:
    add     byte ptr ds:[ bx + si ], alplace_00a21h:
    inc     spplace_00a22h:
;;  UNKNOWN instructionplace_00a23h:
;;  UNKNOWN instructionplace_00a24h:
    jne     place_00a8dhplace_00a26h:
    and     byte ptr ds:[ di + 065h ], chplace_00a29h:
    jae     place_00a9ehplace_00a2bh:
    popa    place_00a2ch:
;;  UNKNOWN instructionplace_00a2dh:
;;  UNKNOWN instructionplace_00a2eh:
    or      ax, 0240ahplace_00a31h:
    das     place_00a32h:
    aas     place_00a33h:
    add     byte ptr ds:[ bx ], chplace_00a35h:
;;  UNKNOWN instructionplace_00a36h:
    add     byte ptr ds:[ bx ], chplace_00a38h:
    dec     axplace_00a39h:
    add     byte ptr ds:[ di ], chplace_00a3bh:
;;  UNKNOWN instructionplace_00a3ch:
    add     byte ptr ds:[ di ], chplace_00a3eh:
    dec     axplace_00a3fh:
    add     byte ptr ds:[ di ], chplace_00a41h:
    sub     ax, 06568hplace_00a44h:
    insb    place_00a45h:
    jo      place_00a47hplace_00a47h:
    push    axplace_00a48h:
    jb      place_00aafhplace_00a4ah:
    jae     place_00abfhplace_00a4ch:
    and     byte ptr ds:[ bx + di + 06eh ], ahplace_00a4fh:
    jns     place_00a71hplace_00a51h:
;;  UNKNOWN instructionplace_00a52h:
;;  UNKNOWN instructionplace_00a53h:
    jns     place_00a75hplace_00a55h:
    je      place_00ac6hplace_00a57h:
    and     byte ptr ds:[ bp + di + 06fh ], ahplace_00a5ah:
    outsb   place_00a5bh:
    je      place_00ac6hplace_00a5dh:
    outsb   place_00a5eh:
    jne     place_00ac5hplace_00a60h:
    and     al, 00dhplace_00a65h:
    and     byte ptr cs:[ bx + si ], ahplace_00a67h:
    and     byte ptr ds:[ bx + si ], ahplace_00a69h:
    and     byte ptr ds:[ bx + si ], ahplace_00a6bh:
    and     byte ptr ds:[ bx + si ], ahplace_00a6dh:
    and     byte ptr ds:[ bx + si ], ahplace_00a6fh:
    and     byte ptr ds:[ bx + si ], ahplace_00a71h:
    and     byte ptr ds:[ bx + si ], ahplace_00a73h:
    and     byte ptr ds:[ bx + si ], ahplace_00a75h:
    and     byte ptr ds:[ bx + si ], ahplace_00a77h:
    and     byte ptr ds:[ bx + si ], ahplace_00a79h:
    and     byte ptr ds:[ bx + si ], ahplace_00a7bh:
    and     byte ptr ds:[ bx + si ], ahplace_00a7dh:
    and     byte ptr ds:[ bx + si ], ahplace_00a7fh:
    and     byte ptr ds:[ bx + si ], ahplace_00a81h:
    and     byte ptr ds:[ bx + si ], ahplace_00a83h:
    and     byte ptr ds:[ di ], clplace_00a85h:
    and     al, 00ahplace_00a87h:
    inc     bpplace_00a88h:
    push    dxplace_00a89h:
    push    dxplace_00a8ah:
    dec     diplace_00a8bh:
    push    dxplace_00a8ch:
    cmp     ah, byte ptr ds:[ bx + si ]place_00a8eh:
    and     al, 046hplace_00a90h:
    popa    place_00a91h:
;;  UNKNOWN instructionplace_00a92h:
    insb    place_00a93h:
;;  UNKNOWN instructionplace_00a94h:
;;  UNKNOWN instructionplace_00a95h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00a98h:
    and     byte ptr ds:[ bx + 070h ], chplace_00a9bh:
;;  UNKNOWN instructionplace_00a9ch:
    outsb   place_00a9dh:
    and     byte ptr ds:[ bp + 069h ], ahplace_00aa0h:
    insb    place_00aa1h:
;;  UNKNOWN instructionplace_00aa2h:
    and     word ptr ds:[ di ], cxplace_00aa4h:
    or      cl, byte ptr ds:[ bp + si ]place_00aa6h:
    and     al, 046hplace_00aa8h:
    popa    place_00aa9h:
;;  UNKNOWN instructionplace_00aaah:
    insb    place_00aabh:
;;  UNKNOWN instructionplace_00aach:
;;  UNKNOWN instructionplace_00aadh:
    and     byte ptr ds:[ si + 06fh ], dhplace_00ab0h:
    and     byte ptr ds:[ bp + di + 072h ], ahplace_00ab3h:
;;  UNKNOWN instructionplace_00ab4h:
    popa    place_00ab5h:
    je      place_00b1chplace_00ab7h:
    and     byte ptr ds:[ bp + 069h ], ahplace_00abah:
    insb    place_00abbh:
;;  UNKNOWN instructionplace_00abch:
    and     word ptr ds:[ di ], cxplace_00abeh:
    or      cl, byte ptr ds:[ bp + si ]place_00ac0h:
    and     al, 046hplace_00ac2h:
    popa    place_00ac3h:
;;  UNKNOWN instructionplace_00ac4h:
    insb    place_00ac5h:
;;  UNKNOWN instructionplace_00ac6h:
;;  UNKNOWN instructionplace_00ac7h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00acah:
    and     byte ptr ds:[ bp + si + 065h ], dhplace_00acdh:
    popa    place_00aceh:
;;  UNKNOWN instructionplace_00acfh:
    and     byte ptr ds:[ bp + 069h ], ahplace_00ad2h:
    insb    place_00ad3h:
;;  UNKNOWN instructionplace_00ad4h:
    and     word ptr ds:[ di ], cxplace_00ad6h:
    or      cl, byte ptr ds:[ bp + si ]place_00ad8h:
    and     al, 046hplace_00adah:
    popa    place_00adbh:
;;  UNKNOWN instructionplace_00adch:
    insb    place_00addh:
;;  UNKNOWN instructionplace_00adeh:
;;  UNKNOWN instructionplace_00adfh:
    and     byte ptr ds:[ si + 06fh ], dhplace_00ae2h:
    and     byte ptr ds:[ bx + 072h ], dhplace_00ae5h:
;;  UNKNOWN instructionplace_00ae6h:
    je      place_00b4dhplace_00ae8h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00aebh:
    and     byte ptr ds:[ bp + 069h ], ahplace_00aeeh:
    insb    place_00aefh:
;;  UNKNOWN instructionplace_00af0h:
    and     word ptr ds:[ di ], cxplace_00af2h:
    or      cl, byte ptr ds:[ bp + si ]place_00af4h:
    and     al, 050hplace_00af6h:
    popa    place_00af7h:
    jb      place_00b5ahplace_00af9h:
    insw    place_00afah:
;;  UNKNOWN instructionplace_00afbh:
    je      place_00b62hplace_00afdh:
    jb      place_00b72h;;  SCANNING...
place_00affh:
    and     byte ptr ds:[ bx + di + 072h ], ahplace_00b02h:
;;  UNKNOWN instructionplace_00b03h:
    and     byte ptr ds:[ bp + 06fh ], chplace_00b06h:
    je      place_00b28hplace_00b08h:
    jae     place_00b7ahplace_00b0ah:
;;  UNKNOWN instructionplace_00b0bh:
;;  UNKNOWN instructionplace_00b0ch:
;;  UNKNOWN instructionplace_00b0dh:
;;  UNKNOWN instructionplace_00b0eh:
;;  UNKNOWN instructionplace_00b0fh:
;;  UNKNOWN instructionplace_00b10h:
;;  UNKNOWN instructionplace_00b11h:
    and     word ptr ds:[ di ], cxplace_00b13h:
    or      cl, byte ptr ds:[ bp + si ]place_00b15h:
    and     al, 054hplace_00b17h:
    outsw   place_00b18h:
    outsw   place_00b19h:
    and     byte ptr ds:[ di + 061h ], chplace_00b1ch:
    outsb   place_00b1dh:
    jns     place_00b3fhplace_00b1fh:
    jo      place_00b82hplace_00b21h:
    jb      place_00b84hplace_00b23h:
    insw    place_00b24h:
;;  UNKNOWN instructionplace_00b25h:
    je      place_00b8chplace_00b27h:
    jb      place_00b9chplace_00b29h:
    and     word ptr ds:[ di ], cxplace_00b2bh:
    or      cl, byte ptr ds:[ bp + si ]place_00b2dh:
    and     al, 049hplace_00b2fh:
    outsb   place_00b30h:
    jbe     place_00b93hplace_00b32h:
    insb    place_00b33h:
;;  UNKNOWN instructionplace_00b34h:
;;  UNKNOWN instructionplace_00b35h:
    and     byte ptr ds:[ si + 069h ], chplace_00b38h:
    outsb   place_00b39h:
;;  UNKNOWN instructionplace_00b3ah:
    and     byte ptr ds:[ si + 065h ], chplace_00b3dh:
    outsb   place_00b3eh:
;;  UNKNOWN instructionplace_00b3fh:
    je      place_00ba9hplace_00b41h:
    and     word ptr ds:[ bx + si ], spplace_00b43h:
    inc     bxplace_00b44h:
    popa    place_00b45h:
    outsb   place_00b46h:
    daa     place_00b47h:
    je      place_00b69hplace_00b49h:
;;  UNKNOWN instructionplace_00b4ah:
    popa    place_00b4bh:
    jbe     place_00bb2hplace_00b4dh:
    and     byte ptr ds:[ bp + di + 079h ], dhplace_00b50h:
    insw    place_00b51h:
;;  UNKNOWN instructionplace_00b52h:
    outsw   place_00b53h:
    insb    place_00b54h:
    jae     place_00b76hplace_00b56h:
    outsw   place_00b57h:
    jb      place_00b79hplace_00b59h:
    outsb   place_00b5ah:
    jne     place_00bc9hplace_00b5ch:
;;  UNKNOWN instructionplace_00b5dh:
;;  UNKNOWN instructionplace_00b5eh:
    jb      place_00b80hplace_00b60h:
;;  UNKNOWN instructionplace_00b61h:
    jno     place_00bd8hplace_00b63h:
    popa    place_00b64h:
    insb    place_00b65h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00b68h:
    and     byte ptr ds:[ bp + si + 065h ], bhplace_00b6bh:
    jb      place_00bdchplace_00b6dh:
    and     word ptr ds:[ bx + di ], spplace_00b6fh:
    and     word ptr ds:[ di ], cxplace_00b71h:
    or      cl, byte ptr ds:[ bp + si ]place_00b73h:
    and     al, 04chplace_00b75h:
;;  UNKNOWN instructionplace_00b76h:
    outsb   place_00b77h:
;;  UNKNOWN instructionplace_00b78h:
    and     byte ptr ds:[ si + 065h ], chplace_00b7bh:
    outsb   place_00b7ch:
;;  UNKNOWN instructionplace_00b7dh:
    je      place_00be7hplace_00b7fh:
    and     byte ptr ds:[ bx + di + 073h ], chplace_00b82h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00b85h:
    outsw   place_00b86h:
    and     byte ptr ds:[ bp + si + 069h ], ahplace_00b89h:
;;  UNKNOWN instructionplace_00b8ah:
    and     word ptr ds:[ bx + si ], spplace_00b8ch:
    push    bxplace_00b8dh:
;;  UNKNOWN instructionplace_00b8eh:
    outsw   place_00b8fh:
    jne     place_00bfdhplace_00b91h:
;;  UNKNOWN instructionplace_00b92h:
    and     byte ptr ds:[ bp + si + 065h ], ahplace_00b95h:
    and     byte ptr ds:[ bp + si ], dhplace_00b97h:
    xor     ax, 02035hplace_00b9ah:
    outsw   place_00b9bh:
    jb      place_00bbdhplace_00b9dh:
    insb    place_00b9eh:
;;  UNKNOWN instructionplace_00b9fh:
    jae     place_00c14hplace_00ba1h:
    and     word ptr ds:[ bx + di ], spplace_00ba3h:
    and     word ptr ds:[ di ], cxplace_00ba5h:
    or      cl, byte ptr ds:[ bp + si ]place_00ba7h:
    and     al, 048hplace_00ba9h:
    inc     bpplace_00baah:
    dec     spplace_00babh:
    push    axplace_00bach:
    and     byte ptr ds:[ di ], chplace_00baeh:
    sub     ax, 04820hplace_00bb1h:
    inc     bpplace_00bb2h:
    dec     spplace_00bb3h:
    push    axplace_00bb4h:
    and     byte ptr ds:[ di ], chplace_00bb6h:
    sub     ax, 04820hplace_00bb9h:
    inc     bpplace_00bbah:
    dec     spplace_00bbbh:
    push    axplace_00bbch:
    and     byte ptr ds:[ di ], chplace_00bbeh:
    sub     ax, 04820hplace_00bc1h:
    inc     bpplace_00bc2h:
    dec     spplace_00bc3h:
    push    axplace_00bc4h:
    and     byte ptr ds:[ di ], chplace_00bc6h:
    sub     ax, 04820hplace_00bc9h:
    inc     bpplace_00bcah:
    dec     spplace_00bcbh:
    push    axplace_00bcch:
    and     byte ptr ds:[ di ], chplace_00bceh:
    sub     ax, 04820hplace_00bd1h:
    inc     bpplace_00bd2h:
    dec     spplace_00bd3h:
    push    axplace_00bd4h:
    and     byte ptr ds:[ di ], chplace_00bd6h:
    sub     ax, 04820hplace_00bd9h:
    inc     bpplace_00bdah:
    dec     spplace_00bdbh:
    push    axplace_00bdch:
    and     byte ptr ds:[ di ], chplace_00bdeh:
    sub     ax, 04820hplace_00be1h:
    inc     bpplace_00be2h:
    dec     spplace_00be3h:
    push    axplace_00be4h:
    and     byte ptr ds:[ di ], chplace_00be6h:
    sub     ax, 04820hplace_00be9h:
    inc     bpplace_00beah:
    dec     spplace_00bebh:
    push    axplace_00bech:
    and     byte ptr ds:[ di ], chplace_00beeh:
    sub     ax, 04820hplace_00bf1h:
    inc     bpplace_00bf2h:
    dec     spplace_00bf3h:
    push    axplace_00bf4h:
    or      ax, 00d0ahplace_00bf7h:
    or      ah, byte ptr ds:[ si ]place_00bf9h:
    dec     siplace_00bfah:
    inc     cxplace_00bfbh:
    dec     bpplace_00bfch:
    inc     bpplace_00bfdh:
    or      ax, 0200ah;;  SCANNING...
place_00c00h:
    and     byte ptr ds:[ bx + si ], ahplace_00c02h:
    and     byte ptr ds:[ bx + si ], ahplace_00c04h:
    and     byte ptr ds:[ bx + si ], ahplace_00c06h:
    popa    place_00c07h:
    outsb   place_00c08h:
    je      place_00c7chplace_00c0ah:
    popa    place_00c0bh:
    and     byte ptr ds:[ di ], chplace_00c0dh:
    and     byte ptr ds:[ bp + di + 070h ], dlplace_00c10h:
    insb    place_00c11h:
;;  UNKNOWN instructionplace_00c12h:
    je      place_00c34hplace_00c14h:
    je      place_00c7bhplace_00c16h:
    js      place_00c8chplace_00c18h:
    and     byte ptr ds:[ bp + 069h ], ahplace_00c1bh:
    insb    place_00c1ch:
;;  UNKNOWN instructionplace_00c1dh:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_00c20h:
    je      place_00c91hplace_00c22h:
    and     byte ptr ds:[ si + 069h ], chplace_00c25h:
    outsb   place_00c26h:
;;  UNKNOWN instructionplace_00c27h:
    jae     place_00c49hplace_00c29h:
    outsw   place_00c2ah:
;;  UNKNOWN instructionplace_00c2bh:
    and     byte ptr ds:[ bp + di + 070h ], dhplace_00c2eh:
;;  UNKNOWN instructionplace_00c2fh:
;;  UNKNOWN instructionplace_00c30h:
;;  UNKNOWN instructionplace_00c31h:
;;  UNKNOWN instructionplace_00c32h:
;;  UNKNOWN instructionplace_00c33h:
;;  UNKNOWN instructionplace_00c34h:
;;  UNKNOWN instructionplace_00c35h:
    and     byte ptr ds:[ di + 061h ], chplace_00c38h:
    js      place_00ca3hplace_00c3ah:
    insw    place_00c3bh:
    jne     place_00caahplace_00c3dh:
    and     byte ptr ds:[ si + 065h ], chplace_00c40h:
    outsb   place_00c41h:
;;  UNKNOWN instructionplace_00c42h:
    je      place_00cachplace_00c44h:
    or      ax, 0200ahplace_00c47h:
    and     byte ptr ds:[ bx + si ], ahplace_00c49h:
    and     byte ptr ds:[ bx + si ], ahplace_00c4bh:
    and     byte ptr ds:[ bx + si ], ahplace_00c4dh:
    popa    place_00c4eh:
    outsb   place_00c4fh:
;;  UNKNOWN instructionplace_00c50h:
    and     byte ptr ds:[ bx + 072h ], dhplace_00c53h:
;;  UNKNOWN instructionplace_00c54h:
    je      place_00cbbhplace_00c56h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00c59h:
    and     byte ptr ds:[ bx + di + 020h ], ahplace_00c5ch:
    outsb   place_00c5dh:
;;  UNKNOWN instructionplace_00c5eh:
    ja      place_00c80hplace_00c60h:
;;  UNKNOWN instructionplace_00c61h:
;;  UNKNOWN instructionplace_00c62h:
    insb    place_00c63h:
;;  UNKNOWN instructionplace_00c64h:
    or      ax, 00d0ahplace_00c68h:
    or      ah, byte ptr cs:[ si ]place_00c6ah:
    push    bxplace_00c6bh:
    pop     cxplace_00c6ch:
    dec     siplace_00c6dh:
    dec     diplace_00c6eh:
    push    axplace_00c6fh:
    push    bxplace_00c70h:
    dec     cxplace_00c71h:
    push    bxplace_00c72h:
    or      ax, 0200ahplace_00c75h:
    and     byte ptr ds:[ bx + si ], ahplace_00c77h:
    and     byte ptr ds:[ bx + si ], ahplace_00c79h:
    and     byte ptr ds:[ bx + si ], ahplace_00c7bh:
    popa    place_00c7ch:
    outsb   place_00c7dh:
    je      place_00cf1hplace_00c7fh:
    popa    place_00c80h:
    and     byte ptr ds:[ bx + di + 04eh ], clplace_00c83h:
    push    axplace_00c84h:
    push    bpplace_00c85h:
    push    spplace_00c86h:
    pop     diplace_00c87h:
    inc     siplace_00c88h:
    dec     cxplace_00c89h:
    dec     spplace_00c8ah:
    inc     bpplace_00c8bh:
    and     byte ptr ds:[ di + 041h ], clplace_00c8eh:
    pop     axplace_00c8fh:
    pop     diplace_00c90h:
    dec     spplace_00c91h:
    dec     cxplace_00c92h:
    dec     siplace_00c93h:
    inc     bpplace_00c94h:
    pop     diplace_00c95h:
    dec     spplace_00c96h:
    inc     bpplace_00c97h:
    dec     siplace_00c98h:
    inc     diplace_00c99h:
    push    spplace_00c9ah:
    dec     axplace_00c9bh:
    and     byte ptr ds:[ bx + 055h ], clplace_00c9eh:
    push    spplace_00c9fh:
    push    axplace_00ca0h:
    push    bpplace_00ca1h:
    push    spplace_00ca2h:
    pop     diplace_00ca3h:
    inc     siplace_00ca4h:
    dec     cxplace_00ca5h:
    dec     spplace_00ca6h:
    inc     bpplace_00ca7h:
    or      ax, 00d0ahplace_00caah:
    or      ah, byte ptr ds:[ bx + si ]place_00cach:
    and     byte ptr ds:[ bx + si ], ahplace_00caeh:
    and     byte ptr ds:[ bx + si ], ahplace_00cb0h:
    and     byte ptr ds:[ bx + si ], ahplace_00cb2h:
    popa    place_00cb3h:
    outsb   place_00cb4h:
    je      place_00d28hplace_00cb6h:
    popa    place_00cb7h:
    and     byte ptr ds:[ bx ], chplace_00cb9h:
    aas     place_00cbah:
    or      ax, 00d0ahplace_00cbdh:
    or      ah, byte ptr ds:[ bx + si ]place_00cbfh:
    and     byte ptr ds:[ bx + si ], ahplace_00cc1h:
    and     byte ptr ds:[ bx + si ], ahplace_00cc3h:
    and     byte ptr ds:[ bx + si ], ahplace_00cc5h:
    popa    place_00cc6h:
    outsb   place_00cc7h:
    je      place_00d3bhplace_00cc9h:
    popa    place_00ccah:
    and     byte ptr ds:[ bx ], chplace_00ccch:
;;  UNKNOWN instructionplace_00ccdh:
    or      ax, 00d0ahplace_00cd0h:
    or      ah, byte ptr ds:[ bx + si ]place_00cd2h:
    and     byte ptr ds:[ bx + si ], ahplace_00cd4h:
    and     byte ptr ds:[ bx + si ], ahplace_00cd6h:
    and     byte ptr ds:[ bx + si ], ahplace_00cd8h:
    popa    place_00cd9h:
    outsb   place_00cdah:
    je      place_00d4ehplace_00cdch:
    popa    place_00cddh:
    and     byte ptr ds:[ bx ], chplace_00cdfh:
    dec     axplace_00ce0h:
    or      ax, 00d0ahplace_00ce3h:
    or      ah, byte ptr ds:[ bx + si ]place_00ce5h:
    and     byte ptr ds:[ bx + si ], ahplace_00ce7h:
    and     byte ptr ds:[ bx + si ], ahplace_00ce9h:
    and     byte ptr ds:[ bx + si ], ahplace_00cebh:
    popa    place_00cech:
    outsb   place_00cedh:
    je      place_00d61hplace_00cefh:
    popa    place_00cf0h:
    and     byte ptr ds:[ di ], chplace_00cf2h:
;;  UNKNOWN instructionplace_00cf3h:
    or      ax, 00d0ahplace_00cf6h:
    or      ah, byte ptr ds:[ bx + si ]place_00cf8h:
    and     byte ptr ds:[ bx + si ], ahplace_00cfah:
    and     byte ptr ds:[ bx + si ], ahplace_00cfch:
    and     byte ptr ds:[ bx + si ], ahplace_00cfeh:
    popa    ;;  SCANNING...
place_00cffh:
    outsb   place_00d00h:
    je      place_00d74hplace_00d02h:
    popa    place_00d03h:
    and     byte ptr ds:[ di ], chplace_00d05h:
    dec     axplace_00d06h:
    or      ax, 00d0ahplace_00d09h:
    or      ah, byte ptr ds:[ bx + si ]place_00d0bh:
    and     byte ptr ds:[ bx + si ], ahplace_00d0dh:
    and     byte ptr ds:[ bx + si ], ahplace_00d0fh:
    and     byte ptr ds:[ bx + si ], ahplace_00d11h:
    popa    place_00d12h:
    outsb   place_00d13h:
    je      place_00d87hplace_00d15h:
    popa    place_00d16h:
    and     byte ptr ds:[ di ], chplace_00d18h:
    sub     ax, 06568hplace_00d1bh:
    insb    place_00d1ch:
    jo      place_00d2bhplace_00d1eh:
    or      cl, byte ptr ds:[ di ]place_00d20h:
    or      ah, byte ptr ds:[ si ]place_00d22h:
    inc     spplace_00d23h:
    inc     bpplace_00d24h:
    push    bxplace_00d25h:
    inc     bxplace_00d26h:
    push    dxplace_00d27h:
    dec     cxplace_00d28h:
    push    axplace_00d29h:
    push    spplace_00d2ah:
    dec     cxplace_00d2bh:
    dec     diplace_00d2ch:
    dec     siplace_00d2dh:
    or      ax, 0200ahplace_00d30h:
    and     byte ptr ds:[ bx + si ], ahplace_00d32h:
    and     byte ptr ds:[ bx + si ], ahplace_00d34h:
    and     byte ptr ds:[ bx + si ], ahplace_00d36h:
    popa    place_00d37h:
    outsb   place_00d38h:
    je      place_00dachplace_00d3ah:
    popa    place_00d3bh:
    and     byte ptr ds:[ bp + si + 065h ], dhplace_00d3eh:
    popa    place_00d3fh:
;;  UNKNOWN instructionplace_00d40h:
    jae     place_00d62hplace_00d42h:
    je      place_00dachplace_00d44h:
;;  UNKNOWN instructionplace_00d45h:
    and     byte ptr ds:[ bp + di + 06fh ], ahplace_00d48h:
    outsb   place_00d49h:
    je      place_00db0hplace_00d4bh:
    outsb   place_00d4ch:
    je      place_00dc1hplace_00d4eh:
    and     byte ptr ds:[ bx + 066h ], chplace_00d51h:
    and     byte ptr ds:[ bx + di + 04eh ], clplace_00d54h:
    push    axplace_00d55h:
    push    bpplace_00d56h:
    push    spplace_00d57h:
    pop     diplace_00d58h:
    inc     siplace_00d59h:
    dec     cxplace_00d5ah:
    dec     spplace_00d5bh:
    inc     bpplace_00d5ch:
    and     byte ptr ds:[ bx + di + 06eh ], ahplace_00d5fh:
;;  UNKNOWN instructionplace_00d60h:
    and     byte ptr ds:[ bp + di + 070h ], dhplace_00d63h:
    insb    place_00d64h:
;;  UNKNOWN instructionplace_00d65h:
    je      place_00ddahplace_00d67h:
    and     byte ptr ds:[ bx + di + 074h ], chplace_00d6ah:
    jae     place_00d8chplace_00d6ch:
    je      place_00dd3hplace_00d6eh:
    js      place_00de4hplace_00d70h:
    or      ax, 0200ahplace_00d73h:
    and     byte ptr ds:[ bx + si ], ahplace_00d75h:
    and     byte ptr ds:[ bx + si ], ahplace_00d77h:
    and     byte ptr ds:[ bx + si ], ahplace_00d79h:
;;  UNKNOWN instructionplace_00d7ah:
    outsb   place_00d7bh:
    je      place_00dechplace_00d7dh:
    and     byte ptr ds:[ si + 069h ], chplace_00d80h:
    outsb   place_00d81h:
;;  UNKNOWN instructionplace_00d82h:
    jae     place_00db0hplace_00d84h:
    and     byte ptr ds:[ di + 06eh ], ahplace_00d87h:
    jae     place_00dfehplace_00d89h:
    jb      place_00df4hplace_00d8bh:
    outsb   place_00d8ch:
;;  UNKNOWN instructionplace_00d8dh:
    and     byte ptr ds:[ di + 061h ], ahplace_00d90h:
;;  UNKNOWN instructionplace_00d91h:
;;  UNKNOWN instructionplace_00d92h:
    and     byte ptr ds:[ si + 069h ], chplace_00d95h:
    outsb   place_00d96h:
;;  UNKNOWN instructionplace_00d97h:
    and     byte ptr ds:[ si + 06fh ], ahplace_00d9ah:
;;  UNKNOWN instructionplace_00d9bh:
    jae     place_00dbdhplace_00d9dh:
    outsb   place_00d9eh:
    outsw   place_00d9fh:
    je      place_00dc1hplace_00da1h:
;;  UNKNOWN instructionplace_00da2h:
    js      place_00e07hplace_00da4h:
;;  UNKNOWN instructionplace_00da5h:
;;  UNKNOWN instructionplace_00da6h:
;;  UNKNOWN instructionplace_00da7h:
    and     byte ptr ds:[ di + 041h ], clplace_00daah:
    pop     axplace_00dabh:
    pop     diplace_00dach:
    dec     spplace_00dadh:
    dec     cxplace_00daeh:
    dec     siplace_00dafh:
    inc     bpplace_00db0h:
    pop     diplace_00db1h:
    dec     spplace_00db2h:
    inc     bpplace_00db3h:
    dec     siplace_00db4h:
    inc     diplace_00db5h:
    push    spplace_00db6h:
    dec     axplace_00db7h:
    or      ax, 0200ahplace_00dbah:
    and     byte ptr ds:[ bx + si ], ahplace_00dbch:
    and     byte ptr ds:[ bx + si ], ahplace_00dbeh:
    and     byte ptr ds:[ bx + si ], ahplace_00dc0h:
;;  UNKNOWN instructionplace_00dc1h:
;;  UNKNOWN instructionplace_00dc2h:
    popa    place_00dc3h:
    jb      place_00e26hplace_00dc5h:
;;  UNKNOWN instructionplace_00dc6h:
    je      place_00e2dhplace_00dc8h:
    jb      place_00e3dhplace_00dcah:
    and     byte ptr cs:[ si + 068h ], dlplace_00dceh:
;;  UNKNOWN instructionplace_00dcfh:
    and     byte ptr ds:[ bx + 075h ], chplace_00dd2h:
    je      place_00e44hplace_00dd4h:
    jne     place_00e4ahplace_00dd6h:
    and     byte ptr ds:[ bx + di + 073h ], chplace_00dd9h:
    and     byte ptr ds:[ bx + 072h ], dhplace_00ddch:
;;  UNKNOWN instructionplace_00dddh:
    je      place_00e53hplace_00ddfh:
;;  UNKNOWN instructionplace_00de0h:
    outsb   place_00de1h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00de4h:
    and     byte ptr ds:[ bx + 055h ], clplace_00de7h:
    push    spplace_00de8h:
    push    axplace_00de9h:
    push    bpplace_00deah:
    push    spplace_00debh:
    pop     diplace_00dech:
    inc     siplace_00dedh:
    dec     cxplace_00deeh:
    dec     spplace_00defh:
    inc     bpplace_00df0h:
;;  UNKNOWN instructionplace_00df1h:
    and     byte ptr ds:[ bx + 069h ], dhplace_00df4h:
    je      place_00e5ehplace_00df6h:
    and     byte ptr ds:[ di + 061h ], ahplace_00df9h:
;;  UNKNOWN instructionplace_00dfah:
;;  UNKNOWN instructionplace_00dfbh:
    or      ax, 0200ah;;  SCANNING...
place_00dfeh:
    and     byte ptr ds:[ bx + si ], ahplace_00e00h:
    and     byte ptr ds:[ bx + si ], ahplace_00e02h:
    and     byte ptr ds:[ bx + si ], ahplace_00e04h:
    insb    place_00e05h:
;;  UNKNOWN instructionplace_00e06h:
    outsb   place_00e07h:
;;  UNKNOWN instructionplace_00e08h:
    and     byte ptr ds:[ bp + 06fh ], ahplace_00e0bh:
    jb      place_00e7ahplace_00e0dh:
    popa    place_00e0eh:
    je      place_00e84hplace_00e10h:
;;  UNKNOWN instructionplace_00e11h:
;;  UNKNOWN instructionplace_00e12h:
    and     byte ptr ds:[ bx + di + 063h ], ahplace_00e15h:
;;  UNKNOWN instructionplace_00e16h:
    outsw   place_00e17h:
    jb      place_00e7dhplace_00e19h:
;;  UNKNOWN instructionplace_00e1ah:
    outsb   place_00e1bh:
;;  UNKNOWN instructionplace_00e1ch:
    and     byte ptr ds:[ si + 06fh ], dhplace_00e1fh:
    and     byte ptr ds:[ si + 068h ], dhplace_00e22h:
;;  UNKNOWN instructionplace_00e23h:
    and     byte ptr ds:[ bp + di + 070h ], dhplace_00e26h:
;;  UNKNOWN instructionplace_00e27h:
;;  UNKNOWN instructionplace_00e28h:
;;  UNKNOWN instructionplace_00e29h:
;;  UNKNOWN instructionplace_00e2ah:
;;  UNKNOWN instructionplace_00e2bh:
;;  UNKNOWN instructionplace_00e2ch:
;;  UNKNOWN instructionplace_00e2dh:
    and     byte ptr ds:[ si + 065h ], chplace_00e30h:
    outsb   place_00e31h:
;;  UNKNOWN instructionplace_00e32h:
    je      place_00e9chplace_00e34h:
    or      ax, 00d0ahplace_00e38h:
    or      ah, byte ptr cs:[ si ]place_00e3ah:
    and     byte ptr ds:[ bx + si ], ahplace_00e3ch:
    and     byte ptr ds:[ bx + si ], ahplace_00e3eh:
    and     byte ptr ds:[ bx + si ], ahplace_00e40h:
    and     byte ptr ds:[ di + 078h ], alplace_00e43h:
    popa    place_00e44h:
    insw    place_00e45h:
    jo      place_00eb3hplace_00e47h:
;;  UNKNOWN instructionplace_00e48h:
    cmp     cl, byte ptr ds:[ di ]place_00e4ah:
    or      ah, byte ptr ds:[ bx + si ]place_00e4ch:
    and     byte ptr ds:[ bx + si ], ahplace_00e4eh:
    and     byte ptr ds:[ bx + si ], ahplace_00e50h:
    and     byte ptr ds:[ bx + si ], ahplace_00e52h:
    and     byte ptr ds:[ bx + si ], ahplace_00e54h:
    and     byte ptr ds:[ bx + si ], ahplace_00e56h:
    and     byte ptr ds:[ bx + si ], ahplace_00e58h:
    and     byte ptr ds:[ bx + di + 066h ], clplace_00e5bh:
    and     byte ptr ds:[ bx ], ahplace_00e5dh:
;;  UNKNOWN instructionplace_00e5eh:
    jne     place_00ecfhplace_00e60h:
    insw    place_00e61h:
    je      place_00edchplace_00e64h:
    je      place_00e8dhplace_00e66h:
    and     byte ptr cs:[ bp + di + 06fh ], ahplace_00e69h:
    outsb   place_00e6ah:
    je      place_00ecdhplace_00e6ch:
;;  UNKNOWN instructionplace_00e6dh:
    outsb   place_00e6eh:
    jae     place_00e90hplace_00e70h:
    popa    place_00e71h:
    and     byte ptr ds:[ si + 06fh ], chplace_00e74h:
    outsb   place_00e75h:
;;  UNKNOWN instructionplace_00e76h:
    and     byte ptr ds:[ bp + si + 06ch ], ahplace_00e79h:
    outsw   place_00e7ah:
;;  UNKNOWN instructionplace_00e7bh:
;;  UNKNOWN instructionplace_00e7ch:
    and     byte ptr ds:[ bx + 066h ], chplace_00e7fh:
    and     byte ptr ds:[ si + 065h ], dhplace_00e82h:
    js      place_00ef8hplace_00e84h:
;;  UNKNOWN instructionplace_00e85h:
    and     byte ptr ds:[ bp + si + 075h ], dhplace_00e88h:
    outsb   place_00e89h:
    outsb   place_00e8ah:
;;  UNKNOWN instructionplace_00e8bh:
    outsb   place_00e8ch:
;;  UNKNOWN instructionplace_00e8dh:
    cmp     cl, byte ptr ds:[ di ]place_00e8fh:
    or      ah, byte ptr ds:[ bx + si ]place_00e91h:
    and     byte ptr ds:[ bx + si ], ahplace_00e93h:
    and     byte ptr ds:[ bx + si ], ahplace_00e95h:
    and     byte ptr ds:[ bx + si ], ahplace_00e97h:
    and     byte ptr ds:[ bx + si ], ahplace_00e99h:
    and     byte ptr ds:[ bx + si ], ahplace_00e9bh:
    and     byte ptr ds:[ bx + si ], ahplace_00e9dh:
    and     byte ptr ds:[ bx + si ], ahplace_00e9fh:
    and     byte ptr ds:[ bx + si ], ahplace_00ea1h:
    and     byte ptr ds:[ bx + di + 06eh ], ahplace_00ea4h:
    je      place_00f18hplace_00ea6h:
    popa    place_00ea7h:
    and     byte ptr ds:[ si + 075h ], ahplace_00eaah:
    outsw   place_00eabh:
    insw    place_00each:
    je      place_00f27hplace_00eafh:
    je      place_00ed1hplace_00eb1h:
    cmp     byte ptr cs:[ bx + si ], dhplace_00eb3h:
    and     byte ptr ds:[ bp + si + 065h ], dhplace_00eb6h:
    jp      place_00ee6hplace_00eb8h:
    je      place_00f32hplace_00ebah:
    je      place_00ec9hplace_00ebch:
    or      ah, byte ptr ds:[ bx + si ]place_00ebeh:
    and     byte ptr ds:[ bx + si ], ahplace_00ec0h:
    and     byte ptr ds:[ bx + si ], ahplace_00ec2h:
    and     byte ptr ds:[ bx + si ], ahplace_00ec4h:
    and     byte ptr ds:[ bx + si ], ahplace_00ec6h:
    and     byte ptr ds:[ bx + si ], ahplace_00ec8h:
    and     byte ptr ds:[ bx + si ], ahplace_00ecah:
    and     byte ptr ds:[ bx + 069h ], dhplace_00ecdh:
    insb    place_00eceh:
    insb    place_00ecfh:
    and     byte ptr ds:[ bp + di + 072h ], ahplace_00ed2h:
;;  UNKNOWN instructionplace_00ed3h:
    popa    place_00ed4h:
    je      place_00f3bhplace_00ed6h:
    and     byte ptr ds:[ bx ], ahplace_00ed8h:
    jb      place_00f3fhplace_00edah:
    jp      place_00f0ahplace_00edch:
    je      place_00f56hplace_00edeh:
    je      place_00f07hplace_00ee0h:
;;  UNKNOWN instructionplace_00ee1h:
    and     byte ptr ds:[ bx + 068h ], dhplace_00ee4h:
;;  UNKNOWN instructionplace_00ee5h:
    jb      place_00f4chplace_00ee7h:
    and     byte ptr ds:[ di + 061h ], ahplace_00eeah:
;;  UNKNOWN instructionplace_00eebh:
;;  UNKNOWN instructionplace_00eech:
    and     byte ptr ds:[ si + 069h ], chplace_00eefh:
    outsb   place_00ef0h:
;;  UNKNOWN instructionplace_00ef1h:
    and     byte ptr ds:[ bx + di + 073h ], chplace_00ef4h:
    and     byte ptr ds:[ bp + 06fh ], chplace_00ef7h:
    and     byte ptr ds:[ si + 06fh ], chplace_00efah:
    outsb   place_00efbh:
;;  UNKNOWN instructionplace_00efch:
;;  UNKNOWN instruction;;  SCANNING...
place_00efdh:
    jb      place_00f0chplace_00effh:
    or      ah, byte ptr ds:[ bx + si ]place_00f01h:
    and     byte ptr ds:[ bx + si ], ahplace_00f03h:
    and     byte ptr ds:[ bx + si ], ahplace_00f05h:
    and     byte ptr ds:[ bx + si ], ahplace_00f07h:
    and     byte ptr ds:[ bx + si ], ahplace_00f09h:
    and     byte ptr ds:[ bx + si ], ahplace_00f0bh:
    and     byte ptr ds:[ bx + si ], ahplace_00f0dh:
    and     byte ptr ds:[ si + 068h ], dhplace_00f10h:
    popa    place_00f11h:
    outsb   place_00f12h:
    and     byte ptr ds:[ bx + si ], bhplace_00f14h:
    xor     byte ptr ds:[ bx + si ], ahplace_00f16h:
;;  UNKNOWN instructionplace_00f17h:
;;  UNKNOWN instructionplace_00f18h:
    popa    place_00f19h:
    jb      place_00f7chplace_00f1bh:
;;  UNKNOWN instructionplace_00f1ch:
    je      place_00f83hplace_00f1eh:
    jb      place_00f93hplace_00f20h:
;;  UNKNOWN instructionplace_00f21h:
    and     byte ptr ds:[ bp + si + 061h ], ahplace_00f24h:
    jae     place_00f8bhplace_00f26h:
;;  UNKNOWN instructionplace_00f27h:
    and     byte ptr ds:[ bx + 06eh ], chplace_00f2ah:
    and     byte ptr ds:[ si + 068h ], dhplace_00f2dh:
;;  UNKNOWN instructionplace_00f2eh:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_00f31h:
    jo      place_00fa8hplace_00f33h:
    je      place_00f55hplace_00f35h:
    je      place_00f9chplace_00f37h:
    js      place_00fadhplace_00f39h:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_00f3ch:
    and     byte ptr ds:[ bx ], ahplace_00f3eh:
;;  UNKNOWN instructionplace_00f3fh:
    jne     place_00fb0hplace_00f41h:
    insw    place_00f42h:
    je      place_00fbdhplace_00f45h:
    je      place_00f6ehplace_00f47h:
    or      ax, 00d0ahplace_00f4bh:
    or      ah, byte ptr cs:[ si ]place_00f4dh:
    dec     diplace_00f4eh:
    push    axplace_00f4fh:
    push    spplace_00f50h:
    dec     cxplace_00f51h:
    dec     diplace_00f52h:
    dec     siplace_00f53h:
    push    bxplace_00f54h:
    or      ax, 0200ahplace_00f57h:
    and     byte ptr ds:[ bx + si ], ahplace_00f59h:
    and     byte ptr ds:[ bx + si ], ahplace_00f5bh:
    and     byte ptr ds:[ bx + si ], ahplace_00f5dh:
    dec     cxplace_00f5eh:
    dec     siplace_00f5fh:
    push    axplace_00f60h:
    push    bpplace_00f61h:
    push    spplace_00f62h:
    pop     diplace_00f63h:
    inc     siplace_00f64h:
    dec     cxplace_00f65h:
    dec     spplace_00f66h:
    inc     bpplace_00f67h:
    or      ax, 0200ahplace_00f6ah:
    and     byte ptr ds:[ bx + si ], ahplace_00f6ch:
    and     byte ptr ds:[ bx + si ], ahplace_00f6eh:
    and     byte ptr ds:[ bx + si ], ahplace_00f70h:
    and     byte ptr ds:[ bx + si ], ahplace_00f72h:
    and     byte ptr ds:[ bx + si ], ahplace_00f74h:
    and     byte ptr ds:[ bx + si ], ahplace_00f76h:
    and     byte ptr ds:[ bp + di + 070h ], dlplace_00f79h:
;;  UNKNOWN instructionplace_00f7ah:
;;  UNKNOWN instructionplace_00f7bh:
;;  UNKNOWN instructionplace_00f7ch:
;;  UNKNOWN instructionplace_00f7dh:
;;  UNKNOWN instructionplace_00f7eh:
;;  UNKNOWN instructionplace_00f7fh:
    jae     place_00fa1hplace_00f81h:
    je      place_00febhplace_00f83h:
;;  UNKNOWN instructionplace_00f84h:
    and     byte ptr ds:[ bx + si + 061h ], dhplace_00f87h:
    je      place_00ff1hplace_00f89h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00f8ch:
    and     byte ptr ds:[ si + 068h ], dhplace_00f8fh:
;;  UNKNOWN instructionplace_00f90h:
    and     byte ptr ds:[ bp + 069h ], ahplace_00f93h:
    insb    place_00f94h:
;;  UNKNOWN instructionplace_00f95h:
    and     byte ptr ds:[ bp + di + 06fh ], ahplace_00f98h:
    outsb   place_00f99h:
    je      place_00ffchplace_00f9bh:
;;  UNKNOWN instructionplace_00f9ch:
    outsb   place_00f9dh:
;;  UNKNOWN instructionplace_00f9eh:
    outsb   place_00f9fh:
;;  UNKNOWN instructionplace_00fa0h:
    or      ax, 0200ahplace_00fa3h:
    and     byte ptr ds:[ bx + si ], ahplace_00fa5h:
    and     byte ptr ds:[ bx + si ], ahplace_00fa7h:
    and     byte ptr ds:[ bx + si ], ahplace_00fa9h:
    and     byte ptr ds:[ bx + si ], ahplace_00fabh:
    and     byte ptr ds:[ bx + si ], ahplace_00fadh:
    and     byte ptr ds:[ bx + si ], ahplace_00fafh:
    and     byte ptr ds:[ si + 068h ], dhplace_00fb2h:
;;  UNKNOWN instructionplace_00fb3h:
    and     byte ptr ds:[ si + 065h ], dhplace_00fb6h:
    js      place_0102chplace_00fb8h:
    and     byte ptr ds:[ si + 06fh ], dhplace_00fbbh:
    and     byte ptr ds:[ bp + si + 065h ], ahplace_00fbeh:
    and     byte ptr ds:[ bx + si + 072h ], dhplace_00fc1h:
    outsw   place_00fc2h:
;;  UNKNOWN instructionplace_00fc3h:
;;  UNKNOWN instructionplace_00fc4h:
    jae     place_01039hplace_00fc6h:
;;  UNKNOWN instructionplace_00fc7h:
;;  UNKNOWN instructionplace_00fc8h:
    or      ax, 0200ahplace_00fcch:
    and     byte ptr cs:[ bx + si ], ahplace_00fceh:
    and     byte ptr ds:[ bx + si ], ahplace_00fd0h:
    and     byte ptr ds:[ bx + si ], ahplace_00fd2h:
    dec     bpplace_00fd3h:
    inc     cxplace_00fd4h:
    pop     axplace_00fd5h:
    pop     diplace_00fd6h:
    dec     spplace_00fd7h:
    dec     cxplace_00fd8h:
    dec     siplace_00fd9h:
    inc     bpplace_00fdah:
    pop     diplace_00fdbh:
    dec     spplace_00fdch:
    inc     bpplace_00fddh:
    dec     siplace_00fdeh:
    inc     diplace_00fdfh:
    push    spplace_00fe0h:
    dec     axplace_00fe1h:
    or      ax, 0200ahplace_00fe4h:
    and     byte ptr ds:[ bx + si ], ahplace_00fe6h:
    and     byte ptr ds:[ bx + si ], ahplace_00fe8h:
    and     byte ptr ds:[ bx + si ], ahplace_00feah:
    and     byte ptr ds:[ bx + si ], ahplace_00fech:
    and     byte ptr ds:[ bx + si ], ahplace_00feeh:
    and     byte ptr ds:[ bx + si ], ahplace_00ff0h:
    and     byte ptr ds:[ bp + di + 070h ], dlplace_00ff3h:
;;  UNKNOWN instructionplace_00ff4h:
;;  UNKNOWN instructionplace_00ff5h:
;;  UNKNOWN instructionplace_00ff6h:
;;  UNKNOWN instructionplace_00ff7h:
;;  UNKNOWN instructionplace_00ff8h:
;;  UNKNOWN instructionplace_00ff9h:
    jae     place_0101bhplace_00ffbh:
    je      place_01065h;;  SCANNING...
place_00ffdh:
;;  UNKNOWN instructionplace_00ffeh:
    and     byte ptr ds:[ di + 061h ], chplace_01001h:
    js      place_0106chplace_01003h:
    insw    place_01004h:
    jne     place_01073hplace_01006h:
    and     byte ptr ds:[ bx + di + 06ch ], ahplace_01009h:
    insb    place_0100ah:
    outsw   place_0100bh:
    ja      place_01072hplace_0100dh:
;;  UNKNOWN instructionplace_0100eh:
    and     byte ptr ds:[ si + 065h ], chplace_01011h:
    outsb   place_01012h:
;;  UNKNOWN instructionplace_01013h:
    je      place_0107dhplace_01015h:
    and     byte ptr ds:[ bx + 066h ], chplace_01018h:
    and     byte ptr ds:[ di + 061h ], ahplace_0101bh:
;;  UNKNOWN instructionplace_0101ch:
;;  UNKNOWN instructionplace_0101dh:
    and     byte ptr ds:[ si + 069h ], chplace_01020h:
    outsb   place_01021h:
;;  UNKNOWN instructionplace_01022h:
    or      ax, 0200ahplace_01025h:
    and     byte ptr ds:[ bx + si ], ahplace_01027h:
    and     byte ptr ds:[ bx + si ], ahplace_01029h:
    and     byte ptr ds:[ bx + si ], ahplace_0102bh:
    and     byte ptr ds:[ bx + si ], ahplace_0102dh:
    and     byte ptr ds:[ bx + si ], ahplace_0102fh:
    and     byte ptr ds:[ bx + si ], ahplace_01031h:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_01034h:
    and     byte ptr ds:[ bp + di + 068h ], ahplace_01037h:
    popa    place_01038h:
    jb      place_0109bhplace_0103ah:
;;  UNKNOWN instructionplace_0103bh:
    je      place_010a2hplace_0103dh:
    jb      place_010b2hplace_0103fh:
    and     byte ptr cs:[ si + 069h ], clplace_01043h:
    outsb   place_01044h:
;;  UNKNOWN instructionplace_01045h:
    jae     place_01067hplace_01047h:
    ja      place_010b2hplace_01049h:
    insb    place_0104ah:
    insb    place_0104bh:
    and     byte ptr ds:[ bp + si + 065h ], ahplace_0104eh:
    and     byte ptr ds:[ bx + 072h ], dhplace_01051h:
    popa    place_01052h:
    jo      place_010c4hplace_01054h:
;;  UNKNOWN instructionplace_01055h:
;;  UNKNOWN instructionplace_01056h:
    and     byte ptr ds:[ bx + di + 074h ], ahplace_01059h:
    and     byte ptr ds:[ si + 068h ], dhplace_0105ch:
;;  UNKNOWN instructionplace_0105dh:
    jae     place_0107fhplace_0105fh:
    insb    place_01060h:
;;  UNKNOWN instructionplace_01061h:
    outsb   place_01062h:
;;  UNKNOWN instructionplace_01063h:
    je      place_010cdhplace_01065h:
    or      ax, 0200ahplace_01069h:
    and     byte ptr cs:[ bx + si ], ahplace_0106bh:
    and     byte ptr ds:[ bx + si ], ahplace_0106dh:
    and     byte ptr ds:[ bx + si ], ahplace_0106fh:
    dec     diplace_01070h:
    push    bpplace_01071h:
    push    spplace_01072h:
    push    axplace_01073h:
    push    bpplace_01074h:
    push    spplace_01075h:
    pop     diplace_01076h:
    inc     siplace_01077h:
    dec     cxplace_01078h:
    dec     spplace_01079h:
    inc     bpplace_0107ah:
    or      ax, 0200ahplace_0107dh:
    and     byte ptr ds:[ bx + si ], ahplace_0107fh:
    and     byte ptr ds:[ bx + si ], ahplace_01081h:
    and     byte ptr ds:[ bx + si ], ahplace_01083h:
    and     byte ptr ds:[ bx + si ], ahplace_01085h:
    and     byte ptr ds:[ bx + si ], ahplace_01087h:
    and     byte ptr ds:[ bx + si ], ahplace_01089h:
    and     byte ptr ds:[ bp + di + 070h ], dlplace_0108ch:
;;  UNKNOWN instructionplace_0108dh:
;;  UNKNOWN instructionplace_0108eh:
;;  UNKNOWN instructionplace_0108fh:
;;  UNKNOWN instructionplace_01090h:
;;  UNKNOWN instructionplace_01091h:
;;  UNKNOWN instructionplace_01092h:
    jae     place_010b4hplace_01094h:
    je      place_010fehplace_01096h:
;;  UNKNOWN instructionplace_01097h:
    and     byte ptr ds:[ bx + si + 061h ], dhplace_0109ah:
    je      place_01104hplace_0109ch:
    and     byte ptr ds:[ si + 06fh ], dhplace_0109fh:
    and     byte ptr ds:[ si + 068h ], dhplace_010a2h:
;;  UNKNOWN instructionplace_010a3h:
    and     byte ptr ds:[ bp + 069h ], ahplace_010a6h:
    insb    place_010a7h:
;;  UNKNOWN instructionplace_010a8h:
    and     byte ptr ds:[ bx + 068h ], dhplace_010abh:
;;  UNKNOWN instructionplace_010ach:
    jb      place_01113hplace_010aeh:
    and     byte ptr ds:[ si + 068h ], dhplace_010b1h:
;;  UNKNOWN instructionplace_010b2h:
    and     byte ptr ds:[ bx + 075h ], chplace_010b5h:
    je      place_01127hplace_010b7h:
    jne     place_0112dhplace_010b9h:
    or      ax, 0200ahplace_010bch:
    and     byte ptr ds:[ bx + si ], ahplace_010beh:
    and     byte ptr ds:[ bx + si ], ahplace_010c0h:
    and     byte ptr ds:[ bx + si ], ahplace_010c2h:
    and     byte ptr ds:[ bx + si ], ahplace_010c4h:
    and     byte ptr ds:[ bx + si ], ahplace_010c6h:
    and     byte ptr ds:[ bx + si ], ahplace_010c8h:
    and     byte ptr ds:[ bx + si ], chplace_010cah:
;;  UNKNOWN instructionplace_010cbh:
    outsw   place_010cch:
    jb      place_0113bhplace_010ceh:
    popa    place_010cfh:
    je      place_01145hplace_010d1h:
;;  UNKNOWN instructionplace_010d2h:
;;  UNKNOWN instructionplace_010d3h:
    and     byte ptr ds:[ si + 065h ], dhplace_010d6h:
    js      place_0114chplace_010d8h:
    sub     word ptr ds:[ bx + si ], spplace_010dah:
    ja      place_01145hplace_010dch:
    insb    place_010ddh:
    insb    place_010deh:
    and     byte ptr ds:[ bp + si + 065h ], ahplace_010e1h:
    and     byte ptr ds:[ bp + di + 061h ], dhplace_010e4h:
    jbe     place_0114bhplace_010e6h:
;;  UNKNOWN instructionplace_010e7h:
    or      ax, 00d0ahplace_010ebh:
    or      ah, byte ptr cs:[ si ]place_010edh:
    dec     siplace_010eeh:
    dec     diplace_010efh:
    push    spplace_010f0h:
    inc     bpplace_010f1h:
    push    bxplace_010f2h:
    or      ax, 0200ahplace_010f5h:
    and     byte ptr ds:[ bx + si ], ahplace_010f7h:
    and     byte ptr ds:[ bx + si ], ahplace_010f9h:
    and     byte ptr ds:[ bx + si ], ahplace_010fbh:
    sub     ax, 05420h;;  SCANNING...
place_010feh:
;;  UNKNOWN instructionplace_010ffh:
;;  UNKNOWN instructionplace_01100h:
    and     byte ptr ds:[ bx + si + 072h ], dhplace_01103h:
    outsw   place_01104h:
;;  UNKNOWN instructionplace_01105h:
    jb      place_01168hplace_01107h:
    insw    place_01108h:
    and     byte ptr ds:[ bp + si + 065h ], dhplace_0110bh:
    popa    place_0110ch:
;;  UNKNOWN instructionplace_0110dh:
    jae     place_0112fhplace_0110fh:
    je      place_01179hplace_01111h:
;;  UNKNOWN instructionplace_01112h:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_01115h:
    jo      place_0118chplace_01117h:
    je      place_01139hplace_01119h:
    je      place_01180hplace_0111bh:
    js      place_01191hplace_0111dh:
    and     byte ptr ds:[ bp + 069h ], ahplace_01120h:
    insb    place_01121h:
;;  UNKNOWN instructionplace_01122h:
    and     byte ptr ds:[ bx + di + 06eh ], ahplace_01125h:
;;  UNKNOWN instructionplace_01126h:
    and     byte ptr ds:[ bp + si + 072h ], ahplace_01129h:
;;  UNKNOWN instructionplace_0112ah:
    popa    place_0112bh:
;;  UNKNOWN instructionplace_0112ch:
    jae     place_0114ehplace_0112eh:
    insb    place_0112fh:
;;  UNKNOWN instructionplace_01130h:
    outsb   place_01131h:
;;  UNKNOWN instructionplace_01132h:
    jae     place_01141hplace_01134h:
    or      ah, byte ptr ds:[ bx + si ]place_01136h:
    and     byte ptr ds:[ bx + si ], ahplace_01138h:
    and     byte ptr ds:[ bx + si ], ahplace_0113ah:
    and     byte ptr ds:[ bx + si ], ahplace_0113ch:
    and     byte ptr ds:[ bx + si ], ahplace_0113eh:
;;  UNKNOWN instructionplace_0113fh:
    popa    place_01140h:
    jae     place_011a7hplace_01142h:
;;  UNKNOWN instructionplace_01143h:
    and     byte ptr ds:[ bx + 06eh ], chplace_01146h:
    and     byte ptr ds:[ si + 068h ], dhplace_01149h:
;;  UNKNOWN instructionplace_0114ah:
    and     byte ptr ds:[ bp + di + 070h ], dhplace_0114dh:
;;  UNKNOWN instructionplace_0114eh:
;;  UNKNOWN instructionplace_0114fh:
;;  UNKNOWN instructionplace_01150h:
;;  UNKNOWN instructionplace_01151h:
;;  UNKNOWN instructionplace_01152h:
;;  UNKNOWN instructionplace_01153h:
;;  UNKNOWN instructionplace_01154h:
    and     byte ptr ds:[ bp + di + 068h ], ahplace_01157h:
    popa    place_01158h:
    jb      place_011bbhplace_0115ah:
;;  UNKNOWN instructionplace_0115bh:
    je      place_011c2hplace_0115dh:
    jb      place_0117fhplace_0115fh:
    insb    place_01160h:
;;  UNKNOWN instructionplace_01161h:
    insw    place_01162h:
;;  UNKNOWN instructionplace_01163h:
    je      place_01191hplace_01165h:
    and     byte ptr ds:[ bx + di + 066h ], chplace_01168h:
    and     byte ptr ds:[ bx + si + 06fh ], dhplace_0116bh:
    jae     place_011e0hplace_0116dh:
;;  UNKNOWN instructionplace_0116eh:
;;  UNKNOWN instructionplace_0116fh:
    insb    place_01170h:
;;  UNKNOWN instructionplace_01171h:
    or      ax, 0200ahplace_01175h:
    and     byte ptr cs:[ bx + si ], ahplace_01177h:
    and     byte ptr ds:[ bx + si ], ahplace_01179h:
    and     byte ptr ds:[ bx + si ], ahplace_0117bh:
    sub     ax, 05420hplace_0117eh:
;;  UNKNOWN instructionplace_0117fh:
;;  UNKNOWN instructionplace_01180h:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_01183h:
    jo      place_011fahplace_01185h:
    je      place_011a7hplace_01187h:
    popa    place_01188h:
    outsb   place_01189h:
;;  UNKNOWN instructionplace_0118ah:
    and     byte ptr ds:[ bx + 075h ], chplace_0118dh:
    je      place_011ffhplace_0118fh:
    jne     place_01205hplace_01191h:
    and     byte ptr ds:[ bp + 069h ], ahplace_01194h:
    insb    place_01195h:
;;  UNKNOWN instructionplace_01196h:
    and     byte ptr ds:[ bx + si + 061h ], dhplace_01199h:
    je      place_01203hplace_0119bh:
    jae     place_011bdhplace_0119dh:
    jae     place_01207hplace_0119fh:
    outsw   place_011a0h:
    jne     place_0120ehplace_011a2h:
;;  UNKNOWN instructionplace_011a3h:
    and     byte ptr ds:[ bp + si + 065h ], ahplace_011a6h:
    and     byte ptr ds:[ bx + si + 072h ], dhplace_011a9h:
    outsw   place_011aah:
    jbe     place_01215hplace_011ach:
;;  UNKNOWN instructionplace_011adh:
;;  UNKNOWN instructionplace_011aeh:
;;  UNKNOWN instructionplace_011afh:
    and     byte ptr ds:[ bx + 069h ], dhplace_011b2h:
    je      place_0121chplace_011b4h:
    and     byte ptr ds:[ bx + di + 00dh ], ahplace_011b7h:
    or      ah, byte ptr ds:[ bx + si ]place_011b9h:
    and     byte ptr ds:[ bx + si ], ahplace_011bbh:
    and     byte ptr ds:[ bx + si ], ahplace_011bdh:
    and     byte ptr ds:[ bx + si ], ahplace_011bfh:
    and     byte ptr ds:[ bx + si ], ahplace_011c1h:
    insw    place_011c2h:
    popa    place_011c3h:
    js      place_0122ehplace_011c5h:
    insw    place_011c6h:
    jne     place_01235hplace_011c8h:
    and     byte ptr ds:[ bx + 066h ], chplace_011cbh:
    and     byte ptr ds:[ bp + si ], dhplace_011cdh:
    xor     ax, 02035hplace_011d0h:
;;  UNKNOWN instructionplace_011d1h:
;;  UNKNOWN instructionplace_011d2h:
    popa    place_011d3h:
    jb      place_01236hplace_011d5h:
;;  UNKNOWN instructionplace_011d6h:
    je      place_0123dhplace_011d8h:
    jb      place_0124dhplace_011dah:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_011ddh:
    and     byte ptr ds:[ si + 065h ], chplace_011e0h:
    outsb   place_011e1h:
;;  UNKNOWN instructionplace_011e2h:
    je      place_0124chplace_011e4h:
    or      ax, 0200ahplace_011e8h:
    and     byte ptr cs:[ bx + si ], ahplace_011eah:
    and     byte ptr ds:[ bx + si ], ahplace_011ech:
    and     byte ptr ds:[ bx + si ], ahplace_011eeh:
    sub     ax, 05420hplace_011f1h:
;;  UNKNOWN instructionplace_011f2h:
;;  UNKNOWN instructionplace_011f3h:
    and     byte ptr ds:[ di + 041h ], clplace_011f6h:
    pop     axplace_011f7h:
    pop     diplace_011f8h:
    dec     spplace_011f9h:
    dec     cxplace_011fah:
    dec     siplace_011fbh:
    inc     bpplace_011fch:
    pop     di;;  SCANNING...
place_011fdh:
    dec     spplace_011feh:
    inc     bpplace_011ffh:
    dec     siplace_01200h:
    inc     diplace_01201h:
    push    spplace_01202h:
    dec     axplace_01203h:
    and     byte ptr ds:[ bp + di + 068h ], dhplace_01206h:
    outsw   place_01207h:
    jne     place_01275hplace_01209h:
;;  UNKNOWN instructionplace_0120ah:
    and     byte ptr ds:[ bp + si + 065h ], ahplace_0120dh:
    and     byte ptr ds:[ bx + di + 020h ], ahplace_01210h:
    jo      place_01281hplace_01212h:
    jae     place_0127dhplace_01214h:
    je      place_0127fhplace_01216h:
    jbe     place_0127dhplace_01218h:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_0121bh:
    je      place_01282hplace_0121dh:
;;  UNKNOWN instructionplace_0121eh:
;;  UNKNOWN instructionplace_0121fh:
    jb      place_0124dhplace_01221h:
    and     byte ptr ds:[ si + 079h ], dhplace_01224h:
    jo      place_0128fhplace_01226h:
;;  UNKNOWN instructionplace_01227h:
    popa    place_01228h:
    insb    place_01229h:
    insb    place_0122ah:
    jns     place_01239hplace_0122ch:
    or      ah, byte ptr ds:[ bx + si ]place_0122eh:
    and     byte ptr ds:[ bx + si ], ahplace_01230h:
    and     byte ptr ds:[ bx + si ], ahplace_01232h:
    and     byte ptr ds:[ bx + si ], ahplace_01234h:
    and     byte ptr ds:[ bx + si ], ahplace_01236h:
    outsb   place_01237h:
    outsw   place_01238h:
    je      place_0125ahplace_0123ah:
;;  UNKNOWN instructionplace_0123bh:
    jb      place_012a2hplace_0123dh:
    popa    place_0123eh:
    je      place_012a5hplace_01240h:
    jb      place_01262hplace_01242h:
    je      place_012achplace_01244h:
    popa    place_01245h:
    outsb   place_01246h:
    and     byte ptr ds:[ bp + si ], dhplace_01248h:
    xor     ax, 07335hplace_0124bh:
    or      ax, 00d0ahplace_0124fh:
    or      ah, byte ptr cs:[ si ]place_01251h:
    inc     bpplace_01252h:
    pop     axplace_01253h:
    inc     cxplace_01254h:
    dec     bpplace_01255h:
    push    axplace_01256h:
    dec     spplace_01257h:
    inc     bpplace_01258h:
    push    bxplace_01259h:
    or      ax, 0200ahplace_0125ch:
    and     byte ptr ds:[ bx + si ], ahplace_0125eh:
    and     byte ptr ds:[ bx + si ], ahplace_01260h:
    and     byte ptr ds:[ bx + si ], ahplace_01262h:
    push    spplace_01263h:
    outsw   place_01264h:
    and     byte ptr ds:[ bp + 06fh ], ahplace_01267h:
    jb      place_012d6hplace_01269h:
    popa    place_0126ah:
    je      place_0128chplace_0126ch:
    daa     place_0126dh:
;;  UNKNOWN instructionplace_0126eh:
    jne     place_012dfhplace_01270h:
    insw    place_01271h:
    je      place_012echplace_01274h:
    je      place_0129dhplace_01276h:
    and     byte ptr cs:[ bx + 069h ], dhplace_01279h:
    je      place_012e3hplace_0127bh:
    and     byte ptr ds:[ si + 069h ], chplace_0127eh:
    outsb   place_0127fh:
;;  UNKNOWN instructionplace_01280h:
    jae     place_012a2hplace_01282h:
    jne     place_012f4hplace_01284h:
    and     byte ptr ds:[ si + 06fh ], dhplace_01287h:
    and     byte ptr ds:[ bx + si ], bhplace_01289h:
    xor     byte ptr ds:[ bx + si ], ahplace_0128bh:
;;  UNKNOWN instructionplace_0128ch:
;;  UNKNOWN instructionplace_0128dh:
    popa    place_0128eh:
    jb      place_012f1hplace_01290h:
;;  UNKNOWN instructionplace_01291h:
    je      place_012f8hplace_01293h:
    jb      place_01308hplace_01295h:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_01298h:
    and     byte ptr ds:[ si + 065h ], chplace_0129bh:
    outsb   place_0129ch:
;;  UNKNOWN instructionplace_0129dh:
    je      place_01307hplace_0129fh:
    or      ax, 0200ahplace_012a2h:
    and     byte ptr ds:[ bx + si ], ahplace_012a4h:
    and     byte ptr ds:[ bx + si ], ahplace_012a6h:
    and     byte ptr ds:[ bx + si ], ahplace_012a8h:
    popa    place_012a9h:
    outsb   place_012aah:
;;  UNKNOWN instructionplace_012abh:
    and     byte ptr ds:[ bp + di + 061h ], dhplace_012aeh:
    jbe     place_01315hplace_012b0h:
    and     byte ptr ds:[ bx + di + 074h ], chplace_012b3h:
    and     byte ptr ds:[ si + 06fh ], dhplace_012b6h:
    and     byte ptr ds:[ bx ], ahplace_012b8h:
    jb      place_0131fhplace_012bah:
    jp      place_012eahplace_012bch:
    je      place_01336hplace_012beh:
    je      place_012e7hplace_012c0h:
    cmp     cl, byte ptr ds:[ di ]place_012c2h:
    or      cl, byte ptr ds:[ di ]place_012c4h:
    or      ah, byte ptr ds:[ bx + si ]place_012c6h:
    and     byte ptr ds:[ bx + si ], ahplace_012c8h:
    and     byte ptr ds:[ bx + si ], ahplace_012cah:
    and     byte ptr ds:[ bx + si ], ahplace_012cch:
    and     byte ptr ds:[ bx + si ], ahplace_012ceh:
    and     byte ptr ds:[ bx + si ], ahplace_012d0h:
    and     byte ptr ds:[ bx + si ], ahplace_012d2h:
    and     byte ptr ds:[ bx + di + 06eh ], ahplace_012d5h:
    je      place_01349hplace_012d7h:
    popa    place_012d8h:
    and     byte ptr ds:[ si + 075h ], ahplace_012dbh:
    outsw   place_012dch:
    insw    place_012ddh:
    je      place_01358hplace_012e0h:
    je      place_01302hplace_012e2h:
    cmp     byte ptr cs:[ bx + si ], dhplace_012e4h:
    and     byte ptr ds:[ bp + si + 065h ], dhplace_012e7h:
    jp      place_01317hplace_012e9h:
    je      place_01363hplace_012ebh:
    je      place_012fahplace_012edh:
    or      cl, byte ptr ds:[ di ]place_012efh:
    or      ah, byte ptr ds:[ bx + si ]place_012f1h:
    and     byte ptr ds:[ bx + si ], ahplace_012f3h:
    and     byte ptr ds:[ bx + si ], ahplace_012f5h:
    and     byte ptr ds:[ bx + si ], ahplace_012f7h:
    push    spplace_012f8h:
    outsw   place_012f9h:
    and     byte ptr ds:[ bp + 06fh ], ah;;  SCANNING...
place_012fch:
    jb      place_0136bhplace_012feh:
    popa    place_012ffh:
    je      place_01321hplace_01301h:
    popa    place_01302h:
    and     byte ptr ds:[ si + 069h ], ahplace_01305h:
;;  UNKNOWN instructionplace_01306h:
;;  UNKNOWN instructionplace_01307h:
;;  UNKNOWN instructionplace_01308h:
    jb      place_0136fhplace_0130ah:
    outsb   place_0130bh:
    je      place_0132dhplace_0130dh:
;;  UNKNOWN instructionplace_0130eh:
;;  UNKNOWN instructionplace_0130fh:
    insb    place_01310h:
;;  UNKNOWN instructionplace_01311h:
;;  UNKNOWN instructionplace_01312h:
    and     byte ptr ds:[ bx ], ahplace_01314h:
;;  UNKNOWN instructionplace_01315h:
    outsb   place_01316h:
    jo      place_0138dhplace_01318h:
    je      place_01348hplace_0131ah:
    je      place_01394hplace_0131ch:
    je      place_01345hplace_0131eh:
;;  UNKNOWN instructionplace_0131fh:
    and     byte ptr ds:[ bx + 069h ], dhplace_01322h:
    je      place_0138chplace_01324h:
    and     byte ptr ds:[ si + 069h ], chplace_01327h:
    outsb   place_01328h:
;;  UNKNOWN instructionplace_01329h:
    jae     place_0134bhplace_0132bh:
    jne     place_0139dhplace_0132dh:
    and     byte ptr ds:[ si + 06fh ], dhplace_01330h:
    and     byte ptr ds:[ bx + di ], dhplace_01332h:
    xor     byte ptr ds:[ bx + si ], dhplace_01334h:
    or      ax, 0200ahplace_01337h:
    and     byte ptr ds:[ bx + si ], ahplace_01339h:
    and     byte ptr ds:[ bx + si ], ahplace_0133bh:
    and     byte ptr ds:[ bx + si ], ahplace_0133dh:
;;  UNKNOWN instructionplace_0133eh:
;;  UNKNOWN instructionplace_0133fh:
    popa    place_01340h:
    jb      place_013a3hplace_01342h:
;;  UNKNOWN instructionplace_01343h:
    je      place_013aahplace_01345h:
    jb      place_013bahplace_01347h:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_0134ah:
    and     byte ptr ds:[ si + 065h ], chplace_0134dh:
    outsb   place_0134eh:
;;  UNKNOWN instructionplace_0134fh:
    je      place_013b9hplace_01351h:
    cmp     cl, byte ptr ds:[ di ]place_01353h:
    or      cl, byte ptr ds:[ di ]place_01355h:
    or      ah, byte ptr ds:[ bx + si ]place_01357h:
    and     byte ptr ds:[ bx + si ], ahplace_01359h:
    and     byte ptr ds:[ bx + si ], ahplace_0135bh:
    and     byte ptr ds:[ bx + si ], ahplace_0135dh:
    and     byte ptr ds:[ bx + si ], ahplace_0135fh:
    and     byte ptr ds:[ bx + si ], ahplace_01361h:
    and     byte ptr ds:[ bx + si ], ahplace_01363h:
    and     byte ptr ds:[ bx + di + 06eh ], ahplace_01366h:
    je      place_013dahplace_01368h:
    popa    place_01369h:
    and     byte ptr ds:[ bx + di + 06eh ], chplace_0136ch:
    jo      place_013e3hplace_0136eh:
    je      place_0139ehplace_01370h:
    je      place_013eahplace_01372h:
    je      place_01394hplace_01374h:
    add     word ptr ds:[ bx + si ], siplace_01376h:
    xor     byte ptr ds:[ bx + si ], ahplace_01378h:
    outsw   place_01379h:
    jne     place_013efhplace_0137bh:
    jo      place_013f2hplace_0137dh:
    je      place_013adhplace_0137fh:
    je      place_013f9hplace_01381h:
    je      place_01390hplace_01383h:
    or      cl, byte ptr ds:[ di ]place_01385h:
    or      ah, byte ptr ds:[ si ]place_01387h:
    inc     cxplace_01388h:
    push    bpplace_01389h:
    push    spplace_0138ah:
    dec     axplace_0138bh:
    dec     diplace_0138ch:
    push    dxplace_0138dh:
    or      ax, 0200ahplace_01390h:
    and     byte ptr ds:[ bx + si ], ahplace_01392h:
    and     byte ptr ds:[ bx + si ], ahplace_01394h:
    and     byte ptr ds:[ bx + si ], ahplace_01396h:
    push    diplace_01397h:
    jb      place_01402hplace_01399h:
    je      place_0140fhplace_0139bh:
;;  UNKNOWN instructionplace_0139ch:
    outsb   place_0139dh:
    and     byte ptr ds:[ bp + si + 079h ], ahplace_013a0h:
    and     byte ptr ds:[ bp + si + 06fh ], dlplace_013a3h:
;;  UNKNOWN instructionplace_013a4h:
    popa    place_013a5h:
    jae     place_013c7hplace_013a7h:
    inc     dxplace_013a8h:
    jb      place_0140bhplace_013aah:
;;  UNKNOWN instructionplace_013abh:
;;  UNKNOWN instructionplace_013ach:
    outsw   place_013adh:
;;  UNKNOWN instructionplace_013aeh:
    popa    place_013afh:
    jae     place_013dfhplace_013b1h:
    or      ax, 00d0ahplace_013b4h:
    or      ah, byte ptr ds:[ si ]place_013b6h:
    inc     bxplace_013b7h:
    dec     diplace_013b8h:
    push    axplace_013b9h:
    pop     cxplace_013bah:
    push    dxplace_013bbh:
    dec     cxplace_013bch:
    inc     diplace_013bdh:
    dec     axplace_013beh:
    push    spplace_013bfh:
    or      ax, 0200ahplace_013c2h:
    and     byte ptr ds:[ bx + si ], ahplace_013c4h:
    and     byte ptr ds:[ bx + si ], ahplace_013c6h:
    and     byte ptr ds:[ bx + si ], ahplace_013c8h:
    inc     bxplace_013c9h:
    outsw   place_013cah:
    jo      place_01445hplace_013cch:
    jb      place_01437hplace_013ceh:
;;  UNKNOWN instructionplace_013cfh:
;;  UNKNOWN instructionplace_013d0h:
    je      place_013f2hplace_013d2h:
    xor     dh, byte ptr ds:[ bx + si ]place_013d4h:
    xor     dh, byte ptr ds:[ si ]place_013d6h:
    and     byte ptr ds:[ bp + 055h ], dlplace_013d9h:
    or      ax, 0240ahplace_013ddh:
    je      place_01457hplace_013dfh:
    je      place_01401hplace_013e1h:
    cmp     byte ptr cs:[ bx + si ], dhplace_013e3h:
    and     byte ptr ds:[ bp + si + 065h ], dhplace_013e6h:
    jp      place_01416hplace_013e8h:
    je      place_01462hplace_013eah:
    je      place_013f9hplace_013ech:
    or      cl, byte ptr ds:[ di ]place_013eeh:
    or      ah, byte ptr ds:[ bx + si ]place_013f0h:
    and     byte ptr ds:[ bx + si ], ahplace_013f2h:
    and     byte ptr ds:[ bx + si ], ahplace_013f4h:
    and     byte ptr ds:[ bx + si ], ahplace_013f6h:
    push    spplace_013f7h:
    outsw   place_013f8h:
    and     byte ptr ds:[ bp + 06fh ], ah;;  SCANNING...
END
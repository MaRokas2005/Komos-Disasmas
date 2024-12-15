;***************************************************;
;                 load text to buffer               ;
;             si - pointer to input text            ;
;           di - pointer to output buffer           ;
;***************************************************;
loadTextToBuffer PROC
    @@copy_start:
        lodsb
        cmp     al, 0
        je      @@done
        stosb
        inc     word ptr outputLength
        jmp     @@copy_start
    
    @@done:

    ret
loadTextToBuffer ENDP

;***************************************************;
;                  get mod reg r/m                  ;
;                 dl = mod reg r/m                  ;
;***************************************************;
getModRegRM PROC




    ret
getModRegRM ENDP
ins_unknown     db ";;  UNKNOWN instruction", 0
ins_mov         db "    mov     ", 0
ins_in          db "    in      ", 0
ins_insb        db "    insb    ", 0
ins_insw        db "    insw    ", 0
ins_out         db "    out     ", 0
ins_outsb       db "    outsb   ", 0
ins_outsw       db "    outsw   ", 0
ins_push        db "    push    ", 0
ins_pop         db "    pop     ", 0
ins_xchg        db "    xchg    ", 0
ins_xlatb       db "    xlatb   ", 0
ins_lea         db "    lea     ", 0
ins_leave       db "    leave   ", 0
ins_lds         db "    lds     ", 0
ins_les         db "    les     ", 0
ins_lss         db "    lss     ", 0
ins_loop        db "    loop    ", 0
ins_loope       db "    loope   ", 0
ins_loopne      db "    loopne  ", 0
ins_lahf        db "    lahf    ", 0
ins_sahf        db "    sahf    ", 0
ins_pusha       db "    pusha   ", 0
ins_pushf       db "    pushf   ", 0
ins_popa        db "    popa    ", 0
ins_popf        db "    popf    ", 0
ins_ja          db "    ja      ", 0
ins_jae         db "    jae     ", 0
ins_jb          db "    jb      ", 0
ins_jbe         db "    jbe     ", 0
ins_je          db "    je      ", 0
ins_jcxz        db "    jcxz    ", 0
ins_jg          db "    jg      ", 0
ins_jge         db "    jge     ", 0
ins_jl          db "    jl      ", 0
ins_jle         db "    jle     ", 0
ins_jne         db "    jne     ", 0
ins_jno         db "    jno     ", 0
ins_jnp         db "    jnp     ", 0
ins_jp          db "    jp      ", 0
ins_jo          db "    jo      ", 0
ins_jns         db "    jns     ", 0
ins_js          db "    js      ", 0
ins_inc         db "    inc     ", 0
ins_aaa         db "    aaa     ", 0
ins_daa         db "    daa     ", 0
ins_dec         db "    dec     ", 0
ins_aas         db "    aas     ", 0
ins_das         db "    das     ", 0
ins_aam         db "    aam     ", 0
ins_aad         db "    aad     ", 0
ins_cbw         db "    cbw     ", 0
ins_cwd         db "    cwd     ", 0
ins_rep         db "    rep     ", 0
ins_repne       db "    repne   ", 0
ins_movsb       db "    movsb   ", 0
ins_movsw       db "    movsw   ", 0
ins_cmpsb       db "    cmpsb   ", 0
ins_cmpsw       db "    cmpsw   ", 0
ins_scasb       db "    scasb   ", 0
ins_scasw       db "    scasw   ", 0
ins_stosb       db "    stosb   ", 0
ins_stosw       db "    stosw   ", 0
ins_lodsb       db "    lodsb   ", 0
ins_lodsw       db "    lodsw   ", 0
ins_call        db "    call    ", 0
ins_ret         db "    ret     ", 0
ins_retf        db "    retf    ", 0
ins_jmp         db "    jmp     ", 0
ins_int         db "    int     ", 0
ins_int1        db "    int1    ", 0
ins_int3        db "    int3    ", 0
ins_into        db "    into    ", 0
ins_iret        db "    iret    ", 0
ins_stc         db "    stc     ", 0
ins_clc         db "    clc     ", 0
ins_cmc         db "    cmc     ", 0
ins_std         db "    std     ", 0
ins_cld         db "    cld     ", 0
ins_sti         db "    sti     ", 0
ins_cli         db "    cli     ", 0
ins_hlt         db "    hlt     ", 0
ins_wait        db "    wait    ", 0
ins_lock        db "    lock    ", 0
ins_nop         db "    nop     ", 0
; order below is needed for opcodes 80h, 81h, 82h, 83h
ins_add         db "    add     ", 0, "   "
ins_or          db "    or      ", 0, "   "
ins_adc         db "    adc     ", 0, "   "
ins_sbb         db "    sbb     ", 0, "   "
ins_and         db "    and     ", 0, "   "
ins_sub         db "    sub     ", 0, "   "
ins_xor         db "    xor     ", 0, "   "
ins_cmp         db "    cmp     ", 0, "   "
; order below is needed for opcodes c0h, c1h, d0h, d1h, d2h, d3h
ins_rol         db "    rol     ", 0, "   "
ins_ror         db "    ror     ", 0, "   "
ins_rcl         db "    rcl     ", 0, "   "
ins_rcr         db "    rcr     ", 0, "   "
ins_shl         db "    shl     ", 0, "   "
ins_shr         db "    shr     ", 0, "   "
ins_sal         db "    sal     ", 0, "   "
ins_sar         db "    sar     ", 0, "   "
; order below is needed for opcodes f6h, f7h
ins_test        db "    test    ", 0, "   "
fake_fake       db "", 0, "               "
ins_not         db "    not     ", 0, "   "
ins_neg         db "    neg     ", 0, "   "
ins_mul         db "    mul     ", 0, "   "
ins_imul        db "    imul    ", 0, "   "
ins_div         db "    div     ", 0, "   "
ins_idiv        db "    idiv    ", 0, "   "


reg_al          db "al", 0, " "
reg_cl          db "cl", 0, " "
reg_dl          db "dl", 0, " "
reg_bl          db "bl", 0, " "
reg_ah          db "ah", 0, " "
reg_ch          db "ch", 0, " "
reg_dh          db "dh", 0, " "
reg_bh          db "bh", 0, " "

reg_ax          db "ax", 0, " "
reg_cx          db "cx", 0, " "
reg_dx          db "dx", 0, " "
reg_bx          db "bx", 0, " "
reg_sp          db "sp", 0, " "
reg_bp          db "bp", 0, " "
reg_si          db "si", 0, " "
reg_di          db "di", 0, " "

reg_es          db "es", 0, " "
reg_cs          db "cs", 0, " "
reg_ss          db "ss", 0, " "
reg_ds          db "ds", 0, " "

mod_00_000         db "bx + si", 0, "        "
mod_00_001         db "bx + di", 0, "        "
mod_00_010         db "bp + si", 0, "        "
mod_00_011         db "bp + di", 0, "        "
mod_00_100         db "si", 0, "             "
mod_00_101         db "di", 0, "             "
mod_00_110         db "", 0, "               "
mod_00_111         db "bx", 0, "             "

mod_01_10_000      db "bx + si + ", 0, "     "
mod_01_10_001      db "bx + di + ", 0, "     "
mod_01_10_010      db "bp + si + ", 0, "     "
mod_01_10_011      db "bp + di + ", 0, "     "
mod_01_10_100      db "si + ", 0, "          "
mod_01_10_101      db "di + ", 0, "          "
mod_01_10_110      db "bp + ", 0, "          "
mod_01_10_111      db "bx + ", 0, "          "
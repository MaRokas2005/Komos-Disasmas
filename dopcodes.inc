ins_unknown     db "; UNKNOWN instruction", 0
ins_mov         db "    MOV     ", 0
ins_in          db "    IN      ", 0
ins_out         db "    OUT     ", 0
ins_push        db "    PUSH    ", 0
ins_pop         db "    POP     ", 0
ins_xchg        db "    XCHG    ", 0
ins_xlat        db "    XLAT    ", 0
ins_lea         db "    LEA     ", 0
ins_lds         db "    LDS     ", 0
ins_lss         db "    LSS     ", 0
ins_lahf        db "    LAHF    ", 0
ins_sahf        db "    SAHF    ", 0
ins_pushf       db "    PUSHF   ", 0
ins_popf        db "    POPF    ", 0
ins_ja          db "    JA      ", 0
ins_jae         db "    JAE     ", 0
ins_jb          db "    JB      ", 0
ins_jbe         db "    JBE     ", 0
ins_je          db "    JE      ", 0
ins_jcxz        db "    JCXZ    ", 0
ins_jg          db "    JG      ", 0
ins_jge         db "    JGE     ", 0
ins_jl          db "    JL      ", 0
ins_jle         db "    JLE     ", 0
ins_jne         db "    JNE     ", 0
ins_jno         db "    JNO     ", 0
ins_jnp         db "    JNP     ", 0
ins_jp          db "    JP      ", 0
ins_jo          db "    JO      ", 0
ins_jns         db "    JNS     ", 0
ins_js          db "    JS      ", 0
ins_add         db "    ADD     ", 0
ins_adc         db "    ADC     ", 0
ins_inc         db "    INC     ", 0
ins_aaa         db "    AAA     ", 0
ins_daa         db "    DAA     ", 0
ins_sub         db "    SUB     ", 0
ins_sbb         db "    SBB     ", 0
ins_dec         db "    DEC     ", 0
ins_neg         db "    NEG     ", 0
ins_cmp         db "    CMP     ", 0
ins_aas         db "    AAS     ", 0
ins_das         db "    DAS     ", 0
ins_mul         db "    MUL     ", 0
ins_imul        db "    IMUL    ", 0
ins_aam         db "    AAM     ", 0
ins_div         db "    DIV     ", 0
ins_idiv        db "    IDIV    ", 0
ins_aad         db "    AAD     ", 0
ins_cbw         db "    CBW     ", 0
ins_cwd         db "    CWD     ", 0
ins_not         db "    NOT     ", 0
ins_and         db "    AND     ", 0
ins_or          db "    OR      ", 0
ins_xor         db "    XOR     ", 0
ins_test        db "    TEST    ", 0
ins_shl         db "    SHL     ", 0
ins_shr         db "    SHR     ", 0
ins_sar         db "    SAR     ", 0
ins_rol         db "    ROL     ", 0
ins_ror         db "    ROR     ", 0
ins_rcl         db "    RCL     ", 0
ins_rcr         db "    RCR     ", 0
ins_rep         db "    REP     ", 0
ins_repne       db "    REPNE   ", 0
ins_movsb       db "    MOVSB   ", 0
ins_movsw       db "    MOVSW   ", 0
ins_cmpsb       db "    CMPSB   ", 0
ins_cmpsw       db "    CMPSW   ", 0
ins_scasb       db "    SCASB   ", 0
ins_scasw       db "    SCASW   ", 0
ins_stosb       db "    STOSB   ", 0
ins_stosw       db "    STOSW   ", 0
ins_lodsb       db "    LODSB   ", 0
ins_lodsw       db "    LODSW   ", 0
ins_call        db "    CALL    ", 0
ins_ret         db "    RET     ", 0
ins_retf        db "    RETF    ", 0
ins_jmp         db "    JMP     ", 0
ins_int         db "    INT     ", 0
ins_into        db "    INTO    ", 0
ins_iret        db "    IRET    ", 0
ins_stc         db "    STC     ", 0
ins_clc         db "    CLC     ", 0
ins_cmc         db "    CMC     ", 0
ins_std         db "    STD     ", 0
ins_cld         db "    CLD     ", 0
ins_sti         db "    STI     ", 0
ins_cli         db "    CLI     ", 0
ins_hlt         db "    HLT     ", 0
ins_wait        db "    WAIT    ", 0
ins_lock        db "    LOCK    ", 0
ins_nop         db "    NOP     ", 0

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

reg_small       dw offset reg_al, offset reg_cl, offset reg_dl, offset reg_bl, offset reg_ah, offset reg_ch, offset reg_dh, offset reg_bh
reg_large       dw offset reg_ax, offset reg_cx, offset reg_dx, offset reg_bx, offset reg_sp, offset reg_bp, offset reg_si, offset reg_di
reg_segment     dw offset reg_es, offset reg_cs, offset reg_ss, offset reg_ds

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

mod_00_offset       dw  offset mod_00_000, offset mod_00_001
                    dw  offset mod_00_010, offset mod_00_011
                    dw  offset mod_00_100, offset mod_00_101
                    dw  offset mod_00_110, offset mod_00_111

mod_01_10_offset    dw  offset mod_01_10_000, offset mod_01_10_001
                    dw  offset mod_01_10_010, offset mod_01_10_011
                    dw  offset mod_01_10_100, offset mod_01_10_101
                    dw  offset mod_01_10_110, offset mod_01_10_111


; ins_types ENUM {
;     ins_type_unknown,
;     ins_type_normal,
;     ins_type_extented,
;     ins_type_seg_ovr,
;     ins_type_prefix,
;     ins_type_custom
; }

; ins_operands ENUM {
;     op_void,
;     op_al,
;     op_cl,
;     op_dl,
;     op_bl,
;     op_ah,
;     op_ch,
;     op_dh,
;     op_bh,
;     op_ax,
;     op_cx,
;     op_dx,
;     op_bx,
;     op_sp,
;     op_bp,
;     op_si,
;     op_di,
;     op_es,
;     op_cs,
;     op_ss,
;     op_ds,
;     op_const1,
;     op_const3,
;     op_imm8,
;     op_eimm8,
;     op_short,
;     op_imm16,
;     op_near,
;     op_mem,
;     op_far,
;     op_reg8,
;     op_reg16,
;     op_segreg,
;     op_regmem8,
;     op_regmem16,
; }

; LABEL instruction_list
;     instruction<ins_add,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0000 0000
;     instruction<ins_add,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0000 0001
;     instruction<ins_add,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0000 0010
;     instruction<ins_add,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0000 0011
;     instruction<ins_add,        ins_type_normal,    op_al,          op_imm8>        ; 0000 0100
;     instruction<ins_add,        ins_type_normal,    op_ax,          op_imm16>       ; 0000 0101
;     instruction<ins_push,       ins_type_normal,    op_es,          op_void>        ; 0000 0110
;     instruction<ins_pop,        ins_type_normal,    op_es,          op_void>        ; 0000 0111
;     instruction<ins_or,         ins_type_normal,    op_regmem8,     op_reg8>        ; 0000 1000
;     instruction<ins_or,         ins_type_normal,    op_regmem16,    op_reg16>       ; 0000 1001
;     instruction<ins_or,         ins_type_normal,    op_reg8,        op_regmem8>     ; 0000 1010
;     instruction<ins_or,         ins_type_normal,    op_reg16,       op_regmem16>    ; 0000 1011
;     instruction<ins_or,         ins_type_normal,    op_al,          op_imm8>        ; 0000 1100
;     instruction<ins_or,         ins_type_normal,    op_ax,          op_imm16>       ; 0000 1101
;     instruction<ins_push,       ins_type_normal,    op_cs,          op_void>        ; 0000 1110
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0000 1111
;     instruction<ins_adc,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0001 0000
;     instruction<ins_adc,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0001 0001
;     instruction<ins_adc,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0001 0010
;     instruction<ins_adc,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0001 0011
;     instruction<ins_adc,        ins_type_normal,    op_al,          op_imm8>        ; 0001 0100
;     instruction<ins_adc,        ins_type_normal,    op_ax,          op_imm16>       ; 0001 0101
;     instruction<ins_push,       ins_type_normal,    op_ss,          op_void>        ; 0001 0110
;     instruction<ins_pop,        ins_type_normal,    op_ss,          op_void>        ; 0001 0111
;     instruction<ins_sbb,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0001 1000
;     instruction<ins_sbb,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0001 1001
;     instruction<ins_sbb,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0001 1010
;     instruction<ins_sbb,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0001 1011
;     instruction<ins_sbb,        ins_type_normal,    op_al,          op_imm8>        ; 0001 1100
;     instruction<ins_sbb,        ins_type_normal,    op_ax,          op_imm16>       ; 0001 1101
;     instruction<ins_push,       ins_type_normal,    op_ds,          op_void>        ; 0001 1110
;     instruction<ins_pop,        ins_type_normal,    op_ds,          op_void>        ; 0001 1111
;     instruction<ins_and,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0010 0000
;     instruction<ins_and,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0010 0001
;     instruction<ins_and,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0010 0010
;     instruction<ins_and,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0010 0011
;     instruction<ins_and,        ins_type_normal,    op_al,          op_imm8>        ; 0010 0100
;     instruction<ins_and,        ins_type_normal,    op_ax,          op_imm16>       ; 0010 0101
;     instruction<op_es,          ins_type_seg_ovr,   op_void,        op_void>        ; 0010 0110
;     instruction<ins_daa,        ins_type_normal,    op_void,        op_void>        ; 0010 0111
;     instruction<ins_sub,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0010 1000
;     instruction<ins_sub,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0010 1001
;     instruction<ins_sub,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0010 1010
;     instruction<ins_sub,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0010 1011
;     instruction<ins_sub,        ins_type_normal,    op_al,          op_imm8>        ; 0010 1100
;     instruction<ins_sub,        ins_type_normal,    op_ax,          op_imm16>       ; 0010 1101
;     instruction<op_cs,          ins_type_seg_ovr,   op_void,        op_void>        ; 0010 1110
;     instruction<ins_das,        ins_type_normal,    op_void,        op_void>        ; 0010 1111
;     instruction<ins_xor,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0011 0000
;     instruction<ins_xor,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0011 0001
;     instruction<ins_xor,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0011 0010
;     instruction<ins_xor,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0011 0011
;     instruction<ins_xor,        ins_type_normal,    op_al,          op_imm8>        ; 0011 0100
;     instruction<ins_xor,        ins_type_normal,    op_ax,          op_imm16>       ; 0011 0101
;     instruction<op_ss,          ins_type_seg_ovr,   op_void,        op_void>        ; 0011 0110
;     instruction<ins_aaa,        ins_type_normal,    op_void,        op_void>        ; 0011 0111
;     instruction<ins_cmp,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0011 1000
;     instruction<ins_cmp,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0011 1001
;     instruction<ins_cmp,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0011 1010
;     instruction<ins_cmp,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0011 1011
;     instruction<ins_cmp,        ins_type_normal,    op_al,          op_imm8>        ; 0011 1100
;     instruction<ins_cmp,        ins_type_normal,    op_ax,          op_imm16>       ; 0011 1101
;     instruction<op_ds,          ins_type_seg_ovr,   op_void,        op_void>        ; 0011 1110
;     instruction<ins_aas,        ins_type_normal,    op_void,        op_void>        ; 0011 1111
;     instruction<ins_inc,        ins_type_normal,    op_ax,          op_void>        ; 0100 0000
;     instruction<ins_inc,        ins_type_normal,    op_cx,          op_void>        ; 0100 0001
;     instruction<ins_inc,        ins_type_normal,    op_dx,          op_void>        ; 0100 0010
;     instruction<ins_inc,        ins_type_normal,    op_bx,          op_void>        ; 0100 0011
;     instruction<ins_inc,        ins_type_normal,    op_sp,          op_void>        ; 0100 0100
;     instruction<ins_inc,        ins_type_normal,    op_bp,          op_void>        ; 0100 0101
;     instruction<ins_inc,        ins_type_normal,    op_si,          op_void>        ; 0100 0110
;     instruction<ins_inc,        ins_type_normal,    op_di,          op_void>        ; 0100 0111
;     instruction<ins_dec,        ins_type_normal,    op_ax,          op_void>        ; 0100 1000
;     instruction<ins_dec,        ins_type_normal,    op_cx,          op_void>        ; 0100 1001
;     instruction<ins_dec,        ins_type_normal,    op_dx,          op_void>        ; 0100 1010
;     instruction<ins_dec,        ins_type_normal,    op_bx,          op_void>        ; 0100 1011
;     instruction<ins_dec,        ins_type_normal,    op_sp,          op_void>        ; 0100 1100
;     instruction<ins_dec,        ins_type_normal,    op_bp,          op_void>        ; 0100 1101
;     instruction<ins_dec,        ins_type_normal,    op_si,          op_void>        ; 0100 1110
;     instruction<ins_dec,        ins_type_normal,    op_di,          op_void>        ; 0100 1111
;     instruction<ins_push,       ins_type_normal,    op_ax,          op_void>        ; 0101 0000
;     instruction<ins_push,       ins_type_normal,    op_cx,          op_void>        ; 0101 0001
;     instruction<ins_push,       ins_type_normal,    op_dx,          op_void>        ; 0101 0010
;     instruction<ins_push,       ins_type_normal,    op_bx,          op_void>        ; 0101 0011
;     instruction<ins_push,       ins_type_normal,    op_sp,          op_void>        ; 0101 0100
;     instruction<ins_push,       ins_type_normal,    op_bp,          op_void>        ; 0101 0101
;     instruction<ins_push,       ins_type_normal,    op_si,          op_void>        ; 0101 0110
;     instruction<ins_push,       ins_type_normal,    op_di,          op_void>        ; 0101 0111
;     instruction<ins_pop,        ins_type_normal,    op_ax,          op_void>        ; 0101 1000
;     instruction<ins_pop,        ins_type_normal,    op_cx,          op_void>        ; 0101 1001
;     instruction<ins_pop,        ins_type_normal,    op_dx,          op_void>        ; 0101 1010
;     instruction<ins_pop,        ins_type_normal,    op_bx,          op_void>        ; 0101 1011
;     instruction<ins_pop,        ins_type_normal,    op_sp,          op_void>        ; 0101 1100
;     instruction<ins_pop,        ins_type_normal,    op_bp,          op_void>        ; 0101 1101
;     instruction<ins_pop,        ins_type_normal,    op_si,          op_void>        ; 0101 1110
;     instruction<ins_pop,        ins_type_normal,    op_di,          op_void>        ; 0101 1111
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0000
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0001
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0010
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0011
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0100
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0101
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0110
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0111
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1000
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1001
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1010
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1011
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1100
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1101
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1110
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1111
;     instruction<ins_jo,         ins_type_normal,    op_short,       op_void>        ; 0111 0000
;     instruction<ins_jno,        ins_type_normal,    op_short,       op_void>        ; 0111 0001
;     instruction<ins_jb,         ins_type_normal,    op_short,       op_void>        ; 0111 0010
;     instruction<ins_jae,        ins_type_normal,    op_short,       op_void>        ; 0111 0011
;     instruction<ins_je,         ins_type_normal,    op_short,       op_void>        ; 0111 0100
;     instruction<ins_jne,        ins_type_normal,    op_short,       op_void>        ; 0111 0101
;     instruction<ins_jbe,        ins_type_normal,    op_short,       op_void>        ; 0111 0110
;     instruction<ins_ja,         ins_type_normal,    op_short,       op_void>        ; 0111 0111
;     instruction<ins_js,         ins_type_normal,    op_short,       op_void>        ; 0111 1000
;     instruction<ins_jns,        ins_type_normal,    op_short,       op_void>        ; 0111 1001
;     instruction<ins_jp,         ins_type_normal,    op_short,       op_void>        ; 0111 1010
;     instruction<ins_jnp,        ins_type_normal,    op_short,       op_void>        ; 0111 1011
;     instruction<INS_JL,         ins_type_normal,    op_short,       op_void>        ; 0111 1100
;     instruction<ins_jge,        ins_type_normal,    op_short,       op_void>        ; 0111 1101
;     instruction<ins_jle,        ins_type_normal,    op_short,       op_void>        ; 0111 1110
;     instruction<ins_jg,         ins_type_normal,    op_short,       op_void>        ; 0111 1111
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1000 0000
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1000 0001
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1000 0010
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1000 0011
;     instruction<ins_test,       ins_type_normal,    op_reg8,        op_regmem8>     ; 1000 0100
;     instruction<ins_test,       ins_type_normal,    op_reg16,       op_regmem16>    ; 1000 0101
;     instruction<ins_xchg,       ins_type_normal,    op_reg8,        op_regmem8>     ; 1000 0110
;     instruction<ins_xchg,       ins_type_normal,    op_reg16,       op_regmem16>    ; 1000 0111
;     instruction<ins_mov,        ins_type_normal,    op_regmem8,     op_reg8>        ; 1000 1000
;     instruction<ins_mov,        ins_type_normal,    op_regmem16,    op_reg16>       ; 1000 1001
;     instruction<ins_mov,        ins_type_normal,    op_reg8,        op_regmem8>     ; 1000 1010
;     instruction<ins_mov,        ins_type_normal,    op_reg16,       op_regmem16>    ; 1000 1011
;     instruction<ins_mov,        ins_type_normal,    op_regmem16,    op_segreg>      ; 1000 1100
;     instruction<ins_lea,        ins_type_normal,    op_reg16,       op_regmem16>    ; 1000 1101
;     instruction<ins_mov,        ins_type_normal,    op_segreg,      op_regmem16>    ; 1000 1110
;     instruction<ins_pop,        ins_type_normal,    op_regmem16,    op_void>        ; 1000 1111
;     instruction<ins_xchg,       ins_type_normal,    op_ax,          op_ax>          ; 1001 0000
;     instruction<ins_xchg,       ins_type_normal,    op_cx,          op_ax>          ; 1001 0001
;     instruction<ins_xchg,       ins_type_normal,    op_dx,          op_ax>          ; 1001 0010
;     instruction<ins_xchg,       ins_type_normal,    op_bx,          op_ax>          ; 1001 0011
;     instruction<ins_xchg,       ins_type_normal,    op_sp,          op_ax>          ; 1001 0100
;     instruction<ins_xchg,       ins_type_normal,    op_bp,          op_ax>          ; 1001 0101
;     instruction<ins_xchg,       ins_type_normal,    op_si,          op_ax>          ; 1001 0110
;     instruction<ins_xchg,       ins_type_normal,    op_di,          op_ax>          ; 1001 0111
;     instruction<ins_cbw,        ins_type_normal,    op_void,        op_void>        ; 1001 1000
;     instruction<ins_cwd,        ins_type_normal,    op_void,        op_void>        ; 1001 1001
;     instruction<ins_call,       ins_type_normal,    op_far,         op_void>        ; 1001 1010
;     instruction<ins_wait,       ins_type_normal,    op_void,        op_void>        ; 1001 1011
;     instruction<ins_pushf,      ins_type_normal,    op_void,        op_void>        ; 1001 1100
;     instruction<ins_popf,       ins_type_normal,    op_void,        op_void>        ; 1001 1101
;     instruction<ins_sahf,       ins_type_normal,    op_void,        op_void>        ; 1001 1110
;     instruction<ins_lahf,       ins_type_normal,    op_void,        op_void>        ; 1001 1111
;     instruction<ins_mov,        ins_type_normal,    op_al,          op_mem>         ; 1010 0000
;     instruction<ins_mov,        ins_type_normal,    op_ax,          op_mem>         ; 1010 0001
;     instruction<ins_mov,        ins_type_normal,    op_mem,         op_al>          ; 1010 0010
;     instruction<ins_mov,        ins_type_normal,    op_mem,         op_ax>          ; 1010 0011
;     instruction<ins_movsb,      ins_type_normal,    op_void,        op_void>        ; 1010 0100
;     instruction<ins_movsw,      ins_type_normal,    op_void,        op_void>        ; 1010 0101
;     instruction<ins_cmpsb,      ins_type_normal,    op_void,        op_void>        ; 1010 0110
;     instruction<ins_cmpsw,      ins_type_normal,    op_void,        op_void>        ; 1010 0111
;     instruction<ins_test,       ins_type_normal,    op_al,          op_imm8>        ; 1010 1000
;     instruction<ins_test,       ins_type_normal,    op_ax,          op_imm16>       ; 1010 1001
;     instruction<ins_stosb,      ins_type_normal,    op_void,        op_void>        ; 1010 1010
;     instruction<ins_stosw,      ins_type_normal,    op_void,        op_void>        ; 1010 1011
;     instruction<ins_lodsb,      ins_type_normal,    op_void,        op_void>        ; 1010 1100
;     instruction<ins_lodsw,      ins_type_normal,    op_void,        op_void>        ; 1010 1101
;     instruction<ins_scasb,      ins_type_normal,    op_void,        op_void>        ; 1010 1110
;     instruction<ins_scasw,      ins_type_normal,    op_void,        op_void>        ; 1010 1111
;     instruction<ins_mov,        ins_type_normal,    op_al,          op_imm8>        ; 1011 0000
;     instruction<ins_mov,        ins_type_normal,    op_cl,          op_imm8>        ; 1011 0001
;     instruction<ins_mov,        ins_type_normal,    op_dl,          op_imm8>        ; 1011 0010
;     instruction<ins_mov,        ins_type_normal,    op_bl,          op_imm8>        ; 1011 0011
;     instruction<ins_mov,        ins_type_normal,    op_ah,          op_imm8>        ; 1011 0100
;     instruction<ins_mov,        ins_type_normal,    op_ch,          op_imm8>        ; 1011 0101
;     instruction<ins_mov,        ins_type_normal,    op_dh,          op_imm8>        ; 1011 0110
;     instruction<ins_mov,        ins_type_normal,    op_bh,          op_imm8>        ; 1011 0111
;     instruction<ins_mov,        ins_type_normal,    op_ax,          op_imm16>       ; 1011 1000
;     instruction<ins_mov,        ins_type_normal,    op_cx,          op_imm16>       ; 1011 1001
;     instruction<ins_mov,        ins_type_normal,    op_dx,          op_imm16>       ; 1011 1010
;     instruction<ins_mov,        ins_type_normal,    op_bx,          op_imm16>       ; 1011 1011
;     instruction<ins_mov,        ins_type_normal,    op_sp,          op_imm16>       ; 1011 1100
;     instruction<ins_mov,        ins_type_normal,    op_bp,          op_imm16>       ; 1011 1101
;     instruction<ins_mov,        ins_type_normal,    op_si,          op_imm16>       ; 1011 1110
;     instruction<ins_mov,        ins_type_normal,    op_di,          op_imm16>       ; 1011 1111
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1100 0000
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1100 0001
;     instruction<ins_ret,        ins_type_normal,    op_imm16,       op_void>        ; 1100 0010
;     instruction<ins_ret,        ins_type_normal,    op_void,        op_void>        ; 1100 0011
;     instruction<INS_LES,        ins_type_normal,    op_reg16,       op_regmem16>    ; 1100 0100
;     instruction<ins_lds,        ins_type_normal,    op_reg16,       op_regmem16>    ; 1100 0101
;     instruction<ins_mov,        ins_type_normal,    op_regmem8,     op_imm8>        ; 1100 0110
;     instruction<ins_mov,        ins_type_normal,    op_regmem16,    op_imm16>       ; 1100 0111
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1100 1000
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1100 1001
;     instruction<ins_retf,       ins_type_normal,    op_imm16,       op_void>        ; 1100 1010
;     instruction<ins_retf,       ins_type_normal,    op_void,        op_void>        ; 1100 1011
;     instruction<ins_int,        ins_type_normal,    op_const3,      op_void>        ; 1100 1100
;     instruction<ins_int,        ins_type_normal,    op_imm8,        op_void>        ; 1100 1101
;     instruction<ins_into,       ins_type_normal,    op_void,        op_void>        ; 1100 1110
;     instruction<ins_iret,       ins_type_normal,    op_void,        op_void>        ; 1100 1111
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0000
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0001
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0010
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0011
;     instruction<ins_aam,        ins_type_custom,    op_void,        op_void>        ; 1101 0100
;     instruction<ins_aad,        ins_type_custom,    op_void,        op_void>        ; 1101 0101
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0110
;     instruction<ins_xlat,       ins_type_normal,    op_void,        op_void>        ; 1101 0111
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1000
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1001
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1010
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1011
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1100
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1101
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1110
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1111
;     instruction<INS_LOOPNE,     ins_type_normal,    op_short,       op_void>        ; 1110 0000
;     instruction<INS_LOOPE,      ins_type_normal,    op_short,       op_void>        ; 1110 0001
;     instruction<INS_LOOP,       ins_type_normal,    op_short,       op_void>        ; 1110 0010
;     instruction<ins_jcxz,       ins_type_normal,    op_short,       op_void>        ; 1110 0011
;     instruction<ins_in,         ins_type_normal,    op_al,          op_imm8>        ; 1110 0100
;     instruction<ins_in,         ins_type_normal,    op_ax,          op_imm16>       ; 1110 0101
;     instruction<ins_out,        ins_type_normal,    op_imm8,        op_al>          ; 1110 0110
;     instruction<ins_out,        ins_type_normal,    op_imm8,        op_ax>          ; 1110 0111
;     instruction<ins_call,       ins_type_normal,    op_near,        op_void>        ; 1110 1000
;     instruction<ins_jmp,        ins_type_normal,    op_near,        op_void>        ; 1110 1001
;     instruction<ins_jmp,        ins_type_normal,    op_far,         op_void>        ; 1110 1010
;     instruction<ins_jmp,        ins_type_normal,    op_short,       op_void>        ; 1110 1011
;     instruction<ins_in,         ins_type_normal,    op_al,          op_dx>          ; 1110 1100
;     instruction<ins_in,         ins_type_normal,    op_ax,          op_dx>          ; 1110 1101
;     instruction<ins_out,        ins_type_normal,    op_dx,          op_al>          ; 1110 1110
;     instruction<ins_out,        ins_type_normal,    op_dx,          op_ax>          ; 1110 1111
;     instruction<ins_lock,       ins_type_prefix,    op_void,        op_void>        ; 1111 0000
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 0001
;     instruction<ins_repne,      ins_type_prefix,    op_void,        op_void>        ; 1111 0010
;     instruction<ins_rep,        ins_type_prefix,    op_void,        op_void>        ; 1111 0011
;     instruction<ins_hlt,        ins_type_normal,    op_void,        op_void>        ; 1111 0100
;     instruction<ins_cmc,        ins_type_normal,    op_void,        op_void>        ; 1111 0101
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 0110
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 0111
;     instruction<ins_clc,        ins_type_normal,    op_void,        op_void>        ; 1111 1000
;     instruction<ins_stc,        ins_type_normal,    op_void,        op_void>        ; 1111 1001
;     instruction<ins_cli,        ins_type_normal,    op_void,        op_void>        ; 1111 1010
;     instruction<ins_sti,        ins_type_normal,    op_void,        op_void>        ; 1111 1011
;     instruction<ins_cld,        ins_type_normal,    op_void,        op_void>        ; 1111 1100
;     instruction<ins_std,        ins_type_normal,    op_void,        op_void>        ; 1111 1101
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 1110
;     instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 1111
; 
; 
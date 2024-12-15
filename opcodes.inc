ins_unknown     DB "UNKNOWN instruction$"
ins_mov         DB "MOV $"
ins_in          DB "IN $"
ins_out         DB "OUT $"
ins_push        DB "PUSH $"
ins_pop         DB "POP $"
ins_xchg        DB "XCHG $"
ins_xlat        DB "XLAT $"
ins_lea         DB "LEA $"
ins_lds         DB "LDS $"
ins_lss         DB "LSS $"
ins_lahf        DB "LAHF $"
ins_sahf        DB "SAHF $"
ins_pushf       DB "PUSHF $"
ins_popf        DB "POPF $"
ins_ja          DB "JA $"
ins_jae         DB "JAE $"
ins_jb          DB "JB $"
ins_jbe         DB "JBE $"
ins_je          DB "JE $"
ins_jcxz        DB "JCXZ $"
ins_jg          DB "JG $"
ins_jge         DB "JGE $"
ins_jl          DB "JL $"
ins_jle         DB "JLE $"
ins_jne         DB "JNE $"
ins_jno         DB "JNO $"
ins_jnp         DB "JNP $"
ins_jp          DB "JP $"
ins_jo          DB "JO $"
ins_jns         DB "JNS $"
ins_js          DB "JS $"

ins_add         DB "ADD $"
ins_adc         DB "ADC $"
ins_inc         DB "INC $"
ins_aaa         DB "AAA $"
ins_daa         DB "DAA $"
ins_sub         DB "SUB $"
ins_sbb         DB "SBB $"
ins_dec         DB "DEC $"
ins_neg         DB "NEG $"
ins_cmp         DB "CMP $"
ins_aas         DB "AAS $"
ins_das         DB "DAS $"
ins_mul         DB "MUL $"
ins_imul        DB "IMUL $"
ins_aam         DB "AAM $"
ins_div         DB "DIV $"
ins_idiv        DB "IDIV $"
ins_aad         DB "AAD $"
ins_cbw         DB "CBW $"
ins_cwd         DB "CWD $"

ins_not         DB "NOT $"
ins_and         DB "AND $"
ins_or          DB "OR $"
ins_xor         DB "XOR $"
ins_test        DB "TEST $"

ins_shl         DB "SHL $"
ins_shr         DB "SHR $"
ins_sar         DB "SAR $"

ins_rol         DB "ROL $"
ins_ror         DB "ROR $"
ins_rcl         DB "RCL $"
ins_rcr         DB "RCR $"

ins_rep         DB "REP $"
ins_repne       DB "REPNE $"

ins_movsb       DB "MOVSB $"
ins_movsw       DB "MOVSW $"
ins_cmpsb       DB "CMPSB $"
ins_cmpsw       DB "CMPSW $"
ins_scasb       DB "SCASB $"
ins_scasw       DB "SCASW $"
ins_stosb       DB "STOSB $"
ins_stosw       DB "STOSW $"
ins_lodsb       DB "LODSB $"
ins_lodsw       DB "LODSW $"

ins_call        DB "CALL $"
ins_ret         DB "RET $"
ins_retf        DB "RETF $"
ins_jmp         DB "JMP $"

ins_int         DB "INT $"
ins_into        DB "INTO $"
ins_iret        DB "IRET $"

ins_stc         DB "STC $"
ins_clc         DB "CLC $"
ins_cmc         DB "CMC $"
ins_std         DB "STD $"
ins_cld         DB "CLD $"
ins_sti         DB "STI $"
ins_cli         DB "CLI $"

ins_hlt         DB "HLT $"
ins_wait        DB "WAIT $"
ins_lock        DB "LOCK $"
ins_nop         DB "NOP $"

ins_types ENUM {
    ins_type_unknown,
    ins_type_normal,
    ins_type_extented,
    ins_type_seg_ovr,
    ins_type_prefix,
    ins_type_custom
}

ins_operands ENUM {
    op_void,
    op_al,
    op_cl,
    op_dl,
    op_bl,
    op_ah,
    op_ch,
    op_dh,
    op_bh,
    op_ax,
    op_cx,
    op_dx,
    op_bx,
    op_sp,
    op_bp,
    op_si,
    op_di,
    op_es,
    op_cs,
    op_ss,
    op_ds,
    op_const1,
    op_const3,
    op_imm8,
    op_eimm8,
    op_short,
    op_imm16,
    op_near,
    op_mem,
    op_far,
    op_reg8,
    op_reg16,
    op_segreg,
    op_regmem8,
    op_regmem16,
}

LABEL instruction_list
    instruction<ins_add,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0000 0000
    instruction<ins_add,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0000 0001
    instruction<ins_add,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0000 0010
    instruction<ins_add,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0000 0011
    instruction<ins_add,        ins_type_normal,    op_al,          op_imm8>        ; 0000 0100
    instruction<ins_add,        ins_type_normal,    op_ax,          op_imm16>       ; 0000 0101
    instruction<ins_push,       ins_type_normal,    op_es,          op_void>        ; 0000 0110
    instruction<ins_pop,        ins_type_normal,    op_es,          op_void>        ; 0000 0111
    instruction<ins_or,         ins_type_normal,    op_regmem8,     op_reg8>        ; 0000 1000
    instruction<ins_or,         ins_type_normal,    op_regmem16,    op_reg16>       ; 0000 1001
    instruction<ins_or,         ins_type_normal,    op_reg8,        op_regmem8>     ; 0000 1010
    instruction<ins_or,         ins_type_normal,    op_reg16,       op_regmem16>    ; 0000 1011
    instruction<ins_or,         ins_type_normal,    op_al,          op_imm8>        ; 0000 1100
    instruction<ins_or,         ins_type_normal,    op_ax,          op_imm16>       ; 0000 1101
    instruction<ins_push,       ins_type_normal,    op_cs,          op_void>        ; 0000 1110
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0000 1111
    instruction<ins_adc,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0001 0000
    instruction<ins_adc,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0001 0001
    instruction<ins_adc,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0001 0010
    instruction<ins_adc,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0001 0011
    instruction<ins_adc,        ins_type_normal,    op_al,          op_imm8>        ; 0001 0100
    instruction<ins_adc,        ins_type_normal,    op_ax,          op_imm16>       ; 0001 0101
    instruction<ins_push,       ins_type_normal,    op_ss,          op_void>        ; 0001 0110
    instruction<ins_pop,        ins_type_normal,    op_ss,          op_void>        ; 0001 0111
    instruction<ins_sbb,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0001 1000
    instruction<ins_sbb,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0001 1001
    instruction<ins_sbb,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0001 1010
    instruction<ins_sbb,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0001 1011
    instruction<ins_sbb,        ins_type_normal,    op_al,          op_imm8>        ; 0001 1100
    instruction<ins_sbb,        ins_type_normal,    op_ax,          op_imm16>       ; 0001 1101
    instruction<ins_push,       ins_type_normal,    op_ds,          op_void>        ; 0001 1110
    instruction<ins_pop,        ins_type_normal,    op_ds,          op_void>        ; 0001 1111
    instruction<ins_and,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0010 0000
    instruction<ins_and,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0010 0001
    instruction<ins_and,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0010 0010
    instruction<ins_and,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0010 0011
    instruction<ins_and,        ins_type_normal,    op_al,          op_imm8>        ; 0010 0100
    instruction<ins_and,        ins_type_normal,    op_ax,          op_imm16>       ; 0010 0101
    instruction<op_es,          ins_type_seg_ovr,   op_void,        op_void>        ; 0010 0110
    instruction<ins_daa,        ins_type_normal,    op_void,        op_void>        ; 0010 0111
    instruction<ins_sub,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0010 1000
    instruction<ins_sub,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0010 1001
    instruction<ins_sub,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0010 1010
    instruction<ins_sub,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0010 1011
    instruction<ins_sub,        ins_type_normal,    op_al,          op_imm8>        ; 0010 1100
    instruction<ins_sub,        ins_type_normal,    op_ax,          op_imm16>       ; 0010 1101
    instruction<op_cs,          ins_type_seg_ovr,   op_void,        op_void>        ; 0010 1110
    instruction<ins_das,        ins_type_normal,    op_void,        op_void>        ; 0010 1111
    instruction<ins_xor,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0011 0000
    instruction<ins_xor,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0011 0001
    instruction<ins_xor,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0011 0010
    instruction<ins_xor,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0011 0011
    instruction<ins_xor,        ins_type_normal,    op_al,          op_imm8>        ; 0011 0100
    instruction<ins_xor,        ins_type_normal,    op_ax,          op_imm16>       ; 0011 0101
    instruction<op_ss,          ins_type_seg_ovr,   op_void,        op_void>        ; 0011 0110
    instruction<ins_aaa,        ins_type_normal,    op_void,        op_void>        ; 0011 0111
    instruction<ins_cmp,        ins_type_normal,    op_regmem8,     op_reg8>        ; 0011 1000
    instruction<ins_cmp,        ins_type_normal,    op_regmem16,    op_reg16>       ; 0011 1001
    instruction<ins_cmp,        ins_type_normal,    op_reg8,        op_regmem8>     ; 0011 1010
    instruction<ins_cmp,        ins_type_normal,    op_reg16,       op_regmem16>    ; 0011 1011
    instruction<ins_cmp,        ins_type_normal,    op_al,          op_imm8>        ; 0011 1100
    instruction<ins_cmp,        ins_type_normal,    op_ax,          op_imm16>       ; 0011 1101
    instruction<op_ds,          ins_type_seg_ovr,   op_void,        op_void>        ; 0011 1110
    instruction<ins_aas,        ins_type_normal,    op_void,        op_void>        ; 0011 1111
    instruction<ins_inc,        ins_type_normal,    op_ax,          op_void>        ; 0100 0000
    instruction<ins_inc,        ins_type_normal,    op_cx,          op_void>        ; 0100 0001
    instruction<ins_inc,        ins_type_normal,    op_dx,          op_void>        ; 0100 0010
    instruction<ins_inc,        ins_type_normal,    op_bx,          op_void>        ; 0100 0011
    instruction<ins_inc,        ins_type_normal,    op_sp,          op_void>        ; 0100 0100
    instruction<ins_inc,        ins_type_normal,    op_bp,          op_void>        ; 0100 0101
    instruction<ins_inc,        ins_type_normal,    op_si,          op_void>        ; 0100 0110
    instruction<ins_inc,        ins_type_normal,    op_di,          op_void>        ; 0100 0111
    instruction<ins_dec,        ins_type_normal,    op_ax,          op_void>        ; 0100 1000
    instruction<ins_dec,        ins_type_normal,    op_cx,          op_void>        ; 0100 1001
    instruction<ins_dec,        ins_type_normal,    op_dx,          op_void>        ; 0100 1010
    instruction<ins_dec,        ins_type_normal,    op_bx,          op_void>        ; 0100 1011
    instruction<ins_dec,        ins_type_normal,    op_sp,          op_void>        ; 0100 1100
    instruction<ins_dec,        ins_type_normal,    op_bp,          op_void>        ; 0100 1101
    instruction<ins_dec,        ins_type_normal,    op_si,          op_void>        ; 0100 1110
    instruction<ins_dec,        ins_type_normal,    op_di,          op_void>        ; 0100 1111
    instruction<ins_push,       ins_type_normal,    op_ax,          op_void>        ; 0101 0000
    instruction<ins_push,       ins_type_normal,    op_cx,          op_void>        ; 0101 0001
    instruction<ins_push,       ins_type_normal,    op_dx,          op_void>        ; 0101 0010
    instruction<ins_push,       ins_type_normal,    op_bx,          op_void>        ; 0101 0011
    instruction<ins_push,       ins_type_normal,    op_sp,          op_void>        ; 0101 0100
    instruction<ins_push,       ins_type_normal,    op_bp,          op_void>        ; 0101 0101
    instruction<ins_push,       ins_type_normal,    op_si,          op_void>        ; 0101 0110
    instruction<ins_push,       ins_type_normal,    op_di,          op_void>        ; 0101 0111
    instruction<ins_pop,        ins_type_normal,    op_ax,          op_void>        ; 0101 1000
    instruction<ins_pop,        ins_type_normal,    op_cx,          op_void>        ; 0101 1001
    instruction<ins_pop,        ins_type_normal,    op_dx,          op_void>        ; 0101 1010
    instruction<ins_pop,        ins_type_normal,    op_bx,          op_void>        ; 0101 1011
    instruction<ins_pop,        ins_type_normal,    op_sp,          op_void>        ; 0101 1100
    instruction<ins_pop,        ins_type_normal,    op_bp,          op_void>        ; 0101 1101
    instruction<ins_pop,        ins_type_normal,    op_si,          op_void>        ; 0101 1110
    instruction<ins_pop,        ins_type_normal,    op_di,          op_void>        ; 0101 1111
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0000
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0001
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0010
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0011
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0100
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0101
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0110
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 0111
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1000
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1001
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1010
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1011
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1100
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1101
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1110
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 0110 1111
    instruction<ins_jo,         ins_type_normal,    op_short,       op_void>        ; 0111 0000
    instruction<ins_jno,        ins_type_normal,    op_short,       op_void>        ; 0111 0001
    instruction<ins_jb,         ins_type_normal,    op_short,       op_void>        ; 0111 0010
    instruction<ins_jae,        ins_type_normal,    op_short,       op_void>        ; 0111 0011
    instruction<ins_je,         ins_type_normal,    op_short,       op_void>        ; 0111 0100
    instruction<ins_jne,        ins_type_normal,    op_short,       op_void>        ; 0111 0101
    instruction<ins_jbe,        ins_type_normal,    op_short,       op_void>        ; 0111 0110
    instruction<ins_ja,         ins_type_normal,    op_short,       op_void>        ; 0111 0111
    instruction<ins_js,         ins_type_normal,    op_short,       op_void>        ; 0111 1000
    instruction<ins_jns,        ins_type_normal,    op_short,       op_void>        ; 0111 1001
    instruction<ins_jp,         ins_type_normal,    op_short,       op_void>        ; 0111 1010
    instruction<ins_jnp,        ins_type_normal,    op_short,       op_void>        ; 0111 1011
    instruction<INS_JL,         ins_type_normal,    op_short,       op_void>        ; 0111 1100
    instruction<ins_jge,        ins_type_normal,    op_short,       op_void>        ; 0111 1101
    instruction<ins_jle,        ins_type_normal,    op_short,       op_void>        ; 0111 1110
    instruction<ins_jg,         ins_type_normal,    op_short,       op_void>        ; 0111 1111
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1000 0000
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1000 0001
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1000 0010
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1000 0011
    instruction<ins_test,       ins_type_normal,    op_reg8,        op_regmem8>     ; 1000 0100
    instruction<ins_test,       ins_type_normal,    op_reg16,       op_regmem16>    ; 1000 0101
    instruction<ins_xchg,       ins_type_normal,    op_reg8,        op_regmem8>     ; 1000 0110
    instruction<ins_xchg,       ins_type_normal,    op_reg16,       op_regmem16>    ; 1000 0111
    instruction<ins_mov,        ins_type_normal,    op_regmem8,     op_reg8>        ; 1000 1000
    instruction<ins_mov,        ins_type_normal,    op_regmem16,    op_reg16>       ; 1000 1001
    instruction<ins_mov,        ins_type_normal,    op_reg8,        op_regmem8>     ; 1000 1010
    instruction<ins_mov,        ins_type_normal,    op_reg16,       op_regmem16>    ; 1000 1011
    instruction<ins_mov,        ins_type_normal,    op_regmem16,    op_segreg>      ; 1000 1100
    instruction<ins_lea,        ins_type_normal,    op_reg16,       op_regmem16>    ; 1000 1101
    instruction<ins_mov,        ins_type_normal,    op_segreg,      op_regmem16>    ; 1000 1110
    instruction<ins_pop,        ins_type_normal,    op_regmem16,    op_void>        ; 1000 1111
    instruction<ins_xchg,       ins_type_normal,    op_ax,          op_ax>          ; 1001 0000
    instruction<ins_xchg,       ins_type_normal,    op_cx,          op_ax>          ; 1001 0001
    instruction<ins_xchg,       ins_type_normal,    op_dx,          op_ax>          ; 1001 0010
    instruction<ins_xchg,       ins_type_normal,    op_bx,          op_ax>          ; 1001 0011
    instruction<ins_xchg,       ins_type_normal,    op_sp,          op_ax>          ; 1001 0100
    instruction<ins_xchg,       ins_type_normal,    op_bp,          op_ax>          ; 1001 0101
    instruction<ins_xchg,       ins_type_normal,    op_si,          op_ax>          ; 1001 0110
    instruction<ins_xchg,       ins_type_normal,    op_di,          op_ax>          ; 1001 0111
    instruction<ins_cbw,        ins_type_normal,    op_void,        op_void>        ; 1001 1000
    instruction<ins_cwd,        ins_type_normal,    op_void,        op_void>        ; 1001 1001
    instruction<ins_call,       ins_type_normal,    op_far,         op_void>        ; 1001 1010
    instruction<ins_wait,       ins_type_normal,    op_void,        op_void>        ; 1001 1011
    instruction<ins_pushf,      ins_type_normal,    op_void,        op_void>        ; 1001 1100
    instruction<ins_popf,       ins_type_normal,    op_void,        op_void>        ; 1001 1101
    instruction<ins_sahf,       ins_type_normal,    op_void,        op_void>        ; 1001 1110
    instruction<ins_lahf,       ins_type_normal,    op_void,        op_void>        ; 1001 1111
    instruction<ins_mov,        ins_type_normal,    op_al,          op_mem>         ; 1010 0000
    instruction<ins_mov,        ins_type_normal,    op_ax,          op_mem>         ; 1010 0001
    instruction<ins_mov,        ins_type_normal,    op_mem,         op_al>          ; 1010 0010
    instruction<ins_mov,        ins_type_normal,    op_mem,         op_ax>          ; 1010 0011
    instruction<ins_movsb,      ins_type_normal,    op_void,        op_void>        ; 1010 0100
    instruction<ins_movsw,      ins_type_normal,    op_void,        op_void>        ; 1010 0101
    instruction<ins_cmpsb,      ins_type_normal,    op_void,        op_void>        ; 1010 0110
    instruction<ins_cmpsw,      ins_type_normal,    op_void,        op_void>        ; 1010 0111
    instruction<ins_test,       ins_type_normal,    op_al,          op_imm8>        ; 1010 1000
    instruction<ins_test,       ins_type_normal,    op_ax,          op_imm16>       ; 1010 1001
    instruction<ins_stosb,      ins_type_normal,    op_void,        op_void>        ; 1010 1010
    instruction<ins_stosw,      ins_type_normal,    op_void,        op_void>        ; 1010 1011
    instruction<ins_lodsb,      ins_type_normal,    op_void,        op_void>        ; 1010 1100
    instruction<ins_lodsw,      ins_type_normal,    op_void,        op_void>        ; 1010 1101
    instruction<ins_scasb,      ins_type_normal,    op_void,        op_void>        ; 1010 1110
    instruction<ins_scasw,      ins_type_normal,    op_void,        op_void>        ; 1010 1111
    instruction<ins_mov,        ins_type_normal,    op_al,          op_imm8>        ; 1011 0000
    instruction<ins_mov,        ins_type_normal,    op_cl,          op_imm8>        ; 1011 0001
    instruction<ins_mov,        ins_type_normal,    op_dl,          op_imm8>        ; 1011 0010
    instruction<ins_mov,        ins_type_normal,    op_bl,          op_imm8>        ; 1011 0011
    instruction<ins_mov,        ins_type_normal,    op_ah,          op_imm8>        ; 1011 0100
    instruction<ins_mov,        ins_type_normal,    op_ch,          op_imm8>        ; 1011 0101
    instruction<ins_mov,        ins_type_normal,    op_dh,          op_imm8>        ; 1011 0110
    instruction<ins_mov,        ins_type_normal,    op_bh,          op_imm8>        ; 1011 0111
    instruction<ins_mov,        ins_type_normal,    op_ax,          op_imm16>       ; 1011 1000
    instruction<ins_mov,        ins_type_normal,    op_cx,          op_imm16>       ; 1011 1001
    instruction<ins_mov,        ins_type_normal,    op_dx,          op_imm16>       ; 1011 1010
    instruction<ins_mov,        ins_type_normal,    op_bx,          op_imm16>       ; 1011 1011
    instruction<ins_mov,        ins_type_normal,    op_sp,          op_imm16>       ; 1011 1100
    instruction<ins_mov,        ins_type_normal,    op_bp,          op_imm16>       ; 1011 1101
    instruction<ins_mov,        ins_type_normal,    op_si,          op_imm16>       ; 1011 1110
    instruction<ins_mov,        ins_type_normal,    op_di,          op_imm16>       ; 1011 1111
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1100 0000
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1100 0001
    instruction<ins_ret,        ins_type_normal,    op_imm16,       op_void>        ; 1100 0010
    instruction<ins_ret,        ins_type_normal,    op_void,        op_void>        ; 1100 0011
    instruction<INS_LES,        ins_type_normal,    op_reg16,       op_regmem16>    ; 1100 0100
    instruction<ins_lds,        ins_type_normal,    op_reg16,       op_regmem16>    ; 1100 0101
    instruction<ins_mov,        ins_type_normal,    op_regmem8,     op_imm8>        ; 1100 0110
    instruction<ins_mov,        ins_type_normal,    op_regmem16,    op_imm16>       ; 1100 0111
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1100 1000
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1100 1001
    instruction<ins_retf,       ins_type_normal,    op_imm16,       op_void>        ; 1100 1010
    instruction<ins_retf,       ins_type_normal,    op_void,        op_void>        ; 1100 1011
    instruction<ins_int,        ins_type_normal,    op_const3,      op_void>        ; 1100 1100
    instruction<ins_int,        ins_type_normal,    op_imm8,        op_void>        ; 1100 1101
    instruction<ins_into,       ins_type_normal,    op_void,        op_void>        ; 1100 1110
    instruction<ins_iret,       ins_type_normal,    op_void,        op_void>        ; 1100 1111
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0000
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0001
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0010
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0011
    instruction<ins_aam,        ins_type_custom,    op_void,        op_void>        ; 1101 0100
    instruction<ins_aad,        ins_type_custom,    op_void,        op_void>        ; 1101 0101
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 0110
    instruction<ins_xlat,       ins_type_normal,    op_void,        op_void>        ; 1101 0111
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1000
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1001
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1010
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1011
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1100
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1101
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1110
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1101 1111
    instruction<INS_LOOPNE,     ins_type_normal,    op_short,       op_void>        ; 1110 0000
    instruction<INS_LOOPE,      ins_type_normal,    op_short,       op_void>        ; 1110 0001
    instruction<INS_LOOP,       ins_type_normal,    op_short,       op_void>        ; 1110 0010
    instruction<ins_jcxz,       ins_type_normal,    op_short,       op_void>        ; 1110 0011
    instruction<ins_in,         ins_type_normal,    op_al,          op_imm8>        ; 1110 0100
    instruction<ins_in,         ins_type_normal,    op_ax,          op_imm16>       ; 1110 0101
    instruction<ins_out,        ins_type_normal,    op_imm8,        op_al>          ; 1110 0110
    instruction<ins_out,        ins_type_normal,    op_imm8,        op_ax>          ; 1110 0111
    instruction<ins_call,       ins_type_normal,    op_near,        op_void>        ; 1110 1000
    instruction<ins_jmp,        ins_type_normal,    op_near,        op_void>        ; 1110 1001
    instruction<ins_jmp,        ins_type_normal,    op_far,         op_void>        ; 1110 1010
    instruction<ins_jmp,        ins_type_normal,    op_short,       op_void>        ; 1110 1011
    instruction<ins_in,         ins_type_normal,    op_al,          op_dx>          ; 1110 1100
    instruction<ins_in,         ins_type_normal,    op_ax,          op_dx>          ; 1110 1101
    instruction<ins_out,        ins_type_normal,    op_dx,          op_al>          ; 1110 1110
    instruction<ins_out,        ins_type_normal,    op_dx,          op_ax>          ; 1110 1111
    instruction<ins_lock,       ins_type_prefix,    op_void,        op_void>        ; 1111 0000
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 0001
    instruction<ins_repne,      ins_type_prefix,    op_void,        op_void>        ; 1111 0010
    instruction<ins_rep,        ins_type_prefix,    op_void,        op_void>        ; 1111 0011
    instruction<ins_hlt,        ins_type_normal,    op_void,        op_void>        ; 1111 0100
    instruction<ins_cmc,        ins_type_normal,    op_void,        op_void>        ; 1111 0101
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 0110
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 0111
    instruction<ins_clc,        ins_type_normal,    op_void,        op_void>        ; 1111 1000
    instruction<ins_stc,        ins_type_normal,    op_void,        op_void>        ; 1111 1001
    instruction<ins_cli,        ins_type_normal,    op_void,        op_void>        ; 1111 1010
    instruction<ins_sti,        ins_type_normal,    op_void,        op_void>        ; 1111 1011
    instruction<ins_cld,        ins_type_normal,    op_void,        op_void>        ; 1111 1100
    instruction<ins_std,        ins_type_normal,    op_void,        op_void>        ; 1111 1101
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 1110
    instruction<ins_unknown,    ins_type_unknown,   op_void,        op_void>        ; 1111 1111


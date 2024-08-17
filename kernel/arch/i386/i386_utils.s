.section text

.global _mos_k_hang_i386
.type _mos_k_hang_i386, @function
_mos_k_hang_i386:
    cli
    hlt
    jmp _mos_k_hang_i386

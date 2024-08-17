#include "arch/utils.h"
#include "arch/vga.h"

void mos_k_main(void) {
    const vga_module vga = _mos_k_get_vga_module();

    vga.clear();
    vga.move_cursor(0, 0);
    vga.puts("mOS - v 0.1.0");

}

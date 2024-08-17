#pragma once

#include <stdint.h>


typedef enum {
    vga_color_black,
    vga_color_blue,
    vga_color_green,
    vga_color_cyan,
    vga_color_red,
    vga_color_magenta,
    vga_color_brown,
    vga_color_light_grey,
    vga_color_dark_grey,
    vga_color_light_blue,
    vga_color_light_green,
    vga_color_light_cyan,
    vga_color_light_red,
    vga_color_light_magenta,
    vga_color_light_brown,
    vga_color_white
} vga_color;

typedef struct {
    /* Printing functions */
    void (*clear)(void);

    void (*set_colors)(vga_color foreground, vga_color background);
    void (*move_cursor)(uint8_t x, uint8_t y);

    void (*putc)(const char c);
    void (*puts)(const char *s);
} vga_module;

#ifdef _MOS_K_ARCH_I386
vga_module _mos_k_get_vga_module(void);
#endif

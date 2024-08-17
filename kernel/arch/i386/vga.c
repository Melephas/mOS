#include "../vga.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_ADDRESS 0xB8000


static uint8_t color;
static uint8_t row;
static uint8_t column;
static uint16_t *buffer;


static void clear(void);
static void set_colors(vga_color foreground, vga_color background);
static void move_cursor(uint8_t x, uint8_t y);
static void putc(const char c);
static void puts(const char* str);

static void clear(void) {
    move_cursor(0, 0);
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
      putc(' ');
    }
}

static void set_colors(vga_color foreground, vga_color background) {
    color = foreground | background << 4;
}

static void move_cursor(uint8_t x, uint8_t y) {
    row = y;
    column = x;
}

static void putc(const char c) {
    const uint8_t offset = row * VGA_WIDTH + column;
    buffer[offset] = (uint16_t) c | (uint16_t) color << 8;
    if (column++ == VGA_WIDTH) {
        column = 0;
        if (row++ == VGA_HEIGHT) {
            row = 0;
        }
    }
}

static void puts(const char* str) {
    while (*str) {
        putc(*str++);
    }
}

vga_module _mos_k_get_vga_module(void) {
    buffer = (uint16_t*) VGA_ADDRESS;

    set_colors(vga_color_light_grey, vga_color_black);
    clear();

    return (vga_module) {
        .clear = clear,
        .set_colors = set_colors,
        .move_cursor = move_cursor,
        .putc = putc,
        .puts = puts,
    };
}

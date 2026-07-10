/*
 * hagl_hal.c
 *
 *  Created on: Jun 18, 2026
 *      Author: 02
 */

#ifndef SRC_HAGL_HAL_C_
#define SRC_HAGL_HAL_C_

#include "hagl_hal.h"
#include "lcd.h"

static void put_pixel(void *self, int16_t x, int16_t y, hagl_color_t color)
{
    if (x < 0 || y < 0 || x >= LCD_WIDTH || y >= LCD_HEIGHT)
    {
        return;
    }

    lcd_put_pixel(x, y, color);
}

static hagl_color_t get_pixel(void *self, int16_t x, int16_t y)
{
    return 0;
}

static hagl_color_t color(void *self, uint8_t r, uint8_t g, uint8_t b)
{
    uint16_t c;

    c = ((r & 0xF8) << 8) |
        ((g & 0xFC) << 3) |
        (b >> 3);

    return (uint16_t)((c >> 8) | (c << 8));
}

static size_t flush(void *self)
{
    lcd_copy();
    return 0;
}

static void close(void *self)
{
}

void hagl_hal_init(hagl_backend_t *backend)
{
    backend->width = LCD_WIDTH;
    backend->height = LCD_HEIGHT;
    backend->depth = 16;

    backend->put_pixel = put_pixel;
    backend->get_pixel = get_pixel;
    backend->color = color;

    backend->flush = flush;
    backend->close = close;

    backend->buffer = 0;
    backend->buffer2 = 0;
}

#endif /* SRC_HAGL_HAL_C_ */

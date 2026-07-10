/*
 * hagl_hal.h
 *
 *  Created on: Jun 18, 2026
 *      Author: 02
 */

#ifndef INC_HAGL_HAL_H_
#define INC_HAGL_HAL_H_

#pragma once

#include <stdint.h>
#include <stddef.h>

#include "lcd.h"
#include "hagl/backend.h"
#include "hagl_hal_color.h"

#define DISPLAY_WIDTH   (LCD_WIDTH)
#define DISPLAY_HEIGHT  (LCD_HEIGHT)
#define DISPLAY_DEPTH   16

void hagl_hal_init(hagl_backend_t *backend);

#endif /* INC_HAGL_HAL_H_ */

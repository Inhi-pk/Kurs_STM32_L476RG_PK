/*
 * ws2812b.h
 *
 *  Created on: 9 lip 2026
 *      Author: Paweł Kopczyński
 */

#ifndef INC_WS2812B_H_
#define INC_WS2812B_H_

#pragma once

#include "stm32l476xx.h"
#include "tim.h"

void ws2812b_init(TIM_HandleTypeDef *TIM_Handle, uint32_t Channel);

void ws2812b_set_color(uint32_t led, uint8_t red, uint8_t green, uint8_t blue);

void ws2812b_update(void);

void ws2812b_wait(void);


#endif /* INC_WS2812B_H_ */

/*
 * lps25hb.h
 *
 *  Created on: 7 lip 2026
 *      Author: Paweł Kopczyński
 */

#ifndef INC_LPS25HB_H_
#define INC_LPS25HB_H_

#pragma once
#include "stm32l4xx.h"

HAL_StatusTypeDef lps_init(void);

float lps_read_temp(void);

float lps_read_pressure(void);

void lps_set_calib(uint16_t value);

#endif

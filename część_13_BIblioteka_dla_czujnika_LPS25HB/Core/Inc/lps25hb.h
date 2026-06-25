/*
 * lps25hb.h
 *
 *  Created on: Jun 19, 2026
 *      Author: 02
 */

#ifndef INC_LPS25HB_H_
#define INC_LPS25HB_H_

#pragma once
#include "stm32l4xx.h"
// Inicjalizacja czujnika LPS25HB
// Obudzenie i automatyczne pomiary
// return - HAL_OK lub HAL_ERROR
HAL_StatusTypeDef lps25hb_init(void);
// Odczyt temperatury
// return - wynik w stopniach C
float lps25hb_read_temp(void);
// Odczyt ciśnienia
// reuturn - wynik w hPa
float lps25hb_read_pressure(void);

void lps25hb_set_calib(uint16_t value);


#endif /* INC_LPS25HB_H_ */

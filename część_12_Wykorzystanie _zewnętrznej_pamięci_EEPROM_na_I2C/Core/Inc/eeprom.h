/*
 * eeprom.h
 *
 *  Created on: 6 lip 2026
 *      Author: Paweł Kopczyński
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#pragma once

#include "stm32l4xx.h"

void eeprom_wait(void);

HAL_StatusTypeDef eeprom_read(uint32_t addr, void* data, uint32_t size);

HAL_StatusTypeDef eeprom_write(uint32_t addr, const void* data, uint32_t size);


#endif /* INC_EEPROM_H_ */

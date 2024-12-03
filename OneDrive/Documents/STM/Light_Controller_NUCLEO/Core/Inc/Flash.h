/*
 * Flash.h
 *
 *  Created on: Nov 26, 2024
 *      Author: ASUS
 */
#include "main.h"

#ifndef INC_FLASH_H_
#define INC_FLASH_H_
#define 	FLASH_ADDR_PAGE_126 ((uint32_t)0x0801F810)
#define 	FLASH_ADDR_PAGE_127 ((uint32_t)0x0801FC00)

#define 	START_ADDR_PAGE		FLASH_ADDR_PAGE_127
#define 	END_ADDR_PAGE 		FLASH_ADDR_PAGE_127 + FLASH_PAGE_SIZE

extern uint32_t	startpage;
extern uint32_t	dataread;

extern unsigned int dataSize;

void writePage(uint32_t startPage, uint32_t endPage, uint32_t data);
uint32_t readData(uint32_t Addr);
#endif /* INC_FLASH_H_ */

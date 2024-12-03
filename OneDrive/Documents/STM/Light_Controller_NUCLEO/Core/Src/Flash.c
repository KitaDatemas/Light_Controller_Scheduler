/*
 * Flash.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ASUS
 */
#include "Flash.h"

unsigned int dataSize;
uint32_t	startpage 	  =  	START_ADDR_PAGE;
uint32_t	dataread;

void writePage(uint32_t startPage, uint32_t endPage, uint32_t data) {
	dataSize = FLASH_TYPEPROGRAM_WORD;

	HAL_FLASH_Unlock();
	FLASH_EraseInitTypeDef EraseInit;
	EraseInit.TypeErase = FLASH_TYPEERASE_PAGES;
	EraseInit.PageAddress = startPage;
	EraseInit.NbPages = (endPage - startPage)/FLASH_PAGE_SIZE;
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&EraseInit, &PageError);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, startPage, data);
	HAL_FLASH_Lock();
}

uint32_t readData(uint32_t Addr){
	return *((__IO uint32_t *)Addr) & 0xFFFF;
}

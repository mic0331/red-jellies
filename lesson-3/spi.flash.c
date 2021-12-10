#include <stdint.h>
#include <stdio.h>

/*
The W25Q80DV/DL array is organized into 4,096 programmable pages of 256-bytes
each. Up to 256 bytes can be programmed at a time. Pages can be erased in groups
of 16 (4KB sector erase), groups of  128  (32KB  block  erase),  groups  of  256
(64KB  block  erase)  or  the  entire  chip  (chip  erase).  The W25Q80DV/DL has
256 erasable sectors and 16 erasable blocks respectively. The small 4KB sectors
allow for greater flexibility in applications that require data and parameter
storage.
*/

#define DATA_SIZE = 4096;
#define DATA_PAGE = 256;
#define DATA_FILE_NAME = "flash_temp"

FILE* fpFLASH_DATA;

void sFLASH_Init(void) {
  fpFLASH_DATA = fopen(DATA_FILE_NAME, "ab+");
  sFLASH_EraseBulk();
}
void sFLASH_EraseSector(uint32_t SectorAddr) {}
void sFLASH_EraseBulk(void) {}
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr,
                      uint16_t NumByteToWrite) {}
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr,
                        uint16_t NumByteToWrite) {}
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr,
                       uint16_t NumByteToRead) {}
uint32_t sFLASH_ReadID(void) {}
void sFLASH_StartReadSequence(uint32_t ReadAddr) {}

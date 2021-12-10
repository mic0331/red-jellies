#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PAGES 4096
#define PAGE_SIZE 256
#define SECTOR_SIZE 4096
#define BUFFER_VALUE 0xFF

uint32_t MEMORY_SIZE;
uint8_t* MEMORY;

void sFLASH_Init(void) {
  MEMORY_SIZE = PAGES * PAGE_SIZE;
  MEMORY = calloc(MEMORY_SIZE, sizeof(uint8_t));
}

void sFLASH_EraseBulk(void) { free(MEMORY); }

void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr,
                        uint16_t NumByteToWrite) {
  if (WriteAddr + NumByteToWrite < MEMORY_SIZE) {
    MEMORY[WriteAddr] = *pBuffer;
  } else {
    printf("sFLASH_WriteBuffer::Exceeding the allocated memory \n");
  }
}

/*
Crude implementation of a write page ! We don't care about how it is
implemented. Instead we want to understand the user interaction with the IC !
*/
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr,
                      uint16_t NumByteToWrite) {
  if (WriteAddr + NumByteToWrite < MEMORY_SIZE) {
    for (uint8_t idx = 0; idx <= NumByteToWrite; ++idx) {
      MEMORY[WriteAddr + idx] = pBuffer[idx];
    }
  } else {
    printf("sFLASH_WritePage::Exceeding the allocated memory \n");
  }
}

void sFLASH_EraseSector(uint32_t SectorAddr) {
  if (SectorAddr <= MEMORY_SIZE) {
    MEMORY[SectorAddr] = 0x00;
  } else {
    printf("sFLASH_EraseSector::Exceeding the allocated memory \n");
  }
}

void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr,
                       uint16_t NumByteToRead) {
  if (ReadAddr + NumByteToRead < MEMORY_SIZE) {
    *pBuffer = MEMORY[ReadAddr];
  } else {
    printf("sFLASH_ReadBuffer::Exceeding the allocated memory \n");
  }
}

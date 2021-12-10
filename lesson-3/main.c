#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "spi_flash.h"

/*
    Assumption: This is a simulator for spi_flash.
    A simple memory block is used to reflect the behavior of the IC.
*/

int main(void) {
  sFLASH_Init();
  uint8_t w_value = 0xFF;
  uint8_t r_value = 0x00;

  // Read a non allocated memory address
  sFLASH_ReadBuffer(&r_value, 5555, 1);
  assert(0x00 == r_value);

  // Read buffer
  sFLASH_ReadBuffer(&r_value, 5000 * 256, 1);
  // erase sector exceeding memory
  sFLASH_EraseSector(5000 * 256);

  // Writing-Reading values
  sFLASH_WriteBuffer(&w_value, 2, sizeof(w_value));
  sFLASH_ReadBuffer(&r_value, 2, sizeof(w_value));
  assert(w_value == r_value);
  printf("Write value %u, Read value %u \n", w_value, r_value);
  sFLASH_EraseSector(2);
  sFLASH_ReadBuffer(&r_value, 2, sizeof(w_value));
  assert(0x00 == r_value);

  // Writing-Reading values
  w_value = 0xCA;
  sFLASH_WriteBuffer(&w_value, 4, sizeof(w_value));
  sFLASH_ReadBuffer(&r_value, 4, sizeof(w_value));
  assert(w_value == r_value);
  printf("Write value %u, Read value %u \n", w_value, r_value);

  // Write a Page, reading each buffer
  char* testString = "test";
  sFLASH_WritePage((uint8_t*)testString, 657, strlen(testString) + 1);
  sFLASH_ReadBuffer(&r_value, 657, sizeof(w_value));
  assert('t' == r_value);
  // correspond to 't' in ASCII
  printf("Write value %u, Read value %u \n", 't', r_value);

  sFLASH_ReadBuffer(&r_value, 658, sizeof(w_value));
  // correspond to 'e' in ASCII
  printf("Write value %u, Read value %u \n", 'e', r_value);
  assert('e' == r_value);
  return 0;
}
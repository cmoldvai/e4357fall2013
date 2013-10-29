/*
 * File: hw1_lib.c
 * gcc -c hw1_lib.c -o hw1_lib.o
 * gcc -S hw1_lib.c -o hw1_lib.s
 * objdump -D hw1_lib.o
 */
#include "hw1_lib.h"

/* Gray Code to Binary Conversion */
uint16_t gray_to_binary(uint16_t gray16)
{
uint16_t bin16;
uint16_t MASK;
uint16_t i, temp;

   MASK = 0x8000;
   bin16 = gray16 & MASK;
   MASK >>= 1;

  for(i=0; i<15; i++){
      temp = (((bin16 >> 1) & MASK) ^ (gray16 & MASK));
      bin16 = (bin16 | temp);
      MASK >>= 1;
  }
  return bin16;
}

/* Binary to Gray Code Conversion */
uint16_t binary_to_gray(uint16_t bin16)
{
   uint16_t gray16;
   uint16_t MASK;
   uint16_t temp;

   MASK = 0x8000;
   temp = (bin16 >> 1) ^ bin16;
   gray16 = (bin16 & MASK) | temp;

   return gray16;
}



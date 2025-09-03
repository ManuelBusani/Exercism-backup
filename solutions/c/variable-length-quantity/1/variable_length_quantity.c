#include "variable_length_quantity.h"

static int encode_integer(uint32_t integer, uint8_t *output){
   int length = 1;
   for(uint32_t aux = 1 << 7; aux != 0 && aux <= integer;){
      aux <<= 7;
      length++;
   }

   output[length - 1] = (uint8_t)integer&0x7f;

   for(int i = length - 1; i > 0;){
      integer >>= 7;
      output[--i] = (uint8_t)(integer&0x7f) | 0x80;
   }

   return length;
}

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   if(!integers || integers_len == 0 || !output) return ERROR;

   int length = 0;
   for(size_t i = 0; i < integers_len; i++){
      length += encode_integer(integers[i], output+length);
   }

   return length;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   if(!bytes || buffer_len == 0 || !output) return ERROR;
   *output = 0;
   int length = 0; 

   for(size_t i = 0; i < buffer_len; i++){
      int byte = bytes[i];
      // if the decoded number doesnt fit in 32 bits then
      // information is lost when bit shifting.
      *output = (*output << 7) | (uint32_t)(byte & 0x7f);

      if(byte < 0x80){
         output++; length++;
         *output = 0;

      } else if(i + 1 >= buffer_len) {
         return ERROR;
      }
   }
   return length;
}

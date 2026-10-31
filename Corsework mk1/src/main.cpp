#include "mbed.h"
int main()
{
/*
hash table to link Characters to their LEDs
eg A = 35
LED combination stored as 8 bit integer
A = 1, B = 2, C = 4, D = 8, E = 16, F = 32, G = 64, DP = 128
so this shows that to show the character A on the display you need lights F B A to be turned on 
*/
std::unordered_map<char, uint8_t> segments = {
    {'A', 0b00100011}, // a,b,f
    {'B', 0b01101100}, // c,d,f,g
    {'C', 0b01100001}, // a,f,g
    {'D', 0b01011010}, // b,d,e,g
    {'E', 0b01001001}, // a,d,g
    {'F', 0b01010001}, // a,e,g
    {'G', 0b11001100}, // c,d,g,dp
    {'H', 0b01110100}, // c,e,f,g
    {'I', 0b10010000}, // e,dp
    {'J', 0b10001100}, // c,d,dp
    {'K', 0b11110000}, // e,f,g,dp
    {'L', 0b00011000}, // d,e
    {'M', 0b00010101}, // a,c,e
    {'N', 0b01000100}, // c,g
    {'O', 0b01100011}, // a,b,f,g
    {'P', 0b01010011}, // a,b,e,g
    {'Q', 0b01100101}, // a,c,f,g
    {'R', 0b01010000}, // e,g
    {'S', 0b01001101}, // a,c,d,g
    {'T', 0b00110001}, // a,e,f
    {'U', 0b00011100}, // c,d,e
    {'V', 0b10011100}, // c,d,e,dp
    {'W', 0b11100010}, // b,f,g,dp
    {'X', 0b00110110}, // b,c,e,f
    {'Y', 0b11100100}, // c,f,g,dp
    {'Z', 0b10001111}, // a,b,c,d,dp
    {'0', 0b00111111}, // a,b,c,d,e,f
    {'1', 0b00000110}, // b,c
    {'2', 0b01011011}, // a,b,d,e,g
    {'3', 0b01001111}, // a,b,c,d,g
    {'4', 0b01100110}, // b,c,f,g
    {'5', 0b01101101}, // a,c,d,f,g
    {'6', 0b01111101}, // a,c,d,e,f,g
    {'7', 0b00000111}, // a,b,c
    {'8', 0b01111111}, // a,b,c,d,e,f,g
    {'9', 0b01101111}, // a,b,c,d,f,g
    {' ', 0b00000000}  // blank (padding)
};



  DigitalOut light(D7);
  

  printf("Hello World!\n");
  
 while (true)
 {
  light = 0;
  
 }  
}
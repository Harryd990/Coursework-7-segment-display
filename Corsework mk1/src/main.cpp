#include "mbed.h"
int main()
{
  DigitalOut light(D7);
  printf("Hello World!\n");
  light = 1;
 return 0;   
}
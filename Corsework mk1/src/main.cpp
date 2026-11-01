#include "mbed.h"
#include <unordered_map>
#include <list>
/*
what to talk about in write up:
indexing issues 
why i chose list 
hash table 
need to clear leds after each one is diplayed 
why chose binary store
*/




/*
hash table to link Characters to their LEDs
eg A = 35
LED combination stored as 8 bit integer
A = 1, B = 2, C = 4, D = 8, E = 16, F = 32, G = 64, DP = 128
so this shows that to show the character A on the display you need lights F B A to be turned on 
*/
DigitalOut A(D0);
DigitalOut B(D1);
DigitalOut C(D2);
DigitalOut D(D3);
DigitalOut E(D4);
DigitalOut F(D5);
DigitalOut G(D6);
DigitalOut DP(D7);

// array of lights so i can reference just the number (7) and it will turn on d7
DigitalOut leds[8] = {
    DigitalOut(D0), DigitalOut(D1), DigitalOut(D2), DigitalOut(D3),
    DigitalOut(D4), DigitalOut(D5), DigitalOut(D6), DigitalOut(D7)
};


unordered_map<char, uint8_t> segments = {
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


/*
takes input character that we want to display 
outputs a list of true/false coresponding to if the dp light should be on
... all the way to light A
*/
list<bool> parser(char input)
{
  // this part converts our string into each individual character of the string



    list<bool> result;
    uint8_t binval = segments.at(input); // look up in table what the binary value linked to letter is 
    int counter = 7; //counter is 8 cos 8 bits
    while (counter >= 0)
    {
      if(binval & (1 << counter)) //checks if the bit in slot x is 1 or 0 
      {
        result.push_back(true); //if 1 add true to list 

      }
      else
      {
        result.push_back(false); // if bit is 0 (else) then add false to list 
      }
      counter--;
      
    }
    
    return result;
}

/*
should take the list outputted by parser and turn on the lights from t/f values 
starts from dp (if index 0 is true)
goes whole way till index 7 (if a is true)
then should turn on chorisponding light 
*/
void lightdisplay(list<bool> values)
{
  int counter = 0;
  while (counter < 8)
  {
    if(*next(values.begin(), counter)) // check t/f at counters index
    {
      int lightnumb = (7-counter); // flip the counter value (as the decimal point is first item in list but is the last D (d7)
      leds[lightnumb] = 1; //turn on the light at that index

    }
    counter++;
    
  }


}

// goes through and clears all the lights
void lightClear()
{
  int i = 0;
  while (i < 8)
  {
    leds[i] = 0; 
    i++;

  }
  
}
void combination(string input)
{
  int stringLen = input.size();
    int counter = 0;
  while (counter < stringLen)
  {
    
    char currentChr = toupper(input[counter]); // sets the character in the string at counter (this is the one we work on) and capitalises it


    lightdisplay(parser(currentChr));// call all the funcs on eachother 
    thread_sleep_for(1000);// wait a sec so light can be seen
    lightClear(); // resert all leds to 0 (off) so the next letter can be displaed
    counter++;
    
  }


  

}

int main()
{
  // should add validation for caps (A,a)
  string word1 = "harry";
  string word2 = "duff5";
  combination(word1);
  combination(word2);


 while (true)
 {
  

  
 }  
}
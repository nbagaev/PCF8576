// Test sketch for Philips PCF8576C and 8 Digit 16 Segment LCD from car radio

#include <Wire.h>
#include "font.h"

//PCF8576C pins

//A0->Vdd A1->Vss A2->Vss => device adress 001

//SA0->Vss => I2C bus slave adress B0111000

//OSC->Vss => internal clock

//BP0,BP1,BP2,BP3->LCD => four backplanes, multiplex drive mode 1:4, bias 1/3

#define bus_slave_adress B0111000 //I2C bus slave adress  (011100) (SA0)
                                  //                      (011100)  (0)
#define mode B11001000  //mode set (command)(fixed value)(power-saving mode)(enable)(bias)(multiplex drive mode)
                        //            (1)        (10)             (0)          (1)    (0)         (00)
#define device_adress B11100001  //device adress (command)(fixed value)(A2 A1 A0)
                                 //                  (1)      (1100)      (001)

void setChar(uint8_t chr,uint8_t pos)
{
  if(((pos>-1)&&(pos<8))&&((chr>31)&&(chr<127)))
  {
    uint8_t data_pointer=pos*4;
    uint8_t char_pos=chr-32;
    
    Wire.beginTransmission(bus_slave_adress);
    Wire.write(device_adress); 
  
    Wire.write(data_pointer);    

    Wire.write(pgm_read_byte(&font[char_pos][0]));
    Wire.write(pgm_read_byte(&font[char_pos][1]));  

    Wire.endTransmission();
  }
}

void allSegmentsOn(bool on)
{
  uint8_t data;
  uint8_t data_pointer=B00000000;
  Wire.beginTransmission(bus_slave_adress);
  Wire.write(device_adress);   
  Wire.write(data_pointer);
  if(on)
    data=B11111111;
  else
    data=B00000000;
  for(uint8_t i=0; i<20; i++)
  {
    Wire.write(data);
    Wire.write(data);
  }
  Wire.endTransmission();
}

void initLCD()
{
  Wire.begin();
  Wire.beginTransmission(bus_slave_adress);   
  Wire.write(mode);  
  Wire.endTransmission();
}

void setup()
{
  delay(1);
  initLCD();
  allSegmentsOn(true);
  delay(1000);
  allSegmentsOn(false);
  setChar('H',7);
  setChar('E',6);
  setChar('L',5);
  setChar('L',4);
  setChar('O',3);
}

void loop()
{

}

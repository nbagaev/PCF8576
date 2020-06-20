// Test sketch for Philips PCF8576C and 8 Digit 16 Segment LCD from car radio

#include <Wire.h>

void setup()
{
  delay(1);
  Wire.begin(); // join i2c bus (address optional for master)
    
  //---------------------------------------------------------------------------

  Wire.beginTransmission(B0111000);  //Adress one of the lower I2C-controllers.   
  
  Wire.write(B11001000);  //MODE SET (Command)(10)(LowPower)(Enable)(Bias)  (Mux)
                         //         (1)          (0)       (1)     (1/4) (1:4)
  Wire.write(B11100001);  //Device select (Command)(1100)(A2 A1 A0)
  Wire.write(B00000000);  //Data pointer points at adress "00000000"
  
  Wire.write(B00000000);
  Wire.write(B00000000);

    Wire.write(B00000000);
  Wire.write(B00000000);

    Wire.write(B00000000);
  Wire.write(B00000000);


  Wire.write(B10011001);
  Wire.write(B10011001);  // O
  
  Wire.write(B00000001);
  Wire.write(B00011001); //L

  Wire.write(B00000001);
  Wire.write(B00011001); //L
  
  Wire.write(B10111000);
  Wire.write(B10001101);//A
  
  Wire.write(B10110000);
  Wire.write(B00001101);  // H
  
  Wire.write(B11111111);
  Wire.write(B11111110);
  
  Wire.endTransmission();/**/
}

void loop()
{ 

}

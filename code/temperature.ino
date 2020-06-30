#include <Wire.h>

#define DEV_ID 0x90 >> 1                    

void setup() {
  Serial.begin (9600);
  
  Wire.begin ();
  Wire.beginTransmission (DEV_ID); 
  Wire.write (0xAC);               
  Wire.write (0x02);                
  Wire.beginTransmission (DEV_ID); 
  Wire.write (0xEE);                
  Wire.endTransmission ();
}


void loop() {
  unsigned int data;
  
  Wire.beginTransmission (DEV_ID);
  Wire.write (0xAA);                        
  Wire.endTransmission ();
  Wire.requestFrom (DEV_ID, 2); 
  if (Wire.available ()) data  = Wire.read () << 8;
  if (Wire.available ()) data |= Wire.read ();
  
  Serial.print (data >> 8);
  Serial.print (data & 0xFF ? ".5" : ".0");
  Serial.println("");
  
  delay (1000);
}

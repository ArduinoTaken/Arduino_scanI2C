//#include "CmdAndFeedback.h"
#include <Wire.h>
//#include <Adafruit_INA219.h>

//Adafruit_INA219 ina219;
/*
This code for Arduino board
N02-PD device switch
LED pin:D13
KEY pin:A0 -Ready
ScanI2C->Scan i2c devices
INA219->Get Volt&Current
*/

void setup()
{
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);

  delay(5);
}

void loop()
{
  // put your main code here, to run repeatedly:
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  delay(1000);
  nDevices = 0;
  for (address = 1; address < 127; address++ ){
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0){
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }else if (error == 4){
      Serial.print("Unknow error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
}


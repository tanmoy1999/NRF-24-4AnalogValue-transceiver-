#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (7, 8);
byte addresses[][6] = {"0"};
int temperature = A0;
int id = A1;
int ir = A5;
int ir2 = A4;

struct package
{
  int id;
  int temperature;
  int ir;
  int ir2;
  
};


typedef struct package Package;
Package data;

void setup()
{
  Serial.begin(115200);
  delay(1000);
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openWritingPipe( addresses[0]);
  pinMode(temperature,INPUT);
  pinMode(id,INPUT);
  pinMode(ir,INPUT);
  pinMode(ir2,INPUT);
  delay(1000);
}

void loop()
{
  myRadio.write(&data, sizeof(data)); 
  int val = analogRead(temperature);
  int val2 = analogRead(id);
  int val3 = analogRead(ir);
  int val4 = analogRead(ir2);
  Serial.print("\nY AXIS ");
  Serial.println(val2);
  Serial.print("\nX AXIS ");
  Serial.println(val);
  Serial.print("\n");
  Serial.print("\nIR ");
  Serial.println(val3);
  Serial.print("\n");
  Serial.print("\nIR2 ");
  Serial.println(val4);
  Serial.print("\n");
  //Serial.println(data.text);
  data.id = val2;
  data.temperature = val;
  data.ir = val3;
  data.ir2 = val4;
  delay(100);

}

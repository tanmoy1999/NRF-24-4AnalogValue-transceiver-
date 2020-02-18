#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (7, 8);
int relay1 = 3;
int relay2 = 9;
int relay3 = 5;
int relay4 = 10;
int val3;
int val;
int val4;
int val2;


struct package
{
  int id;
  int temperature;  
  int ir;
  int ir2;
};

byte addresses[][6] = {"0"}; 



typedef struct package Package;
Package data;

void setup() 
{
  Serial.begin(115200);
  delay(1000);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
  
  myRadio.begin(); 
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();
  
}
void loop()  
{

  if ( myRadio.available()) 
  {
    while (myRadio.available())
    {
      myRadio.read( &data, sizeof(data) );
    }
    Serial.print("y: ");    //VAL4
    Serial.print(data.id);
    Serial.print("\n");
    Serial.print("x: ");   //VAL3
    Serial.print(data.temperature);
    Serial.print("\n");
    Serial.print(data.ir);
    Serial.print("\n");
    Serial.print(data.ir2);
    Serial.print("\n");
    val=data.temperature;
    val2=data.id;
    val3=data.ir;
    val4=data.ir2;
    
    
    
    //Serial.println(data.text);
  
  }
  

}

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const int xInput = A0;
const int yInput = A1;
const int zInput = A2;
int RawMin = 0;
int RawMax = 1023;

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(xInput,INPUT);
  pinMode(yInput,INPUT);
  pinMode(zInput,INPUT);
}

void loop() {
  //const char text[] = "";
  int xRaw = analogRead(xInput);
  int yRaw = analogRead(yInput);
  int zRaw = analogRead(zInput);
  Serial.print(xRaw);
  Serial.print("   " );
  Serial.println(yRaw);
  if(xRaw>=264 && xRaw<=273 && yRaw>=312 && yRaw<=331)
  {
    //Serial.write('1');// F for forward
//    const char text[]="forward";
    int text = 1;
    radio.write(&text, sizeof(text)); 
    Serial.println("F");
  }
  if(xRaw>=337 && xRaw<=403 && yRaw>=325 && yRaw<=340)
  {
    //Serial.write('2');// B for backward
//    const char text[]="backward";
    int text = 2;
    radio.write(&text, sizeof(text));
    Serial.println("B"); 
  }
  if(xRaw>=323 && xRaw<=337 && yRaw>=393 && yRaw<=410)
  {
    //Serial.write('3');// L for left
//    const char text[]="left";
    int text = 3;
    radio.write(&text, sizeof(text));
    Serial.println("L"); 
  }
  if(xRaw>=329 && xRaw<=334 && yRaw>=262 && yRaw<=266)
  {
    //Serial.write('4');// R for right
//    const char text[]="right";
    int text = 4;
    radio.write(&text, sizeof(text));
    Serial.println("R"); 
  }
  
  
  delay(100);
}

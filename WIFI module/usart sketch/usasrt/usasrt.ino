#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial ESPserial(3, 1); // RX | TX on the board
//备选方案，U1TXD US GPIO2
uint16_t data=118;
void setup()
{
  Serial.begin(115200); 
  ESPserial.begin(9600);
  Serial.println("initial ready");
  
  if(Serial.available()){
    loop();
  }
}
 

void loop() {
    
    Serial.println("118 sent");
     ESPserial.write(118);
     delay(1000);
     Serial.println("132 sent");
     ESPserial.write(132);
    if(ESPserial.available()){
    
    Serial.println("ESP written");
    ESPserial.write(0x76);
     ESPserial.write(0x84);
    Serial.println( ESPserial.read());
  }
    delay(1000);
}

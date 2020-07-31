#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = ""; // insert your blynk auth token

char ssid[] = ""; // insert your ssid
char pass[] = ""; // insert your password

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX
#define ESP8266_BAUD 115200 // use different bauds to see which one works for your ESP

void actuatorPull();
void actuatorPush();

const int relay1 = 7;
const int relay2 = 8;


ESP8266 wifi(&EspSerial);

void setup()
{
  Serial.begin(115200);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 80);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
}

void loop(){
  
  Blynk.run();
  
}

BLYNK_WRITE(V0) {
 int pVal = param.asInt(); 
 if (pVal == 1) {
    actuatorPush(); 
  } else {
    actuatorPull();
 }
}



void actuatorPush(){
  
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);  

}

void actuatorPull(){
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
}

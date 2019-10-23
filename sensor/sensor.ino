/**
 * Interfacing Photoresistor using ESP32
 * By TechMartian
 */

//#include <OSCMessage.h>
#include <WebServer.h>
#include <WiFi.h>
#include <WiFiUdp.h>

/* Put your SSID & Password */
const char* ssid = "beepbopboopbop";  // Enter SSID here
const char* password = "123456789";  // Enter Password here

/* Put IP Address details */
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);

WiFiUDP udp;

//constants for the pins where sensors are plugged into.
const int ledPin = 18;
const int diyPin = 32;

//Set up some global variables for the light level an initial value.
int lightInit;  // initial value
int lightVal;   // light reading

//DIY Sensors
int diyVal;


void setup()
{
  Serial.begin(9600);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);

  server.begin();
  
  // We'll set up the LED pin to be an output.
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  diyVal = analogRead(diyPin);
  Serial.println(diyVal);

  if (diyVal == 0)
  {
      digitalWrite (ledPin, HIGH); // turn on light
  }

  //otherwise, it is bright
  else
  {
    digitalWrite (ledPin, LOW); // turn off light
  }

    udp.beginPacket("192.168.1.2", 57222);
    udp.print(String(diyVal));
    udp.endPacket();

    // Wait for 1 second
    delay(100);

}

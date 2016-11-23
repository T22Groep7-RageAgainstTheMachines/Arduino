#include <Wire.h>
#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "Rp6.h"

const int HitPin = 9;
const int OutPin = 8;
const int GotHitPin = 6;
const int AOut = 3;
const int BOut = 2;
const int COut = 1;
const int DOut = 0;


int speedLeft;
int speedRight;
unsigned long timer = 0;

RP6_registers regs;
RP6_LEDs leds;
RP6_DIRECTION dir = RP6_FORWARD;

int status = WL_IDLE_STATUS;
char ssid[] = "ASUS_88"; //  your network SSID (name)
char pass[] = "BattlebotsWifi";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)
unsigned int localPort = 2390;      // local port to listen on

char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back
char  SendBuffer[] = "Message";
int stepsRemain;
int steps;
const int totalsteps = 1000;
bool reverse;
bool attack;

WiFiUDP Udp;
IPAddress TargetPCip(192, 168, 1, 122); //Ip address van de battleStationPC

void setup() {
  //Initialize serial and wait for port to open:
  timer = millis();
  steps = -1;
  stepsRemain = totalsteps;
  attack = false;
  reverse = false;
  pinMode(9, INPUT);
  pinMode(8, OUTPUT);
  pinMode(6, INPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid);

    // wait 10 seconds for connection:
    delay(1000);
  }
  Serial.println("Connected to wifi");
  printWifiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  Udp.begin(localPort);
  Serial.println("Connected");
  Rp6.begin();
  speedLeft = 0;
  speedRight = 0;

}

void loop() {
  // if there's data available, read a packet

  if (digitalRead(HitPin) == HIGH)
  {
    RP6Hit();
  }

  if (digitalRead(GotHitPin) == HIGH)
  {
    RP6GotHit();
  }
  int packetSize = Udp.parsePacket();
  if (packetSize) 
  {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    Serial.println("Message:");
    Serial.println(packetBuffer);
    String message = packetBuffer;
    processMessage(message);
    if (attack)
    {
      if (millis() - timer > 2)
      {
        timer+= 2;
        if (!reverse)
        {
          if (stepsRemain > 0)
          {            
            stepper();
            steps++;
            if (steps > 3)
            {
              steps = 0;
            }
            stepsRemain--;
          }
          else
          {
            stepsRemain = totalsteps;
            steps = 3;
          }
        }
        else
        {
          if (stepsRemain > 0)
          {            
            stepper();            
            if (steps == 0)
            {
              steps = 4;
            }
            steps--;
            stepsRemain--;
          }
          else
          {
            reverse = false;

            
            steps = 0;
            attack = false;
            stepsRemain = totalsteps;
            digitalWrite(AOut, LOW);
            digitalWrite(BOut, LOW);
            digitalWrite(COut, LOW);
            digitalWrite(DOut, LOW);
          }
        }
      }
    }
  }
}

void RP6GotHit()
{
  //TODO if RP6 got hit
  char gotHit[] = "GotHit";
  Udp.beginPacket(TargetPCip, 11000);
  Udp.write(gotHit);
  Udp.endPacket();
}
void RP6Hit()
{
  //TODO if RP6 got hit
  char hit[] = "Hit";
  Udp.beginPacket(TargetPCip, 11000);
  Udp.write(hit);
  Udp.endPacket();
}








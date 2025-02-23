#include <ESP8266WiFi.h>                     // Import 'ESP8266WiFi.h' libary
#include <WiFiClientSecure.h>                // Import 'WiFiClientSecure.h' libary
#include <EEPROM.h>                        // Import 'EEPROM.h' libary
//=====================================================================================================================
const char* ssid = "Hextronics";             // Your wifi name or SSID.
const char* password = "ESP123..";           // Your wifi password.

const char* host = "script.google.com";      // host script 
const int httpsPort = 443;                   // httpsport ID

WiFiClientSecure client;                     // Create a WiFiClientSecure object.

String GAS_ID = "AKfycbw5JVGfzC4TOuKlH6hb5Z-SDY9Uuqh35YNng32_-hrFIv-NY7I7OXmnyIJKVGzGOU7k";  // spreadsheet GAS service id
const char* fingerprint = "ACA68049BB245F7DC3BD8D4C355EDD36EBF8C195";                          // Google spreadsheet fingerprint id
//=====================================================================================================================
#define MOTOR_RELAY 13                         // define the Relay pin
//=====================================================================================================================
#define PH_PIN A0                            // define the PH_Sensor pin

float ph_Data;                               // PH data Variable
float pH_Value=0;                            // pH_value Initial position 0
float voltage;                               // Declear the variable voltage
//=====================================================================================================================
#define FLOW_SENSOR_1 D1                      // define the  FLOW_SENSOR_1 pin
#define FLOW_SENSOR_2 D2                      // define the  FLOW_SENSOR_2 pin

volatile long pulse_1;                        // 
unsigned long lastTime_1;                     //
float volume_1;                               //

volatile long pulse_2;                        //
unsigned long lastTime_2;                     //
float volume_2;                               //

int EEPROM_PUMP_AUTO_STATUS_DATA;
int A=0;
int B=0;
int C=0;
//=====================================================================================================================s
#define TRIG_PIN 12                          //                    
#define ECHO_PIN 14

#define SOUND_VELOCITY 0.034
//#define CM_TO_INCH 0.393701

long duration;

float ULTRASONIC_DATA_CM;
//float ULTRASONIC_DATA_INCH;

float CALCULATION_WATER_LEVEL_PERCENTAGE=0;
float  WATER_LEVEL_PERCENTAGE=0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {                                          // put your setup code here, to run once:                                  
pinMode(MOTOR_RELAY,OUTPUT);                            // Relay Pin as define as output to control the pump
//=====================================================================================================================s
pinMode(PH_PIN,INPUT);                                  // pH sensor pin as input declear
//=====================================================================================================================s
pinMode(TRIG_PIN, OUTPUT);                              // Sets the trigPin as an Output
pinMode(ECHO_PIN, INPUT);                               // Sets the echoPin as an Input
//=====================================================================================================================s
pinMode(FLOW_SENSOR_1, INPUT);                          // Set the "FLOW_SENSOR_1" as an input
pinMode(FLOW_SENSOR_2, INPUT);                          // Set the "FLOW_SENSOR_2" as an input
attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_1), increase_1, RISING);  // "FLOW_SENSOR_1" as an use as interrupt  RISING
attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_2), increase_2, RISING);  // "FLOW_SENSOR_2" as an use as interrupt  RISING
//=====================================================================================================================s                                               
Serial.begin(19200);                                   // Serial Communication with computer
EEPROM.begin(512);                                     // 
EEPROM_DATA();
EEPROM_PUMP_AUTO_STATUS_DATA=EEPROM.read(1);           //
wifi_setup();                                          // Now call or Fetch the "wifi_setup"
plx_daq_setup();                                      
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {                                                // put your main code here, to run repeatedly:
 flow_sensor_loop();                                         // Now call or Fetch the "flow_sensor_loop"
 Ultrasonic_Loop();                                          // Now call or Fetch the "Ultrasonic_Loop"                 
 pH_sensor_loop();                                           // Now call or Fetch the "pH_sensor_loop" 
 PUMP_Setup();
 plx_daq_loop();
 sendData(volume_1,volume_2,WATER_LEVEL_PERCENTAGE,ph_Data); //

}

ICACHE_RAM_ATTR void increase_1() {
  pulse_1++;
}
ICACHE_RAM_ATTR void increase_2() {
  pulse_2++;
}

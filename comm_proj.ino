#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define ONE_WIRE_BUS 2
#define MasterFan 6
#define in_out_fan 5
#define light 8
#define heater 3
#define reset 9

OneWire oneWire(ONE_WIRE_BUS);
Adafruit_SSD1306 display(OLED_RESET);
DallasTemperature sensors(&oneWire);

int pulse;
unsigned long interval=600000;
unsigned long previousMillis=0;
bool fan_running=false;
bool fan_state=true, heating=false, cooling=false;


void setup(void)
{
//gpio init 
  pinMode(2, INPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(9, OUTPUT);
    
  //pulse begin
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  delay(100);
  //pulse end   
  Serial.begin(9600);
  sensors.begin(); 

  digitalWrite(MasterFan, HIGH);
  delay(100); 
  digitalWrite(light, HIGH); 
  delay(100);
  digitalWrite(heater, HIGH);
  delay(100);
  digitalWrite(in_out_fan, HIGH);

  //display init  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}
void loop(void)
{  
  //pulse begin
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  delay(100);
  //pulse end
  unsigned long currentMillis = millis(); 
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  if (!fan_running && (unsigned long)(currentMillis - previousMillis) >= interval) {
    previousMillis = currentMillis;
    fan_state=false;  
    fan_running=true; 
  }
  if (fan_running && (unsigned long)(currentMillis - previousMillis) >= 25000) {
    previousMillis = currentMillis;
    fan_state=true;
    fan_running=false;   
  }  
  digitalWrite(in_out_fan, fan_state);      
  float low_temp_raw=analogRead(A2);
  float high_temp_raw=analogRead(A3);
  int low_temp=(1023+low_temp_raw)/51.15;
  int high_temp=(1023+high_temp_raw)/51.15; 
  int new_temp;
  display.print("low temp: ");
  display.print(low_temp);
  display.setCursor(0,10);
  display.print("high temp: ") ;
  display.print(high_temp);
  sensors.requestTemperatures();
  float temp=sensors.getTempCByIndex(0);
  if (temp!=-127){   
    new_temp=temp;}
  display.setCursor(0,20);
  display.print("current temp: ");
  display.print(new_temp);
  display.display();  
  display.clearDisplay();
  if (heating==false && new_temp<low_temp){
    digitalWrite(MasterFan, HIGH);
    delay(100);
    digitalWrite(heater, LOW);
    delay(100);
    digitalWrite(light, LOW);
    delay(100);
    heating=true;
    cooling=false;
  }  
  if (cooling==false && new_temp>high_temp){
    digitalWrite(light, HIGH);
    delay(100);
    digitalWrite(heater, HIGH);
    delay(100);
    digitalWrite(MasterFan, LOW);
    delay(100);
    heating=false;
    cooling=true;    
  }  
}
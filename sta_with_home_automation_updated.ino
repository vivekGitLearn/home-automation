#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#define DHTPIN D7
#include"DHT.h"
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
const char* ssid = "realme 3 Pro";
const char* password ="pineapple";
const char* ssid1 = "homeNetwork";
const char* password1 ="homeNetwork";
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server (80);
   
float Temperature;
float Humidity;

uint8_t led_0=D0;
uint8_t led_1=D1;
uint8_t led_2=D2;
uint8_t led_3=D3;
uint8_t led_4=D4;
uint8_t led_5=D5;
uint8_t led_6=D6;
uint8_t led_8=D8;

bool led_0s=LOW;
bool led_1s=LOW;
bool led_2s=LOW;
bool led_3s=LOW;
bool led_4s=LOW;
bool led_5s=LOW;
bool led_6s=LOW;
bool led_8s=LOW;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(100);
pinMode(DHTPIN,INPUT);
pinMode(led_0,OUTPUT);
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
pinMode(led_3,OUTPUT);
pinMode(led_4,OUTPUT);
pinMode(led_5,OUTPUT);
pinMode(led_6,OUTPUT);
pinMode(led_8,OUTPUT);

WiFi.softAP(ssid1, password1);
WiFi.softAPConfig(local_ip,gateway,subnet);
 delay(100);
 
Serial.println("connecting to ");
Serial.println(ssid);
dht.begin();
  

WiFi.begin(ssid,password);
while(WiFi.status() != WL_CONNECTED){
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("wifi connected...!");
Serial.print("got ip: ");Serial.print(WiFi.localIP());
delay(100);
server.on("/",handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);

   server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  
  server.on("/led3on", handle_led3on);
  server.on("/led3off", handle_led3off);
  
  server.on("/led4on", handle_led4on);
  server.on("/led4off", handle_led4off);
  
  server.on("/led5on", handle_led5on);
  server.on("/led5off", handle_led5off);

  server.on("/led8on", handle_led8on);
  server.on("/led8off", handle_led8off);
  
  server.on("/led7on", handle_led7on);
  server.on("/led7off", handle_led7off);
  
  server.on("/led6on", handle_led6on);
  server.on("/led6off", handle_led6off);
server.onNotFound(handle_NotFound);
server.begin();
Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
 if(led_0s)
  {digitalWrite(led_0, HIGH);}
  else
  {digitalWrite(led_0, LOW);}
  
  if(led_1s)
  {digitalWrite(led_1, HIGH);}
  else
  {digitalWrite(led_1, LOW);}


   if(led_2s)
  {digitalWrite(led_2, HIGH);}
  else
  {digitalWrite(led_2, LOW);}
  
  if(led_3s)
  {digitalWrite(led_3, HIGH);}
  else
  {digitalWrite(led_3, LOW);}


 if(led_4s)
  {digitalWrite(led_4, HIGH);}
  else
  {digitalWrite(led_4, LOW);}
  
  if(led_5s)
  {digitalWrite(led_5, HIGH);}
  else
  {digitalWrite(led_5, LOW);}

 if(led_6s)
  {digitalWrite(led_6, HIGH);}
  else
  {digitalWrite(led_6, LOW);}
  
  if(led_8s)
  {digitalWrite(led_8, HIGH);}
  else
  {digitalWrite(led_8, LOW);}
//Serial.println("got ip: ");Serial.print(WiFi.localIP());
}

void handle_OnConnect()
{
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
 led_0s=LOW;
 led_1s=LOW;
 led_2s=LOW;
 led_3s=LOW;
 led_4s=LOW;
 led_5s=LOW;
 led_6s=LOW;
 led_8s=LOW;
    
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,led_4s,led_5s,led_6s,led_8s));
}
void handle_led1on() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_0s =HIGH;
    
  server.send(200,"text/html", SendHTML(Temperature,Humidity,true,led_1s,led_2s,led_3s,led_4s,led_5s,led_6s,led_8s));
}
void handle_led1off() {
    
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_0s =LOW;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,false,led_1s,led_2s,led_3s,led_4s,led_5s,led_6s,led_8s));
}

void handle_led2on() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_1s =HIGH;
    
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,true,led_2s,led_3s,led_4s,led_5s,led_6s,led_8s));

}
void handle_led2off() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_1s =LOW;
    
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,false,led_2s,led_3s,led_4s,led_5s,led_6s,led_8s));
}

void handle_led3on() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_2s =HIGH;
    
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,true,led_3s,led_4s,led_5s,led_6s,led_8s));
}
void handle_led3off() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  
  led_2s =LOW;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,false,led_3s,led_4s,led_5s,led_6s,led_8s));
}

void handle_led4on() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
    
  led_3s =HIGH;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,true,led_4s,led_5s,led_6s,led_8s));
}
void handle_led4off() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
    
  led_3s =LOW;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,false,led_4s,led_5s,led_6s,led_8s));
}

void handle_led5on() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
    
  led_4s =HIGH;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,true,led_5s,led_6s,led_8s));
}
void handle_led5off() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_4s =LOW;
    
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,false,led_5s,led_6s,led_8s));
}

void handle_led6on() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_5s =HIGH;
    
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,led_4s,true,led_6s,led_8s));
}
void handle_led6off() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_5s =LOW;  
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,led_4s,false,led_6s,led_8s));
}

void handle_led7on() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_6s =HIGH;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,led_4s,led_5s,true,led_8s));
}
void handle_led7off() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_6s =LOW;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,led_4s,led_5s,false,led_8s));
}

void handle_led8on() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_8s =HIGH;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,led_4s,led_5s,led_6s,true));
}
void handle_led8off() {
  Temperature = dht.readTemperature();
  Humidity =dht.readHumidity();
  led_8s =LOW;
  server.send(200,"text/html", SendHTML(Temperature,Humidity,led_0s,led_1s,led_2s,led_3s,led_4s,led_5s,led_6s,false));
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
String SendHTML(float TemperatureStat,float humidityStat,uint8_t led1stat,uint8_t led2stat,uint8_t led3stat,uint8_t led4stat,uint8_t led5stat,uint8_t led6stat,uint8_t led7stat,uint8_t led8stat)
{ String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP8266 Weather Report</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #44444;margin: 50px auto 30px;}\n";
   ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP8266 NodeMCU Weather Report</h1>\n";
  
  ptr +="<p>Temperature: ";
  ptr +=(float)TemperatureStat;
  ptr +="'C</p>";
  ptr +="<p>Humidity: ";
  ptr +=(float)humidityStat;
  ptr +="%</p>";
  
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
   if(led1stat)
  {ptr +="<p>fan Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";}
  else
  {ptr +="<p>fan Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";}

  if(led2stat)
  {ptr +="<p>tube light Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";}
  else
  {ptr +="<p>tube light Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";}

  if(led3stat)
  {ptr +="<p>LED bulb Status: ON</p><a class=\"button button-off\" href=\"/led3off\">OFF</a>\n";}
  else
  {ptr +="<p>LED bulb Status: OFF</p><a class=\"button button-on\" href=\"/led3on\">ON</a>\n";}

if(led4stat)
  {ptr +="<p>tv Status: ON</p><a class=\"button button-off\" href=\"/led4off\">OFF</a>\n";}
  else
  {ptr +="<p>tv Status: OFF</p><a class=\"button button-on\" href=\"/led4on\">ON</a>\n";}
  
  if(led5stat)
  {ptr +="<p>home theatre Status: ON</p><a class=\"button button-off\" href=\"/led5off\">OFF</a>\n";}
  else
  {ptr +="<p>home theatre Status: OFF</p><a class=\"button button-on\" href=\"/led5on\">ON</a>\n";}

 if(led6stat)
  {ptr +="<p>alexa Status: ON</p><a class=\"button button-off\" href=\"/led6off\">OFF</a>\n";}
  else
  {ptr +="<p>alexa Status: OFF</p><a class=\"button button-on\" href=\"/led6on\">ON</a>\n";}

if(led7stat)
  {ptr +="<p> others Status: ON</p><a class=\"button button-off\" href=\"/led7off\">OFF</a>\n";}
  else
  {ptr +="<p>others  Status: OFF</p><a class=\"button button-on\" href=\"/led7on\">ON</a>\n";}
if(led8stat)
  {ptr +="<p>charger  Status: ON</p><a class=\"button button-off\" href=\"/led8off\">OFF</a>\n";}
  else
  {ptr +="<p>charger Status: OFF</p><a class=\"button button-on\" href=\"/led8on\">ON</a>\n";}
  return ptr;
  ptr +="</body>\n";
  ptr +="</html>\n";
  
}

#include <ESP8266WiFi.h>

const char* ssid = "redmi";
const char* password = "vishvaas";
const char* host = "maker.ifttt.com";

void setup() {
   Serial.begin(115200);
   Serial.println("Email from Node Mcu");
   delay(100);
   Serial.print("Connecting to ");
   Serial.println(ssid);
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
   }
   Serial.println("");
   Serial.println("IP address: ");
   Serial.println(WiFi.localIP()); 
}
void loop() { 
        WiFiClient client;
        const int httpPort = 80; 
         if (!client.connect(host, httpPort)) { 
               Serial.println("connection failed"); 
         return;}
        if(Serial.available()){
         char a=Serial.read();
         if (a=='o'){
                 String url = "/trigger/notify/json/with/key/tWO4AS0rA0Mx1U_pFIYoY"
                 Serial.print("Requesting URL: ");
                 Serial.println(url);
                 client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                                   "Host: " + host + "\r\n" +  
                                          "Connection: close\r\n\r\n");   
                                   } 
         else{
           Serial.println("Correct character not pressed.Try again");
         }
         }
         delay(1000);
}

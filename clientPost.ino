

 
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char *ssid = "OnePlus3";
const char *password = "node_mcu";

const char *host = "http://192.168.43.236:3000/node/";   
 
void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_OFF);        
  delay(1000);
  WiFi.mode(WIFI_STA);        
  Serial.printf("Connecting to %s",ssid);
  WiFi.begin(ssid, password);    
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
}
 
void loop() {
 int result = postData(host,"rollNo=1234&flag=P");
 if(result = 200)
 Serial.println("Data sent succesfully");
delay(1500000);
}
int postData(String url,String data){
  HTTPClient http; 
  http.begin(url);              
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(data); 
  http.end(); 
  return httpCode;  
}

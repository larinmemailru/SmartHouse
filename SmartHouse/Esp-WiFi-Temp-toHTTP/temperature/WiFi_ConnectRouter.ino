
#include <ESP8266WiFi.h>

const char ssid[16] = "HOME99";
const char password[24] = "1qaz2wsx";
const char host = "http://sadovod71.ru/me_test/"; //http://sadovod71.ru/me_test/index.php?name=wasde&value=44.34&key=Sendkljsilf324KJBjhwerjlkjj5Vhjklhjkd

ESP8266WebServer server(80);

//const char www_user[16] = "admin";
//const char www_pass[24] = "esp8266";


byte WifimodeSTA(){
  
}
/*

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print(ESP.getChipId());
  Serial.println("");
  if(WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Connect Failed! Rebooting...");
    delay(1000);
    ESP.restart();
  }
 // ArduinoOTA.begin();

  server.on("/", [](){
    if(!server.authenticate(www_username, www_password))
      return server.requestAuthentication();
    server.send(200, "text/plain", "Login OK");
  });
  server.begin();

  Serial.print("Open http://");
  Serial.print(WiFi.localIP());
  Serial.println("/ in your browser to see it working");
}
*/

/*
 * //  consolePort.print(F("system_get_chip_id(): 0x"));
//  consolePort.println(system_get_chip_id(), HEX);

 * #include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* www_username = "admin";
const char* www_password = "esp8266";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if(WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Connect Failed! Rebooting...");
    delay(1000);
    ESP.restart();
  }
  ArduinoOTA.begin();

  server.on("/", [](){
    if(!server.authenticate(www_username, www_password))
      return server.requestAuthentication();
    server.send(200, "text/plain", "Login OK");
  });
  server.begin();

  Serial.print("Open http://");
  Serial.print(WiFi.localIP());
  Serial.println("/ in your browser to see it working");
}

void loop() {
  ArduinoOTA.handle();
  server.handleClient();
}
*/

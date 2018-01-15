#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

#define DEBUG

#define ledOFF digitalWrite(LED_BUILTIN, HIGH);
#define ledON digitalWrite(LED_BUILTIN, LOW);

const char *ssid = "SISap55";
const char *password = "1qaz2wsx";

ESP8266WebServer server(80);

void setup() {
  // Для управления синим светодиодом на плате ESP2866
  pinMode(LED_BUILTIN, OUTPUT);  

  // Режим вывожа информации трассировки в консоль
  #ifdef DEBUG
    Serial.begin(115200);
    Serial.print(millis());
    Serial.println("---------------------------------------------------------------");
  #endif

  // Резервируем область памяти для сохранения настроек
  EEPROM.begin(512);

  // Вколючение режима точки доступа
  WiFimodeAP(); 

  // Определение MAC адреса ESP8266
  uint8_t mac[6];
  WiFi.macAddress(mac);
  
  //String clientName = macToStr(mac);
  //clientName += "-";
  //clientName +=  ESP.getChipId();

  //loadConfig();

}


void loop() {
  ledON; 
  delay(100);   
  ledOFF; 
  delay(2000); 

  server.handleClient();
                     
}

//Перевод платы в режимы: Точки доступа, Клиент или совмещенный
void WiFimodeAP() {
  //WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  WiFi.begin();
  WiFi.printDiag(Serial);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}


void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

// ------------------ Преобразование MAC адреса в читаемый вид ------------------
String macToStr(const uint8_t* mac)
{
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
    if (i < 5)
      result += ':';
  }
  return result;
}
// ------------------ Преобразование MAC адреса в читаемый вид ------------------

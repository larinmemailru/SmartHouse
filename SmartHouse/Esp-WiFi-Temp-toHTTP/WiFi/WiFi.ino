#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include <Ticker.h>


#define DEBUG

#define ledOFF digitalWrite(LED_BUILTIN, HIGH);
#define ledON digitalWrite(LED_BUILTIN, LOW);

const char *ssid = "SISap55";
const char *password = "1qaz2wsx";

//ADC_MODE(ADC_VCC);  //Для Функции ESP.getVcc()

//Ticker flipper;

ESP8266WebServer server(80);

//Используемые пины для подключения датчиков
int8_t pin_t[]  =   {2, 4, 5, 12, 13, 14, 15, 16};
int8_t sensor_pin_t[]  =   {0, 0, 0, 0, 0, 0, 0, 0};
/* таблица кодов для сенсоров
 * 0  - Сенсор отсутствуют
 * 1  - Датчик температуры и влажности (DHT11,DHT22,AM2302,RHT03) - DHTesp.h
 * 2  - Цифровой датчик температуры (DS18S20, DS18B20, DS1822) - OneWire.h
*/




void setup() {
  // Для управления синим светодиодом на плате ESP2866
  pinMode(LED_BUILTIN, OUTPUT);  

  // Режим вывожа информации трассировки в консоль
  #ifdef DEBUG
    Serial.begin(115200);
    Serial.println("---------------------------------------------------------------");
  #endif

  // Резервируем область памяти для сохранения настроек
  //EEPROM.begin(512);

  // Вколючение режима точки доступа
  WiFimodeAP(); 

  // Определение MAC адреса ESP8266
  uint8_t mac[6];
  WiFi.macAddress(mac);
  
  //String clientName = macToStr(mac);
  //clientName += "-";
  //clientName +=  ESP.getChipId();

  //loadConfig();
  Serial.println("----------------------- Поиск сенсоров ------------------------");
  scan_sensors();
  Serial.println("---------------------------------------------------------------");


}

void loop() {

  server.handleClient();

                     
}

//Перевод платы в режимы: Точки доступа, Клиент или совмещенный
void WiFimodeAP() {
  //WiFi.mode(WIFI_AP);
  
  WiFi.softAP(ssid, password);
  WiFi.begin();
// диагностическая информация
  #ifdef DEBUG  
   WiFi.printDiag(Serial);
  #endif
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
  led_bip(4, 200);
}


void handleRoot() {
  String html = "<h1>You are connected";
        html += "<br>ID:";
        html +=  ESP.getChipId();
        html += "<br>time:";
        html +=  ESP.getCycleCount();
        html += "<br>vcc:";
        html +=  ESP.getVcc();
        
        html += "</h1>";

        
  
  server.send(200, "text/html", html);
 
}


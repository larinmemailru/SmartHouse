#include <Adafruit_NeoPixel.h>

#include <Ticker.h>  //Для вызова процедур в промежутках указанного времени


Ticker TickerReadTemperature;

byte AnalogPin = 0;    // Терморезистор подключен к pin
byte AnalogPin_old = 1; 


void setup() {
    Serial.begin( 115200 );
    pinMode(LED_BUILTIN, OUTPUT);     //  инициализируем контакт в качестве выходного контакта

    //TickerReadTemperature.attach_ms(5000, ReadTemperature, 10);  //каждые 3 s, вызов процедуры temperature_10k_ch0(10) 
    //TickerReadTemperature.attach(5000, printTemperature);
   
}

void loop() {

  digitalWrite(LED_BUILTIN, HIGH);   //  включаем светодиод;для включения светодиода значение LOW это из-за того, что на ESP-01 активным состоянием  является LOW
     
  if ( AnalogPin != AnalogPin_old ) {  //Хранить адрес в erram
    Serial.print("Изменен pin для tempPin с '");
    Serial.print(AnalogPin);
    Serial.print("' на '");
    Serial.print(AnalogPin_old);
    Serial.println("'");
    AnalogPin_old = AnalogPin;    // Терморезистор подключен к pin
    pinMode( AnalogPin, INPUT );
  }  

  Serial.print(ReadTemperature( 10 )); Serial.println(" C");

  
  delay(3000);
// flipper.detach();  //Отключить таймер
  digitalWrite(LED_BUILTIN, LOW);  //  выключаем светодиод, используя состояние HIGH
  delay(100);
}

void printTemperature() {
  Serial.print( ReadTemperature(10) ); Serial.println("");
}


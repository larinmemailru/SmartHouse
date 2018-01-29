/*
  - Support for DHT11 and DHT22/AM2302/RHT03
  - Auto detect sensor model

#######################################
# Methods and Functions (KEYWORD2)
#######################################

setup  KEYWORD2
getTemperature  KEYWORD2
getHumidity KEYWORD2
getTempAndHumidity  KEYWORD2
getStatus KEYWORD2
getStatusString KEYWORD2
getModel  KEYWORD2
getMinimumSamplingPeriod  KEYWORD2
toFahrenheit  KEYWORD2
toCelsius KEYWORD2
computeHeatIndex  KEYWORD2
computeDewPoint KEYWORD2
getComfortRatio KEYWORD2
getNumberOfDecimalsTemperature KEYWORD2
getLowerBoundTemperature KEYWORD2
getUpperBoundTemperature KEYWORD2
getNumberOfDecimalsHumidity KEYWORD2
getLowerBoundHumidity KEYWORD2
getUpperBoundHumidity KEYWORD2
getComfortProfile KEYWORD2
setComfortProfile KEYWORD2
isTooHot KEYWORD2
isTooHumid KEYWORD2
isTooCold KEYWORD2
isTooDry KEYWORD2
computePerception KEYWORD2

AUTO_DETECT  LITERAL1
DHT11 LITERAL1
DHT22 LITERAL1
AM2302  LITERAL1
RHT03 LITERAL1

ERROR_NONE  LITERAL1
ERROR_TIMEOUT LITERAL1
ERROR_CHECKSUM  LITERAL1
*/
#include "DHTesp.h"  //Датчик температуры и влажности (DHT11,DHT22,AM2302,RHT03)

DHTesp dht;

void dht_scan(int8_t pin) {
  dht.setup(pin); // data pin 5 - D1(WeMos D1)
    if ( dht.getStatusString() == "OK" ) {
      Serial.print("Датчик DHT найден на порту №: ");
      Serial.println(pin);
      sensor_pin_t[pin] = 1;
      Serial.print(dht.getTemperature(), 1);  Serial.print("C \t");
      Serial.print(dht.getHumidity(), 1);  Serial.println("%");
    }
    
  }
  



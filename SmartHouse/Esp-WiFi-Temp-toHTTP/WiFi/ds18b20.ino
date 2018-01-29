//#include <OneWire.h>  // OneWire DS18S20, DS18B20, DS1822 Temperature Example
#include <DallasTemperature.h>

// передаем объект oneWire объекту DS18B20:
OneWire oneWire(5);


void ds_scan(int8_t pin) {
  struct ds18b20 {
    byte addr[8];
    float temp;
  };
  
  byte addr[8];
  OneWire  ds(pin);
  
    if ( !ds.search(addr)) {
      ds.reset_search();
      delay(250);
      return;
    }

    Serial.print("Датчик DALLAS найден на порту №: ");
    Serial.println(pin);
    sensor_pin_t[pin] = 2;
    struct ds18b20 temp;
    temp.temp = 12;

    Serial.println( rom_f(addr) );
 
}

String rom_f( byte addr[8] ) {
  String adr_txt = "";
  for(int i = 0; i < 8; i++) {
    adr_txt += String(addr[i], HEX);
  }  
 return adr_txt;
}

float temp_f ( byte addr[8], int8_t pin ) {
  OneWire  ds(pin);
  byte data[12];
  byte type_s;
  
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

  for ( int i = 0; i < 9; i++) {           // необходимо 9 байт
    data[i] = ds.read();
    Serial.print(data[i], HEX);
    Serial.print(" ");
  }

  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }

  return (float)raw / 16.0;
}


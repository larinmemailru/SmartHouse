void ds_scan(int8_t pin) {
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
 
}


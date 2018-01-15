// Параметры для терморезистора 10к
#define BCOEFFICIENT 3435             // B-коэффициент
#define SERIESRESISTOR 22000          // сопротивление последовательного резистора, 21.2 кОм
#define THERMISTORNOMINAL 10000       // номинальное сопротивления термистора, 10 кОм
#define NOMINAL_T 25                  // номинальная температура (при которой TR = 10 кОм)
//------------------------------------------------------------------------------


float ReadTemperature( int MassCr ){
  float tr = 0;
  
  for (int i=1; i <= MassCr; i++){
    tr += analogRead( AnalogPin );
    delay( 100 );
  }  

  tr = tr / MassCr;

  tr = 1023.0 / tr - 1;
  tr = SERIESRESISTOR / tr;
  tr = tr / THERMISTORNOMINAL;        // (R/Ro)
  tr = log(tr);                       // ln(R/Ro)
  tr /= BCOEFFICIENT;                 // 1/B * ln(R/Ro)
  tr += 1.0 / (NOMINAL_T + 273.15);   // + (1/To)
  tr = 1.0 / tr;                      // Invert
  tr -= 273.15;                       // F to C 
  
  return tr;
}


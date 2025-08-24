#include <Arduino.h>
// #include "temp_reed.h"
#include <GTimer.h>
// #include <microDS18B20.h>// не работает
#include <GyverDS18.h>
// #include "solar_vent_control.h"

GTimerCb<millis> tmr_getTemp, tmr_pingTemp;


GyverDS18Single sensor1(2);  // датчик в канале вентилятора 1
GyverDS18Single sensor2(3);  // датчик в канале вентилятора 2
GyverDS18Single sensorS(4);  // датчик в канале между панелями

int create_error(int err_tip, int dop_1);
int create_error(int err_tip);

// static float temp_rez = -55;
struct temps_out {
  float termS = -55;
  float term1 = -55;
  float term2 = -55;
};
static temps_out* _fSt;

void tempGet() {
  // if (sensor1.ready()) {         // измерения готовы по таймеру
  if (sensor1.readTemp()&&sensor2.readTemp()&&sensorS.readTemp()) {
_fSt->termS = sensorS.getTemp();
_fSt->term1 = sensor1.getTemp();
_fSt->term2 = sensor2.getTemp();
  // принять температуру с 3х термометров
  } else {
    float pertemp = 0; int sens_count = 0;
    if (sensor1.readTemp()) {pertemp = sensor1.getTemp(); sens_count++; } else {create_error(1, 1);} //иначе записать ошибку
    if (sensor2.readTemp()) {pertemp = sensor2.getTemp(); sens_count++; } else {create_error(1, 2);} //иначе записать ошибку
    if (sensorS.readTemp()) {pertemp = sensorS.getTemp(); sens_count++; } else {create_error(1, 3);} //иначе записать ошибку
    if (sens_count) {pertemp = pertemp / sens_count;} else {create_error(2);pertemp = -55;} // если ни один датчик не отвичает записать ошибку про все датчики
    // pertemp = 55;
    _fSt->termS = pertemp;_fSt->term1 = pertemp;_fSt->term2 = pertemp;
  }
  Serial.print(_fSt->term1);  Serial.print(" / ");
  Serial.print(_fSt->term2);  Serial.print(" / ");
  Serial.print(_fSt->termS);Serial.println(" / ");
}//}
void tempPing() {
  // ping 10b20 x3
  //.requestTemp();
  sensorS.requestTemp();
  sensor1.requestTemp();
  sensor2.requestTemp();
  tmr_getTemp.start();
}

void update_temp() {
  tmr_getTemp.tick();
  tmr_pingTemp.tick();
  // return temp_rez;
}

void temp_setup(temps_out* temps) {
  _fSt = temps;
  tmr_getTemp.startTimeout(2000, tempGet);
  tmr_pingTemp.startInterval(10000, tempPing);
  // подключить 3 термометра
}
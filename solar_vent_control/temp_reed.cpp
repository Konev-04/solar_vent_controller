#include <Arduino.h>
// #include "temp_reed.h"
#include <GTimer.h>
#include <microDS18B20.h>
// #include "solar_vent_control.h"

GTimerCb<millis> tmr_getTemp, tmr_pingTemp;

MicroDS18B20<5> sensor1;
MicroDS18B20<6> sensor2;
MicroDS18B20<7> sensorS;
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
  if (sensor2.readTemp()&&sensor2.readTemp()&&sensor2.readTemp()) {
_fSt->termS = sensor1.getTemp();
_fSt->term1 = sensor1.getTemp();
_fSt->term2 = sensor1.getTemp();
  // принять температуру с 3х термометров
  } else {
    float pertemp = 0; int sens_count = 0;
    if (sensor1.readTemp()) {pertemp = sensor1.readTemp(); sens_count++; } else {create_error(1, 1);} //иначе записать ошибку
    if (sensor2.readTemp()) {pertemp = sensor2.readTemp(); sens_count++; } else {create_error(1, 2);} //иначе записать ошибку
    if (sensorS.readTemp()) {pertemp = sensorS.readTemp(); sens_count++; } else {create_error(1, 3);} //иначе записать ошибку
    if (sens_count) {pertemp = pertemp / sens_count;} else {create_error(2);pertemp = -55;} // если ни один датчик не отвичает записать ошибку про все датчики
    _fSt->termS = pertemp;_fSt->term1 = pertemp;_fSt->term2 = pertemp;
  }
  Serial.print(_fSt->termS);Serial.print(_fSt->term1);Serial.println(_fSt->term2);
}
void tempPing() {
  // ping 10b20 x3
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
  tmr_getTemp.startTimeout(1200, tempGet);
  tmr_pingTemp.startInterval(10000, tempPing);
  // подключить 3 термометра
}
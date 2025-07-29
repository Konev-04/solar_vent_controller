#include <Arduino.h>
// #include "temp_reed.h"
#include <GTimer.h>
// #include "solar_vent_control.h"

GTimerCb<millis> tmr_getTemp, tmr_pingTemp;

static float temp_rez = -55;
static int* _fS;

void tempGet() {
  if (*_fS) {
    // температура с двух датчиков
  } else {
    // температура с одного датчика
  }
}
void tempPing() {
  // ping 10b20
  tmr_getTemp.start();
}

float update_temp() {
  tmr_getTemp.tick();
  tmr_pingTemp.tick();
  return temp_rez;
}

void temp_setup(int* fansSpeed) {
  _fS = fansSpeed;
  tmr_getTemp.startTimeout(1000, tempGet);
  tmr_pingTemp.startInterval(10000, tempPing);
}
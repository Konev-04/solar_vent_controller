
#include "solar_vent_control.h"
// #include "reguliator.ino"


fan_motor fan_1(1, 0);
fan_motor fan_2(21, 20);
temps_out terms_out;


void setup() {

#ifdef ESP32
    LittleFS.begin(true);
#else
    LittleFS.begin();
#endif
  setts.begin();

  setts.init(keys::sound_sdvig, 15);  //инициализация бд с настройками

  tempSets sets;
  sets.termON = 28;sets.termOFF = 25;sets.termSdvig = 3;
  setts.init(keys::Stemp_abs, sets); // значения по умолчунию для абс режима
  sets.termON = 7;sets.termOFF = 3;sets.termSdvig = 5;
  setts.init(keys::Stemp_diff, sets);// тоже для диф режима

  Serial.begin(112500);//serial
  fan_1.attach();
  fan_2.attach();
  temp_setup(&terms_out);
  tmr_reguliator.startInterval(3000, reguliaoring);
  pinMode(8, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  update_temp();
  // Serial.println(solar_vent_speed); delay(1000);
  reguliator_tick();
  
}

















#include "solar_vent_control.h"
// #include "reguliator.ino"


fan_motor fan_1(1, 2);
fan_motor fan_2(3, 4);
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
  sets.termON = 30;sets.termOFF = 27;sets.termSdvig = 3;
  setts.init(keys::Stemp_abs, sets); // значения по умолчунию для абс режима
  sets.termON = 7;sets.termOFF = 3;sets.termSdvig = 5;
  setts.init(keys::Stemp_diff, sets);// тоже для диф режима

  Serial.begin(112500);//serial
  fan_1.attach();
  fan_2.attach();
  temp_setup(&terms_out);
  tmr_reguliator.startInterval(300000, reguliaoring);

}

void loop() {
  // put your main code here, to run repeatedly:
  update_temp();
  Serial.println(solar_vent_speed); delay(1000);
  reguliator_tick();
  
}

















#include "solar_vent_control.h"


fan_motor fan_1(1, 2);
fan_motor fan_2(3, 4);


void setup() {
  Serial.begin(112500);
  fan_1.attach();
  fan_2.attach();
  temp_setup(&solar_vent_speed);

}

void loop() {
  // put your main code here, to run repeatedly:
  solar_temp_out = update_temp();
  Serial.println(solar_temp_out); delay(500);
  //
  
}





























// // struct 
// auto rert(int i) {
//   struct ret {int r1; int r2; };
//   return ret {i*2, i*3};
// }




  //  for (int i = 0, ii = 0; ii < 2; i++) {
  //   if (i > 5) {i = 0; ii++;}
  //   // int fanSpeed_1;
  //   // int fanSpeed_2;
  //   fan_motor::speeds_fans_2s(i, fan_1, fan_2, ii);
  //   // fan_1.setspeed(fanSpeed_1);
  //   // fan_2.setspeed(fanSpeed_2);
  //   delay(700);
  // }








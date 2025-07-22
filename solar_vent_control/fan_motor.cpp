#include "fan_motor.h"
#include <Arduino.h>

  void fan_motor::attach() {
    pinMode(_pin_first_speed, OUTPUT);
    digitalWrite(_pin_first_speed, 0);
    pinMode(_pin_second_speed, OUTPUT);
    digitalWrite(_pin_second_speed, 0);
  }

  void fan_motor::setSpeed(int speed) {
    _speed = speed;
    switch (_speed) {
      case 0: {
        digitalWrite(_pin_first_speed, 0);
        digitalWrite(_pin_second_speed, 0);
      } break;
      case 1: {
        digitalWrite(_pin_first_speed, 1);
        digitalWrite(_pin_second_speed, 0);
      } break;
      case 2: {
        digitalWrite(_pin_first_speed, 0);
        digitalWrite(_pin_second_speed, 1);
      } break;
      default: {
        // fault: ошибка, у вентилятора только 2 скорости
      } break;
    }
  }

  int fan_motor::getSpeed() {
    return _speed;
  }

   void fan_motor::speeds_fans_2s(int speed, int* fan_1st, int* fan_2st, bool preoritet) {
    if (speed > 5) {speed = 5;}
    int fan_f[][6] = {{0, 0, 0, 1, 1, 2}, 
                      {0, 1, 2, 1, 2, 2}};
    // int fan_s[][] = {{0, 0, 0, 1, 1, 2},  // для другого режима
    //                  {0, 1, 2, 1, 2, 2}};
    if (preoritet) {
      *fan_1st = fan_f[0][speed];
      *fan_2st = fan_f[1][speed];
    } else {
      *fan_1st = fan_f[1][speed];
      *fan_2st = fan_f[0][speed];
    }
  }







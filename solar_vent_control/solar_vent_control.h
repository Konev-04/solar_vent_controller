#pragma once

#include <GTimer.h>      // таймер для переодического и лтложенного вызова элементов
#include <GyverDBFile.h> // база данных для хранения настроек
#include <LittleFS.h>    // для бд

// таблица

#include "fan_motor.h"
// #include "temp_reed.h"

GyverDBFile setts(&LittleFS, "/setts.db"); // бд с настройками

GTimerCb<millis> tmr_reguliator;// таймер для настройки темпратуры

// int fan_1[] = {0, 415, 570};
// int fan_2[] = {0, 490, 600};
int solar_vent_speed = 0;   // переменная для текущей скорости вентилятора
// float solar_temp_out_S = -55; // температура в середине панели
// float solar_temp_out_1 = -55; // температура перед вентилятором 1
// float solar_temp_out_2 = -55; // температура перед вентилятором 2
float solar_temp_in = -55;  //
// bool preoritet = 0;         // 0 - стандартный, на первый вентилятор
bool temp_mod = 0;          // 0 - по абсолютной температуре, 1 - по разнице вход-выход (дифферинциальный режим)
bool sound_mod = 0;         // 1 - тихий режим, температура переключения смещается на +x градусов

// DB_KEYS(keys,
        //StempON_abs,
        //StempOFF_abs,
        //StempSdvig_abs,

        //StempON_diff,
        //StempOFF_diff,
        //StempSdvig_diff,
        
//         sound_sdvig  // последняя запятая не ставится
// );

DB_KEYS(keys,
        Stemp_abs,   // настройки для абс режима
        Stemp_diff,  // настройки температуры для диff режима
        sound_sdvig,  // сдвиг температуры для тихого режима
        // solar_vent_speed, // ?
        preoritet, // преоритет направления
        avtOn // включаться ли автоматически
);

struct tempSets {
  int termON;
  int termOFF;
  int termSdvig;
};

struct temps_out {
  float termS = -55;
  float term1 = -55;
  float term2 = -55;
};

void temp_setup(temps_out* temps);  //указатель на структуру с температурами
void update_temp();








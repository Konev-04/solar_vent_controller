#pragma once

// #include <GTimer.h>

#include "fan_motor.h"
// #include "temp_reed.h"


// int fan_1[] = {0, 415, 570};
// int fan_2[] = {0, 490, 600};
int solar_vent_speed = 0;
float solar_temp_out = -55;
float solar_temp_in = -55;

// DB_INIT(
//     db,
//     (keys::key1, 123),
//     (keys::key2, 3.14),
//     ("key3", 123321ull),
//     ("key4", "abc")
// );

void temp_setup(int* fansSpeed); //указатель на скорость вентилятора
float update_temp();
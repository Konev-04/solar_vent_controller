
void reguliator_tick() {
  // tempSets this_sets 
  tmr_reguliator.tick(); 
}


void reguliaoring() {
  float reg_temp = -55;
  tempSets this_settings;
      // this_settings = setts[keys::Stemp_abs];
      // температура берётся в зависимости от обдуваемости датчиков
    if (!(fan_1.getSpeed()) && !(fan_2.getSpeed())) {
      reg_temp = terms_out.termS;
    } else if ((fan_1.getSpeed()) && !(fan_2.getSpeed())) {
      reg_temp = (terms_out.termS + terms_out.term1) / 2;
    } else if (!(fan_1.getSpeed()) && (fan_2.getSpeed())) {
      reg_temp = (terms_out.termS + terms_out.term2) / 2;
    }else if ((fan_1.getSpeed()) && (fan_2.getSpeed())) {
      reg_temp = (terms_out.term1 + terms_out.term2) / 2;
    }
  if (temp_mod) {
    setts[keys::Stemp_diff].writeTo(this_settings);
    reg_temp = reg_temp - solar_temp_in;
  } else {
    setts[keys::Stemp_abs].writeTo(this_settings);
  }
  // Serial.println(reg_temp);
  int sdvig = setts[keys::sound_sdvig];
  if (sound_mod) { // сдиг для более тихой работы
    this_settings.termON += sdvig;
    this_settings.termOFF+= sdvig;
    this_settings.termSdvig += sdvig / 3;
  }
  // границы температуры вкл-выкл сдвигаются в рависимости от текущей скорости
  // сдвиг гараниц +скор - -скор в зависимости от текущего режима
  sdvig = this_settings.termSdvig * solar_vent_speed;
  this_settings.termON += sdvig;
  this_settings.termOFF+= sdvig;
  if (reg_temp > this_settings.termON) { // прибавить скорость
    solar_vent_speed++;
  } else if (reg_temp < this_settings.termOFF) {
    solar_vent_speed--;
  }
  solar_vent_speed = constrain(solar_vent_speed, 0, 5);
  
  Serial.print(reg_temp); Serial.print(" / ");
  Serial.print(this_settings.termON); Serial.print(" / ");
  Serial.print(this_settings.termOFF); Serial.print(" / ");
  Serial.println(solar_vent_speed);
  // return retSpeed;
  // speeds_fans_2s
  fan_motor::speeds_fans_2s(solar_vent_speed, fan_1, fan_2, setts[keys::preoritet]);
}












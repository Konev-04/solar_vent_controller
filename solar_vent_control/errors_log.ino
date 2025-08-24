
// свктодиод 8 сигнализирует о наличии ошибок
/*/
  1) ошибка чтения температуры с одного из датчиков + № датчика
  2) ошибка чтения температуры (со всех датчиков)
/*/


int create_error(int err_tip, int dop_1) {
  // временные ошибки стираются при перезапуске
  if (err_tip == 1) {
    // create №датчика неконнект
    Serial.print("Not connect term №");
    Serial.print(dop_1);
    Serial.println(" ");
    digitalWrite(8, 1);
  } else {
    digitalWrite(8, 0);
  }
  return 1;
}
int create_error(int err_tip) {
  // временные ошибки стираются при перезапуске
  if (err_tip == 2) {
    // create ошибка: нет температуры
    Serial.println("Not connect all terms");
    digitalWrite(8, 1);
  } else {
    digitalWrite(8, 0);
  }
  return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int create_long_error(int err_tip, int dop1) {
  // долгие ошибки
  if (err_tip == 1) {
    // create № датчика неконнект
  }
  return 1;
}




















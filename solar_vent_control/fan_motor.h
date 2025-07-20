#pragma once

class fan_motor {

  public: // пин первой скорости / пин второй скорости
    fan_motor(int pin_first_speed, int pin_second_speed) : _pin_first_speed(pin_first_speed), _pin_second_speed(pin_second_speed) {
      // при создании объекта надо задать пины, которые управляют включением соответствующих скоростей
    }
    // static int ded_time = 20;         // задержка переключения скоростей, для исключения одновременного включения двух скоростей
    // static bool speeds = 0;       // 0- 5 градаций, 1- 4 градации   (пока не реализовано)

  private:
    int _pin_first_speed;
    int _pin_second_speed;
    int _speed;

  public:
    void attach();     // "подключение" : делает пины, к которым подключено управление скоростями, выходами
    void setspeed(int speed);// фенкция для изменения скоросто работы вентилятора
    // int getspeed();    // функция чтобы узнать скорость вентилятора
    static void speeds_fans_2s(int speed, int* fan_1st, int* fan_2st, bool preoritet); 
                                                     // функция для управления 2-мя вентиляторами, стоящими паралельно,
                                                     //одной переменной скорости: комбинация на 4(более симметрично) или 5(более плавно) градаций (переключается в speeds ^);
                                                     // ещё надо передать указатели на переменные для получения скоростей вентиляторов
                                                     // если приоритет = 0, то первым включится  вентиятор 1, и скорость прибавится первым у него, если 1, но наоборот у второго
    // static static speeds_fans_2s(int speed, fan_motor& fan_1st, fan_motor& fan_2st); //перегрузка без приоритета
    

};
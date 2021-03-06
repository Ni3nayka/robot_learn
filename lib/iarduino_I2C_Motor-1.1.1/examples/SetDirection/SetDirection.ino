// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):  // * Строки со звёздочкой являются необязательными.
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
iarduino_I2C_Motor mot1(0x09);                    //   Объявляем объект mot1 для работы с функциями и методами библиотеки iarduino_I2C_Motor, указывая адрес модуля на шине I2C.
iarduino_I2C_Motor mot2(0x0A);                    //   Объявляем объект mot2 для работы с функциями и методами библиотеки iarduino_I2C_Motor, указывая адрес модуля на шине I2C.
                                                  //   При наличии нескольких моторов на шине I2C нельзя объявлять объект без указания адреса.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    mot1.begin();                                 //   Инициируем работу с 1 мотором.
    mot2.begin();                                 //   Инициируем работу с 2 мотором.
    mot1.setDirection(true);                      //   Задаём направление вращения для 1 мотора: по часовой стрелке при положительных скоростях и против при отрицательных.
    mot2.setDirection(false);                     //   Задаём направление вращения для 2 мотора: против часовой стрелки при положительных скоростях и по при отрицательных.
}                                                 //
                                                  //
void loop(){                                      //
}                                                 //
                                                  //   
// Если моторы установлены по бокам подвижного    //
// механизма (машине, танке, тракторе...), то для //
// реализации поступательного движения механизма, //
// моторы расположенные на противоположных бортах //
// механизма, должны вращаться в противоположном  //
// направлении.                                   //

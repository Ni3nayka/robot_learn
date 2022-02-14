// ПРИМЕР ВЫВОДИТ РАССТОЯНИЕ ДО ОСТАНОВКИ:        // * Строки со звёздочкой являются необязательными.
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
iarduino_I2C_Motor mot(0x09);                     //   Объявляем объект mot для работы с функциями и методами библиотеки iarduino_I2C_Motor, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_Motor mot;), то адрес будет найден автоматически.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                           //
    while(!Serial){;}                             // * Ждём завершения инициализации шины UART.
    mot.begin();                                  //   Инициируем работу с мотором.
    mot.radius = 12.2;                            //   Указываем радиус колеса в мм.
}                                                 //
                                                  //
void loop(){                                      //
    mot.setSpeed(100, MOT_RPM, 0.5, MOT_MET);     //   Запускаем мотор на скорости 100 об/мин с остановкой мотора через 0.5 метра.
    while(mot.getStop(MOT_MET)){                  //   Если путь до остановки ещё не пройден.
        Serial.print( mot.getStop(MOT_MET) );     //   Выводим оставшееся расстояние до остановки.
        Serial.println(" m.");                    //   Выводим текст.
        delay(100);                               //   Приостанавливаем выполнение скетча на 0.1 секунду.
    }   Serial.println("-----------------");      //   Выводим текст.
    delay(1000);                                  //   Приостанавливаем выполнение скетча на 1 секунду.
}                                                 //
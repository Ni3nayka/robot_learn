// ОПРЕДЕЛЕНИЕ РЕАЛЬНОГО ПЕРЕДАТОЧНОГО ОТНОШЕНИЯ: // * Строки со звёздочкой являются необязательными.
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
    mot.delSum();                                 //   Сбрасываем количество совершённых оборотов вала.
    mot.setReducer(1.0f);                         //   Указываем передаточное отношение редуктора как 1:1.
//  mot.setMagnet(7);                             //   Укажите реальное количество магнитных полюсов одной полярности, кольцевого магнита установленного на роторе мотора.
}                                                 //   Для определения этого значения воспользуйтесь примером библиотеки FindMagnet.
                                                  //
void loop(){                                      //
    Serial.println( mot.getSum(MOT_REV) );        //   Выводим количество полных оборотов вала.
    delay(200);                                   //
}                                                 //
                                                  //
/*  ВЫПОЛНИТЕ СЛЕДУЮЩИЕ ДЕЙСТВИЯ:                 //
 *  После старта скетча, в мониторе будут появляться значения 0.00
 *  При вращении ротора мотора (в любую сторону), эти значения будут увеличиваться.
 *  Поворачивайте вручную ротор мотора до тех пор пока вал редуктора не повернётся на 1 полный оборот.
 *  В мониторе появится значение равное передаточному отношению редуктора. Оно может быть не целым!
 *  Для большей точности советуем поворачивать ротор мотора до тех пор, пока вал редуктора не повернётся 10 раз, и разделить полученное значение на 10.
*/
// ПРИМЕР СМЕНЫ АДРЕСА МОДУЛЯ I2C-FLASH:          // * Строки со звёздочкой являются необязательными.
                                                  //
uint8_t newAddress = 0x09;                        //   Назначаемый модулю адрес (0x07 < адрес < 0x7F).
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Address.h>                 //   Подключаем библиотеку для работы с адресами модулей линейки I2C-flash.
iarduino_I2C_Address j;                           //   Объявляем объект j для работы с модулем I2C-flash. Адрес модуля будет определен автоматически.
                                                  //   Если адрес модуля известен, то его можно указать при создании объекта, например, iarduino_I2C_Address j(0xA0);
void setup(){                                     //
     delay(500);                                  // * Ждём завершение переходных процессов связанных с подачей питания.
     Serial.begin(9600);                          //
     while(!Serial){;}                            // * Ждём завершения инициализации шины UART.
     j.begin();                                   //   Инициируем работу с модулем.
     while(!j){;}                                 // * Запрещаем дальнейшую работу если модуль не инициализирован.
     Serial.print("Найден модуль 0x");            //
     Serial.println( j, HEX );                    //   Выводим текущий адрес модуля.
     j=newAddress;                                //   Меняем адрес модуля на newAddress.
     if(j==newAddress){                           // * Проверяем новый адрес модуля.
         Serial.println("Адрес модуля изменён");  // * Успех записи нового адреса можно проверить по результату присвоения: if( j=newAddress ){/*успешно*/;}else{/*провал*/;}
     }                                            // * 
     Serial.print("Текущий адрес модуля 0x");     //
     Serial.println( j, HEX );                    //   Выводим текущий адрес модуля.
}                                                 //
                                                  //
void loop(){                                      //
}                                                 //
                                                  //
//  ПРИМЕЧАНИЕ:                                   //
//  Данный скетч демонстрирует не только          //
//  возможность смены адреса на указанный в       //
//  переменной newAddress, но и обнаружение,      //
//  и вывод текущего адреса модуля на шине I2C.   //
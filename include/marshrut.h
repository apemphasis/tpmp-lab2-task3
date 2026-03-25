/*
Yauheni Kazlouski
*/

#ifndef MARSHRUT_H
#define MARSHRUT_H

/*
Заголовочный файл модуля для взаимодействия с маршрутами
Здесь описана структура маршрута и функции, относящиеся к ней
*/

#include <stdio.h>


/*
Константы для максимального числа маршрутов в массиве и максимаальной длины имени точки старта/назначения
*/
#define MAX_MARSHUTS 10
#define MAX_NAME_LEN 50

/*
Стркутура MARSHRUT содержит:
 - номер маршрута
 - начальная точка
 - точка назначения
 - расстояние
*/
struct MARSHRUT {
    int     number;
    char    start[MAX_NAME_LEN];
    char    end[MAX_NAME_LEN];
    double  distance;
};

/*
Функция create_array()
Создает массив структур MARSHRUT с вводом данных с клавиатуры

Параметры:
 - routes - указатель на массив структур MARSHRUT
 - max_size - максимальное количество элементов

Возвращает:
  int - количество введенных маршрутов
*/
int create_array(struct MARSHRUT *routes, int max_size);

#endif
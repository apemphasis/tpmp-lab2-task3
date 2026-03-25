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


/*
Функция print_array
Выводит содержимое массива маршрутов на экран
 
Параметры:
  routes - указатель на массив структур MARSHRUT
  size - количество элементов в массиве
*/
void print_array(const struct MARSHRUT *routes, int size);


/*
Функция find_max_length
Находит индекс маршрута с максимальной длиной

Параметры:
  routes - указатель на массив структур MARSHRUT
  size - количество элементов в массиве

Возвращает:
  int - индекс маршрута с максимальной длиной, или -1 если массив пуст
 */
int find_max_length(const struct MARSHRUT *routes, int size);

/*
Функция sort_by_number
Сортирует массив маршрутов по возрастанию номеров

Параметры:
  routes - указатель на массив структур MARSHRUT
  size - количество элементов в массиве
 */
void sort_by_number(struct MARSHRUT *routes, int size);

/*
Функция find_marshruts_by_point
Находит индексы маршрутов, которые начинаются или заканчиваются в заданном пункте

Параметры:
  routes - указатель на массив структур MARSHRUT
  size - количество элементов в массиве
  point - указатель на строку с названием пункта
  indices - указатель на массив для сохранения индексов найденных маршрутов

Возвращает:
  int - количество найденных маршрутов (0, если не найдено или массив пуст)
 */
int find_marshruts_by_point(const struct MARSHRUT *routes, int size, const char *point, int *indices);
#endif
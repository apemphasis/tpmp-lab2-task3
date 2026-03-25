/*
Yauheni Kazlouski
*/

/*
Реализация функций для работы с маршрутами
*/

#include <stdio.h>
#include <string.h>
#include "marshrut.h"

/*
Функция create_marshruts_array
Реализует ввод данных о маршрутах с клавиатуры
*/
int create_array(struct MARSHRUT *routes, int max_size) {
    int     count;
    int     i;

    printf("Введите количество маршрутов (не более %d): ", max_size);
    scanf("%d", &count);
    getchar();
    if (count <= 0 || count > max_size) {
        printf("Ошибка! Количество должно быть от 1 до %d.\n", max_size);
        return 0;
    }

    printf("\nВведите данные о маршрутах:\n");
    for (i = 0; i < count; i++) {
        printf("\nМаршрут [%d/%d]:\n", i + 1, max_size);
        
        printf("  Номер маршрута: ");
        scanf("%d", &routes[i].number);
        getchar();
        
        printf("  Начальный пункт: ");
        fgets(routes[i].start, MAX_NAME_LEN, stdin);
        routes[i].start[strcspn(routes[i].start, "\n")] = '\0';
        
        printf("  Конечный пункт: ");
        fgets(routes[i].end, MAX_NAME_LEN, stdin);
        routes[i].end[strcspn(routes[i].end, "\n")] = '\0';
        
        printf("  Длина маршрута: ");
        scanf("%lf", &routes[i].distance);
        getchar();
    }
    
    return count;
}


/*
Функция print_array
Выводит массив маршрутов на экран
*/
void print_array(const struct MARSHRUT *routes, int size)
{
    int i;
    
    if (size <= 0) {
        printf("Массив маршрутов пуст.\n");
        return;
    }
    
    printf("\nСписок всех маршрутов:\n");
    printf("======================\n");
    
    for (i = 0; i < size; i++) {
        printf("\nМаршрут #%d:\n", i + 1);
        printf("  Номер:         %d\n", routes[i].number);
        printf("  Начальный пункт: %s\n", routes[i].start);
        printf("  Конечный пункт:  %s\n", routes[i].end);
        printf("  Длина:         %.2f\n", routes[i].distance);
        printf("----------------------\n");
    }
}

/*
Функция find_max_length
Находит индекс маршрута с максимальной длиной
*/
int find_max_length(const struct MARSHRUT *routes, int size)
{
    int     max_index;
    int     i;
    
    if (size <= 0) {
        return -1;
    }
    
    max_index = 0;
    for (i = 1; i < size; i++) {
        if (routes[i].distance > routes[max_index].distance) {
            max_index = i;
        }
    }
    
    return max_index;
}


/*
Функция sort_by_number
Сортирует массив маршрутов по возрастанию номеров
 */
void sort_by_number(struct MARSHRUT *routes, int size)
{
    struct MARSHRUT temp;
    int             i, j;
    int             swapped;
    
    if (size <= 1) {
        return; 
    }
    
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (routes[j].number > routes[j + 1].number) {
                temp = routes[j];
                routes[j] = routes[j + 1];
                routes[j + 1] = temp;
                swapped = 1;
            }
        }
       
        if (!swapped) {
            break;
        }
    }
}
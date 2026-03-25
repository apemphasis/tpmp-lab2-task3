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
/*
Yauheni Kazlouski
*/

/*
Точка входа программы
Демонстрирует работу всех функций
*/

#include <stdio.h>
#include <stdbool.h>
#include "marshrut.h"

int main(void) {
    struct MARSHRUT   routes[MAX_MARSHUTS];
    int               current_size;
    int               choice;
    bool              defined = false;
    int               max_index;
    
    printf("Программа для работы с маршрутами\n");
    
    do {
        printf("\nМеню:\n");
        printf("1. Создать массив маршрутов\n");
        printf("2. Вывести все маршруты\n");
        printf("3. Найти маршрут с максимальной длиной\n");
        printf("4. Отсортировать маршруты по номерам\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                current_size = create_array(routes, MAX_MARSHUTS);
                if (current_size > 0) {
                    printf("Создано %d маршрутов.\n", current_size);
                    if (!defined) {
                        defined = true;
                    }
                }
                break;

            case 2:
                if (defined) {
                    print_array(routes, current_size);
                } else {
                    printf("Маршруты не заданы\n");
                }
                break;

            case 3:
                max_index = find_max_length(routes, current_size);
                if (max_index == -1) {
                    printf("Массив маршрутов пуст. Сначала создайте маршруты.\n");
                } else {
                    printf("\nМаршрут с максимальной длиной:\n");
                    printf("==============================\n");
                    printf("Номер:         %d\n", routes[max_index].number);
                    printf("Начальный пункт: %s\n", routes[max_index].start);
                    printf("Конечный пункт:  %s\n", routes[max_index].end);
                    printf("Длина:         %.2f\n", routes[max_index].distance);
                }
                break;

            case 4:
                if (current_size <= 0) {
                    printf("Массив маршрутов пуст. Сначала создайте маршруты.\n");
                } else {
                    sort_by_number(routes, current_size);
                    printf("Маршруты отсортированы по возрастанию номеров.\n");
                }
                break;

            case 0:
                printf("Программа завершена.\n");
                break;
                
            default:
                printf("Неверный выбор! Попробуйте снова.\n");
        }
    } while (choice != 0);
    
    return 0;
}
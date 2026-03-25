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
        printf("5. Найти маршруты, которые начинаются или заканчиваются в пункте\n");
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
                if (!defined) {
                    printf("Массив маршрутов пуст. Сначала создайте маршруты.\n");
                } else {
                    max_index = find_max_length(routes, current_size);
                    printf("\nМаршрут с максимальной длиной:\n");
                    printf("==============================\n");
                    printf("Номер:         %d\n", routes[max_index].number);
                    printf("Начальный пункт: %s\n", routes[max_index].start);
                    printf("Конечный пункт:  %s\n", routes[max_index].end);
                    printf("Длина:         %.2f\n", routes[max_index].distance);
                }
                break;

            case 4:
                if (!defined) {
                    printf("Массив маршрутов пуст. Сначала создайте маршруты.\n");
                } else {
                    sort_by_number(routes, current_size);
                    printf("Маршруты отсортированы по возрастанию номеров.\n");
                }
                break;

            case 5:
                if (!defined) {
                    printf("Массив маршрутов пуст. Сначала создайте маршруты.\n");
                } else {
                    printf("Введите название пункта для поиска: ");
                    char* search_point;
                    fgets(search_point, MAX_NAME_LEN, stdin);
                    search_point[strcspn(search_point, "\n")] = '\0';  
                    int found_count;
                    int* found_indices;
                    found_count = find_marshruts_by_point(routes, current_size, search_point, found_indices);
                    
                    if (found_count == 0) {
                        printf("Маршруты, начинающиеся или заканчивающиеся в пункте '%s', не найдены.\n", search_point);
                    } else {
                        printf("\nНайдено %d маршрут(ов), которые начинаются или заканчиваются в пункте '%s':\n", found_count, search_point);
                        printf("========================================================\n");
                        for (int i = 0; i < found_count; i++) {
                            printf("\nМаршрут #%d:\n", found_indices[i] + 1);
                            printf("  Номер:         %d\n", routes[found_indices[i]].number);
                            printf("  Начальный пункт: %s\n", routes[found_indices[i]].start);
                            printf("  Конечный пункт:  %s\n", routes[found_indices[i]].end);
                            printf("  Длина:         %.2f\n", routes[found_indices[i]].distance);
                            printf("----------------------\n");
                        }
                    }
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
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
    
    printf("Программа для работы с маршрутами\n");
    
    do {
        printf("\nМеню:\n");
        printf("1. Создать массив маршрутов\n");
        printf("2. Вывести все маршруты\n");
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

            case 0:
                printf("Программа завершена.\n");
                break;
                
            default:
                printf("Неверный выбор! Попробуйте снова.\n");
        }
    } while (choice != 0);
    
    return 0;
}
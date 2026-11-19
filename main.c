#include <stdio.h>
#include "funcs.h"

/**
 * @brief точка входу в програму
 * @return 0 при успішному виконанні
 *         1 у разі помилок
 */

int main() {
    // оголошення змінної початкового та кінцевого значення аргументу
    // оголошення змінної кроку зміни аргументу
    double x_start, x_end, step;

    // оголошення змінної кількості точок, в яких буде відбуватись обчислення мат. функ.
    int n;

    // оголошення масивів символів для шифру групи та прізвища ім'я студента
    char group[10];
    char student[30];

    // зчитування вхідних даних із текстового файлу
    // перевірка результату виконання функції read_input
    if(!read_input("../input.txt", &x_start, &x_end, &n, &step, group, student)) {
        printf("error reading input.txt file\n");
        return 1;
    }

    // обчислення функції та запис результатів у текстовий і бінарний файли
    // перевірка результату виконання функції write_files
    if(!write_files("output.txt", "data.bin", x_start, n, step, group, student)) {
        printf("error writing output.txt file\n");
        return 1;
    }

    // зчитування даних із бінарного файлу та виведення таблиці
    // перевірка результату виконання функції read_n_print_bin
    if (!read_n_print_bin("data.bin")) {
        printf("error reading data.bin\n");
        return 1;
    }

    return 0;
}
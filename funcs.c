#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

/**
 * @file funcs.c
 * @brief реалізація функцій
*/

double calc_f(double x) {
    // обчислення значення функції за варіантом 12
    return pow(x / 100 - 5, 5)
           - pow(x / 50 + 10, 4)
           - pow(x / 25 - 15, 3)
           - (x * x)
           - 10;
}

int read_input(const char *filename, double *x_start, double *x_end,
               int *n, double *step, char *group, char *student) {
    // відкриття вхідного текстового файлу в режимі рід-онлі
    FILE *f = fopen(filename, "r");
    // перевірка коректного відкриття файлу
    if (!f) return 0;

    // послідовне зчитування даних
    fscanf(f, "%lf", x_start);
    fscanf(f, "%lf", x_end);
    fscanf(f, "%d", n);
    fscanf(f, "%lf", step);
    fscanf(f, " %9[^\r\n]", group);
    fscanf(f, " %29[^\r\n]", student);
    fclose(f);

    return 1;
}

int write_files(const char *txt_name, const char *bin_name, double x_start, int n,
                 double step, const char *group, const char *student) {
    // відкриття текстового та бінарного файлів у режимі запису
    FILE *ft = fopen(txt_name, "w");
    FILE *fb = fopen(bin_name, "wb");
    if (!ft || !fb) {
        if (ft) fclose(ft);
        if (fb) fclose(fb);
        return 0;
    }
    // запис кількості рядків таблиці n на початок бінарного файлу
    fwrite(&n, sizeof(int), 1, fb);

    // виведення таблиці у текстовий файл
    fprintf(ft, "#-------#-------------#------------#\n");
    fprintf(ft, "#   N   #      X      #    f(x)    #\n");
    fprintf(ft, "#-------#-------------#------------#\n");

    // розрахунок значень функції та запис у обидва файли
    for (int i = 0; i < n; i++) {
        double x = x_start + i * step;
        double y = calc_f(x);

        // запис рядка таблиці у текстовий файл
        fprintf(ft, "| %5d | %11.4lf | %10.2lf |\n", i + 1, x, y);

        // запис пари (х, f(x)) у бінарний файл
        fwrite(&x, sizeof(double), 1, fb);
        fwrite(&y, sizeof(double), 1, fb);
    }

    // вивід шифру групи та ім'я студента
    fprintf(ft, "#-------#-------------#------------#\n");
    fprintf(ft, "%s\n", group);
    fprintf(ft, "%s\n", student);

    // закриття файлів
    fclose(ft);
    fclose(fb);

    return 1;
}

int read_n_print_bin(const char *bin_name) {
    // відкриття бінарного файлу в режимі рід-онлі
    FILE *fb = fopen(bin_name, "rb");
    if (!fb) return 0;

    // зчитування кількості рядків n
    int n = 0;

    fread(&n, sizeof(int), 1, fb);

    // виділення динамічної пам'яті під масив розміром 2*n типу дабл
    double *data = (double *)malloc(2 * n * sizeof(double));

    // зчитування всіх пар (x, f(x)) у динамічний масив
    fread(data, sizeof(double), 2 * n, fb);
    fclose(fb);

    // виведення таблиці
    printf("output from binary file\n");
    printf("#-------#-------------#------------#\n");
    printf("#   N   #      X      #    f(x)    #\n");
    printf("#-------#-------------#------------#\n");
    for (int i = 0; i < n; i++) {
        // data[2*i] - аргумент x, data[2*i+1] - значення f(x)
        printf("| %5d | %11.4lf | %10.2lf |\n", i+1, data[2*i], data[2*i+1]);
    }
    printf("#-------#--------------#-----------#\n");

    // звільнення динамічної пам'яті
    free(data);

    return 1;
}
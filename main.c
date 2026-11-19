#include <stdio.h>
#include "funcs.h"

int main() {
    // оголошення змінної початкового, кінцевого значення аргументу
    // оголошення змінної кроку зміни аргументу
    double x_start, x_end, step;

    // оголошення змінної кількості точок, в яких буде відбуватись обчислення мат. функ.
    int n;
    char group[100];
    char student[100];

    if(!read_input("../input.txt", &x_start, &x_end, &n, &step, group, student)) {
        printf("error reading input.txt file\n");
        return 1;
    }

    if(!write_files("output.txt", "data.bin", x_start, n, step, group, student)) {
        printf("error writing output.txt file\n");
        return 1;
    }

    if (!read_n_print_bin("data.bin")) {
        printf("error reading data.bin\n");
        return 1;
    }

    return 0;
}
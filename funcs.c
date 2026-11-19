#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

double calc_f(double x) {
    return pow(x / 100 - 5, 5)
           - pow(x / 50 + 10, 4)
           - pow(x / 25 - 15, 3)
           - (x * x)
           - 10;
}

int read_input(const char *filename, double *x_start, double *x_end,
               int *n, double *step, char *group, char *student) {
    FILE *f = fopen(filename, "r");
    if (!f) return 0;

    fscanf(f, "%lf", x_start);
    fscanf(f, "%lf", x_end);
    fscanf(f, "%d", n);
    fscanf(f, "%lf", step);
    fscanf(f, " %99[^\r\n]", group);
    fscanf(f, " %99[^\r\n]", student);
    fclose(f);

    return 1;
}

int write_files(const char *txt_name, const char *bin_name, double x_start, int n,
                 double step, const char *group, const char *student) {
    FILE *ft = fopen(txt_name, "w");
    FILE *fb = fopen(bin_name, "wb");
    if (!ft || !fb) {
        if (ft) fclose(ft);
        if (fb) fclose(fb);
        return 0;
    }
    fwrite(&n, sizeof(int), 1, fb);

    fprintf(ft, "#-------#-------------#------------#\n");
    fprintf(ft, "#   N   #      X      #    f(x)    #\n");
    fprintf(ft, "#-------#-------------#------------#\n");

    for (int i = 0; i < n; i++) {
        double x = x_start + i * step;
        double y = calc_f(x);
        fprintf(ft, "| %5d | %11.4lf | %10.2lf |\n", i + 1, x, y);
        fwrite(&x, sizeof(double), 1, fb);
        fwrite(&y, sizeof(double), 1, fb);
    }

    fprintf(ft, "#-------#-------------#------------#\n");
    fprintf(ft, "%s\n", group);
    fprintf(ft, "%s\n", student);

    fclose(ft);
    fclose(fb);

    return 1;
}

int read_n_print_bin(const char *bin_name) {
    FILE *fb = fopen(bin_name, "rb");
    if (!fb) {
        return 0;
    }

    int n = 0;

    fread(&n, sizeof(int), 1, fb);

    double *data = (double *)malloc(2 * n * sizeof(double));
    fread(data, sizeof(double), 2 * n, fb);
    fclose(fb);

    printf("output from binary file\n");
    printf("#-------#-------------#------------#\n");
    printf("#   N   #      X      #    f(x)    #\n");
    printf("#-------#-------------#------------#\n");
    for (int i = 0; i < n; i++) {
        printf("| %5d | %11.4lf | %10.2lf |\n", i+1, data[2*i], data[2*i+1]);
    }
    printf("#-------#--------------#------------#\n");

    free(data);

    return 1;
}
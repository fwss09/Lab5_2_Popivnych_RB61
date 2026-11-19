#ifndef LAB5_2_POPIVNYCH_RB61_FUNCS_H
#define LAB5_2_POPIVNYCH_RB61_FUNCS_H

double calc_f(double x);
int read_input(const char *filename, double *x_start, double *x_end,
               int *n, double *step, char *group, char *student);
void write_files(const char *txt_name, const char *bin_name, double x_start, int n,
                 double step, const char *group, const char *student);
void read_n_print_bin(const char *bin_name);

#endif //LAB5_2_POPIVNYCH_RB61_FUNCS_H
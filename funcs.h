#ifndef LAB5_2_POPIVNYCH_RB61_FUNCS_H
#define LAB5_2_POPIVNYCH_RB61_FUNCS_H

/**
 * @brief обчислює значення математичної функції
 * @param x значення аргументу функції
 * @return обчислене значення функції
 */
double calc_f(double x);

/**
 * @brief зчитує дані з текстового файлу
 * @param filename ім'я/шлях до вхідного текстового файлу
 * @param x_start вказівник для збереження початкового значення аргументу
 * @param x_end вказівник для збереження кінцевого значення аргументу
 * @param n вказівник для збереження кількості точок у таблиці
 * @param step вказівник для збереження кроку зміни аргументу
 * @param group масив символів для збереження шфиру групи
 * @param student масив символів для збереження прізвища та імені студента
 * @return 1 у разі успішного виконання, 0 у разі помилки
 */
int read_input(const char *filename, double *x_start, double *x_end,
               int *n, double *step, char *group, char *student);

/**
 * @brief обчислює значення функції та записує результати у текстовий та бінарний файл
 * @param txt_name ім'я/шлях до текстового файлу
 * @param bin_name ім'я/шлях до бінарного файлу
 * @param x_start початкове значення аргументу
 * @param n кількість точок у таблиці
 * @param step крок зміни аргументу
 * @param group рядок із шифром групи
 * @param student рядок із прізвищем та ім'ям студента
 * @return 1 у разі успішного виконання, 0 у разі помилки
 */
int write_files(const char *txt_name, const char *bin_name, double x_start, int n,
                double step, const char *group, const char *student);

/**
 * @brief зчитує дані з бінарного файлу у динамічний масив та виводить таблицю
 * @param bin_name ім'я/шлях до бінарного файлу
 * @return 1 у разі успішного виконання, 0 у разі помилки
 */
int read_n_print_bin(const char *bin_name);

#endif //LAB5_2_POPIVNYCH_RB61_FUNCS_H
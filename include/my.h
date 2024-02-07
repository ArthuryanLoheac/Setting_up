/*
** EPITECH PROJECT, 2023
** my_header
** File description:
** Write your my.h header
*/

#ifndef MY_H_
    #define MY_H_

int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
int mini_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
int get_number_lines(char *fichier);
int my_compute_power_rec(int nb, int p);
void set_zeros_str(char *str, char *strsave);
char *my_strcat(char *dest, char const *src);
int get_len_lines(char *fichier);
char **set_tableau(char **tableau, int number_lines,
    int len_line, char *fichier);
char **malloc_tableau(char **tableau, int number_lines, int len_line);
char **set_tableau_fichier(char **argv, char **tableau, int *number_lines);
char **set_tableau_generate(char **argv, char **tableau,
    int *number_lines, int *error);
int find_square_and_replace(char **tableau, int number_lines);
void print_array_and_free(char **tableau, int number_lines);

#endif /* MY_H_ */

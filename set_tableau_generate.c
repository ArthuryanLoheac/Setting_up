/*
** EPITECH PROJECT, 2023
** set_tableau_generate
** File description:
** set_tableau_generate
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

static void assign_if_egal(char *str, int *k)
{
    if (*k >= my_strlen(str)) {
        *k = 0;
    }
}

static char **generate_and_set(char **tableau, int number_lines, char *str)
{
    int k = 0;

    for (int i = 0; i < number_lines; i++) {
        for (int j = 0; j <= number_lines; j++) {
            assign_if_egal(str, &k);
            tableau[i][j] = str[k];
            k++;
        }
        tableau[i][number_lines] = '\0';
        k--;
    }
    return tableau;
}

static int get_number(char *str)
{
    int value = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        value += (str[i] - '0') *
        my_compute_power_rec(10, my_strlen(str) - i - 1);
    }
    return value;
}

static int check_valid_str(char **argv)
{
    int len = my_strlen(argv[2]);

    for (int i = 0; i < len; i++) {
        if (argv[2][i] != '.' && argv[2][i] != 'o') {
            return 1;
        }
    }
    return 0;
}

char **set_tableau_generate(char **argv, char **tableau,
    int *number_lines, int *error)
{
    *number_lines = get_number(argv[1]);
    if (*number_lines <= 0) {
        *error = 84;
        return tableau;
    }
    if (check_valid_str(argv) == 1) {
        *error = 84;
        return tableau;
    }
    tableau = malloc_tableau(tableau, *number_lines, *number_lines);
    tableau = generate_and_set(tableau, *number_lines, argv[2]);
    return tableau;
}

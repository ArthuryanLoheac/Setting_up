/*
** EPITECH PROJECT, 2023
** print_array_and_free
** File description:
** print_array_and_free
*/
#include "my.h"
#include "structure.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void print_array_and_free(char **tableau, int number_lines)
{
    int num_cols = my_strlen(tableau[0]);

    for (int i = 0; i < number_lines; i++) {
        write(1, tableau[i], num_cols);
        write(1, "\n", 1);
    }
    free(tableau);
}

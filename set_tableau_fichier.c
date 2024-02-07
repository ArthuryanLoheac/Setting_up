/*
** EPITECH PROJECT, 2023
** set_tableau_fichier
** File description:
** set_tableau_fichier
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

char **set_tableau_fichier(char **argv, char **tableau, int *number_lines)
{
    int len_line = 0;

    *number_lines = get_number_lines(argv[1]);
    if (*number_lines == -1) {
        return NULL;
    }
    len_line = get_len_lines(argv[1]);
    tableau = malloc_tableau(tableau, *number_lines, len_line);
    tableau = set_tableau(tableau, *number_lines, len_line, argv[1]);
    return tableau;
}

/*
** EPITECH PROJECT, 2023
** set tableau
** File description:
** set  tableau with datas
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

char **malloc_tableau(char **tableau, int number_lines, int len_line)
{
    tableau = malloc(sizeof(char *) * number_lines);
    for (int i = 0; i < number_lines; i++) {
        tableau[i] = malloc(sizeof(char) * len_line + 1);
    }
    return tableau;
}

static void read_and_asign(int f1, int i, int j, char **tableau)
{
    char c = '\0';

    read(f1, &c, 1);
    if (c != '\n') {
        tableau[i][j] = c;
    }
}

char **set_tableau(char **tableau, int number_lines,
    int len_line, char *fichier)
{
    char c = '\0';
    int f1 = open(fichier, O_RDONLY);
    int nb_char_read = -1;

    while (nb_char_read != 0 && c != '\n') {
        nb_char_read = read(f1, &c, 1);
    }
    for (int i = 0; i < number_lines; i++) {
        for (int j = 0; j < len_line + 1; j++) {
            read_and_asign(f1, i, j, tableau);
        }
        tableau[i][len_line] = '\0';
    }
    close(f1);
    return tableau;
}

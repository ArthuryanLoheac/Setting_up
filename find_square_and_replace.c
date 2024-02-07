/*
** EPITECH PROJECT, 2023
** find_square_and_replace
** File description:
** find_square_and_replace
*/
#include "my.h"
#include "structure.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void initialise_struct(struct positions *pos,
    int num_lines, int num_cols)
{
    pos->x = -1;
    pos->y = -1;
    pos->len = 0;
    pos->num_lines = num_lines;
    pos->num_cols = num_cols;
}

static int is_different(char a, char b)
{
    if (a != b) {
        return 1;
    }
    return 0;
}

static void is_square(char **tableau, struct positions *pos, int y, int x)
{
    int nb_diff = 0;

    if (pos->len == pos->num_cols || pos->len == pos->num_lines) {
        return;
    }
    for (int i = 0; i < pos->len + 1; i++) {
        for (int j = 0; j < pos->len + 1; j++) {
            nb_diff += is_different(tableau[y + i][x + j], '.');
        }
        if (nb_diff != 0) {
            return;
        }
    }
    pos->len = pos->len + 1;
    pos->x = x;
    pos->y = y;
    return is_square(tableau, pos, y, x);
}

static void is_good_char(int *error, char a)
{
    if (a != '.' && a != 'o') {
        *error = - 1;
    }
}

int find_square_and_replace(char **tableau, int number_lines)
{
    struct positions pos;
    int num_cols = my_strlen(tableau[0]);
    int error = 0;

    initialise_struct(&pos, number_lines, num_cols);
    for (int i = 0; i < number_lines - pos.len; i++) {
        for (int j = 0; j < num_cols - pos.len; j++) {
            is_good_char(&error, tableau[i][j]);
            is_square(tableau, &pos, i, j);
        }
    }
    for (int i = 0; i < pos.len; i++) {
        for (int j = 0; j < pos.len; j++) {
            tableau[pos.y + i][pos.x + j] = 'x';
        }
    }
    return error;
}

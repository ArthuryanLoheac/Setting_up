/*
** EPITECH PROJECT, 2023
** Main setting up
** File description:
** main setting up
*/
#include "my.h"
#include "structure.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int test_argc(struct stat *stat_fichier, int argc)
{
    if ((stat_fichier->st_mode & __S_IFMT) != __S_IFREG) {
        return 1;
    }
    if (argc != 2) {
        return 1;
    }
    return 0;
}

static int return_find_and_print(int error, char **tableau, int number_lines)
{
    if (error != 0 || tableau == NULL) {
        return 84;
    }
    if (find_square_and_replace(tableau, number_lines) == -1) {
        return 84;
    }
    print_array_and_free(tableau, number_lines);
    return 0;
}

int main(int argc, char **argv)
{
    struct stat stat_fichier;
    int number_lines = 0;
    char **tableau;
    int error = 0;

    tableau = malloc(sizeof(char *) * 1);
    if (stat(argv[1], &stat_fichier) == 0) {
        error += test_argc(&stat_fichier, argc);
        if (error == 0) {
            tableau = set_tableau_fichier(argv, tableau, &number_lines);
        }
    } else {
        if (argc == 3) {
            tableau = set_tableau_generate(argv, tableau,
                &number_lines, &error);
        } else {
            return 84;
        }
    }
    return return_find_and_print(error, tableau, number_lines);
}

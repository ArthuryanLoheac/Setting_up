/*
** EPITECH PROJECT, 2023
** get_number_lines
** File description:
** get and return tthe number of lines
*/
#include <stdlib.h>
#include "my.h"
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

static int get_number_from_str(char *str)
{
    int len = my_strlen(str);
    int value = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
        value += (str[i] - '0')
            * my_compute_power_rec(10, (len - i - 1));
    }
    return value;
}

static char *put_number_in_str(char *str, char *strsave, char *fichier)
{
    int i = 0;
    char c = '\0';
    int f1 = open(fichier, O_RDONLY);

    while (read(f1, &c, 1) != 0 && c != '\n') {
        my_strcpy(strsave, str);
        i++;
        str = malloc(sizeof(char) * i);
        my_strcpy(str, strsave);
        str[i - 1] = c;
        strsave = malloc(sizeof(char) * i);
    }
    read(f1, &c, 1);
    close(f1);
    return str;
}

void set_zeros_str(char *str, char *strsave)
{
    int j = 0;

    while (str[j] != '\0') {
        str[j] = '\0';
        j++;
    }
    j = 0;
    while (strsave[j] != '\0') {
        strsave[j] = '\0';
        j++;
    }
}

int get_number_lines(char *fichier)
{
    int number_lines = 0;
    char *str;
    char *strsave;

    str = malloc(sizeof(char) * 1);
    strsave = malloc(sizeof(char) * 1);
    set_zeros_str(str, strsave);
    str = put_number_in_str(str, strsave, fichier);
    number_lines = get_number_from_str(str);
    free(str);
    free(strsave);
    return number_lines;
}

int get_len_lines(char *fichier)
{
    int len_lines = 0;
    char c = '\0';
    int f1 = open(fichier, O_RDONLY);
    int nb_char_read = -1;

    while (nb_char_read != 0 && c != '\n') {
        nb_char_read = read(f1, &c, 1);
    }
    while (read(f1, &c, 1) != 0 && c != '\n') {
        len_lines++;
    }
    return len_lines;
}

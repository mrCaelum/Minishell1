/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Get_entery function
*/

#include "minishell1.h"

static char **add_to_tab(char **tab, char *str)
{
    char **new = NULL;
    int size = 0;

    if (tab)
        for (; tab[size]; size++);
    if (!(new = malloc((size + 2) * sizeof(char *))))
        return (tab);
    for (int i = 0; i < size; i++)
        new[i] = tab[i];
    new[size] = str;
    new[size + 1] = NULL;
    free(tab);
    return (new);
}

static char read_char(char old, unsigned char dp)
{
    char c;

    if (read(0, &c, 1) <= 0)
        exit(0);
    if (!dp && (old == ' ' || old == '\t') && (c == ' ' || c == '\t'))
        return (0);
    return (c);
}

static void free_ptr(char **ptr)
{
    if (*ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}

char **get_entery(void)
{
    unsigned char dp = 0;
    char c[2] = {0, 0};
    char **entery = NULL;
    char *str = NULL;
    char *tmp = NULL;

    while (c[0] != '\n') {
        c[0] = read_char(c[0], dp);
        if (c[0] == '\"')
            dp = !dp;
        else if ((c[0] == ' ' || c[0] == '\t') && !dp) {
            entery = add_to_tab(entery, str);
            str = NULL;
        } else if (c[0] >= 32 && c[0] <= 126) {
            tmp = str;
            str = str_concat(str, c);
        }
        free_ptr(&tmp);
    }
    return (str ? add_to_tab(entery, str) : entery);
}

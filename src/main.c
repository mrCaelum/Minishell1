/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Main
*/

#include "minishell1.h"
#include <stdio.h>

static const char const *default_env[] = {
    "PATH=/usr/bin",
    NULL
};

static char **get_env(char const *env[])
{
    char **new;
    int size = 0;

    if (!env[0])
        return (NULL);
    for (; env[size]; size++);
    if (!(new = malloc((size + 1) * sizeof(char *))))
        return (NULL);
    for (int i = 0; env[i]; i++) {
        new[i] = malloc((str_length(env[i]) + 1) * sizeof(char));
        new[i] = str_alloc(env[i]);
    }
    new[size] = NULL;
    return (new);
}

int main(int argc, char const *argv[], char const *env[])
{
    char **mod_env = NULL;

    mod_env = get_env((!env) || (!(*env)) ? default_env : env);
    return (sh(&mod_env));
}

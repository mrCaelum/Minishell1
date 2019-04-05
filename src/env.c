/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Env Functions
*/

#include "env.h"

char *get_env_element(char ***env, char const *element)
{
    char *aelement = str_alloc(element);
    char *env_el = str_concat(aelement, "=");
    char *str = NULL;

    free(aelement);
    if (!(*env))
        return (NULL);
    for (int i = 0; (*env)[i]; i++)
        if (str_startwith((*env)[i], env_el))
            str = str_alloc((*env)[i] + str_length(env_el));
    free(env_el);
    return (str);
}

void func_env(char **entery, char ***env)
{
    if (!(*env))
        return;
    for (int i = 0; (*env)[i]; i++)
        if ((*env)[i]) {
            write(1, (*env)[i], str_length((*env)[i]));
            write(1, "\n", 1);
        }
}

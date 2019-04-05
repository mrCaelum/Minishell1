/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Env Functions
*/

#include "env.h"

static int get_env_pos(char ***env, char const *element)
{
    char *aelement = str_alloc(element);
    char *env_el = str_concat(aelement, "=");

    free(aelement);
    if (!(*env))
        return (-1);
    for (int i = 0; (*env)[i]; i++)
        if (str_startwith((*env)[i], env_el)) {
            free(env_el);
            return (i);
        }
    free(env_el);
    return (-1);
}

static int change_tab(char ***env)
{
    char **old = (*env);
    char **new;
    int size = 0;

    if (!(*env)) {
        (*env) = malloc(2 * sizeof(char *));
        (*env)[1] = NULL;
        return (0);
    }
    for (; old[size]; size++);
    new = malloc((size + 2) * sizeof(char *));
    for (int i = 0; old[i]; i++)
        new[i] = old[i];
    new[size + 1] = NULL;
    (*env) = new;
    free(old);
    return (size);
}

void func_setenv(char **entery, char ***env)
{
    char *env_el = get_env_element(env, entery[1]);
    int pos = 0;
    char *tmp = NULL;
    char *new = NULL;

    if (!entery || !entery[0] || !entery[1]) {
        if (!entery[1])
            func_env(NULL, env);
        return;
    }
    tmp = str_concat(entery[1], "=");
    new = entery[2] ? str_concat(tmp, entery[2]) : tmp;
    if (entery[2])
        free(tmp);
    if (env_el) {
        pos = get_env_pos(env, entery[1]);
        free((*env)[pos]);
    } else
        pos = change_tab(env);
    (*env)[pos] = new;
}

static char *copy_env(char *old, char **entery, int *id)
{
    for (int i = 1; entery[i]; i++)
        if (str_startwith(old, entery[i]))
            return (free(old), NULL);
    (*id)++;
    return (old);
}

void func_unsetenv(char **entery, char ***env)
{
    char **old = (*env);
    char **new;
    int size = 0;

    if (!entery[1])
        return (void)write(2, "unsetenv: Too few arguments.\n", 29);
    for (; old[size]; size++);
    for (int i = 1; entery[i]; i++)
        if (get_env_pos(env, entery[i]) >= 0)
            size--;
    if (!(new = malloc((size + 1) * sizeof(char *))))
        return;
    for (int i = 0, j = 0; old[j]; j++)
        new[i] = copy_env(old[j], entery, &i);
    new[size] = NULL;
    (*env) = new;
    free(old);
}

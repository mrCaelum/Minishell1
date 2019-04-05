/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** PS
*/

#include "minishell1.h"

void print_ps(char const *str, char ***env)
{
    char *aps = NULL;
    char cwd[64];
    char *user = get_env_element(env, "USER");
    char *home = get_env_element(env, "HOME");

    if (!str)
        return (void)write(1, "$ ", 2);
    aps = str_alloc(str);
    if (getcwd(cwd, 64))
        aps = str_replace(aps, "%d", cwd);
    if (user) {
        aps = str_replace(aps, "%u", user);
        free(user);
    }
    if (home) {
        aps = str_replace(aps, home, "~");
        free(home);
    }
    write(1, aps, str_length(aps));
    free(aps);
}

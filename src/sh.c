/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Sh function
*/

#include "minishell1.h"

static const struct ptr_tab const cmd_tab[] = {
    {"cd", &func_cd},
    {"env", &func_env},
    {"setenv", &func_setenv},
    {"unsetenv", &func_unsetenv},
    {NULL, NULL}
};

static int check_arg(char * const *tab, char const *str)
{
    int i = 0;

    for (; tab[0][i] == str[i] && str[i]; i++);
    if ((!tab[0][i] || tab[0][i] == ' ') && !str[i])
        return (1);
    return (0);
}

static void cmd(char **entery, char ***env, char **ps)
{
    if (check_arg(entery, "exit"))
        return;
    for (int i = 0; cmd_tab[i].cmd; i++)
        if (check_arg(entery, cmd_tab[i].cmd))
            return (cmd_tab[i].ptr(entery, env));
    if (call_cmd(entery, env) == -1) {
        write(2, entery[0], str_length(entery[0]));
        write(2, ": Command not found.\n", 21);
    }
}

int sh(char ***env)
{
    int active = 1;
    int return_value = 0;
    char **entery = NULL;
    char *ps = "[\033[1;31m%u\033[37m@earth] \033[34m%d \033[36m$\033[0;37m ";

    signal(SIGINT, (void *)signal_exit);
    while (active) {
        print_ps(ps, env);
        entery = get_entery();
        if (entery && check_arg(entery, "exit")
        && (return_value = func_exit(entery)) >= 0) {
            return (return_value);
        } else if (entery) {
            cmd(entery, env, &ps);
            free(entery);
        }
    }
    write(1, "exit\n", 5);
    return (0);
}

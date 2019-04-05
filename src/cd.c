/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Cd function
*/

#include "minishell1.h"

static void set_env_dir(char ***env, char *el, char *pwd)
{
    char cwd[64];
    char *tab[4] = {
        "setenv",
        el,
        pwd ? pwd : cwd,
        NULL
    };

    if (pwd)
        func_setenv(tab, env);
    else
        if (getcwd(cwd, 64))
            func_setenv(tab, env);
}

static char *replace_home(char *path, char ***env)
{
    for (int i = 0; (*env)[i]; i++)
        if (str_startwith((*env)[i], "HOME="))
            return (str_replace(path, "~", (*env)[i] + 5));
    return (path);
}

static void cd_errors(char const *path)
{
    if (errno == 2) {
        write(2, path, str_length(path));
        write(2, ": No such file or directory.\n", 29);
    }
    if (errno == 13) {
        write(2, path, str_length(path));
        write(2, ": Permission denied.\n", 21);
    }
}

static void cd(char *path, char ***env)
{
    char oldpwd[64];

    if (!getcwd(oldpwd, 64))
        oldpwd[0] = 0;
    if (str_is_equal(path, "-")) {
        free(path);
        path = get_env_element(env, "OLDPWD");
    } else
        path = replace_home(path, env);
    if (chdir(path) != 0)
        cd_errors(path);
    else {
        set_env_dir(env, "OLDPWD", oldpwd[0] ? oldpwd : NULL);
        set_env_dir(env, "PWD", NULL);
    }
    free(path);
}

void func_cd(char **cmd, char ***env)
{
    char *path = str_alloc(cmd[1] ? cmd[1] : "~");
    int i = 0;

    cd(path, env);
}

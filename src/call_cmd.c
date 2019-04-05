/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Call cmd function
*/

#include "minishell1.h"

static const struct signal_error signal_errors[] = {
    {SIGHUP,  "Hangup"},
    {SIGQUIT, "Quit"},
    {SIGABRT, "Abort"},
    {SIGBUS,  "Bus error "},
    {SIGFPE,  "Floating exception"},
    {SIGKILL, "Killed"},
    {SIGUSR1, "User signal 1"},
    {SIGSEGV, "Segmentation fault"},
    {SIGUSR2, "User signal 2"},
    {SIGPIPE, "Broken pipe"},
    {SIGTERM, "Terminated"},
    {0, NULL}
};

static void print_err(char const *str)
{
    write(2, str, str_length(str));
}

static char *get_exec(char **env_path_tab, char **entery)
{
    if (access(entery[0], X_OK) == -1)
        return (NULL);
    else
        return (str_alloc(entery[0]));
}

static char *get_path(char **env_path_tab, char **entery)
{
    char *path = NULL;
    char *tmp = NULL;

    for (int i = 0; env_path_tab[i]; i++) {
        tmp = str_concat(env_path_tab[i], "/");
        path = str_concat(tmp, entery[0]);
        free(tmp);
        if (access(path, X_OK) == -1) {
            free(path);
            path = NULL;
        } else
            break;
    }
    return (path);
}

static void check_status(int status)
{
    if (!WIFSIGNALED(status))
        return;
    for (int i = 0; signal_errors[i].id; i++)
        if (signal_errors[i].id == WTERMSIG(status)) {
            print_err(signal_errors[i].str);
            print_err(WCOREDUMP(status) ? " (core dumped)\n" : "\n");
        }
}

int call_cmd(char **entery, char ***env)
{
    char *env_path = get_env_element(env, "PATH");
    char **env_path_tab = str_to_tab(env_path ? env_path + 5 : NULL, ':');
    int status;
    int pid = 0;
    int return_value = 0;
    char *path = str_contain(entery[0], '/') ?
    get_exec(env_path_tab, entery) : get_path(env_path_tab, entery);

    if (!path)
        return (-1);
    if (!(pid = fork())) {
        return_value = execve(path, entery, (*env));
    } else
        waitpid(pid, &status, 0);
    check_status(status);
    free(path);
    free(env_path);
    free(env_path_tab);
    return (return_value);
}

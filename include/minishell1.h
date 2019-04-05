/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Header file
*/

#ifndef MINISHELL1_H_
#define MINISHELL1_H_

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <errno.h>
#include "str.h"
#include "env.h"

struct ptr_tab {
    char const *cmd;
    void (*ptr)(char **, char ***);
};

struct signal_error {
    int id;
    char const *str;
};

int sh(char ***);
char **get_entery(void);
char *get_realpath(char *, char ***);
int call_cmd(char **, char ***);

int func_exit(char **);
void func_cd(char **, char ***);

void print_ps(char const *, char ***);

void signal_exit(void);

#endif

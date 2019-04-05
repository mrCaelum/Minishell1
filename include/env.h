/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Header file
*/

#ifndef ENV_H_
#define ENV_H_

#include <unistd.h>
#include <stdlib.h>
#include "str.h"

char *get_env_element(char ***, char const *);
char **get_env_tab(char ***);

void func_env(char **, char ***);
void func_setenv(char **, char ***);
void func_unsetenv(char **, char ***);

#endif

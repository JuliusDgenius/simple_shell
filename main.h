#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void execute_cmd(char **argv);
char *get_path(char *cmd);
void prompt(void);
void prompt2(void);

#endif

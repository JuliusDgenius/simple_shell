#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * execute_cmd - executes the command passsed to the shell
 * @argv: An array of NULL terminated arg strings to the shell
 *
 * Return: Nothing
 */
void execute_cmd(char **argv)
{
	char *cmd = NULL, *real_cmd = NULL;
	pid_t pid;

	if (argv)
	{
		/* get command */
		cmd = argv[0];

		/* generate path to cmd */
		real_cmd = get_path(cmd);

		/* execute using execve */
		pid = fork();
		if (pid == 0)
		{
			if (execve(real_cmd, argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		wait(NULL);
	}
}

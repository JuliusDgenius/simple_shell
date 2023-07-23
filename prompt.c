#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * main - main function to print a prompt to thr terminal
 * @argc: argument count
 * @argv: argument vectors
 *
 * Return: Nothing
 */
int main(int argc, char **argv)
{
	char *prompt = "myShell$ "; /* prompt variable to hold the prompt */
	char *cmd = NULL, *cmd_cpy = NULL, *token; /* buffer to store ccommand*/
	size_t size_buf = 0; /* size of the buffer */
	ssize_t ret_val_getline; /* return value of getline */
	const char *delim = " \n"; /* delimiter for parsing */
	int num_tokens = 0, i; /* number of tokens */

	(void)argc;
	/* create an infinite loop to return to shell after executing */
	while (1)
	{
		printf("%s ", prompt); /* print a prompt */
		/* read and grab user input from stdin */
		ret_val_getline = getline(&cmd, &size_buf, stdin);
		/* check if EOF is reached or getline failed */
		if (ret_val_getline == -1)
		{
			printf("Exited shell...\n");
			return (-1);
		}


		/* allocate memory dynamically for the copy of lineptr */
		cmd_cpy = malloc(sizeof(char) * ret_val_getline);
		if (cmd_cpy == NULL)
		{
			perror("sh: memory allocation error");
			return (-1);
		}

		strcpy(cmd_cpy, cmd); /* make a copy of the strings */

		/* get tokens and arg count */
		token = strtok(cmd, delim); /* get the first token */
		/* loop to get other tokens and count the number of tokens */
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		/* allocate memory for the tokens from strtok */
		argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(cmd_cpy, delim); /* get first token */

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token); /* store token in array */

			token = strtok(NULL, delim);
		}
		argv[i] = NULL; /* add the NULL terminating character to arr*/

		/* execute the command */
		execute_cmd(argv);
	}


	/* free all memory */
	free(cmd);
	free(cmd_cpy);

	return (0);
}


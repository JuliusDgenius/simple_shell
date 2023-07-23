#include "main.h"

/**
 * get_path - gets the path to the command executable
 * @cmd: the command whose path to get
 *
 * Return: Returns the path to command
 */
char *get_path(char *cmd)
{
	char *path, *path_cpy, *path_token, *file_path; /* declare variables */
	int cmd_len, dir_len;
	struct stat buffer;

	/* get the value of the PATH environ variable and store in path */
	path = getenv("PATH");

	if (path)
	{
		path_cpy = strdup(path); /* make a copy due to strtok side effect */
		cmd_len = strlen(cmd); /* get cmd length */

		/* getting the dtring tokens */
		path_token = strtok(path_cpy, ":");

		while (path_token != NULL)
		{
			/* get dir length */
			dir_len = strlen(path_token);
			/* set mem to store cmd and dir name */
			file_path = malloc(cmd_len + dir_len + 2);
			/* copy dir path and append cmd to it */
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");

			/** - stat returns 0 if file path exists and we free allocated memory */
			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);

				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}


		/* free mem if file_path don't match cmd */
		free(path_cpy);
		/* check if cmd is a file path that exist */
		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}
		else
		{
		return (NULL);
		}
	}
		return (NULL);
}

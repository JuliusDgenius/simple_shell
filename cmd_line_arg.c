#include "main.h"

int main(void)
{
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
	char *delim = " /n";
	ssize_t n = 0;
	int argc = 0, i = 0;
	char **argv = NULL;
	
	/*fail check on getline*/
	if (getline(&cmd, &n, stdin) == -1)
		return -1;

	cmd_cpy = strdup(cmd);

	while (cmd[i])
	{
		if (cmd[i] == '\n')
			printf("\\n --> Input character is %ld ", strlen(cmd));
		else
			printf("%c", cmd[i]);
		i++;
	}

	return 0;
}

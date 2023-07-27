#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "main.h"

/**
 * read_input_cmd - A function to read commands
 *
 * Return: Returns a pointer to the strings read from stdin
 */
char *read_input_cmd(void)
{
	char buf[1024];
	char *ptr = NULL;
	char ptrlen = 0;

	/* REPL loop */
	while (fgets(buf, 1024, stdin))
	{
		int buflen = strlen(buf);

		if (!ptr)
		{
			ptr = malloc(buflen + 1);
		}
		else
		{
			char *ptr2 = realloc(ptr, ptrlen + buflen + 1);

			if (ptr2)
			{
				ptr = ptr2;
			}
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}
		if (!ptr)
		{
			fprintf(stderr, "error: failed to alloc buffer: %s\n",
				strerror(errno));
			return (NULL);
		}

		strcpy(ptr + ptrlen, buf);

		/* Handle really long input */
		if (buf[buflen - 1] == '\n')
		{
			if (buflen == 1 || buf[buflen - 2] != '\\')
			{
				return (ptr);
			}

			ptr[ptrlen + buflen - 2] = '\0';
			buflen -= 2;
			prompt2();
		}
		ptrlen += buflen;
	}
	return (ptr);
}

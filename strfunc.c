#include "shell.h"

/**
 * _puts - writes strings to STDOUT
 * @str: the string to write to stdout
 *
 * Return: returns number of chars written to stdout or -1 on failure
 */
ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * _strdup - makes a duplicate string
 * @strtodup: the string to be duplicated
 * Return: returns a pointer to the new duplicated string
 */
char *_strdup(char *strtodup)
{
	char *copy;

	int len, i;

	if (strtodup == 0)
		return (NULL);

	for (len = 0; strtodup[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
	copy[i] = strtodup[i];

	return (copy);
}

/**
 * _strcmpr - custom string compare funtion for 2 strings
 * @strcmp1: the first string to be compared in length
 * @strcmp2: second string to be compared
 * Return: On success 0, 1 on failure
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
}

/**
 * _strcat - function to concat two strings
 * @strc1: the first string
 * @strc2: the second string
 * Return: returns a pointer to the new string
 */
char *_strcat(char *strc1, char *strc2)
{
	char *newstring;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
	if (strc1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2;
	newstring = malloc(newlen * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		newstring[i] = strc1[i];
	newstring[i] = '/';
	for (j = 0; j < len2; j++)
		newstring[i + 1 + j] = strc2[j];
	newstring[len1 + len2 + 1] = '\0';
	return (newstring);
}

/**
 * _strlen - calaculates the length of a string
 * @str: holds string passed
 * Return: returns the length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

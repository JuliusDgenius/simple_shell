#include <stdio.h>
#include "shell.h"

/**
 * print_prompt1 - Handle prompt at start of shell '$'
 *
 * Return: returns void
 */
void print_prompt1(void)
{
	fprintf(stderr, "$ ");
}

/**
 * print_prompt2 - prints the shell prompt '>' for long entry
 *
 * Return: return 0 on succes.
 */
void print_prompt2(void)
{
	fprintf(stderr, "> ");
}

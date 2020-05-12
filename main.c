/*
 * ===================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Function that handles all events of monty
 *
 *        Version:  1.0
 *        Created:  05/12/2020 04:56:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SAMUEL GOMEZ Y ANDRES HUGUET
 *   Organization:  Holberton
 *
 * ===================================================
 */
#include "monty.h"
/**
 * main - Entry Point
 * @argc: Arguments count
 * @argv: Array with actual arguments
 * Description: Entry Point
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	int line_number = 0;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fptr = fopen(argv[1],"r");
	while ((linelen = getline(&line, &linecap, fptr)) > 0)
	{
		fwrite(line, linelen, 1, stdout);
		line_number++;
	}

	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}			/* ----------  end of function main  ---------- */

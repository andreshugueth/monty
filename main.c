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
 *         Author:  SAMUEL GOMEZ & ANDRES HUGUET
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
	char **col_strings = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 1;
	stack_t *stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fptr = fopen(argv[1],"r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fptr)) != -1)
	{
		col_strings = _tokenizer(line);
		if (col_strings)
		{
			get_op_func_wrapper(line_number, col_strings, &stack);
		}
		line_number++;
		free(col_strings);
	}
	fclose(fptr);
	free_list(stack);
	return (EXIT_SUCCESS);
}			/* ----------  end of function main  ---------- */

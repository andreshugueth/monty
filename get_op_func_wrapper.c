/*
 * ===================================================
 *
 *       Filename:  get_op_func_wraper.c
 *
 *    Description:  Function that verifies if the command and the arguments are valid,
 *    if so it returns the function that is called.
 *
 *        Version:  1.0
 *        Created:  05/13/2020 01:40:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SAMUEL GOMEZ J & ANDRES HUGUET
 *   Organization:  Holberton
 *
 * ===================================================
 */
#include "monty.h"
/**
 * get_op_func_wrapper - Function that verifies if the command and the
 * arguments are valid, if so it returns the integer of push converted.
 * @stack:
 * @line_number:
 * @col_strings:
 *
 * Return: Integer of col_strings converted if success and EXIT_FAILURE
 * if the number doesn't exist and returns 1 if is another function
 */
int get_op_func_wrapper(unsigned int line_number, char **col_strings, stack_t **stack)
{
	if (strcmp(col_strings[0], "push") == 0)
	{
		if (col_strings[1] != NULL)
			glob_vars.glob_int = atoi(col_strings[1]);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (EXIT_FAILURE);
		}
		get_op_func(col_strings[0], line_number)(stack, line_number);
	}
	else
		get_op_func(col_strings[0], line_number)(stack, line_number);
	return (0);
}

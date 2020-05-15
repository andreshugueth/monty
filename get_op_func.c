/*
 * ===================================================
 *
 *       Filename:  get_op_func.c
 *
 *    Description:  Select the correct operation function asked by the user
 *
 *        Version:  1.0
 *        Created:  05/12/2020 07:13:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SAMUEL GOMEZ J & ANDRES HUGUETH
 *   Organization:  Holberton
 *
 * ===================================================
 */
#include "monty.h"
/**
 * get_op_func - Select the correct operation function asked by the user
 * @code: Operation code
 * @ln: Number of read line
 * Return: Function pointer to operator given
 *
 */
void (*get_op_func(char *code, unsigned int ln))(stack_t **stack, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", own_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, free_all}
	};

	unsigned int x = 0;

	while (ops[x].opcode != NULL)
	{
		if (strcmp(ops[x].opcode, code) == 0)
			return (ops[x].f);
		x++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, code);
	return (ops[x].f);
}

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
 *         Author:  SAMUEL GOMEZ J & ANDRES HUGUET
 *   Organization:  Holberton
 *
 * ===================================================
 */
#include "monty.h"
/**
 * get_op_func - Select the correct operation function asked by the user
 * @opcode: Operation code
 *
 * Return: Function pointer to operator given
 *
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	unsigned int x = 0;
	while (x < (sizeof(ops) / sizeof(ops[0])))
	{
		if (strcmp(ops[x].opcode, opcode) == 0)
			return (ops[x].f);
		x++;
	}
	return (0);
}

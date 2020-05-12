/*
 * ===================================================
 *
 *       Filename:  get_op_func.c
 *
 *    Description:
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
int (*get_op_func(char *opcode))(stack_t, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};
	int x = 0;
	while (x < (sizeof(ops) / sizeof(ops[0])))
	{
		if (*(ops[x].opcode) == *opcode)
		{
			return (ops[x].f);
		}
		x++;
	}
	return (0);
}
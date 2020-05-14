/*
 * ===================================================
 *
 *       Filename:  op_functions_3.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/14/2020 06:17:36 PM
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
 * mul - mul the top two elements of the stack
 * @stack: Top of the Linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_num)
{
	int aux;
	stack_t *tmp;

	tmp = (*stack);

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;
	aux *= (*stack)->next->n;
	(*stack)->next->n = aux;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * mod - mod the top two elements of the stack
 * @stack: Top of the Linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_num)
{
	int aux, rest;
	stack_t *tmp;

	tmp = (*stack);

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}


	aux = (*stack)->n;
	rest = (*stack)->next->n;
	aux = aux % rest;
	(*stack)->next->n = aux;
	*stack = (*stack)->next;
	free(tmp);
}


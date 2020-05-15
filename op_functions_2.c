/*
 * ===================================================
 *
 *       Filename:  op_functions_2.c
 *
 *    Description:  Operations to be executed
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
 * add - adds the top two elements of the stack
 * @stack: Top of the Linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_num)
{
	int aux;
	stack_t *tmp;

	tmp = (*stack);

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;
	aux += (*stack)->next->n;
	(*stack)->next->n = aux;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * nop - doesn’t do anything
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
/**
 * free_all - Frees stack in case of invalid command
 * @stack: Top of the linked list
 * @line_num: Number of read line
 */
void free_all(stack_t **stack, unsigned int line_num)
{
	free_list(*stack);
	(void) line_num;
	exit(EXIT_FAILURE);
}

/**
 * sub - subs the top two elements of the stack
 * @stack: Top of the Linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_num)
{
	int aux;
	stack_t *tmp;

	tmp = (*stack);

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->next->n;
	aux -= (*stack)->n;
	(*stack)->next->n = aux;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * own_div - divs the top two elements of the stack
 * @stack: Top of the Linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void own_div(stack_t **stack, unsigned int line_num)
{
	int aux;
	stack_t *tmp;

	tmp = (*stack);

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->next->n;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	aux /= (*stack)->n;
	(*stack)->next->n = aux;
	*stack = (*stack)->next;
	free(tmp);
}

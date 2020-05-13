/*
 * ===================================================
 *
 *       Filename:  op_functions.c
 *
 *    Description:  Collection of functions that are called
 *
 *        Version:  1.0
 *        Created:  05/12/2020 07:13:02 PM
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
 *
 *
 *
 *
 *
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node, *last;
	if (!stack)
	{
		fprintf(stderr, "L%d: Need to use line_num\n", line_num);
		exit(EXIT_FAILURE);
	}
	last = *stack;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = glob_vars.glob_int;
	new_node->next = NULL;
	if (!*stack)
	{
		new_node->prev = NULL;
		*stack = new_node;
		return;
	}
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}
void pall(stack_t **stack, unsigned int line_num)
{
	const dlistint_t *tmp;
	tmp = stack;
	if (!stack)
	{
		fprintf(stderr, "L%d: Need to use line_num\n", line_num);
		exit(EXIT_FAILURE);
	}
	while (tmp != NULL)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
}
void pint(stack_t **stack, unsigned int line_num)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
void pop(stack_t **stack, unsigned int line_num)
{
	printf("Función pop\n");
}
void swap(__attribute__((unused))stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	printf("Función swap\n");
}
void add(__attribute__((unused))stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	printf("Función add\n");
}
void nop(__attribute__((unused))stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	printf("Función nop\n");
}

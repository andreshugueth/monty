/*
 * ===================================================
 *
 *       Filename:  op_functions.c
 *
 *    Description:
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
	stack_t *new, *prev;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		printf("Error malloc new/push");

	prev = NULL;
	while (*stack)
	{
		prev = *stack;
		stack = &(*stack)->next;
	}
	new->n = glob_vars.glob_int;
	new->prev = prev;
	new->next = NULL;
}
void pall(stack_t **stack,unsigned int line_num)
{
	int i;

	i = 0;
	while (*stack)
	{
		stack = &(*stack)->next;
		i++;
	}
	while (i != 0)
	{
		printf("%d\n", stack->n);
		stack = stack->prev;
		i--;
	}

}
void pint(__attribute__((unused))stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	printf("Función pint\n");
}
void pop(__attribute__((unused))stack_t **stack, __attribute__((unused)) unsigned int line_num)
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

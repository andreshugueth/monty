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
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "L%d: Need to use line_num\n", line_num);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = glob_vars.glob_int;
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!stack)
	{
		fprintf(stderr, "L%d: Need to use line_num\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
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
	stack_t *tmp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);
	if ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		glob_vars.glob_int = (*stack)->n;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
void swap(stack_t **stack, unsigned int line_num)
{
	int sw1, sw2, counter;
	stack_t *tmp, *cnt;

	sw1 = sw2 = counter = 0;
	
	cnt = (*stack);
	while (cnt)
	{
		cnt = cnt->next;
		counter++;
	}
	if (counter < 2)
	{
		fprintf(stderr,"L%d: can't swap, stack too short", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);
	sw1 = tmp->n;
	sw2 = tmp->next->n;
	(*stack)->n = sw2;
	(*stack)->next->n = sw1;
}
void add(stack_t **stack, unsigned int line_num)
{
	int result, counter, n1, n2;
	stack_t *tmp, *cnt;

	n1 = n2 = result = counter = 0;

	cnt = (*stack);
	while (cnt)
	{
		cnt = cnt->next;
		counter++;
	}
	if (counter < 2)
	{
		fprintf(stderr,"L%d: can't add, stack too short", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);
	n1 = tmp->n;
	n2 = tmp->next->n;
	result = n1 + n2;
	(*stack)->next->n = result;
	*stack = (*stack)->next;
	free(tmp);
}
void nop(__attribute__((unused))stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	return;;
}

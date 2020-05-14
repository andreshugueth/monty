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
 * push - pushes an argument to the beginning of a lk list
 * @stack: top of the lk linst
 * @line_num: number of read line
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "L%d: Need to use line_num\n", line_num);
		free_list(*stack);
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
/**
 * pall - prints all the values on the stack, starting on the top
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
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
/**
 * pint - prints the value at the top of the stack
 * @stack: Top of the linked list
 * @line_num: number of read line
 *
 * Return: Nothing
 */
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
/**
 * pop - removes the top element of the stack
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_list(*stack);
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
/**
 * swap - swaps the top two elements of the stack
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int aux;

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;
}

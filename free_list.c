/*
 * ===================================================
 *
 *       Filename:  free_list.c
 *
 *    Description:  Free a linked list
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
 * free_list - free a double lk list
 * @stack: head of the lk list
 *
 * Return: Nothing
 */
void free_list(stack_t *stack)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

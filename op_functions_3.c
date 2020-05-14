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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}


	aux = (*stack)->n;
	if (aux == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	rest = (*stack)->next->n;
	aux = rest % aux;
	(*stack)->next->n = aux;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * pchar - prints the char at the top of the stack
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	int number;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->n;
	if (number < 0 || number > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	putchar(number);
	putchar('\n');
}
/**
 * pstr - 
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	(void) line_num;
	int number;
	stack_t *tmp;

	if (!*stack || !stack)
	{
		putchar('\n');
		return;
	}
	tmp = (*stack);
	while (tmp)
	{
		number = tmp->n;
		if (number == 0 || number < 0 || number > 127)
			break;
		putchar(number);
		tmp = tmp->next;
	}
	putchar('\n');
}

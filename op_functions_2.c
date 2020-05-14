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
 * add - adds the top two elements of the stack
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->next->n;
	aux -= (*stack)->n;
	(*stack)->next->n = aux;
	*stack = (*stack)->next;
	free(tmp);
}

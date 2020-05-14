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
		fprintf(stderr, "L%d: can't add, stack too short", line_num);
		free_list(*stack);
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


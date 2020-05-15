#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack)->prev = tmp;
	(*stack) = (*stack)->prev;
	tmp->prev->next = NULL;
	(*stack)->prev = NULL;
}

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

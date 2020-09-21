#include "monty.h"
/**
 * pall - print all elements of list stack.
 * @stack: pointer head stack.
 * @l_n: files line number.
 * Return: the number of nodes.
 */

void pall(stack_t **stack, unsigned int l_n)
{
	stack_t *h = *stack;
	(void)l_n;
	while (h != NULL)
	{
		printf("%i\n", h->n);
		h = h->next;
	}
}

/**
 * push - Adds nodes.
 * @stack: pointer head stack.
 * @l_n: line number in file.
 * Return: nothing.
 */

void push(stack_t **stack, unsigned int l_n)
{
	stack_t *node = NULL;
	stack_t *copy = *stack;
	(void)l_n;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_n);
		glob_v[1] = 1;
		return;
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		glob_v[1] = 1;
		return;
	}
	node->prev = NULL;
	node->n = glob_v[0];
	node->next = *stack;
	if (*stack)
		copy->prev = node;
	*stack = node;
}

#include "monty.h"

/**
 * free_malloc - free stack to memory.
 * @h: pointer to head of the stack.
 * Return: void.
 */

void free_malloc(stack_t *h)
{
	stack_t *list = h;

	if (h == NULL)
	{
		return;
	}
	while (h != NULL)
	{
		list = h;
		h = h->next;
		free(list);
	}
}
/**
 * functions_m - compares the opcodes and run the associated functions.
 * @stack: poiter to h of the stack.
 * @cmd_f: pass string to command of function.
 * @ln_n: line number in file.
 * Return: void.
 */
void functions_m(stack_t **stack, char *cmd_f, unsigned int ln_n)
{
	instruction_t inst_funcs[] = {
		{"pall", pall}, {"push", push}, {"pint", pint},
		{NULL, NULL}};
	unsigned int i = 0;
	int checker = 0;

	while (i < 11 && cmd_f != NULL)
	{
		if (cmd_f[0] == '#')
			break;
		if (strcmp(inst_funcs[i].opcode, cmd_f) == 0)
		{
			inst_funcs[i].f(stack, ln_n);
			checker = 1;
			break;
		}
		i++;
	}
	if (checker == 0 && cmd_f[0] != '#')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln_n, cmd_f);
		free(cmd_f);
		glob_v[1] = 1;
		exit(EXIT_FAILURE);
	}
}

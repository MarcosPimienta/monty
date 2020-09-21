#include "monty.h"

/**
 *l_check - check lines to arguments
 *@string: contain all
 *@l_n: count to lines inside the file
 *Return: Tokens
 */

char *l_check(char *string, unsigned int l_n)
{
	char *token = NULL, *num_t = NULL;
	long int i = 0;

	token = strtok(string, " \t\n");
	if (strcmp(token, "push") == 0)
	{
		num_t = strtok(NULL, " \t\n");
		if (num_t == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", l_n);
			free(string);
			glob_v[1] = 1;
			return (NULL);
		}
		for (i = 0; num_t[i] != '\0'; i++)
		{
			if (num_t[i] == '-')
				i++;
			if (num_t[i] < 48 || num_t[i] > 57)
			{
				fprintf(stderr, "L%u: usage: push integer\n", l_n);
				/* free(string); */
				glob_v[1] = 1;
				return (NULL);
			}
		}
		glob_v[0] = atoi(num_t);
	}
	return (token);
}

/**
 *main - execute the monty interpreter
 *@argc: count number to arguments per line
 *@argv: array to arguments
 *Return: 0 if no exist or exit failure in case to error
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char *string = NULL, *cmd_f = NULL;
	size_t size = 0;
	unsigned int l_n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&string, &size, file) != EOF)
	{
		l_n++;
		if (strlen(string) == 1 || strspn(string, " \t\n") == strlen(string))
			continue;
		cmd_f = l_check(string, l_n);
		if (cmd_f == NULL)
			break;
		functions_m(&stack, cmd_f, l_n);
	}
	free(string);
	free_malloc(stack);
	fclose(file);
	if (glob_v[1] == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

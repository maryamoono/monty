#include "monty.h"
stack_t *head = NULL;
/**
 * main - djdlesj
 * @argc: tedfe
 * @argv: desfef
 * Return: ddkdlfk
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_stack(&head);
		exit(EXIT_FAILURE);
	}
	execute_instructions(file);
	fclose(file);
	free_stack(&head);
	return (0);
}

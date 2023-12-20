#include "monty.h"
void execute_instructions(FILE *file);
/**
 * check_for_int - check for int
 * @in: an array
 * Return: val or -1
 */
int check_for_int(char in[127])
{
	int i = 0;

	while (in[i] != '\0')
	{
		if (in[i] == '.' || ((in[i] > 57 || in[i] < 48) && in[i] != '-'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/**
 * push - push element to the stacks
 * @line_number: kjbdkhsjd
 * @stack: stack
 * @value: the element we want to push
 * Return: its void
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_number;
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	head = *stack;
}
/**
 * pall - oilo
 * @line_number: oihngf
 * @stack: thefdsefs
 * Return: fvfbf
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 *execute_instructions - grggb
 *@file: grgrg
 *Return: fkf;dkf;df
 */
void execute_instructions(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char opcode[256];
	char value[127];
	int num;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		if (sscanf(line, "%s", opcode) == 1)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (sscanf(line, "%*s %s", value) == 1 && check_for_int(value) != 0)
				{
					num = atoi(value);
					push(&head, num, line_number);
				}
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					fclose(file);
					free_stack(&head);
					free(line);
					exit(EXIT_FAILURE);
				}
			}
			else if (check_for_comment(opcode) == 0)
				continue;
			else
			{
				_fopcodes(opcode, line_number, file, line);
			}
		}
	}
	free(line);
}
/**
 *free_stack - bgvbfr
 *@stack: drd
 *Return: bhdcfhu
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		stack_t *next = current->next;

		free(current);
		current = next;
	}
	*stack = NULL;
}

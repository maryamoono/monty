#include "monty.h"
/**
 * _fopcodes - cdfkjljlcjdfj
 *@opcode: dfvfdlfl
 *@line_number: tdfdf
 *@file: fdff
 *@line: thsees
 */
void _fopcodes(char *opcode, unsigned int line_number, FILE *file, char *line)
{
	if (strcmp(opcode, "pall") == 0)
		pall(&head, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(&head, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(&head, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(&head, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(&head, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(&head, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(&head, line_number);
	else if (strcmp(opcode, "div") == 0)
		div_op(&head, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul(&head, line_number);
	else if (strcmp(opcode, "mod") == 0)
		mod(&head, line_number);
	else if (strcmp(opcode, "pchar") == 0)
		pchar(&head, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(&head, line_number);
	else if (strcmp(opcode, "rotl") == 0)
		rotl(&head, line_number);
	else if (strcmp(opcode, "rotr") == 0)
		rotr(&head, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free_stack(&head);
		free(line);
		exit(EXIT_FAILURE);
	}
}

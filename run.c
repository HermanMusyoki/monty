#include "monty.h"
/**
* execute - a function that executes the opcode
* @stack: pointer to the beginning of the stack
* @counter: parameter for the line count
* @file: pointer to monty file components
* @content: parameter for the contents of the line
* Return: nothing
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", pushFunc}, {"pall", printStack}, {"pint", printNode},
				{"pop", popFunc},
				{"swap", swapFunc},
				{"add", addFunc},
				{"nop", f_nop},
				{"sub", subFunc},
				{"div", divFunc},
				{"mul", mulFunc},
				{"mod", moduloFunc},
				{"pchar", printChar},
				{"pstr", printString},
				{"rotl", top_rot},
				{"rotr", bottom_rot},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

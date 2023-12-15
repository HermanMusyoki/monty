#include "monty.h"
/**
  *f_nop- a null function
  *@head: double pointer to the beginning of the stack
  *@counter: parameter for the line count
  *Return: nothing
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * printNode - a function that prints the fisrt node of the stack
 * @head: double pointer to the beginning of the stack
 * @counter: parameter for line count
 * Return: nothing
*/
void printNode(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * printStack - a function that prints all contents of the stack
 * @head: double pointer to the beginning of the stack
 * @counter: parameter for line count
 * Return: nothing
*/
void printStack(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

#include "monty.h"
/**
* free_stack - a function that frees a doubly linked list
* @head: pointer to the beginning of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

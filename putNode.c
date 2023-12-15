#include "monty.h"
/**
 * addNode - a function that adds node to start of the stack
 * @head: double pointer to the beginning of the stack
 * @n: parameter for new value
 * Return: nothing
*/
void addNode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

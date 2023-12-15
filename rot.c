#include "monty.h"
/**
  *top_rot- a function that rotates the stack to the top
  *@head: double pointer to the beginning of the stack
  *@counter: parameter for the line count
  *Return: nothing
 */
void top_rot(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
  *bottom_rot- a function that rotates the stack to the bottom
  *@head: double pointer to the beginning opf the stack
  *@counter: parameter for the line count
  *Return: nothing
 */
void bottom_rot(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

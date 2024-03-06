#include "sort.h"

/**
 * swap_forward - swap two nodes
 *
 * @head: beginning of the list
 * @tail: the end of the list
 * @shaker: the pointer to the to be swapped node
 */
void swap_forward(listint_t **head, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*head = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}
/**
 * swap_backward - swap two nodes
 *
 * @head: beginning of the list
 * @tail: the end of the list
 * @shaker: the pointer to the to be swapped node
 */
void swap_backward(listint_t **head, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*head = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}
/**
 * cocktail_sort_list - Linked list implementation of cocktail sort
 *
 * @list: linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int count = 1;
	listint_t *ptr, *tail;

	for (tail = *list; tail != NULL; tail = tail->next)
		;
	while (count == 1)
	{
		count = 0;

		for (ptr = *list; ptr != tail; ptr = ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				swap_forward(list, &tail, &ptr);
				print_list(*list);
				count = 1;
			}
		}
		if (count == 0)
			break;
		count = 0;

		for (ptr = ptr->prev; ptr != *list; ptr = ptr->prev)
		{
			if (ptr->n < ptr->next->n)
			{
				swap_backward(list, &tail, &ptr);
				print_list(*list);
				count = 1;
			}
		}
	}
}

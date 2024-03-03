#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - linked list implementation of insertion sort
 *
 * @list: doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted, *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	unsorted = (*list)->next;
	while (unsorted)
	{
		sorted = unsorted->prev;
		while (sorted != NULL && unsorted->n < sorted->n)
		{
			swap(list, &sorted, unsorted);
			print_list((const listint_t *)*list);
		}
		unsorted = unsorted->next;
	}
}
/**
 * swap - swaps two nodes
 * @head: the head of the list
 * @n1: the first node
 * @n2: the second node
 */
void swap(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

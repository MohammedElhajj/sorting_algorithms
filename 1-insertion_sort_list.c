#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: The doubly linked list to be sorted
 *
 * Return: Nothing (void).
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *last, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current->next;
		last = current->prev;
		while (last != NULL && current->n < last->n)
		{
			if (last->prev)
				last->prev->next = current;
			last->next = current->next;
			current->next = last;
			current->prev = last->prev;
			last->prev = current;
			if (last->next)
				last->next->prev = last;
			if (!current->prev)
				(*list) = current;
			print_list(*list);
			last = current->prev;
		}
		current = tmp;
	}
}

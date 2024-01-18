#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		key = current;
		prev = current->prev;

		while (prev != NULL && key->n < prev->n)
		{
			if (key->next != NULL)
				key->next->prev = prev;
			prev->next = key->next;
			key->prev = prev->prev;
			prev->prev = key;
			key->next = prev;

			if (key->prev != NULL)
				key->prev->next = key;
			else
				*list = key;

			prev = key->prev;
			print_list(*list);
		}

		current = current->next;
	}
}

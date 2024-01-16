#include "sort.h"

/**
 * first_to_swap - swap with the first node of the list
 * @list: the list of nodes
 * @temp: pointer on the list
 *
 * Return: void
 */

void first_to_swap(listint_t **list, listint_t *temp)
{
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	temp->prev->prev = temp;
	temp->next = temp->prev;
	temp->prev = NULL;
	*list = temp;
	print_list(*list);
}

/**
 * middle_swap - swap nodes in the middle of the list
 * @list: the list of nodes
 * @temp: pointer on the list
 * @temp3: pointer on the list
 *
 * Return: void
 */

void middle_swap(listint_t **list, listint_t *temp, listint_t *temp3)
{
	temp3->prev->next = temp;
	temp->next->prev = temp3;
	temp->prev = temp3->prev;
	temp3->next = temp->next;
	temp3->prev = temp;
	temp->next = temp3;

	print_list(*list);
}

/**
 * end_to_swapzz - swap with the last node of the list
 * @list: the list of nodes
 * @temp: pointer on the list
 * @temp3: pointer on the list
 *
 * Return: void
 */

void end_to_swapzz(listint_t **list, listint_t *temp, listint_t *temp3)
{
	temp3->prev->next = temp3->next;
	temp3->next = NULL;
	temp->next = temp->prev;
	temp->prev = temp3->prev;
	temp3->prev = temp;

	print_list(*list);
}

/**
 * two_nodes_only - swaps only two nodes
 * @list: the list of nodes
 * @temp: pointer on the list
 *
 * Return: void
 */

void two_nodes_only(listint_t **list, listint_t *temp)
{
	temp->prev->next = NULL;
	temp->prev->prev = temp;
	temp->next = temp->prev;
	temp->prev = NULL;
	*list = temp;

	print_list(*list);
}

/**
 * insertion_sort_list - function that sorts the nodes
 * @list: the list of nodes
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2, *temp3;

	if (!list)
		return;

	temp2 = (*list)->next;
	while (temp2 != NULL)
	{
		temp = temp2;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				temp3 = temp->prev;
				if (temp->next == NULL && temp->prev->prev == NULL)
				{
					two_nodes_only(list, temp);
				}
				else if (temp->prev->prev == NULL)
				{
					first_to_swap(list, temp);
				}
				else if (temp->prev->prev != NULL && temp->next != NULL)
				{
					middle_swap(list, temp, temp3);
				}
				else
				{
					end_to_swapzz(list, temp, temp3);
				}
			}
			else
				temp = temp->prev;
		}
		temp2 = temp2->next;
	}
}

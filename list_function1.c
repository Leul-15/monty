#include "monty.h"

/**
 * dlistint_len - returns the number of nodes in a doubly linked list
 * @head: pointer to the list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *head)
{
	size_t num = 0;

	if (!head)
		return (0);

	while (head)
	{
		num++;
		head = head->next;
	}

	return (num);
}

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @num: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int num)
{
	dlistint_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = num;

	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}

/**
 * print_dlistint - prints a doubly linked list
 * @head: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *head)
{
	size_t num = 0;

	if (!head)
		return (0);

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		num++;
	}

	return (num);
}

/**
 * delete_dnodeint_at_index - deltes a node in a doubly linked list
 * at a given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *new = *head;
	unsigned int i = 0;

	if (!index)
	{
		(*head) = new->next;
		if (new->next)
			new->next->prev = NULL;
		new->next = NULL;
		free(new);
		return (1);
	}

	while (i < index)
	{
		new = new->next;
		i++;
		if (!new)
			return (0);
	}

	new->prev->next = new->next;
	if (new->next)
		new->next->prev = new->prev;
	free(new);

	return (1);
}

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list
 * @head: pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (!head)
		return (NULL);

	while (head && count < index)
	{
		head = head->next;
		count++;
	}

	return (head ? head : NULL);
}

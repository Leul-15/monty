#include "monty.h"
#include "lists.h"

/**
 * pint_handler - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void pint_handler(stack_t **stack, unsigned int line_count)
{
	stack_t *head = *stack;

	if (!head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

/**
 * pop_handler - handles the pop instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void pop_handler(stack_t **stack, unsigned int line_count)
{
	stack_t *new_node = *stack;

	if (!new_node)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * swap_handler - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void swap_handler(stack_t **stack, unsigned int line_count)
{
	stack_t *new_node = *stack, *node = NULL;
	int count;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	new_node = get_dnodeint_at_index(*stack, 0);
	count = new_node->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, count);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_handler - handles the nop instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void nop_handler(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
}

/**
 * add_handler - handles the add instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void add_handler(stack_t **stack, unsigned int line_count)
{
	int sum = 0;
	stack_t *new = NULL;
	stack_t *new_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sum = new_0->n + new_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new = add_dnodeint(stack, sum);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

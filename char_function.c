#include "monty.h"
#include "lists.h"

/**
 * pchar_handler - handles the pchar instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void pchar_handler(stack_t **stack, unsigned int line_count)
{
	stack_t *new_node = *stack;

	if (!new_node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (new_node->n < 0 || new_node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(new_node->n);
	putchar('\n');
}

/**
 * pstr_handler - handles the pstr instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void pstr_handler(stack_t **stack, unsigned int line_count)
{
	stack_t *new_node = *stack;

	(void)line_count;

	if (!new_node)
	{
		putchar('\n');
		return;
	}

	while (new_node && new_node->n != 0 && new_node->n >= 0 && new_node->n <= 127)
	{
		putchar(new_node->n);
		new_node = new_node->next;
	}

	putchar('\n');
}

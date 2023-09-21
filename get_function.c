#include "monty.h"
#include "lists.h"

/**
 * get_func - selects the right function
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t function_arr[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"nop", nop_handler},
		{"add", add_handler},
		{"sub", sub_handler},
		{"mul", mul_handler},
		{"div", div_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}};

	int num = 17, i;

	for (i = 0; i < num; i++)
	{
		if (strcmp(function_arr[i].opcode, parsed[0]) == 0)
		{
			return (function_arr[i].f);
		}
	}
	return (NULL);
}

/**
 * push_handler - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void push_handler(stack_t **stack, unsigned int line_count)
{
	stack_t *new_node;
	int num = 0, i;

	if (data.word[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data.word[1][i]; i++)
	{
		if (isalpha(data.word[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_count);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.word[1]);

	if (data.qflag == 0)
		new_node = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new_node = add_dnodeint_end(stack, num);
	if (!new_node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_handler - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void pall_handler(stack_t **stack, unsigned int line_count)
{
	(void)line_count;
	if (*stack)
		print_dlistint(*stack);
}

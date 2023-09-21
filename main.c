#include "monty.h"
#include "lists.h"

data_t data = DATA_INIT;

/**
 * monty_function - helper function for main function
 * @args: pointer to struct of arguments from main
 *
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function
 * that will find the corresponding executing function
 */
void monty_function(args_t *args)
{
	size_t len = 0;
	int get = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (args->argc != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.fpt = fopen(args->argv, "r");
	if (!data.fpt)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->argv);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->line_count++;
		get = getline(&(data.line), &len, data.fpt);
		if (get < 0)
			break;
		data.word = strtow(data.line);
		if (data.word[0] == NULL || data.word[0][0] == '#')
		{
			free_all(0);
			continue;
		}
		code_func = get_func(data.word);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->line_count, data.word[0]);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->line_count);
		free_all(0);
	}
	free_all(1);
}

/**
 * main - entry point for monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	args_t args;

	args.argv = argv[1];
	args.argc = argc;
	args.line_count = 0;

	monty_function(&args);

	return (EXIT_SUCCESS);
}

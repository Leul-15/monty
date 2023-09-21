#include "monty.h"
#include "lists.h"

/**
 * free_all - custom memory handling function
 * @all: flag to indicate what to free
 */
void free_all(int all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_everything(data.word);
		data.word = NULL;
	}

	if (all)
	{
		if (data.stack)
		{
			free_dlistint(data.stack);
			data.stack = NULL;
		}
		if (data.fpt)
		{
			fclose(data.fpt);
			data.fpt = NULL;
		}
	}
}

/*
 * ===================================================
 *
 *       Filename:  parsing.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/12/2020 07:54:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SAMUEL GOMEZ J & ANDRES HUGUET
 *   Organization:  Holberton
 *
 * ===================================================
 */
#include "monty.h"
char **_tokenizer(char *line)
{
	int buffer_size = 1024;
	int i;
	char **tokens = NULL;
	char *token = NULL;

	tokens = malloc(sizeof(char *) * buffer_size);
	if (!tokens)
		exit(1);

	token = strtok(line, TOKEN_DELIMITERS);
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[i] = NULL;
	return (tokens);
}

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
 *         Author:  SAMUEL GOMEZ J & ANDRES HUGUETH
 *   Organization:  Holberton
 *
 * ===================================================
 */
#include "monty.h"
/**
 * _tokenizer - Parses the line into tokens
 * @line: string read by getline function
 *
 * Return: Array of tokens on success, NULL on failure
 *
 */
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
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
	{
		free(tokens);
		return (NULL);
	}
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * is_number - checks if the push command has a number
 * @col_strings: character to be checked
 *
 * Return: 0 on failure, 1 on success
 */
int is_number(char *col_strings)
{
	if (!col_strings)
		return (0);

	if (*col_strings == 45)
		col_strings++;
	while (*col_strings != '\0')
	{
		if (!isdigit(*col_strings))
			return (0);
		col_strings++;
	}
	return (1);
}

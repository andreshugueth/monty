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
 *         Author:  SAMUEL GOMEZ J (samgj18), samgomjim.18@gmail.com
 *   Organization:  Holberton
 *
 * ===================================================
 */
#include "monty.h"
/**
 *_tokenizer - buffer_line read
 *@buffer_line: line to be tokeanized
 *Return: the tokenized line in a 2d array
 */
char **_tokenizer(char *buffer_line)
{
	int i;
	char *piece, **pieces;

	pieces = malloc(sizeof(char *) * 100);/*100 char pointer*/
	if (pieces ==  NULL)
		return (pieces);
	piece = strtok(buffer_line, TOKEN_DELIMITERS);
	i = 0;
	while (piece != NULL)
	{
		if (_is_empty(buffer_line) == 0)
		{
			pieces[i] = ft_strdup(piece);/*space for the string*/
		}
		i++;
		piece = strtok(NULL, TOKEN_DELIMITERS);
	}
	pieces[i] = NULL;
	return (pieces);/* malloc*/
}

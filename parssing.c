#include "shell.h"

/**
 * p_cmd - Parse Line Of Input
 * @input: User Input To Parse
 * Return: Array Of Char (Parsed): Simple Shell
 */
char **p_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = strtok(input, " ");
	i = 0;
	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			perror("hsh");

			for (int j = 0; j < i; j++)
				free(tokens[j]);

			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}

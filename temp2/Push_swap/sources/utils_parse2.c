#include "../includes/push_swap.h"

static int	_nbr_words(char *str)
{
	int	res;
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			res++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (res);
}

static char	*get_word(char *word_pos)
{
	char	*word;
	int		word_len;
	int		i;

	if (word_pos == NULL)
		return (NULL);
	word_len = 0;
	while (word_pos[word_len] && word_pos[word_len] != ' ')
		word_len++;
	word = malloc(word_len + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = word_pos[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_words(char **res, int res_i)
{
	int	 i;

	if (*res == NULL)
		return (NULL);
	i = 0;
	while (i < res_i)
		free(res[i++]);
	free(res);
	return (NULL);
}

static char	**split_words(char *str, char **res)
{
	int		i;
	int		res_i;

	i = 0;
	res_i = 1;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			res[res_i] = get_word(str + i);
			if (res[res_i] == NULL)
				return (free_words(res, res_i));
			res_i++;
		}
		while (str[i] && str[i] != ' ')
			i++;
	}
	res[res_i] = 0;
	return (res);
}

//creasy split
char	**_split_(char *str)
{
	char	**res;
	int		nbr_words;

	if (str == NULL)
		return (NULL);
	nbr_words = _nbr_words(str);
	if (nbr_words == -1)
		return (NULL);
	res = malloc(sizeof(char *) * (nbr_words + 1 + 1));
	if (res == NULL)
		return (NULL);
	res[0] = NULL;
	res = split_words(str, res);
	return (res);
}

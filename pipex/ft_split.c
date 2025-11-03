/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:20:33 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/01 19:49:25 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(const char *s, char c)
{
	int		in_word;
	int		w_count;

	in_word = 0;
	w_count = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			w_count++;
			in_word = 1;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (w_count);
}

static char	*get_word(const char *start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_style(char **result, int last_index)
{
	while (last_index--)
	{
		free(result[last_index]);
	}
	free(result);
}

static char	**splt(char const *s, char c, char **splt)
{
	const char		*start;
	int				len;
	int				j;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		start = s;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			splt[j] = get_word(start, len);
			if (splt[j] == NULL)
				return (free_style(splt, j), NULL);
			j++;
		}
	}
	return (splt);
}

char	**ft_split(char const *s, char const c)
{
	char			**result;
	int				w_count;

	if (s == NULL)
		return (NULL);
	w_count = word_count(s, c);
	result = malloc((w_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = splt(s, c, result);
	if (!result)
		return (NULL);
	result[w_count] = NULL;
	return (result);
}

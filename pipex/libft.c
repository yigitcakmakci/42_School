/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:25:09 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/01 18:47:05 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j]
			&& i + j < len && big[i + j] == little[j])
		{
			j++;
		}
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	str_len;

	str_len = 0;
	while (s[str_len])
	{
		str_len++;
	}
	return (str_len);
}

static char	*join(char const *s1, char const *s2, char *join)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	return (join);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*cpy;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	cpy = malloc(((s1_len + s2_len) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	join(s1, s2, cpy);
	cpy[s1_len + s2_len] = '\0';
	return (cpy);
}

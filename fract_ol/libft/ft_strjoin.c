/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:27:00 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/07/09 15:29:56 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

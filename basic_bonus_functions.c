/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_bonus_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:47:21 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/02 20:47:29 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	char	*res;

	if (s1 == NULL)
		s1 = "";
	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = (char *) malloc(size_s1 + size_s2 + 1 * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i != size_s1 + size_s2)
	{
		if (i < size_s1)
			res[i] = s1[i];
		else
			res[i] = s2[i - size_s1];
		i++;
	}
	res[i] = '\0';
	return (res);
}

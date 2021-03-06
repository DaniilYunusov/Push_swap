/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_split_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:41:30 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 01:42:06 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_num_of_prt(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

void	ft_memory_clean(char **res, int i)
{
	while (--i != 0)
		free(res[i]);
	free(res[0]);
	free(res);
}

char	**ft_full_array(char const *s, char c, char **res, int num_of_word)
{
	int		i;
	size_t	word_len;

	i = 0;
	while (i < num_of_word)
	{
		while (*s == c)
			s++;
		word_len = ft_word_len(s, c);
		res[i] = ft_substr(s, 0, word_len);
		if (res[i] == NULL)
		{
			ft_memory_clean(res, i);
			return (NULL);
		}
		while (word_len--)
			s++;
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		num_of_word;
	char	**res;

	if (s == NULL)
		return (NULL);
	num_of_word = ft_num_of_prt(s, c);
	res = (char **) malloc((num_of_word + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[num_of_word] = NULL;
	return (ft_full_array(s, c, res, num_of_word));
}

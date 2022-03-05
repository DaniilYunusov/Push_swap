/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:35:15 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 00:36:21 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*t;
	size_t	i;

	i = 0;
	t = s;
	while (i < n)
	{
		t[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*res;
	size_t	quan;

	quan = count * size;
	res = (size_t *)malloc(quan * sizeof(char));
	if (res != NULL)
		ft_bzero(res, quan);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (s == 0)
		return (NULL);
	if (ft_strlen(s) <= start)
		return ((char *) ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	while (len-- && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

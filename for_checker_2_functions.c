/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_checker_2_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:50:11 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/02 21:38:28 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a_and_b_checker(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_a_for_rr(stack_a);
	ft_rotate_b_for_rr(stack_b);
}

void	ft_reverse_rotate_a_and_b_checker(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate_a_for_rrr(stack_a);
	ft_reverse_rotate_b_for_rrr(stack_b);
}

int	ft_viewing_command(char *string, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(string, "sa\n"))
		ft_swap_a_checker(stack_a);
	else if (!ft_strcmp(string, "sb\n"))
		ft_swap_b_checker(stack_b);
	else if (!ft_strcmp(string, "ss\n"))
		ft_swap_a_b_checker(stack_a, stack_b);
	else if (!ft_strcmp(string, "pa\n"))
		ft_push_a_checker(stack_a, stack_b);
	else if (!ft_strcmp(string, "pb\n"))
		ft_push_b_checker(stack_a, stack_b);
	else if (!ft_strcmp(string, "ra\n"))
		ft_rotate_a_for_rr(stack_a);
	else if (!ft_strcmp(string, "rb\n"))
		ft_rotate_b_for_rr(stack_b);
	else if (!ft_strcmp(string, "rr\n"))
		ft_rotate_a_and_b_checker(stack_a, stack_b);
	else if (!ft_strcmp(string, "rra\n"))
		ft_reverse_rotate_a_for_rrr(stack_a);
	else if (!ft_strcmp(string, "rrb\n"))
		ft_reverse_rotate_b_for_rrr(stack_b);
	else if (!ft_strcmp(string, "rrr\n"))
		ft_reverse_rotate_a_and_b_checker(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strdup(const char *s1)
{
	char	*copy_s;
	size_t	i;

	i = 0;
	copy_s = (char *) ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (copy_s != NULL)
	{
		while (s1[i])
		{
			copy_s[i] = s1[i];
			i++;
		}
	}
	return (copy_s);
}

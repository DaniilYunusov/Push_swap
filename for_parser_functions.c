/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parser_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:34:57 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/03 17:45:14 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_check_int(const char *string)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (string[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (string[i])
	{
		if (string[i] < 48 || string[i] > 57)
			return (3000000000);
		res = (res * 10) + (string[i] - 48);
		i++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		return (3000000000);
	return (res);
}

int	ft_check_doubles(t_list *stack, int inx_last_elem)
{
	t_list	*curr;
	int		i;

	curr = stack;
	i = 1;
	while (stack->next != NULL)
		stack = stack->next;
	while (i < inx_last_elem)
	{
		if (curr->value == stack->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int	ft_check_sort(t_list *stack_a)
{
	while (stack_a != NULL)
	{
		if (stack_a->next != NULL)
		{
			if ((stack_a->value) > (stack_a->next->value))
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

t_list	*ft_parser_string(int argv, char **argc)
{
	int		i;
	int		j;
	char	**string;
	t_list	*stack;
	long	arg;

	stack = NULL;
	j = 1;
	while (j != argv)
	{
		i = 0;
		string = ft_split(argc[j], ' ');
		while (string[i])
		{
			arg = ft_check_int(string[i]);
			if (arg == 3000000000)
				return (0);
			ft_lstadd_back(&stack, ft_lstnew(arg, 0));
			if (!ft_check_doubles(stack, i + j))
				return (0);
			i++;
		}
		j++;
	}
	return (stack);
}

void	ft_create_stack(int argv, char **argc, t_list **stack_a)
{
	if (argv > 1)
	{
		*stack_a = ft_parser_string(argv, argc);
		if (!(*stack_a))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (ft_check_sort(*stack_a))
			exit(0);
	}
	else
		exit(0);
}

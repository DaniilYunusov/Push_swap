/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_main_logic_1_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:37:09 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 00:42:42 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_of_3_elem(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if ((*stack_a)->next->value < (*stack_a)->next->next->value)
		{
			if ((*stack_a)->value < (*stack_a)->next->next->value)
				ft_swap_a(stack_a);
			else
				ft_rotate_a(stack_a);
		}
		else
		{
			ft_swap_a(stack_a);
			ft_reverse_rotate_a(stack_a);
		}
	}
	else if ((*stack_a)->value < (*stack_a)->next->next->value)
	{
		ft_swap_a(stack_a);
		ft_rotate_a(stack_a);
	}
	else
		ft_reverse_rotate_a(stack_a);
}

void	ft_iterate_list(t_list *stack_a)
{
	t_list	*temp;
	t_list	*copy;
	int		i;

	copy = stack_a;
	while (stack_a)
	{
		i = 0;
		temp = copy;
		while (temp)
		{
			if (temp->value <= stack_a->value)
				i++;
			temp = temp->next;
		}
		stack_a->index = i;
		stack_a = stack_a->next;
	}
}

void	ft_arrange_stack_elements(t_list *stack)
{
	t_list	*copy_stack;
	int		i;

	copy_stack = stack;
	i = 0;
	while (copy_stack != NULL)
	{
		copy_stack->order = i;
		copy_stack = copy_stack->next;
		i++;
	}
}

int	ft_max_index_in_stack(t_list *stack)
{
	int	max;

	max = -1;
	while (stack != NULL)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	ft_find_nearest_index(t_list *stack_a, int curr_index)
{
	int	find_index;
	int	min_distance;
	int	global_min_distance;

	global_min_distance = -1;
	while (stack_a != NULL)
	{
		min_distance = stack_a->index - curr_index;
		if (global_min_distance == -1 && min_distance > 0)
		{
			find_index = stack_a->index;
			global_min_distance = min_distance;
		}
		else
		{
			if (min_distance < global_min_distance && min_distance > 0)
			{
				global_min_distance = min_distance;
				find_index = stack_a->index;
			}
		}
		stack_a = stack_a->next;
	}
	return (find_index);
}

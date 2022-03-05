/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_main_logic_3_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:24:23 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 01:30:18 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_proc_min_num_of_operations(int min_operations, \
		t_list **stack_a, t_list **stack_b)
{
	int		all_operations;
	t_list	*copy_stack_b;

	copy_stack_b = *stack_b;
	while (copy_stack_b != NULL)
	{
		all_operations = copy_stack_b->ra + copy_stack_b->rra + \
				copy_stack_b->rb + copy_stack_b->rrb;
		if (min_operations == all_operations)
		{
			ft_distributions_of_operations(stack_a, stack_b, copy_stack_b);
			break ;
		}
		copy_stack_b = (copy_stack_b)->next;
	}
}

void	ft_optional_pa(t_list **stack_a, t_list **stack_b)
{
	int		min_operations;
	int		all_operations;
	t_list	*copy_stack_b;

	min_operations = -1;
	copy_stack_b = *stack_b;
	while (copy_stack_b != NULL)
	{
		all_operations = copy_stack_b->ra + copy_stack_b->rra + \
						copy_stack_b->rb + copy_stack_b->rrb;
		if (min_operations == -1)
			min_operations = all_operations;
		else
		{
			if (min_operations > all_operations)
				min_operations = all_operations;
		}
		copy_stack_b = copy_stack_b->next;
	}
	ft_proc_min_num_of_operations(min_operations, stack_a, stack_b);
}

void	ft_leave_3_elem_in_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	median;

	median = ft_lstsize(*stack_a) / 2;
	if (ft_lstsize(*stack_a) == 2 && !ft_check_sort(*stack_a))
	{
		ft_swap_a(stack_a);
		exit(0);
	}
	while (ft_lstsize(*stack_a) != 3)
	{
		if ((*stack_a)->index <= median)
			ft_push_b(stack_a, stack_b);
		else
		{
			ft_push_b(stack_a, stack_b);
			ft_rotate_b(stack_b);
		}
	}
}

void	ft_twist(t_list **stack_a)
{
	t_list	*copy_stack_a;
	int		median;

	copy_stack_a = *stack_a;
	median = ft_lstsize(*stack_a) / 2;
	while (copy_stack_a->index != 1)
		copy_stack_a = copy_stack_a->next;
	if (copy_stack_a->order <= median)
		copy_stack_a->ra = copy_stack_a->order;
	else
		copy_stack_a->rra = ft_lstsize(*stack_a) - copy_stack_a->order;
	while (copy_stack_a->ra)
	{
		ft_rotate_a(stack_a);
		copy_stack_a->ra--;
	}
	while (copy_stack_a->rra)
	{
		ft_reverse_rotate_a(stack_a);
		copy_stack_a->rra--;
	}
}

void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b)
{
	ft_iterate_list(*stack_a);
	ft_leave_3_elem_in_stack_a(stack_a, stack_b);
	if (!ft_check_sort(*stack_a))
		ft_sort_stack_of_3_elem(stack_a);
	while (ft_lstsize(*stack_b) != 0)
	{
		ft_arrange_stack_elements(*stack_b);
		ft_arrange_stack_elements(*stack_a);
		ft_zeroing_num_of_operations(*stack_b);
		ft_count_num_of_operat_for_each_elem(*stack_b, *stack_a);
		ft_optional_pa(stack_a, stack_b);
	}
	ft_arrange_stack_elements(*stack_a);
	ft_zeroing_num_of_operations(*stack_a);
	ft_twist(stack_a);
}

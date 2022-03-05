/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_main_logic_2_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:46:25 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 00:50:13 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_num_of_operations_in_stack_a(t_list *stack_b, t_list *stack_a)
{
	t_list	*copy_stack_a;
	int		median;

	median = ft_lstsize(stack_a) / 2;
	copy_stack_a = stack_a;
	if (stack_b->index < ft_max_index_in_stack(stack_a))
	{
		while (ft_find_nearest_index(stack_a, stack_b->index)
			!= copy_stack_a->index)
			copy_stack_a = copy_stack_a->next;
		if (copy_stack_a->order <= median)
			stack_b->ra = copy_stack_a->order;
		else
			stack_b->rra = ft_lstsize(stack_a) - copy_stack_a->order;
	}
	else
	{
		while (copy_stack_a->index != ft_max_index_in_stack(stack_a))
			copy_stack_a = copy_stack_a->next;
		if (copy_stack_a->order <= median)
			stack_b->ra = copy_stack_a->order + 1;
		else
			stack_b->rra = ft_lstsize(stack_a) - (copy_stack_a->order + 1);
	}
}

void	ft_count_num_of_operat_for_each_elem(t_list *stack_b, t_list *stack_a)
{
	t_list	*copy_stack_b;
	int		median;

	copy_stack_b = stack_b;
	while (copy_stack_b != NULL)
	{
		median = ft_lstsize(stack_b) / 2;
		if (copy_stack_b->order <= median)
			copy_stack_b->rb = copy_stack_b->order;
		else
			copy_stack_b->rrb = ft_lstsize(stack_b) - copy_stack_b->order;
		ft_num_of_operations_in_stack_a(copy_stack_b, stack_a);
		copy_stack_b = copy_stack_b->next;
	}
}

void	ft_zeroing_num_of_operations(t_list *stack_b)
{
	while (stack_b != NULL)
	{
		stack_b->rra = 0;
		stack_b->ra = 0;
		stack_b->rb = 0;
		stack_b->rrb = 0;
		stack_b = stack_b->next;
	}
}

void	ft_rb_rrb_ra_rra_control(t_list **stack_a, \
									t_list **stack_b, t_list *copy_stack_b)
{
	while (copy_stack_b->ra)
	{
		ft_rotate_a(stack_a);
		copy_stack_b->ra--;
	}
	while (copy_stack_b->rra)
	{
		ft_reverse_rotate_a(stack_a);
		copy_stack_b->rra--;
	}
	while (copy_stack_b->rb)
	{
		ft_rotate_b(stack_b);
		copy_stack_b->rb--;
	}
	while (copy_stack_b->rrb)
	{
		ft_reverse_rotate_b(stack_b);
		copy_stack_b->rrb--;
	}
}

void	ft_distributions_of_operations(t_list **stack_a, \
										t_list **stack_b, t_list *copy_stack_b)
{
	if (copy_stack_b->rb == copy_stack_b->ra && copy_stack_b->rb != 0)
	{
		while (copy_stack_b->rb)
		{
			ft_rotate_a_and_b(stack_a, stack_b);
			copy_stack_b->rb--;
			copy_stack_b->ra--;
		}
	}
	else if (copy_stack_b->rrb == copy_stack_b->rra && copy_stack_b->rrb != 0)
	{
		while (copy_stack_b->rrb)
		{
			ft_reverse_rotate_a_and_b(stack_a, stack_b);
			copy_stack_b->rrb--;
			copy_stack_b->rra--;
		}
	}
	ft_rb_rrb_ra_rra_control(stack_a, stack_b, copy_stack_b);
	ft_push_a(stack_a, stack_b);
}

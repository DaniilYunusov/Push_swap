/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_operations_1_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:30:58 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 01:32:32 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **stack_a)
{
	t_list	*a;
	t_list	*b;

	if (ft_lstsize(*stack_a) >= 2)
	{
		a = *stack_a;
		b = a->next;
		*stack_a = b;
		a->next = b->next;
		b->next = a;
		write(1, "sa\n", 3);
	}
}

void	ft_swap_b(t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	if (ft_lstsize(*stack_b) >= 2)
	{
		a = *stack_b;
		b = a->next;
		*stack_b = b;
		a->next = b->next;
		b->next = a;
		write(1, "sb\n", 3);
	}
}

void	ft_swap_a_b(t_list **stack_a, t_list **stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_a(stack_b);
	write(1, "ss\n", 3);
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*copy_stack_b;

	copy_stack_b = *stack_b;
	if (ft_lstsize(*stack_b))
	{
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, ft_lstnew(copy_stack_b->value, \
					copy_stack_b->index));
		free(copy_stack_b);
		write(1, "pa\n", 3);
	}
}

void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*copy_stack_a;

	copy_stack_a = *stack_a;
	if (ft_lstsize(*stack_a))
	{
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, ft_lstnew(copy_stack_a->value, \
					copy_stack_a->index));
		free(copy_stack_a);
		write(1, "pb\n", 3);
	}
}

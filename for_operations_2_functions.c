/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_operations_2_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:32:44 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 01:33:22 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **stack_a)
{
	t_list	*copy_stack_a;
	t_list	*res_stack_a;

	copy_stack_a = *stack_a;
	if (ft_lstsize(*stack_a) > 1)
	{
		while (copy_stack_a->next != NULL)
			copy_stack_a = copy_stack_a->next;
		copy_stack_a->next = *stack_a;
		res_stack_a = (*stack_a)->next;
		(*stack_a)->next = NULL;
		*stack_a = res_stack_a;
		write(1, "ra\n", 3);
	}
}

void	ft_rotate_a_for_rr(t_list **stack_a)
{
	t_list	*copy_stack_a;
	t_list	*res_stack_a;

	copy_stack_a = *stack_a;
	if (ft_lstsize(*stack_a) > 1)
	{
		while (copy_stack_a->next != NULL)
			copy_stack_a = copy_stack_a->next;
		copy_stack_a->next = *stack_a;
		res_stack_a = (*stack_a)->next;
		(*stack_a)->next = NULL;
		*stack_a = res_stack_a;
	}
}

void	ft_rotate_b(t_list **stack_b)
{
	t_list	*copy_stack_a;
	t_list	*res_stack_a;

	copy_stack_a = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		while (copy_stack_a->next != NULL)
			copy_stack_a = copy_stack_a->next;
		copy_stack_a->next = *stack_b;
		res_stack_a = (*stack_b)->next;
		(*stack_b)->next = NULL;
		*stack_b = res_stack_a;
		write(1, "rb\n", 3);
	}
}

void	ft_rotate_b_for_rr(t_list **stack_b)
{
	t_list	*copy_stack_a;
	t_list	*res_stack_a;

	copy_stack_a = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		while (copy_stack_a->next != NULL)
			copy_stack_a = copy_stack_a->next;
		copy_stack_a->next = *stack_b;
		res_stack_a = (*stack_b)->next;
		(*stack_b)->next = NULL;
		*stack_b = res_stack_a;
	}
}

void	ft_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_a_for_rr(stack_a);
	ft_rotate_b_for_rr(stack_b);
	write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_operations_3_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:33:43 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 01:34:48 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_list **stack_a)
{
	t_list	*copy_stack_a;
	t_list	*last_elem;

	copy_stack_a = *stack_a;
	if (ft_lstsize(*stack_a) > 1)
	{
		while (copy_stack_a->next != NULL)
		{
			if (copy_stack_a->next->next == NULL)
				last_elem = copy_stack_a;
			copy_stack_a = copy_stack_a->next;
		}
		copy_stack_a->next = *stack_a;
		last_elem->next = NULL;
		*stack_a = copy_stack_a;
		write(1, "rra\n", 4);
	}
}

void	ft_reverse_rotate_a_for_rrr(t_list **stack_a)
{
	t_list	*copy_stack_a;
	t_list	*last_elem;

	copy_stack_a = *stack_a;
	if (ft_lstsize(*stack_a) > 1)
	{
		while (copy_stack_a->next != NULL)
		{
			if (copy_stack_a->next->next == NULL)
				last_elem = copy_stack_a;
			copy_stack_a = copy_stack_a->next;
		}
		copy_stack_a->next = *stack_a;
		last_elem->next = NULL;
		*stack_a = copy_stack_a;
	}
}

void	ft_reverse_rotate_b(t_list **stack_b)
{
	t_list	*copy_stack_a;
	t_list	*last_elem;

	copy_stack_a = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		while (copy_stack_a->next != NULL)
		{
			if (copy_stack_a->next->next == NULL)
				last_elem = copy_stack_a;
			copy_stack_a = copy_stack_a->next;
		}
		copy_stack_a->next = *stack_b;
		last_elem->next = NULL;
		*stack_b = copy_stack_a;
		write(1, "rrb\n", 4);
	}
}

void	ft_reverse_rotate_b_for_rrr(t_list **stack_b)
{
	t_list	*copy_stack_a;
	t_list	*last_elem;

	copy_stack_a = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		while (copy_stack_a->next != NULL)
		{
			if (copy_stack_a->next->next == NULL)
				last_elem = copy_stack_a;
			copy_stack_a = copy_stack_a->next;
		}
		copy_stack_a->next = *stack_b;
		last_elem->next = NULL;
		*stack_b = copy_stack_a;
	}
}

void	ft_reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate_a_for_rrr(stack_a);
	ft_reverse_rotate_b_for_rrr(stack_b);
	write(1, "rrr\n", 4);
}

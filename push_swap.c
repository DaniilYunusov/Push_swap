/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:34:25 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 01:42:51 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argv, char **argc)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	ft_create_stack(argv, argc, &stack_a);
	stack_b = NULL;
	ft_sort_stack_a(&stack_a, &stack_b);
}

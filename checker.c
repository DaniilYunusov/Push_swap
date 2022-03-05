/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:45:02 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/02 20:59:55 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argv, char **argc)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*string;

	stack_a = NULL;
	stack_b = NULL;
	ft_create_stack(argv, argc, &stack_a);
	string = ft_strdup("");
	while (string)
	{
		free(string);
		string = get_next_line(0);
		if (!string)
			break ;
		if (!ft_viewing_command(string, &stack_a, &stack_b))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	if (ft_check_sort(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

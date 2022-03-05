/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_linked_list_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:36:32 by hjosua            #+#    #+#             */
/*   Updated: 2021/12/30 00:36:51 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long content, int index)
{
	t_list	*newlist;

	newlist = (t_list *) malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->value = content;
	newlist->index = index;
	newlist->next = NULL;
	return (newlist);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	p = ft_lstlast(p);
	p->next = new;
}

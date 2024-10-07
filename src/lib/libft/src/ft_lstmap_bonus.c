/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:03:45 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/14 08:04:03 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_lstclear_loc(t_list **list, void (*function)(void *))
{
	t_list	*pointer;
	t_list	*auxiliar;

	if (!list || !function)
		return ;
	pointer = *list;
	auxiliar = pointer->next_node;
	while (pointer)
	{
		(*function)(pointer->data);
		free(pointer);
		pointer = auxiliar;
		if (auxiliar)
			auxiliar = auxiliar->next_node;
	}
	*list = (void *) 0;
}

static	void	ft_lstadd_back_loc(t_list **list, t_list *new_node)
{
	t_list	*pointer;

	if (!list || !new_node)
		return ;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	new_node->next_node = (void *) 0;
	pointer = *list;
	while (pointer->next_node)
		pointer = pointer->next_node;
	pointer->next_node = new_node;
}

static	t_list	*ft_lstnew_loc(void *data)
{
	t_list	*pointer;

	pointer = (t_list *) ft_calloc(1, sizeof(t_list));
	if (!pointer)
		return ((void *) 0);
	pointer->data = data;
	pointer->next_node = (void *) 0;
	return (pointer);
}

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*d)(void *))
{
	t_list	*pointer;
	t_list	*ptr_first_node;

	if (!list || !f || !d)
		return ((void *) 0);
	ptr_first_node = (void *) 0;
	while (list)
	{
		pointer = ft_lstnew_loc((*f)(list->data));
		if (!pointer)
		{
			ft_lstclear_loc(&ptr_first_node, d);
			return ((void *) 0);
		}
		ft_lstadd_back_loc(&ptr_first_node, pointer);
		list = list->next_node;
	}
	return (pointer);
}

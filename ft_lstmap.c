/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:03:33 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/11 21:03:34 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	create empty new list
*	while old list exists:
*   apply f to old content
*   create new node with that new content
*   add new node to the new list
*   move to next old node
*	return the start of the new list

loop process 
start with new_list = NULL

while lst exists:
    create new_node with f(lst->content)
    if new_node creation failed:
        clear new_list using del
        return NULL
    add new_node to the back of new_list
    move lst forward

return new_list

*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (0);
	new_list = ft_lstnew(lst->content);
	new_node = ft_lstnew(lst->content);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_list)
		{
			del(new_node);
			return (0);
		}
		new_list->content = new_node->content;
		new_list->next = ft_lstnew(new_node->content); 
		lst = lst ->next;
		new_list = new_list->next;
	}
	free(new_node);
	return (new_list);
}

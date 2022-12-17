/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:52:08 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/03 00:57:32 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*new;
	t_list	*r;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((f)(lst->content), 0);
	r = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((f)(lst->content), 0);
		if (!new)
		{
			ft_lstclear(&lst);
			ft_lstclear(&r);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&r, new);
	}
	return (r);
}

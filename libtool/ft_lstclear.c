/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:46:08 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/08 06:35:25 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tl;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tl = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tl;
	}	
}

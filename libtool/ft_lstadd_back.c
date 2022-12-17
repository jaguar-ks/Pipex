/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:37:02 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/02 23:40:54 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cr;

	if (lst)
	{
		if (*lst)
		{
			cr = ft_lstlast(*lst);
			cr->next = new;
		}
		else
			*lst = new;
	}
}

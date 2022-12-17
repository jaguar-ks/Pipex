/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:53:13 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/18 04:58:35 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *d, const void *s, size_t l)
{
	size_t	i;

	if (d < s && l > 0)
	{
		i = 0;
		while (i < l)
		{
			((char *)d)[i] = ((char *)s)[i];
			i++;
		}
	}
	if (s < d && l > 0)
	{
		while (--l > 0)
			((char *)d)[l] = ((char *)s)[l];
		((char *)d)[l] = ((char *)s)[l];
	}
	return (d);
}

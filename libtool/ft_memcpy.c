/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:13:23 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/18 03:49:54 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *d, const void *s, size_t l)
{
	size_t	i;

	i = 0;
	if (!d && !s)
		return (NULL);
	while (i < l)
	{
		((char *)d)[i] = ((char *)s)[i];
		i++;
	}
	return (d);
}

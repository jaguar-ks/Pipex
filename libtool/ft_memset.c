/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:02:08 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/18 04:31:08 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)p)[i++] = (unsigned char)c;
	return (p);
}

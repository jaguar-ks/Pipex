/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:21:33 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/13 23:53:52 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t c, size_t s)
{
	void	*p;

	p = malloc(c * s);
	if (!p)
		return (NULL);
	ft_bzero(p, (s * c));
	return (p);
}

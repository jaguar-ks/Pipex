/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:47:10 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/10 02:14:01 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char	*d, char *s, size_t ds)
{
	size_t	i;

	i = 0;
	if (ds == 0)
		return (ft_strlen(s));
	while (s[i] && i < ds - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen(s));
}

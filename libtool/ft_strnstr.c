/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:41:31 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/15 21:48:00 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *hs, const char *ndl, size_t l)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if ((!hs || !ndl) && !l)
		return (NULL);
	if (ndl[0] == '\0')
		return ((char *)hs);
	while (hs[i] && i < l)
	{
		j = 0;
		while (hs[i + j] == ndl[j] && (i + j) < l)
		{
			if (ndl[j + 1] == '\0')
				return ((char *)hs + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

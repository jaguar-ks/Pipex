/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:41:33 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/13 23:57:04 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (len >= ft_strlen(s))
		j = ft_strlen(s);
	else
		j = len + 1;
	d = (char *)ft_calloc(j, sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		d[i] = 0;
	while (start <= ft_strlen(s) && i < len)
		d[i++] = s[start++];
	d[i] = '\0';
	return (d);
}

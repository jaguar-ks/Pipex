/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:45:45 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/17 01:00:08 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_concat(char *s, char *d)
{
	int	i;
	int	j;

	i = ft_strlen(d);
	j = -1;
	while (s[++j])
		d[i + j] = s[j];
	d[i + j] = '\0';
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	d = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!d)
		return (NULL);
	d = ft_concat((char *)s1, d);
	d = ft_concat((char *)s2, d);
	return (d);
}

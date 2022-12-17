/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:16:06 by faksouss          #+#    #+#             */
/*   Updated: 2022/10/17 01:00:23 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	kayn(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		t;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	t = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && kayn((char *)set, s1[i]))
		i++;
	while (kayn((char *)set, s1[j]) && j >= 0)
		j--;
	if (j >= i)
		r = (char *)ft_calloc((j - i + 1) + 1, sizeof(char));
	else
		r = (char *)ft_calloc(1, sizeof(char));
	if (!r)
		return (NULL);
	while (i <= j && s1[i])
		r[t++] = s1[i++];
	r[t] = '\0';
	return (r);
}

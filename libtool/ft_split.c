/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:22:35 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/28 03:04:53 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	is_c(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	h_m_str(char *s, char c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (s && c == '\0')
		return (1);
	while (s[++i])
	{
		while (s[i] && is_c(s[i], c))
			i++;
		if (s[i] && !is_c(s[i], c))
		{
			j++;
			while (s[i] && !is_c(s[i], c))
				i++;
		}
		if (!s[i])
			i--;
	}
	return (j);
}

static int	h_m_ch(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && is_c(s[i], c))
		i++;
	while (s[i] && !is_c(s[i], c))
	{
		i++;
		j++;
	}
	return (j);
}

void	*deallocate(char **r)
{
	int	i;

	i = -1;
	while (r[++i])
		free(r[i]);
	free(r);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		st;
	char	**r;

	if (!s)
		return (NULL);
	i = -1;
	st = 0;
	r = (char **)malloc(sizeof(char *) * (h_m_str((char *)s, c) + 1));
	if (!r)
		return (NULL);
	while (++i < h_m_str((char *)s, c) && s[st])
	{
		while (s[st] && is_c(s[st], c))
			st++;
		if (!s[st])
			break ;
		r[i] = ft_substr((char *)s, st, h_m_ch((char *)s + st, c));
		if (!r[i])
			return (deallocate(r));
		st += h_m_ch((char *)s + st, c);
	}
	r[i] = NULL;
	return (r);
}

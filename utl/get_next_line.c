/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:53:32 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/25 05:41:35 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*rtrn_ln(char *s)
{
	int		i;
	char	*r;

	if (!s || !ft_strlen(s))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	r = ft_substr(s, 0, i);
	return (r);
}

char	*th_rst(char *s)
{
	int		i;
	int		j;
	char	*r;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	while (s[j] && s[j] != '\n')
		j++;
	if (!s[j])
		return (free(s), NULL);
	if (s[j] == '\n')
		j++;
	r = ft_substr(s, j, (i - j));
	free(s);
	if (!ft_strlen(r))
		return (free(r), NULL);
	return (r);
}

char	*get_next_line(int fd)
{
	char		*bf;
	static char	*s;
	char		*r;
	int			i;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	while (i && search(s, '\n'))
	{
		bf = (char *)malloc(BUFFER_SIZE + 1);
		if (!bf)
			return (NULL);
		i = read(fd, bf, BUFFER_SIZE);
		if (i < 0)
			return (free(bf), NULL);
		bf[i] = '\0';
		if (!ft_strlen(bf))
		{
			free(bf);
			break ;
		}
		s = join_str(s, bf);
	}
	return ((r = rtrn_ln(s)), (s = th_rst(s)), r);
}

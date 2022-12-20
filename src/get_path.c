/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:38:32 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/20 01:55:52 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

char	*get_path(char **en, char *cm)
{
	char	**pth;
	char	*r;
	char	*cmd;
	int		i;

	while (ft_strncmp((*en), "PATH", 4))
		*en++;
	pth = ft_split((*en + 5), ':');
	i = -1;
	cmd = ft_strjoin("/", cm);
	while (pth[++i])
	{
		// *pth = ft_strjoin(*pth, "/");
		r = ft_strjoin(pth[i], cmd);
		if (access(r, (F_OK | X_OK)) == 0)
			break ;
		free(r);
	}
	return (deallocate(pth), free(cmd), r);
}

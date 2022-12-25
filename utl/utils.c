/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:20:40 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/25 06:38:29 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

void	do_cmd(char **cmd, char **en)
{
	char	*pth;

	pth = get_path(en, cmd[0]);
	if (!pth)
	{
		deallocate(cmd);
		ft_putstr_fd("Error: command not found\n", 2);
		exit(127);
	}
	if (execve(pth, cmd, en) < 0)
		exit(error());
}

char	*get_path(char **en, char *cm)
{
	char	**pth;
	char	*r;
	char	*cmd;
	int		i;

	i = 0;
	while (ft_strncmp((en[i]), "PATH", 4))
		i++;
	pth = ft_split((en[i] + 5), ':');
	i = -1;
	cmd = ft_strjoin("/", cm);
	while (pth[++i])
	{
		r = ft_strjoin(pth[i], cmd);
		if (access(r, (X_OK)) == 0)
			break ;
		free(r);
		r = NULL;
	}
	return (deallocate(pth), free(cmd), r);
}

int	error(void)
{
	perror("Error");
	return (errno);
}

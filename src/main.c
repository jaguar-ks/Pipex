/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:41:05 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/20 02:28:47 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

void	bambino_processo(char **av, char **en, int *fd)
{
	char	*pth;
	char	**cmd;
	int		ingresso;

	close(fd[0]);
	ingresso = open(av[1], O_RDONLY, 0777);
	if (ingresso < 0)
		strerror(errno);
	cmd = ft_split(av[2], ' ');
	pth = get_path(en, *cmd);
	dup2(fd[1], 0);
	dup2(ingresso, 1);
	if (execve(pth, cmd, en) < 0)
		strerror(errno);
}

int main(int ac, char **av, char **en)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			strerror(errno);
		pid = fork();
		if (!pid)
			bambino_processo(av, en, fd[0]);
		wait
	}
}

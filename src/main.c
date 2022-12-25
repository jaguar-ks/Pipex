/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:41:05 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/25 22:00:13 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

void	bambino_processo(char **av, char **en, int *fd)
{
	int		ingresso;

	ingresso = open(av[1], O_RDONLY, 0777);
	if (ingresso < 0)
		exit(error());
	dup2(fd[1], STDOUT_FILENO);
	dup2(ingresso, STDIN_FILENO);
	close(fd[0]);
	do_cmd(ft_split(av[2], ' '), en);
}

void	padre_processo(char **av, char **en, int *fd)
{
	int		produzione;

	produzione = open(av[4], (O_CREAT | O_WRONLY | O_TRUNC), 0777);
	if (produzione < 0)
		exit(error());
	dup2(fd[0], STDIN_FILENO);
	dup2(produzione, STDOUT_FILENO);
	close(fd[1]);
	do_cmd(ft_split(av[3], ' '), en);
}

int	main(int ac, char **av, char **en)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			exit(127);
		pid = fork();
		if (!pid)
			bambino_processo(av, en, fd);
		waitpid(pid, NULL, 0);
		padre_processo(av, en, fd);
	}
	else
		ft_putstr_fd("ERROR: There are too many or not enough argiments\n", 2);
}

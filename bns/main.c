/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:45:39 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/25 06:42:34 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

int	check_lim(char *lim, char *r)
{
	if ((!ft_strncmp(lim, r, ft_strlen(lim))
			&& (ft_strlen(lim) + 1 == ft_strlen(r))))
		return (1);
	else
		return (0);
}

void	here_doc(char *lim)
{
	char	*r;
	int		fd[2];
	int		pid;

	if (pipe(fd) < 0)
		exit(error());
	pid = fork();
	if (!pid)
	{
		close(fd[0]);
		while (1)
		{
			ft_putstr_fd("heredoc> ", 1);
			r = get_next_line(0);
			if (check_lim(lim, r))
				exit(EXIT_SUCCESS);
			ft_putstr_fd(r, fd[1]);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	children(int i, int ac, char **av, char **en)
{
	int	fd[2];
	int	pid;

	while (i < ac - 2)
	{
		if (pipe(fd) < 0)
			exit(error());
		pid = fork();
		if (!pid)
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			do_cmd(ft_split(av[i], ' '), en);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			waitpid(pid, NULL, 0);
		}
		i++;
	}
}

int	open_out(char **av, int ac, int mode)
{
	int	fd;

	fd = -1;
	if (mode == 3)
	{
		fd = open(av[ac - 1], (O_CREAT | O_RDWR | O_APPEND), 0777);
		if (fd < 0)
			exit(error());
	}
	else if (mode == 2)
	{
		fd = open(av[ac - 1], (O_CREAT | O_RDWR | O_TRUNC), 0777);
		if (fd < 0)
			exit(error());
	}
	return (fd);
}

int	main(int ac, char **av, char **en)
{
	int	in;
	int	out;
	int	i;

	if (ac > 5)
	{
		i = 3;
		if (!ft_strncmp(av[1], "here_doc", 9))
			here_doc(av[2]);
		else
		{
			in = open(av[1], O_RDWR, 0777);
			if (in < 0)
				exit(error());
			dup2(in, STDIN_FILENO);
			i = 2;
		}
		out = open_out(av, ac, i);
		children(i, ac, av, en);
		dup2(out, STDOUT_FILENO);
		do_cmd(ft_split(av[ac - 2], ' '), en);
	}
	else
		ft_putstr_fd("Error: number of arguments is less than expected\n", 2);
}

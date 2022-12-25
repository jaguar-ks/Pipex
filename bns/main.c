/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:45:39 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/25 05:02:54 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

int	open_in(char **av, int *i)
{
	int fd;

	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		fd = open(av[1], (O_CREAT | O_RDWR | O_APPEND), 0777);
		if (fd < 0)
			exit(error());
		*i = 3;
	}
	else
	{
		fd = open(av[1], O_RDWR, 0777);
		if (fd < 0)
			exit(error());
		*i = 2;
	}
	return(fd);
}

void	here_doc(int fd, char *lim)
{
	char	*r;
	while (1)
	{
		write(1, "heredoc> ", 10);
		r = get_next_line(0);
		if ((!ft_strncmp(lim, r, ft_strlen(lim))
			&& (ft_strlen(lim) + 1 == ft_strlen(r))) || !r)
			break ;
		write(fd, r, ft_strlen(r));
	}
}

// void	children(char *cm, char **en, int in, int out)
// {
// 	int	fd[2];
// 	int	pid;

// 	if (pipe(fd) < 0)
// 		exit(error());
// 	pid = fork();
// 	if (pid < 0)
// 		exit(error());
// 	if (!pid)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		dup2(in, STDIN_FILENO);
// 		do_cmd(ft_split(cm, ' '), en);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		dup2(out, STDOUT_FILENO);
// 		waitpid(pid, NULL, 0);
// 	}
// }

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
	int	fd[2];
	int	pid;

	in = open_in(av, &i);
	out = open_out(av, ac, i);
	if (i == 3)
		here_doc(in, av[2]);
	dup2(in, STDIN_FILENO);
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
	if (!ft_strncmp(av[1], "here_doc", 9))
		unlink(av[1]);
	dup2(out, STDOUT_FILENO);
	do_cmd(ft_split(av[ac - 2], ' '), en);
}

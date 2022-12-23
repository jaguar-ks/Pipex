/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:08:37 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/24 00:53:38 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

void	here_doc(int fd, char *limite)
{
	char	*r;

	while (1)
	{
		write(1, "heredoc> ", 10);
		r = get_next_line(0);
		if ((!ft_strncmp(r, limite, ft_strlen(limite))
			&& ft_strlen(limite) + 1 == ft_strlen(r)) || !r)
		{
			free(r);
			break ;
		}
		write(fd, r, ft_strlen(r));
		free(r);
	}
}

int	open_ingresso(char **av)
{
	int	ingresso;

	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		ingresso = open(".here_doc.txt", (O_CREAT | O_WRONLY), 0777);
		if (ingresso < 0)
			exit(error());
		here_doc(ingresso, av[2]);
	}
	else
	{
		ingresso = open(av[1], O_RDONLY, 0777);
		if (ingresso < 0)
			exit(error());
	}
	return (ingresso);
}

void	sacco_di_bambini(char *cm, char **en, int ingresso, int *fd)
{
	int		pid;
	char	**cmd;

	if (pipe(fd) < 0)
		exit(error());
	cmd = ft_split(cm, ' ');
	pid = fork();
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(ingresso, STDIN_FILENO);
		eseguire_il_comanda(cmd, en);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	open_produzione(char *name, int how)
{
	int	fd;

	if (how == 3)
		fd = open(name, (O_CREAT | O_WRONLY | O_APPEND), 0777);
	else
		fd = open(name, (O_CREAT | O_WRONLY | O_TRUNC), 0777);
	if (fd < 0)
		exit(error());
	return (fd);	
}

int	main(int ac, char **av, char **en)
{
	int	fd[2];
	int	ingresso;
	int	produzione;
	int	i;

	if (ac > 5)
	{
		if (!ft_strncmp(av[1], "here_doc", 9))
			i = 3;
		else
			i = 2;
		ingresso = open_ingresso(av);
		while (i < ac - 2)
			sacco_di_bambini(av[i++], en, ingresso, fd);
		if (!ft_strncmp(av[1], "here_doc", 9))
			unlink(".here_doc.txt");
		produzione = open_produzione(av[ac - 1], i);
		dup2(produzione, STDOUT_FILENO);
		eseguire_il_comanda(ft_split(av[ac - 2], ' '), en);
	}
	else
		ft_putstr_fd("ERROR: There are too many or not enough argiments\n", 2);
}

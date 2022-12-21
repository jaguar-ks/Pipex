/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:41:05 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/21 23:33:32 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

int	error(void)
{
	perror("Error");
	return (1);
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

void	bambino_processo(char **av, char **en, int *fd)
{
	char	*pth;
	char	**cmd;
	int		ingresso;

	ingresso = open(av[1], O_RDONLY, 0777);
	if (ingresso < 0)
		exit(error());
	cmd = ft_split(av[2], ' ');
	pth = get_path(en, *cmd);
	if (!pth)
		exit(ft_putstr_fd("Error: command not found\n", 2));
	dup2(fd[1], STDOUT_FILENO);
	dup2(ingresso, STDIN_FILENO);
	close(fd[0]);
	if (execve(pth, cmd, en) < 0)
		exit(error());
}

void	padre_processo(char **av, char **en, int *fd)
{
	int		produzione;
	char	**cmd;
	char	*pth;

	produzione = open(av[4], (O_CREAT | O_WRONLY | O_TRUNC), 0777);
	if (produzione < 0)
		exit(error());
	cmd = ft_split(av[3], ' ');
	pth = get_path(en, *cmd);
	if (!pth)
		exit(ft_putstr_fd("Error: command not found\n", 2));
	dup2(fd[0], STDIN_FILENO);
	dup2(produzione, STDOUT_FILENO);
	close(fd[1]);
	if (execve(pth, cmd, en) < 0)
		exit(error());
}

int	main(int ac, char **av, char **en)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			exit(error());
		pid = fork();
		if (!pid)
			bambino_processo(av, en, fd);
		waitpid(pid, NULL, 0);
		padre_processo(av, en, fd);
	}
	else
		ft_putstr_fd("ERROR: There are too many or not enough argiments\n", 2);
}

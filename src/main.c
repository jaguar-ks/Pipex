/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:41:05 by deman_wolf        #+#    #+#             */
/*   Updated: 2022/12/21 04:44:14 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

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
		// *pth = ft_strjoin(*pth, "/");
		r = ft_strjoin(pth[i], cmd);
		if (access(r, (F_OK | X_OK)) == 0)
			break ;
		free(r);
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
		strerror(errno);
	cmd = ft_split(av[2], ' ');
	pth = get_path(en, *cmd);
	dup2(fd[1], STDOUT_FILENO);
	dup2(ingresso, STDIN_FILENO);
	close(fd[0]);
	if (execve(pth, cmd, en) < 0)
		strerror(errno);
}

void	padre_processo(char **av, char **en, int *fd)
{
	int		produzione;
	char	**cmd;
	char	*pth;

	produzione = open(av[4], (O_CREAT | O_WRONLY), 0777);
	if (produzione < 0)
		strerror(errno);
	cmd = ft_split(av[3], ' ');
	pth = get_path(en, *cmd);
	dup2(fd[0], STDIN_FILENO);
	dup2(produzione, STDOUT_FILENO);
	close(fd[1]);
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
			bambino_processo(av, en, fd);
		waitpid(pid, NULL, 0);
		padre_processo(av, en, fd);
	}
	else
		ft_putstr_fd("ERROR: There are too many or not enough argiments\nExp => ./pipex <input_file> <first_command> <second_command> <output_file`>", 2);
}

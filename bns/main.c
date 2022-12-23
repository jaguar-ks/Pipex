/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:08:37 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/23 04:46:20 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/pipex.h"

void	here_doc(int fd, char *limite)
{
	char	*r;
	char	*fl;

	while (1)
	{
		write(1, "heredoc>", 9);
		r = get_next_line(0);
		if (!ft_strncmp(r, limite, ft_strlen(limite))
			&& ft_strlen(limite) + 1 == ft_strlen(r))
		{
			free(r);
			break ;
		}
		fl = join_str(fl, r);
	}
	write(fd, fl, ft_strlen(fl));
	free(fl);
}

int	main(int ac, char **av, char **en)
{
	int	fd[2];
	int	ingresso;
	int	produzione;
	int	i;

	if (ac > 5)
	{
		if (pipe(fd) < 0)
			exit(error());
		if (!ft_strncmp(av[1], "here_doc", 9))
		{
			i = 3;
			ingresso = open(".here_doc.txt", (O_CREAT | O_RDWR), 0777);
			here_doc(ingresso, av[2]);
		}
		else
		{
			ingresso = open(av[1], O_RDONLY, 0777);
			i = 2;
		}
		
	}
}

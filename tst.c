#include "inc/pipex.h"
// int main(int ac, char **av, char **en)
// {
// 	(void)ac;
// 	// int fd[2];
// 	// pipe(fd);
// 	// printf("%d\n%d", fd[0], fd[1]);
// 	char	*pth;
// 	char	**cmd;
// 	int		ingresso;

// 	ingresso = open(av[1], O_RDWR, 0777);
// 	if (ingresso < 0)
// 		strerror(errno);
// 	cmd = ft_split(av[2], ' ');
// 	pth = get_path(en, *cmd);
// 	printf("path of cmd :-->|%s|\n", pth);
// 	printf("cmd :-->|%s|\n", *cmd);
// 	dup2(ingresso, STDIN_FILENO);
// 	system("leaks a.out");
// 	if (execve(pth, cmd, en) < 0)
// 		strerror(errno);
// 	// char *c = get_cmd(av[1]);
// 	// char *r = get_path(en, c);
// 	// printf("%s\n",r);
// 	// free(r);
// 	// free(c);
// 	// (void)ac;
// 	// (void)av;
// 	// char	**r;
// 	// while (ft_strncmp(*en, "PATH", 4))
// 	// 	*en++;
// 	// *en = (*en) + 5;
// 	// r = ft_split(*en, ':');
// 	// while (*r)
// 	// 	printf("%s\n", *r++);
// 	// int fd = open("hello.txt", O_RDWR, 0777);
// 	// int fd1;
// 	// if (fd == -1)
// 	// 	perror("dup");
// 	// fd1 = dup(1);
// 	// printf("-->%d\n", fd1);
// 	// read(4, r, 10);
// 	// printf("alllah m3ak ajay l3ali\n");
// 	// printf("---->%s", (char *)r);
// }

int main(int ac, char **av)
{
	char *r;
	char *fl;
	while (1)
	{
		write(1, "heredoc> ", 10);
		r = get_next_line(0);
		if (!ft_strncmp(r, av[1], ft_strlen(av[1])) && ft_strlen(av[1])+1 == ft_strlen(r))
		{
			free(r);
			break ;
		}
		fl = join_str(fl, r);
	}
	printf("%s", fl);
	free(fl);
	system("leaks a.out");
}
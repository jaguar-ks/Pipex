#include "inc/pipex.h"
int main(int ac, char **av, char **en)
{
	// (void)ac;
	// (void)av;
	// char **r;
	// while (ft_strncmp(*en, "PATH", 4))
	// 	*en++;
	// *en = (*en) + 5;
	// r = ft_split(*en, ':');
	// while (*r)
	// 	printf("%s\n", *r++);
	int fd = open("hello.txt", O_RDWR, 0777);
	dup2(fd, 1);
	printf("alllah m3ak ajay l3ali\n");
}
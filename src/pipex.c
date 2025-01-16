#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	j;
	
	(void) j;
	(void) envp;
	i = 1;
	if (access(av[i], F_OK) == 0
		&& access(av[ac - 1], F_OK) == 0)
	{
		printf("hello");
	}
	else
		return 0;
}

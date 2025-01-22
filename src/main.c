#include "../inc/pipex.h"

void	init_pipex(t_pipex **pipex, int size)
{
	(*pipex) = malloc(sizeof(t_pipex));
	if (!(*pipex))
		return ;
	(*pipex)->fd[0] = -1;
	(*pipex)->fd[1] = -1;
	(*pipex)->here_doc = 0;
	(*pipex)->paths = malloc(sizeof(char *) * size - 2);
	(*pipex)->cmds = malloc(sizeof(char *) * size - 2);
	if (!(*pipex)->paths || !(*pipex)->cmds)
		return ;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		i;

	pipex = NULL;
	init_pipex(&pipex, ac);
	if (!valid_input(&pipex, av, ac))
		return (free_error(&pipex, "ERROR: Invalid Input"));
	if (!valid_cmds(&pipex, av, envp, ac))
		return (free_error(&pipex, "ERROR: Command Not Found"));
	if (!valid_args(&pipex, av, envp, ac))
		return (free_error(&pipex, "ERROR: Invalid Arguments"));
	i = 1;
	int j = 0;
	while (++i < ac - 1)
	{
		printf("%s\n", pipex->cmds[j]);
		printf("%s\n", pipex->paths[j]);
		/*printf("loop");*/
		++j;
	}
	exec(&pipex, av, envp, ac);
	/*free_error(pipex, "SUCCESS");*/
	return (0);
}

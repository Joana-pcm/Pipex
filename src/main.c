#include "../inc/pipex.h"

void	init_pipex(t_pipex **pipex)
{
	(*pipex) = malloc(sizeof(t_pipex));
	if (!(*pipex))
		return ;
	(*pipex)->fd[0] = -1;
	(*pipex)->fd[1] = -1;
	(*pipex)->here_doc = 0;
	(*pipex)->paths = NULL;
	(*pipex)->cmds = NULL;
}



int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		i;

	pipex = NULL;
	init_pipex(&pipex);
	if (!valid_input(&pipex, av, ac))
		return (free_error(&pipex, "ERROR: Invalid Input"));
	if (!valid_cmds(&pipex, av, envp, ac))
		return (free_error(&pipex, "ERROR: Command Not Found"));
	if (!valid_args(&pipex, av, envp, ac))
		return (free_error(&pipex, "ERROR: Invalid Arguments"));
	i = 1;
	while (++i < ac - 1)
	{
		printf("loop");
		exec(&pipex, av, envp, ac);
	}
	/*free_error(pipex, "SUCCESS");*/
	return (0);
}

#include "../inc/pipex_bonus.h"
#include <fcntl.h>

void	init_pipex(t_pipex **pipex, int size)
{
	(*pipex) = malloc(sizeof(t_pipex));
	if (!(*pipex))
		return ;
	(*pipex)->in_fd = -1;
	(*pipex)-> out_fd = -1;
	(*pipex)->here_doc = 0;
	(*pipex)->paths = malloc(sizeof(char *) * size - 2);
	(*pipex)->cmds = malloc(sizeof(char *) * size - 1);
	if (!(*pipex)->paths || !(*pipex)->cmds)
		return ;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	/*int		i;*/

	pipex = NULL;
	init_pipex(&pipex, ac);
	if (!valid_input(&pipex, av, ac))
		return (free_error(&pipex, "ERROR: Invalid Input"));
	if (!valid_cmds(&pipex, av, envp, ac))
		return (free_error(&pipex, "ERROR: Command Not Found"));
	/*if (!valid_args(&pipex, av, envp, ac))*/
	/*	return (free_error(&pipex, "ERROR: Invalid Arguments"));*/
	pipex->in_fd = open(av[1], O_RDONLY, 0777);
	pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT, 0777);
	dup2(pipex->in_fd, 0);
	/*printf("here\n");*/
	dup2(pipex->out_fd, 1);
	main_process(&pipex, envp, 0, (ac - 1));
	/*exec(&pipex, envp, i, ac - 1);*/
	/*free_error(pipex, "SUCCESS");*/
	return (0);
}

#include "../inc/pipex.h"

int	exec(t_pipex **pipex, char **av, char **envp, int size)
{
	pid_t	pid;

	if (pipe((*pipex)->fd) == -1)
		free_error(pipex, "ERROR: Incapable of creating pipe");
	pid = fork();
	if (pid == -1)
		free_error(pipex, "ERROR");
	if (pid == 0)
		child_process(pipex, av, envp);
	waitpid(pid, NULL, 0);
(void) size;	
	return (0);
}

int	child_process(t_pipex **pipex, char **av, char **envp)
{
	int	in_fd;

	in_fd = open(av[1], O_RDONLY, 0777);
	if (in_fd == -1)
	{
		free_error(pipex, "ERROR");
		return (1);
	}
	dup2((*pipex)->fd[1], STDOUT_FILENO);
	dup2(in_fd, STDIN_FILENO);
	close((*pipex)->fd[0]);
	/*run_cmd(av, envp);*/
	(void) envp;
	return (0);
}

int	parent_process(t_pipex **pipex, char **av, char **envp)
{
	(void) pipex;
	(void) av;
	(void) envp;
	return (0);
}

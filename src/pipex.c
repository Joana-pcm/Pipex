#include "../inc/pipex.h"

int	exec(t_pipex **pipex, char **envp)
{
	pid_t	pid;
	int		*fd;
	int		i;

	i = -1;
	if (pipe(fd) == -1)
		free_error(pipex, "ERROR: Incapable of creating pipe");
	pid = fork();
	if (pid == -1)
		free_error(pipex, "ERROR");
	if (pid == 0)
	{
		while ((*pipex)->paths[++i])
		child_process(pipex, envp, fd);
	}
	waitpid(pid, NULL, 0);
	parent_process(pipex, envp, fd);	
	return (0);
}

int	child_process(t_pipex **pipex, char **envp, int *fd)
{
	int	in_fd;
	int	n;

	n = -1;
	if ( == -1)
	{
		free_error(pipex, "ERROR");
		return (1);
	}
	dup2((*pipex)->fd[1], STDOUT_FILENO);
	dup2(in_fd, STDIN_FILENO);
	close((*pipex)->fd[0]);
	close(in_fd);
	while ((*pipex)->cmds[++n] != NULL)
		execve((*pipex)->paths[n], ft_split((*pipex)->cmds[n], ' '), envp);
	return (0);
}

int	parent_process(t_pipex **pipex, char **envp, int *fd)
{
	int	out_fd;
	int	status;
	int n;

	n = -1;
	out_fd = open(av[size - 1], O_WRONLY , 0777);
	waitpid(-1, &status, 0);
	dup2(out_fd, STDOUT_FILENO);
	dup2((*pipex)->fd[0], STDIN_FILENO);
	close((*pipex)->fd[1]);
	close(out_fd);
	printf("test\n");
	while ((*pipex)->cmds[++n] != NULL)
	{
		execve((*pipex)->paths[n], ft_split((*pipex)->cmds[n], ' '), envp);
	}
	return (0);
}

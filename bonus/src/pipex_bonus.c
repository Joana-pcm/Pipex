#include "../inc/pipex_bonus.h"

int	exec(t_pipex **pipex, char **envp, int index, int size)
{
	pid_t	pid;
	int		*fd;

	fd = NULL;
	if (pipe(fd) == -1)
		free_error(pipex, "ERROR: Incapable of creating pipe");
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		free_error(pipex, "ERROR");
	}
	if (pid == 0)
		child_process(pipex, envp, fd, index, size);
	else
		dup2(fd[0], STDIN_FILENO);
	waitpid(pid, NULL, 0);
	return (0);
}

int	child_process(t_pipex **pipex, char **envp, int *fd, int index, int size)
{
		if (index == 0)
			dup2((*pipex)->in_fd, STDIN_FILENO);
		if (index == size)
			dup2((*pipex)->out_fd, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		if ((*pipex)->paths[index])
			execve((*pipex)->paths[index], ft_split((*pipex)->cmds[index], ' '), envp);
		else
		{
			close(fd[1]);
			close(fd[0]);
		}
	return (0);
}


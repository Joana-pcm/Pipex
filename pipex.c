#include "../inc/pipex.h"

int	exec(t_pipex *pipex, av, ac, envp)
{
	pid_t	pid;

	if (pipe(pipex->fd) == -1)
		free_error(&pipex, "ERROR: Incapable of creating pipe");
	pid = fork();
	if (pid == -1)
		free_error(&pipex, "ERROR");
	if (pid == 0)
	{
		fd_in = open(argv[1], O_RDONLY, 0777);
		if (fd_in == -1)
			free_error(&pipex, "ERROR");
		dup2(pipex->fd[1], STDOUT_FILENO);
		dup2(fd_in, STDIN_FILENO);
		close(pipex->fd[0]);
		run_cmd(argv[i], envp);
	}
	waitpid(pid, NULL, 0);
	
	return (0);
}

int	child_process(t_pipex **pipex, char **av, char **envp)
{
	int	infile_fd;
		fd_in = open(argv[1], O_RDONLY, 0777);
		if (fd_in == -1)
			free_error(&pipex, "ERROR");
		dup2(pipex->fd[1], STDOUT_FILENO);
		dup2(fd_in, STDIN_FILENO);
		close(pipex->fd[0]);
		run_cmd(argv[i], envp);
}

int	parent_process(t_pipex **pipex, char **av, char **envp)
{
}

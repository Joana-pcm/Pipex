/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:19:35 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/03 17:07:35 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	exec(t_pipex **pipex, char **envp, int index)
{
	char	**temp;

	temp = ft_split((*pipex)->cmds[index], ' ');
	if (!temp)
		free_error(pipex, "Could not create array");
	execve((*pipex)->paths[index], temp, envp);
	return (0);
}

int	main_process(t_pipex **pipex, char **envp)
{
	pid_t	pid[2];
	int		fd[2];

	if (pipe(fd) == -1)
		free_error(pipex, "ERROR");
	child_process(pipex, envp, fd, pid);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (1);
}

int	child_process(t_pipex **pipex, char **envp,	int *fd, pid_t *pid)
{
	pid[0] = fork();
	if (pid[0] == -1)
		free_error(pipex, "no child process");
	if (pid[0] > 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec(pipex, envp, 0);
	}
	pid[1] = fork();
	if (pid[1] == -1)
		free_error(pipex, "no child process");
	if (pid[1] > 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec(pipex, envp, 1);
	}
	return (0);
}

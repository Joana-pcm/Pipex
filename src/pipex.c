/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:19:35 by jpatrici          #+#    #+#             */
/*   Updated: 2025/01/27 10:19:40 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	exec(t_pipex **pipex, char **envp, int size)
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
	{
		child_process(pipex, envp, fd, size);
	}
	else
		dup2(fd[0], STDIN_FILENO);
	waitpid(pid, NULL, 0);
	return (0);
}

int	child_process(t_pipex **pipex, char **envp, int *fd, int size)
{
		if (index == 0)
			dup2((*pipex)->in_fd, STDIN_FILENO);
		if (index == size)
			dup2((*pipex)->out_fd, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		if ((*pipex)->paths[0])
			execve((*pipex)->paths[0], ft_split((*pipex)->cmds[0], ' '), envp);
		else
		{
			close(fd[1]);
			close(fd[0]);
		}
	return (0);
}

int	child_process2(t_pipex **pipex, char **envp, int fd, int index, int size)

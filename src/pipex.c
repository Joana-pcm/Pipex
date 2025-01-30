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

int	exec(t_pipex **pipex, char **envp, int index)
{
	char **temp;

	temp = ft_split((*pipex)->cmds[index], ' ');
	if (!temp)
		free_error(pipex, "Could not create array");
	execve((*pipex)->paths[index], temp, envp);
	return (0);
}

int	main_process(t_pipex **pipex, char **envp, int index, int size)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];

	if (pipe(fd) == -1)
		free_error(pipex, "ERROR");
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid > 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec(pipex, envp, index);
	}
	pid2 = fork();
	if (pid2 == -1)
		exit(0);
	if (pid2 > 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec(pipex, envp, index + 1);
	}
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	(void) size;
	return (1);
}

/*int	child_process(t_pipex **pipex, char **envp,int *fd, int index, int size)*/
/*{*/
/*	return(execve((*pipex)->paths[index], \*/
/*	  ft_split((*pipex)->cmds[index], ' '), envp));*/
/*	(void) size;*/
/*	(void) fd;*/
/*}*/

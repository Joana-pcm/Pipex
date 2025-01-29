/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:55:28 by jpatrici          #+#    #+#             */
/*   Updated: 2025/01/27 17:16:57 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"
#include <unistd.h>

int	exec(t_pipex **pipex, char **envp, int index, int size)
{
	char **temp;

	printf("exec\n");
	/*if (!main_process(pipex, envp, index, size))*/
	/*	free_error(pipex, "ERROR could not process");*/
	temp = ft_split((*pipex)->cmds[index], ' ');
	printf("exec\n");
	if (!temp)
		free_error(pipex, "Could not create array");
	execve((*pipex)->paths[index], temp, envp);
	(void)	size;
	return (0);
}

int	main_process(t_pipex **pipex, char **envp, int index, int size)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];
	/*int	status;*/

	/*status = 0;*/
	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid > 0)
	{
		//child process 1
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		printf("before\n");
		exec(pipex, envp, index, size);
		printf("after\n");
	}
	pid2 = fork();
	if (pid2 == -1)
		exit(0);
	if (pid2 > 0)
	{
		//child process 2
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec(pipex, envp, index + 1, size);
	}
	/*else */
	/*{*/
		//main process
		close(fd[1]);
		close(fd[0]);
	/*}*/
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	(void) pipex;
	(void) envp;
	(void) index;
	(void) size;
	/*while (waitpid(pid, NULL, 0) > 0)*/
	/*	;*/
	/*main_process(pipex, envp, index + 1, size);*/
	return (1);
}

/*int	child_process(t_pipex **pipex, char **envp,int *fd, int index, int size)*/
/*{*/
/*	return(execve((*pipex)->paths[index], \*/
/*	  ft_split((*pipex)->cmds[index], ' '), envp));*/
/*	(void) size;*/
/*	(void) fd;*/
/*}*/

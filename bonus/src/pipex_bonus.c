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
\
int	main_process(t_pipex **pipex, char **envp, int index, int size)
{
	pid_t	pid;
	pid_t	pidn;
	pid_t	pid2;
	int		**fd;
	int		n;

	n = -1;
	fd = malloc(sizeof(int *) * (size - 1));
	while (++n <=  size - 2)
		fd[n] = malloc(sizeof(int) * 2);

	n = 0;
	if (pipe(fd[n]) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid > 0)
	{
		close(fd[n][0]);
		dup2(fd[n][1], STDOUT_FILENO);
		close(fd[n][1]);
		exec(pipex, envp, index, size);
	}
	while (++index <= size - 4)
	{	
		if (pipe(fd[++n]) == -1)
			exit(0);
		pidn = fork();
		if (pidn == -1)
			exit (0);
		if (pidn > 0)
		{
			dup2(fd[n][0], STDIN_FILENO);
			close(fd[n][0]);
			dup2(fd[n][1], STDOUT_FILENO);
			close(fd[n][1]);
			exec(pipex, envp, index, size);
		}
		waitpid(pidn, NULL, 0);
	}
	if (pipe(fd[++n]) == -1)
		exit(0);
	pid2 = fork();
	if (pid2 == -1)
		exit(0);
	if (pid2 > 0)
	{
		dup2(fd[n][0], STDIN_FILENO);
		close(fd[n][0]);
		close(fd[n][1]);
		exec(pipex, envp, index, size);
	}
	n = -1;
	while (fd[++n])
	{
		close(fd[n][0]);
		close(fd[n][1]);
	}
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (1);
}

/*int	child_process(t_pipex **pipex, char **envp,int *fd, int index, int size)*/
/*{*/
/*	return(execve((*pipex)->paths[index], \*/
/*	  ft_split((*pipex)->cmds[index], ' '), envp));*/
/*	(void) size;*/
/*	(void) fd;*/
/*}*/

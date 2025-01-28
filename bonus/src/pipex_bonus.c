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

/*int	exec(t_pipex **pipex, char **envp, int index, int size)*/
/*{*/
/*	return (0);*/
/*}*/

int	main_process(t_pipex **pipex, char **envp, int index, int size)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		free_error(pipex, "ERROR: Incapable of creating pipe");
	pid = fork();
	if (pid < 0)
		free_error(pipex, "ERROR: PID error");
	if (pid == 0)
	{	
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		child_process(pipex, envp, fd, index, size);
	}
	/*else */
	/*	dup2(fd[0], STDIN_FILENO);	*/
	if (index < size)
		main_process(pipex, envp, index + 1, size);
	return (0);
}

int	child_process(t_pipex **pipex, char **envp,int *fd, int index, int size)
{
	if ((*pipex)->paths[index])
		execve((*pipex)->paths[index], \
	  ft_split((*pipex)->cmds[index], ' '), envp);
	else
	{
		close(fd[1]);
		close(fd[0]);
		return (0);
	}
	(void) size;
	(void) fd;
	return (0);
}

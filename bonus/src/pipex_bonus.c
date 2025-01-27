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

int	child_process(t_pipex **pipex, char **envp, int index, int size)
{
	pid_t	pid;
	int		fd[2];

	pid = fork();
	if (pipe(fd) == -1)
		free_error(pipex, "ERROR: Incapable of creating pipe");
	if (pid == 0)
	{
		close(fd[0]);
		if (index == 0)
			dup2((*pipex)->in_fd, STDIN_FILENO);
		if (index == size)
			dup2((*pipex)->out_fd, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
	}
	else 
		dup2(fd[0], STDIN_FILENO);
	if ((*pipex)->paths[index])
		execve((*pipex)->paths[index], \
	  ft_split((*pipex)->cmds[index], ' '), envp);
	else
	{
		close(fd[1]);
		close(fd[0]);
		return (0);
	}
	child_process(pipex, envp, (index + 1), size);
	return (0);
}


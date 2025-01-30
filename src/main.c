/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:19:01 by jpatrici          #+#    #+#             */
/*   Updated: 2025/01/27 10:19:08 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <unistd.h>

void	init_pipex(t_pipex **pipex, int size)
{
	(*pipex) = malloc(sizeof(t_pipex));
	if (!(*pipex))
		return ;
	(*pipex)->in_fd = -1;
	(*pipex)-> out_fd = -1;
	(*pipex)->paths = malloc(sizeof(char *) * 2);
	(*pipex)->cmds = malloc(sizeof(char *) * size - 1);
	if (!(*pipex)->paths || !(*pipex)->cmds)
		return ;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;

	pipex = NULL;
	init_pipex(&pipex, ac);
	if (!valid_input(&pipex, av, envp, ac))
		return (free_error(&pipex, "ERROR: Invalid Input"));
	if (!valid_args(&pipex, av, envp, ac))
		return (free_error(&pipex, "ERROR: Invalid Arguments"));
	pipex->in_fd = open(av[1], O_RDONLY, 0777);
	if (access(av[4], F_OK) || !access(av[4], R_OK))
		pipex->out_fd = open(av[4], O_WRONLY | O_CREAT, 0777);
	else
		return (0);
	dup2(pipex->in_fd, STDIN_FILENO);
	dup2(pipex->out_fd, STDOUT_FILENO);
	main_process(&pipex, envp, 0, (ac - 1));
	free_error(&pipex, "SUCCESS");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:19:01 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/03 17:09:54 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <unistd.h>

void	init_pipex(t_pipex **pipex)
{
	(*pipex) = malloc(sizeof(t_pipex));
	if (!(*pipex))
		free_error(pipex, "ERROR");
	(*pipex)->in_fd = -1;
	(*pipex)-> out_fd = -1;
	(*pipex)->paths = ft_calloc(sizeof(char *), 3);
	(*pipex)->cmds = ft_calloc(sizeof(char *), 3);
	if (!(*pipex)->paths || !(*pipex)->cmds)
		free_error(pipex, "ERROR");
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;

	pipex = NULL;
	init_pipex(&pipex);
	if (!valid_input(&pipex, av, envp, ac))
		return (free_error(&pipex, "ERROR"));
	pipex->in_fd = open(av[1], O_RDONLY, 0777);
	if (av[4][0] != '\0' && (access(av[4], F_OK) || !access(av[4], R_OK)))
		pipex->out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (access(av[4], W_OK))
		return (free_error(&pipex, "ERROR"));
	else
		return (free_error(&pipex, "ERROR"));
	dup2(pipex->in_fd, STDIN_FILENO);
	dup2(pipex->out_fd, STDOUT_FILENO);
	main_process(&pipex, envp);
	free_error(&pipex, NULL);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:47:18 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/03 16:59:41 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	char	**paths;
	char	**cmds;
}	t_pipex;

void	init_pipex(t_pipex **pipex);

/*		HANDLE ERRORS		*/

int		valid_input(t_pipex **pipex, char **av, char **envp, int size);
int		valid_cmds(t_pipex **pipex, char **av, char **envp, int size);
int		valid_args(t_pipex **pipex, char **av, char **envp, int size);
int		setcmds(t_pipex **pipex, char **av, char **paths, int size);

/*		FREE ALL		*/

int		free_error(t_pipex **pipex, char *error);
int		free_array(char **arr);
void	free_loop(char *s, char **paths, char **cmds, int j);

/*		EXECUTE		*/

int		exec(t_pipex **pipex, char **envp, int index);
int		child_process(t_pipex **pipex, char **envp, int *fd, pid_t *pid);
int		main_process(t_pipex **pipex, char **envp);

#endif

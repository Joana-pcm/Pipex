#ifndef	PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef	struct	s_pipex
{
	int		fd[2];
	int		here_doc;
	char	**paths;
	char	**cmds;
}	t_pipex;

void	init_pipex(t_pipex **pipex);
int	valid_input(t_pipex **pipex, char **av, int size);
int	valid_cmds(t_pipex **pipex, char **av, char **envp, int size);
int	valid_args(t_pipex **pipex, char **av,char **envp, int size);
int	free_error(t_pipex **pipex, char *error);


#endif

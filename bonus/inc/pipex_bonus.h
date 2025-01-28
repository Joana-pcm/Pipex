#ifndef	PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../../libft/libft.h"

typedef	struct	s_pipex
{
	int		in_fd;
	int		out_fd;
	int		here_doc;
	char	**paths;
	char	**cmds;
}	t_pipex;

void	init_pipex(t_pipex **pipex, int size);

/*		HANDLE ERRORS		*/

int	valid_input(t_pipex **pipex, char **av, int size);
int	valid_cmds(t_pipex **pipex, char **av, char **envp, int size);
int	valid_args(t_pipex **pipex, char **av,char **envp, int size);
int	setcmds(t_pipex  **pipex, char **av, char **paths, int size);
int	free_error(t_pipex **pipex, char *error);

/*		EXECUTE		*/

int	exec(t_pipex **pipex, char **envp, int	index, int size);
int	main_process(t_pipex **pipex, char **envp, int index, int size);
int	child_process(t_pipex **pipex, char **envp, int *fd, int index, int size);

#endif

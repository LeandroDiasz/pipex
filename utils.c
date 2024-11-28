/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 19:02:34 by ledias-d          #+#    #+#             */
/*   Updated: 2024-11-22 19:02:34 by ledias-d         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free (tab);
}

void	execute(char *av, char **envp)
{
	char	**myargs;
	char	*cmd_path;

	myargs = ft_split(av, ' ');
	if (!myargs || !myargs[0])
		error();
	cmd_path = find_path(myargs[0], envp);
	if (!cmd_path)
	{
		free_tab(myargs);
		error();
	}
	if (execve(cmd_path, myargs, envp) == -1)
	{
		free (cmd_path);
		free_tab(myargs);
		error();
	}
}

char	*find_path(char *myargs, char **envp)
{
	int		i;
	char	**mypaths;
	char	*cmd_path;
	char	*cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	mypaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (mypaths[i])
	{
		cmd = ft_strjoin(mypaths[i], "/");
		cmd_path = ft_strjoin(cmd, myargs);
		free(cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			free_tab(mypaths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_tab(mypaths);
	return (NULL);
}

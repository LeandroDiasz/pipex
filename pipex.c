/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 19:22:53 by ledias-d          #+#    #+#             */
/*   Updated: 2024-11-21 19:22:53 by ledias-d         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **av, char **envp, int *fd)
{
	int		infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
		error();
	if (dup2(fd[1], STDOUT_FILENO) == -1 || dup2(infile, STDIN_FILENO) == -1)
		error();
	close(fd[0]);
	close(fd[1]);
	close(infile);
	execute(av[2], envp);
}

void	parent(char **av, char **envp, int *fd)
{
	int		outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
		error();
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	execute(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		return (ft_putstr_fd("./pipex <file1> <cmd1> <cmd2> <file2>\n", 1), 1);
	if (pipe(fd) == -1)
		error();
	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
		child(av, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		error();
	if (pid2 == 0)
		parent(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

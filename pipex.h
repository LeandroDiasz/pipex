/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-16 20:21:28 by ledias-d          #+#    #+#             */
/*   Updated: 2024-11-16 20:21:28 by ledias-d         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	error(void);
void	execute(char *av, char **envp);
char	*find_path(char *av, char **envp);
void	free_tab(char **tab);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:51:44 by tleister          #+#    #+#             */
/*   Updated: 2025/01/02 12:22:28 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_fds	ft_checkinput(int argc, char **argv)
{
	t_fds	fds;

	fds.infile = open(argv[1], O_RDONLY);
	fds.outfile = open(argv[4], O_RDONLY | O_CREAT, 0644);
	fds.pipefds[0] = 0;
	fds.pipefds[1] = 0;
	if (argc != 5 || fds.infile == -1 || fds.outfile == -1)
		ft_error("input");
	return (fds);
}

char	*ft_buildpath(char *argv, char *envp)
{
}

void	ft_build_exec(char *argv, char *envp)
{
}

int	main(int argc, char **argv, char **envp)
{
	t_fds	fds;
	int		cpid;
	char	*path;

	fds = ft_checkinput(argc, argv);
	cpid = fork();
	if (cpid == -1)
		ft_error("fork");
	if (cpid == 0)
	{
		ft_build_exec(argv, envp);
		ft_error("execv");
	}
	waitpid(cpid, 0, 0);
	ft_build_exec(argv, envp, f);
	ft_error("execv");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:51:44 by tleister          #+#    #+#             */
/*   Updated: 2025/01/02 17:08:19 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	status(char *str)
{
	int	fd;

	fd = open("status", O_WRONLY | O_APPEND | O_CREAT, 0644);
	write(fd, ft_strjoin(str, "\n"), ft_strlen(str) + 1);
}

t_fds	ft_checkinput(int argc, char **argv)
{
	t_fds	fds;

	fds.infile = open(argv[1], O_RDONLY);
	fds.outfile = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	fds.pipefds[0] = -1;
	fds.pipefds[1] = -1;
	if (argc < 5 || fds.infile == -1 || fds.outfile == -1)
		ft_error("input");
	return (fds);
}

char	*ft_buildpath(char *arg, char **envp)
{
	int		i;
	char	**paths;
	char	*temp;
	char	*path;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) && envp[i])
		i++;
	if (!envp[i])
		ft_error("hä");
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, arg);
		free(temp);
		status(path);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

void	ft_build_exec(char *arg, char **envp, t_fds fds)
{
	char	*path;
	char	**split_arg;

	split_arg = ft_split(arg, ' ');
	path = ft_buildpath(split_arg[0], envp);
	execve(path, split_arg, envp);
	free(path);
	free_split(split_arg);
	ft_error("execve");
}

t_fds	ft_get_pipe(t_fds fds)
{
	if (close(fds.infile) == -1)
		ft_error("close");
	fds.infile = fds.pipefds[0];
	if (fds.pipefds[1] > 2)
	{
		if (close(fds.pipefds[1]) == -1)
			ft_error("close");
	}
	if (pipe(fds.pipefds) == -1)
		ft_error("pipe");
	return (fds);
}

t_fds	ft_exec_in(t_fds fds, char **argv, char **envp)
{
	int	cpid;

	if (pipe(fds.pipefds) == -1)
		ft_error("pipe");
	cpid = fork();
	if (cpid == -1)
		ft_error("fork");
	if (cpid == 0)
	{
		if (dup2(fds.infile, 0) == -1 || dup2(fds.pipefds[1], 1) == -1)
			ft_error("dup2");
		ft_build_exec(argv[2], envp, fds);
	}
	return (fds);
}

void	ft_exec_out(t_fds fds, char **argv, int argc, char **envp)
{
	int	cpid;

	cpid = fork();
	if (cpid == -1)
		ft_error("fork");
	if (cpid == 0)
	{
		if (dup2(fds.infile, 0) == -1 || dup2(fds.outfile, 1) == -1)
			ft_error("dup2");
		ft_build_exec(argv[argc - 2], envp, fds);
	}
	if (close(fds.outfile) == -1 || close(fds.infile) == -1)
		ft_error("close");
}

int	main(int argc, char **argv, char **envp)
{
	t_fds	fds;
	int		cpid;
	char	*path;
	int		i;

	unlink("error");
	unlink("status");
	fds = ft_checkinput(argc, argv);
	ft_exec_in(fds, argv, envp);
	i = 5;
	// while (argc > i)
	// {
	// 	fds = ft_get_pipe(fds);
	// 	cpid = fork();
	// 	if (cpid == -1)
	// 		ft_error("fork");
	// 	if (cpid == 0)
	// 	{
	// 		if (dup2(fds.infile, 0) == -1 || dup2(fds.pipefds[1], 1) == -1)
	// 			ft_error("dup2");
	// 		ft_build_exec(argv[i], envp, fds);
	// 	}
	// 	i++;
	// }
	ft_exec_out(fds, argv, argc, envp);
}

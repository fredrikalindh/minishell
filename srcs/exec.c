/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:37:25 by frlindh           #+#    #+#             */
/*   Updated: 2020/01/23 17:01:02 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0) //child
	{
		signal(SIGINT, SIG_DFL);
		if (execve(args[0], args) == -1)
		 	strerror(errno);
		exit(-1);
	}
	else if (pid < 0)
		strerror(errno);
	else
	{
		wpid = waitpid(pid, &status, WUNTRACTED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status)) // dooo smth
			;
	}
	return (1);
}

int		execute(char **args)
{

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 11:59:36 by frlindh           #+#    #+#             */
/*   Updated: 2020/02/18 19:40:14 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

void	put_error(char *errmess)
{
	ft_fprintf(2, "%s\n", errmess);
}

void	xecho(int fd, char **args)
{
	int n;

	if (ft_strcmp(*args, "-n") == 0 && (n = 1) == 1)
		args++;
	while (*args != NULL)
		ft_fprintf(fd, "%s", *args++);
	if (n != 1)
		ft_fprintf(fd, "\n");
}

void	xpwd(int fd, char **args)
{
	char	cwd[1024];

	getcwd(cwd, 1024);
	ft_fprintf(fd, "%s\n", cwd);
}

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
		while (!WIFEXITED(status) && !WIFSIGNALED(status)) // dooo smth killlll here?
			;
	}
	return (1);
}

void	xexit()
{
	ft_fprintf(1, "exit");
	exit (0);
}

void	xcd(char *args)
{
	if (args == NULL)
		chdir("/Users/frlindh"); // get from env list
	else
		if (chdir(args) != 0)
			put_error(strerror(errno));
}

int		execute(char **args)
{
	int i;

	i = -1;
	while (++i < BUILTINS)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
	}
	return launch(args);
}

int		main(int ac, char **av, char **ep)
{
	if (ac < 1)
		return (1);
	if (strcmp(av[1], "cd"))
		ft_cd(av);
	else
		execute(av);
}
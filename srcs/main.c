/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:13:58 by frlindh           #+#    #+#             */
/*   Updated: 2020/01/23 17:09:53 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (-1);
}

void	freem(char *line, char **arg)
{
	free(line);
	while (arg && *arg)
		free(*arg++);
}

char	*read_line() //replace with gnl ?
{
	char	*buf;
	int		i;
	char	c;
	int		size;
	// int		ret;

	i = 0;
	size = 1;
	if (!(buf = (char *)malloc(sizeof(BUFF_SIZE))))
		ft_error("allocation error\n");
	while (1)
	{
		read(0, &c, 1); // prob need to change for EOF
		if (c <= 0 && write(1, "\n", 1) > 0)
			exit(-1);
		if ((c == '\n' || c <= 0) && (buf[i] = '\0') == '\0') // use gnl ?
			return (buf);
		else
			buf[i++] = (char)c;
		if (i > BUFF_SIZE * size)
		{
			size++;
			if (!(buf = realloc(buf, BUFF_SIZE * size)))
				ft_error("allocation error\n");
		}
	}
}

void	sig_handler(int signo)
{
	(void)signo;
	write(1, "\n$> ", 4);
	// exit (-1);
}

void	loop(void)
{
	char	*line;
	char	**arg;
	int		status;

	status = 1;
	signal(SIGINT, sig_handler);
	// signal(SIGINT, SIG_IGN);
	while (status)
	{
		write(1, "$> ", 3);
		line = read_line();
		printf("[%s]\n", line);
		arg = parse(line);
		// status = execute(arg);
		// freem(line, arg);
	}
}

int		main(int ac, char *av[])
{
	(void)ac;
	(void)av;

	loop();
	return (0);
}
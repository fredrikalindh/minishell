/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:34:27 by frlindh           #+#    #+#             */
/*   Updated: 2020/02/17 15:16:16 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "./printf/ft.h"

void	put_error(char *errmess)
{
	ft_fprintf(2, "%s\n", errmess);
}

void	xecho(int fd, char **args)
{
	while (args != NULL)
		ft_fprintf(fd, "%s", *args++);
	ft_fprintf(fd, "\n");
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

int		main(int ac, char **av)
{

}
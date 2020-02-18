/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:48:08 by frlindh           #+#    #+#             */
/*   Updated: 2020/01/22 20:59:11 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **args)
{
	while (args && *args)
	{
		ft_printf("%s\n", *args);
		args++;
	}
}

void	cd(char **args)
{
	chdir(args[1]);
}

void	pwd(char **args)
{
	char	*name;
	int		size;

	size = 50;
	name = NULL;
	while (!name)
	{
		size *= 2;
		if (name = (char *)malloc(size))
			if (!(name = getcwd(name, size))) //leaks if too small?
				free(name);
	}
	ft_printf("%s\n", name);
}
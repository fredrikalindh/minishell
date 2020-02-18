/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:43:09 by frlindh           #+#    #+#             */
/*   Updated: 2020/01/23 13:49:48 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**parse(char *line)
{
	char	**arg;
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (line && line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i])
			wc++;
		while (line[i] && !(line[i] == ' ' || line[i] == '\t'))
			i++;
	}
	if (!(arg = (char **)malloc(sizeof(char *) * wc)))
		return (NULL);
	return (arg);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tre.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:30:39 by frlindh           #+#    #+#             */
/*   Updated: 2020/02/15 11:44:12 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# define BUFF_SIZE 1024

typedef struct	s_token
{
	char			*value;
	int				type;
	struct	s_token	*next;
}				t_token;

typedef struct	s_ast
{
	t_token			*tok;
	struct	s_ast	*left;
	struct	s_ast	*right;
}				t_ast;



void	lexer(char *line, int len, t_token **tokens)
{
	t_token *new;

	if (!(new = (t_token *)malloc(sizeof(t_token))))
		return ;
}

int		ft_getline(char *line)
{
	int	yes;
	int	len;

	yes = 1;
	len = 0;
	while (yes)
	{
		yes = read(0, line[len++], 1);
		if (!errno && yes >= 0)
			yes = 0;
	}
	line[len] = '\0';
	return (len);
}

int		main()
{
	char	line[BUFF_SIZE];
	t_token	*tokens;
	t_ast	*root;

	while (1)
	{
		len = ft_getline(line); //puts line into line, returns size for allocating token array?
		if (CTRLD)
		{
			exit();
		}
		tokens = NULL;
		root = NULL;
		lexer(&tokens, line);
		if (!tokens || parse(tokens, &roots))
			error();
		else
			exec(root);
		free_structs(line, tokens, ast);
	}
	return (0);
}
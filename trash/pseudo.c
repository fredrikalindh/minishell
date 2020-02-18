/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:29:59 by frlindh           #+#    #+#             */
/*   Updated: 2020/02/14 15:56:54 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





%union {
  WORD_DESC *word;		/* the word that we read. */
  int number;			/* the number that we read. */
  WORD_LIST *word_list;
  COMMAND *command;
  REDIRECT *redirect;
  ELEMENT element;
  PATTERN_LIST *pattern;
};

/* Reserved words.  Members of the first group are only recognized
   in the case that they are preceded by a list_terminator.  Members
   of the second group are for [[...]] commands.  Members of the
   third group are recognized only under special circumstances. */
%token IF THEN ELSE ELIF FI CASE ESAC FOR SELECT WHILE UNTIL DO DONE FUNCTION COPROC
%token COND_START COND_END COND_ERROR
%token IN BANG TIME TIMEOPT TIMEIGN

/* More general tokens. yylex () knows how to make these. */
%token <word> WORD ASSIGNMENT_WORD REDIR_WORD
%token <number> NUMBER
%token <word_list> ARITH_CMD ARITH_FOR_EXPRS
%token <command> COND_CMD
%token AND_AND OR_OR GREATER_GREATER LESS_LESS LESS_AND LESS_LESS_LESS
%token GREATER_AND SEMI_SEMI SEMI_AND SEMI_SEMI_AND
%token LESS_LESS_MINUS AND_GREATER AND_GREATER_GREATER LESS_GREATER
%token GREATER_BAR BAR_AND


/*
LEXICON::
	' " \	QUOTE
	; 		SEMI
	{ ( 	PARA
	<		REDIRL
	>		REDIRR
	>> 		REDIRRR
	|		PIPE
	$		DOLLAAA
	$?		DOLLAA\?
	"echo"	CMD / KEYWORD
	hello	WORD
	. .. ;
*/
/*
enum TokenType {
  // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

  EOF
};
*/


// TOKEN FUNCTONS
isatend()
peek() returns next token to eat;
current() returns current token to eat;
previous() returns last token to eaten; // doubly linked?
match()
advance()




typedef struct	s_token
{
	struct s_token		*next;
	char				*value;
	int					ivalue;
	enum TokenType {
	  // Single-character tokens.
	  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
	  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

	  // Literals.
	  IDENTIFIER, STRING, NUMBER,

	  EOF
  }name;
}				t_token;

typedef struct	s_ast
{
	t_token			token;
	struct s_ast	*l;
	struct s_ast	*r;
}				t_ast;

typedef struct	s_err
{
	bool		err;
	int			l;
}				t_err;


int		read_line(t_token *tokens) // purpose: READS command line into a linked list
{
	char	buf[100];
	int		i;
	int		ret;
	t_token	*new;

	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(0, buf + i++, 1);
		/* bla bla reads one character at a time in to buffer, when it reaches
		; <space> EOF <\n> or other IFS it mallocs the size in value part of token
		list and copies it there*/
		if (c == '\' || '\"')
			quote++;


		if (buf[i] = WHITECHAR)
		{
			if (!(new->value = (char *)malloc(i)))
				error("Couldn't allocate memory");
			new->value = strncpy(buf, i - 1);
			new->name = tokenize(new);
			i = 0;
			add_back(new, tokens);
		}
		/* tokenizing straight away?
		after value set, compare to token names and set*/
	}
}


void	loop(void)
{
	char *line; // buff_size?
	t_token *tokens;
	t_tree	*root;

	check_signal(SIG);
	token = NULL;
	while(1)
	{
		// prompt();
		write(1, "> ", 2);
		read_line(&tokens);
		parse(tokens, &tree);
		exec_tree(root);
	}
}

int		main(int ac, char *av[])
{
	if (ac > 1)
		load_files(av);
	loop();
	free_everything();
	return (0);
}







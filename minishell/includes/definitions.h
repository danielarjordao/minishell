#ifndef DEFINITIONS_H
# define DEFINITIONS_H
# include "minishell.h"

// ********************************* ERROR CODES ************************* //

typedef enum e_error_codes
{
	GENERAL_ERROR,
	CMD_NOT_FOUND,
	NO_FILE_DIRECTORY,
	PERMISSION_DENIED,
	AMBIGUOS_REDIRECT,
	IS_DIRECTORY,
	IS_NOT_DIRECTORY,
	TOO_MANY_ARGS,
	SYNTAX_ERROR
}	t_error_codes;

// ********************************* EXIT CODES ************************* //

# define EXIT_USAGE_SYNTAX_ERROR 2
# define EXIT_CMD_NOT_FOUND 127

// ********************************* TOKEN DEFINITIONS *********************** //


typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	ENV_VAR,
	FILENAME
}	t_token_type;

typedef enum e_token_quote
{
	NO_QUOTE,
	SINGLE,
	DOUBLE
}	t_token_quote;


#endif

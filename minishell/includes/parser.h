/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:01:24 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/10 19:06:45 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"

//parser.c
void		polish_list(t_shell *shell);
void		parser(t_shell *shell);

//parser_handlers.c
void		looking_for_here_doc(t_shell *shell);
void		looking_for_env_var(t_shell *shell);
void		looking_for_redir(t_shell *shell);
void		looking_d_quote(t_shell *shell);

//parser_handlers2.c
void		looking_for_cmd(t_shell *shell);
void		looking_for_cmd_args(t_shell *shell);
void		listjoin(t_shell *shell);
void		rm_space_token(t_shell *shell);

//parser_checkers.c
void		check_env_var(t_token *token, t_shell *shell);
void		check_exit_code(t_token *token, t_shell *shell);
char		*check_env_var_d_quote(t_shell *shell, char *data);

//parser_expand.c
void		expand_var(t_token *token, t_shell *shell);
char		*expand_var_d_quote(t_shell *shell, char *tmp, char *cmd, int *i);
char		*expand_exit_code(t_shell *shell, char *tmp);
char		*ft_getenv(t_list *envp_lst, char *name);

//parser_expand_utils.c
void		add_var_token(t_token **token, char *env_var, int j, int i);
void		check_var_space(char *env_var, t_token **token);

//parser_utils.c
void		split_token(t_token *token, int i);
void		add_next_char(char **str, char c);
t_token		*find_redir_file(t_token *tmp, t_token_type type);
void		skip_to_next_pipe(t_token **token);

#endif

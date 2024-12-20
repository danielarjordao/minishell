/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:13:37 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/29 11:13:50 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_CHECK_H
# define SYNTAX_CHECK_H
# include "minishell.h"

typedef enum redir_error
{
	NO_ARGS,
	R_OUT_ERROR,
	R_IN_ERROR,
	APPEND_ERROR,
	HEREDOC_ERROR,
	PIPE_ARG_ERROR
}	t_redir_error;

// syntax_check.c
int		syntax_check(char *cmd);
int		check_pipe(char *cmd);
int		check_quotes(char *cmd);
int		check_spaces(char *cmd);

// syntax_check_utils.c
int		ignore_quotes(char *cmd, int i);
int		is_redir(char c);
int		analyze_error_redir(char *cmd, int i);
void	msg_error_redir(int redir_check);

#endif

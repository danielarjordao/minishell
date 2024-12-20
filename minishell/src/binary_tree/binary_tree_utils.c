/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:08:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/08 20:09:34 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_redir_node_type(t_node_type node_type)
{
	if (node_type == REDIR_IN_NODE || node_type == REDIR_APPEND_NODE
		|| node_type == REDIR_OUT_NODE || node_type == HEREDOC_NODE)
		return (true);
	return (false);
}

bool	is_redir_token(t_token *token)
{
	if (!token)
		return (false);
	if (token->type == REDIR_IN || token->type == REDIR_APPEND
		|| token->type == REDIR_OUT || token->type == HEREDOC)
		return (true);
	return (false);
}

t_token	*get_next_pipe(t_token *token)
{
	while (token)
	{
		if (token->type == PIPE)
			return (token);
		token = token->next;
	}
	return (NULL);
}

int	count_args(t_token *token)
{
	int	i;

	i = 0;
	while (token->type != PIPE && token->type != NULL_TOKEN)
	{
		if (token->type == COMMAND || token->type == COMMAND_ARG)
			i++;
		token = token->next;
	}
	return (i);
}

char	**get_args(t_shell *shell, t_token *token)
{
	int		n_args;
	int		i;
	char	**args;

	n_args = count_args(token);
	if (n_args == 0)
		return (NULL);
	args = ft_calloc(n_args + 1, sizeof(char *));
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
			args, "Calloc failed");
	i = 0;
	while (i < n_args)
	{
		if (token->type == COMMAND || token->type == COMMAND_ARG)
		{
			args[i] = ft_strdup(token->data);
			if (!args[i])
				free_exit_error(shell, GENERAL_ERROR, "Calloc failed");
			i++;
		}
		token = token->next;
	}
	return (args);
}

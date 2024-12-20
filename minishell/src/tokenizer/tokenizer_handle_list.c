/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handle_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:16:40 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/08 12:10:44 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_token(t_shell **shell, char *data, enum e_token_type type, \
	enum e_token_quote quote)
{
	t_token	*new_token;
	t_token	*tmp;

	new_token = (t_token *)malloc(sizeof(t_token));
	new_token->data = data;
	new_token->env_var_name = NULL;
	new_token->type = type;
	new_token->quote = quote;
	if (!(*shell)->token)
	{
		(*shell)->token = new_token;
		(*shell)->token->i = 0;
		(*shell)->token->prev = NULL;
	}
	else
	{
		tmp = (*shell)->token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
		new_token->i = tmp->i + 1;
		new_token->prev = tmp;
	}
	new_token->next = NULL;
}

void	rm_token(t_token **token, t_shell *shell)
{
	t_token	*tmp;

	if (!token || !(*token))
		return ;
	tmp = *token;
	if (!tmp->prev)
		shell->token = tmp->next;
	else
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (tmp->data)
		free(tmp->data);
	if (tmp->env_var_name)
		free(tmp->env_var_name);
	free(tmp);
}

void	find_place(t_token **token, char *word, \
	t_token_quote quote, t_token_type type)
{
	t_token	*new_token;
	t_token	*tmp;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (check_malloc(new_token))
		return ;
	new_token->data = word;
	new_token->type = type;
	new_token->env_var_name = NULL;
	new_token->quote = quote;
	tmp = (*token)->next;
	(*token)->next = new_token;
	new_token->prev = *token;
	new_token->next = tmp;
	if (tmp)
		tmp->prev = new_token;
}

t_token	*last_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

void	clear_token_list(t_shell *shell)
{
	t_token	*tmp;

	while (shell->token)
	{
		tmp = shell->token;
		shell->token = shell->token->next;
		if (tmp->data)
			free(tmp->data);
		if (tmp->env_var_name)
			free(tmp->env_var_name);
		if (tmp)
			free(tmp);
	}
	shell->token = NULL;
}

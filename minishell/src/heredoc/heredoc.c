/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:30:21 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/01 17:30:22 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	save_heredoc_info(t_shell *shell)
{
	t_token		*tmp;
	t_heredoc	*tmp_hd;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
		{
			tmp_hd = shell->heredoc;
			if (tmp_hd->i == 0)
			{
				tmp_hd->i = 1;
				tmp_hd->eof = ft_strdup(tmp->next->data);
			}
			else
				assign_heredoc(&tmp_hd, tmp->next->data);
		}
		tmp = tmp->next;
	}
}

void	fill_fd_heredoc(t_heredoc *tmp_hd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (ft_strncmp(line, tmp_hd->eof, ft_strlen(tmp_hd->eof)) == 0)
		{
			free(line);
			break ;
		}
		write(tmp_hd->fd_heredoc, line, ft_strlen(line));
		write(tmp_hd->fd_heredoc, "\n", 1);
		free(line);
	}
}

void	heredoc(t_shell *shell)
{
	t_heredoc	*tmp_hd;
	char		*i;

	save_heredoc_info(shell);
	tmp_hd = shell->heredoc;
	while (tmp_hd)
	{
		i = ft_itoa(tmp_hd->i);
		tmp_hd->fd_heredoc_path = ft_strjoin("/tmp/tmp_heredoc", i);
		free(i);
		tmp_hd->fd_heredoc = \
			open(tmp_hd->fd_heredoc_path, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (tmp_hd->fd_heredoc < 0)
		{
			printf("Error: can't open tmp file\n");
			return ;
		}
		fill_fd_heredoc(tmp_hd);
		close(tmp_hd->fd_heredoc);
		tmp_hd = tmp_hd->next;
	}
}
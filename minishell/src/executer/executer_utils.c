/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:16:50 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 14:16:51 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	safe_fork(t_shell *shell, int fd[2])
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		msg_error(GENERAL_ERROR, "Fork failed");
		if (fd)
		{
			close(fd[0]);
			close(fd[1]);
		}
		free_all(shell);
	}
	return (pid);
}

//Important because can cause a problem when handling a msg_error
int	safe_access(const char *name, int type)
{
	int	ret;

	ret = access(name, type);
	errno = 0;
	return (ret);
}

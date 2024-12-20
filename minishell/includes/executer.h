/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:20:22 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 22:20:32 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H
# include "minishell.h"

//executer.c
void	executer(t_shell *shell, void *root);
void	execute_tree(t_shell *shell, void *root);
void	execute_root_node(t_shell *shell, void *root);

//executer_utils.c
int		safe_fork(t_shell *shell, int fd[2]);
int		safe_access(const char *name, int type);

//exec_builtin_execve.c
void	execute_builtin_or_execve(t_shell *shell, t_exec *exec, bool is_root);
int		get_child_status(int child_exit_status);

//exec_pipe.c
void	execute_pipe(t_shell *shell, t_pipe *pipe_node);

//exec_redir.c
int		execute_redirect(t_shell *shell, t_redir *redir, bool is_root);
void	execute_redir_root(t_redir *redir, t_shell *shell);

//execve.c
void	execute_execve(t_shell *shell, t_exec *exec);
char	**get_exported_env_vars(t_shell *shell, t_list *envp);

//execve_utils.c
char	**get_exported_env_vars(t_shell *shell, t_list *envp);
#endif

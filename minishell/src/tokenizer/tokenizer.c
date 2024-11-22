#include "../../includes/minishell.h"

void	tokenizer(char *cmd, t_shell *shell, int i)
{
	while (cmd[i])
	{
		if (cmd[i] == '\'')
			i = handle_s_quotes(cmd, i, shell);
		else if (cmd[i] == '\"')
			i = handle_d_quotes(cmd, i, shell);
		else if (cmd[i] == '|')
			i = handle_pipe(cmd, i, shell);
		else if (cmd[i] == '$')
			i = handle_env_var(cmd, i, shell);
		else if (cmd[i] == '>' && cmd[i + 1] == '>')
			i = handle_redir_append(cmd, i, shell);
		else if (cmd[i] == '<' && cmd[i + 1] == '<')
			i = handle_heredoc(cmd, i, shell);
		else if (cmd[i] == '<')
			i = handle_redir_in(cmd, i, shell);
		else if (cmd[i] == '>')
			i = handle_redir_out(cmd, i, shell);
		else if (ft_isspace(cmd[i]))
			i = handle_space(cmd, i, shell);
		else
			i = handle_word(cmd, i, shell);
		if (cmd[i])
			i++;
	}
}

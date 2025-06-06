/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <mevonuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:02:54 by mevonuk           #+#    #+#             */
/*   Updated: 2024/03/25 23:07:28 by ykawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Manages background execution of commands.
 * @param cmd t_cmd*: The command to be executed in the background.
 * @param shell t_shell*: The shell instance.
 * No return value.
 * Error: Background execution is not supported, prints an error message.
 */
void	manage_back(t_cmd *cmd, t_shell *shell)
{
	t_backcmd	*bcmd;

	bcmd = (t_backcmd *)cmd;
	ft_putendl_fd(ERR_BACKGROUND_NOT_SUPPORTED, STDERR_FILENO);
	if (check_tree(bcmd->cmd, shell) == 0)
		run_exec(bcmd->cmd, shell);
}

/**
 * Manages the execution of AND/OR command lists.
 * @param cmd t_cmd*: The command list to be executed.
 * @param shell t_shell*: The shell instance.
 * No return value.
 * Executes the left command and then the right command based on the exit
 * status of the left command and the type of the command (AND or OR).
 */
void	manage_andor(t_cmd *cmd, t_shell *shell)
{
	t_listcmd	*lcmd;

	lcmd = (t_listcmd *)cmd;
	run_exec(lcmd->left, shell);
	if (shell->exit_status == 0 && cmd->type == IFTHEN)
		run_exec(lcmd->right, shell);
	else if (shell->exit_status != 0 && cmd->type == IFOR)
		run_exec(lcmd->right, shell);
}

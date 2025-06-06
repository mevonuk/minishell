/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <mevonuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:14:00 by mevonuk           #+#    #+#             */
/*   Updated: 2024/03/25 23:08:45 by ykawakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Cleans up resources before exiting due to pipe failure.
 * @param shell The current shell instance.
 */
static void	ft_pipe_cleaner(t_shell *shell)
{
	clean_exit(shell);
	exit(1);
}

/**
 * Executes the child process part of a pipe.
 * @param pcmd The command to execute.
 * @param fd File descriptors for the pipe.
 * @param shell The current shell instance.
 */
static void	p_child(t_listcmd *pcmd, int fd[2], t_shell *shell)
{
	close(fd[0]);
	shell->is_inside_pipe = 1;
	shell->out_fd = fd[1];
	if (check_tree(pcmd->left, shell) == 0)
		run_exec(pcmd->left, shell);
}

/**
 * Executes the parent process part of a pipe.
 * @param pcmd The command to execute.
 * @param fd File descriptors for the pipe.
 * @param shell The current shell instance.
 */
static void	p_parent(t_listcmd *pcmd, int fd[2], t_shell *shell)
{
	close(fd[1]);
	if (shell->in_fd != STDIN_FILENO && shell->in_fd != -1)
		close(shell->in_fd);
	shell->is_inside_pipe = 1;
	shell->in_fd = fd[0];
	if (check_tree(pcmd->right, shell) == 0)
		run_exec(pcmd->right, shell);
}

/**
 * Manages the creation and execution of a pipe.
 * @param cmd The command structure containing the pipe.
 * @param shell The current shell instance.
 */
void	manage_pipe(t_cmd *cmd, t_shell *shell)
{
	t_listcmd	*pcmd;
	int			fd[2];
	int			pipe_pid;

	pcmd = (t_listcmd *)cmd;
	if (pipe(fd) < 0)
		ft_pipe_cleaner(shell);
	if (fork_child(shell) == 0)
	{
		p_child(pcmd, fd, shell);
		close(fd[1]);
		clean_exit(shell);
		exit(shell->exit_status);
	}
	else
	{
		pipe_pid = shell->pid;
		p_parent(pcmd, fd, shell);
		close(fd[0]);
		waitpid(pipe_pid, NULL, 0);
		clean_exit(shell);
		exit(shell->exit_status);
	}
}

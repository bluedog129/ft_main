/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:05:25 by hyojocho          #+#    #+#             */
/*   Updated: 2023/04/25 14:26:15 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	update_pwd(t_arraylist *env, t_arraylist *export, char *old_pwd_value)
{
	char	*pwd_value;
	char	*pwd;
	char	*old_pwd;

	apply_unset("OLDPWD", env, export);
	old_pwd = ft_strjoin("OLDPWD=", old_pwd_value);
	al_add_rear(env, old_pwd);
	al_add_rear(export, old_pwd);
	apply_unset("PWD", env, export);
	pwd_value = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", pwd_value);
	al_add_rear(env, pwd);
	al_add_rear(export, pwd);
	free(old_pwd_value);
	free(pwd_value);
}

static void	apply_cd(t_execute *execute, char *pwd_value)
{
	update_pwd(execute->env, execute->export, pwd_value);
	g_exit_code = 0;
	ft_printf("g_exit_code: %d\n", g_exit_code);
	pwd();
	print_export(execute->export, STDOUT_FILENO);
	env(execute->env, STDOUT_FILENO);
}

static int get_env_value(char *str, t_arraylist *envp)
{
	int		envp_idx;
	int		str_idx;

	envp_idx = 0;
	while (envp->data[envp_idx])
	{
		str_idx = 0;
		while (str[str_idx] == envp->data[envp_idx][str_idx])
			str_idx++;
		if (envp->data[envp_idx][str_idx] == '=' && str[str_idx] == '\0')
			return (SUCCESS);
		envp_idx++;
	}
	return (ERROR);
}

static int	check_home_dir(t_execute *execute)
{
	int	home_value;

	home_value = get_env_value("HOME", execute->env);
	if (home_value == ERROR)
	{
		ft_putstr_fd("bash: cd: HOME not set\n", 2);
		g_exit_code = 1;
		ft_printf("g_exit_code: %d\n", g_exit_code);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	count_args(char **args)
{
	int	args_count;

	args_count = 0;
	while (args[args_count])
		args_count++;
	return (args_count);
}

static char *get_target_value(char *str, t_arraylist *envp)
{
	int		envp_idx;
	int		str_idx;

	envp_idx = 0;
	while (envp->data[envp_idx])
	{
		str_idx = 0;
		while (str[str_idx] == envp->data[envp_idx][str_idx])
			str_idx++;
		if (envp->data[envp_idx][str_idx] == '=' && str[str_idx] == '\0')
			return (*(envp->data + envp_idx) + str_idx + 1);
		envp_idx++;
	}
	return (NULL);
}

void	cd(char **args, t_execute *execute)
{
	char	*pwd_value;
	int		args_count;
	
	args_count = count_args(args);
	if (args_count > 3)
	{
		ft_putstr_fd("bash: cd: too many arguments\n", 2);
		g_exit_code = 1;
		ft_printf("g_exit_code(too many): %d\n", g_exit_code);
		return ;
	}
	// apply_unset("HOME", execute->env, execute->export);
	if (check_home_dir(execute) == ERROR)
		return ;
	pwd_value = getcwd(NULL, 0);
	if (args[2] == NULL)
	{
		char	*home_value;
		
		// 1. get "HOME" value in env
		home_value = get_target_value("HOME", execute->env);
		// 2. change directory to "HOME" value
		chdir(home_value);
		pwd();
		return ;
	}
	if (chdir(args[2]) != 0)
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		free(pwd_value);
		g_exit_code = 1;
		ft_printf("g_exit_code(no such file): %d\n", g_exit_code);
		return ;
	}
	apply_cd(execute, pwd_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatice <hatice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:59:12 by hatice            #+#    #+#             */
/*   Updated: 2023/08/24 12:43:31 by hatice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	tot;
	int	i;

	tot = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		tot = tot * 10 + (str[i] - '0');
		i++;
	}
	return (tot);
}

int	ft_print_check_error(char *str)
{
	if (*str == '\0')
	{
		write(1, "Warning: The provided PID is empty.\n", 36);
		return (0);
	}
	if (*str == '-')
	{
		write(1, "Warning:", 8);
		write(1, "Please ensure that the pid provided is not negative.\n", 53);
		return (0);
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
		{
			write(1, "Warning:", 8);
			write(1, "The provided PID contains non-numeric characters\n", 50);
			return (0);
		}
	}
	return (1);
}

int	ft_check_error(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-')
		return (0);
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

void	ft_signal(int pid, char ch)
{
	char	bayt;
	int		ctl;

	ctl = 8;
	while (--ctl >= 0)
	{
		bayt = ch >> ctl;
		if (bayt & 1)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3 && ft_check_error(argv[1]))
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_signal(pid, argv[2][i]);
			i++;
		}
		ft_signal(pid, '\n');
	}
	else if (argc == 3 && !ft_check_error(argv[1]))
		ft_print_check_error(argv[1]);
	else
		write(1, "Error: The number of parameters is not 2.\n", 42);
	return (0);
}

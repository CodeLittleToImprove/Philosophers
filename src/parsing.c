/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:34:25 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/06/26 17:34:25 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

static	bool is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static	bool is_digit(char c)
{
	return (c >= '0' && c <='9');
}

static	const char *valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Only positive numbers allowed");
	if (!is_digit(*str))
		error_exit("Input contains not only digits");
	number = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		error_exit("The value is too big, INT_MAX is the limit");
	return (number);
}

static	long	ft_atol(const char *str)
{
	long num;

	num = 0;
	str = valid_input(str);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
		error_exit("The value is too big, INT_MAX is the limit");
	return (num);
}

void	parse_input(t_table *table, char *argv[])
{
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		error_exit("Use timestamps major than 60ms");
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	else
		table->nbr_limit_meals = -1;
}
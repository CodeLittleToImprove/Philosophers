/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:44:17 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/06/25 18:36:28 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;
	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argv);
//		data_init(&table);
//		dinner_start(&table);
//		clean(&table);
	}
	else
	{
		error_exit("Wrong input:\n"G"Correct is .philo 5 800 200 200 [5]");
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:44:37 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/06/25 18:35:41 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

/* input in this form number_of_philosophers	time_to_die		time_to_eat		time_to_sleep
[number_of_times_each_philosopher_must_eat]
or ./philo 5 800 200 200 [5]
*/
// Reset
#define RESET "\033[0m"

// Bold text colors
#define BLA "\033[1;30m"  // Black
#define R "\033[1;31m"  // Red
#define G "\033[1;32m"  // Green
#define Y "\033[1;33m"  // Yellow
#define B "\033[1;34m"  // Blue
#define M "\033[1;35m"  // Magenta
#define C "\033[1;36m"  // Cyan
#define W "\033[1;37m"  // White

typedef struct s_table	t_table;
typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	pthread_id;
	t_table		*table;
}	t_philo;

struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
};

//utils.c
void	error_exit(const char *error);

//parsing.c
void	parse_input(t_table *table, char *argv[]);
#endif

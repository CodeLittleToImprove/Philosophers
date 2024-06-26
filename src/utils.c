/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:19:36 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/06/26 17:19:36 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

//exit not allowed
void	error_exit(const char *error)
{
	printf(R "%s\n" RESET, error);
	exit(EXIT_FAILURE);
}
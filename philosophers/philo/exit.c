/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:38:27 by mthiry            #+#    #+#             */
/*   Updated: 2022/06/15 14:51:50 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	leave(t_rules *rules)
{
	int	i;
	int	er;

	i = 0;
	while (i < rules->nb_philo)
	{
		er = pthread_join(rules->philo[i].thread, NULL);
		if (er != 0)
			return (1);
		i++;
	}
	i = 0;
	er = pthread_mutex_destroy(&rules->data_race_checker);
	if (er != 0)
		return (1);
	while (i < rules->nb_philo)
	{
		er = pthread_mutex_destroy(&rules->forks[i]);
		if (er != 0)
			return (1);
		i++;
	}
	return (0);
}

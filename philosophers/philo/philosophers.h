/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:06:01 by mthiry            #+#    #+#             */
/*   Updated: 2022/06/15 15:07:56 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	long long		last_meal;
	struct s_rules	*rules;
	pthread_t		thread;
}	t_philo;

typedef struct s_rules
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_philo_eat;
	long long		base_timestamp;
	int				nb_philo_eat_all;
	bool			someone_died;
	pthread_mutex_t	data_race_checker;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_rules;

int			init_all(t_rules *rules, char **argv);
int			ft_processus(t_rules *rules);
int			death_checker(t_rules *rules);
int			eat_checker(t_rules *rules);
void		eating(t_philo *philo, t_rules *rules, int left_id, int right_id);
int			ft_atoi(const char *str);
long long	get_current_timestamp(void);
long long	time_diff(long long past, long long pres);
void		better_usleep(long long time, t_rules *rules);
void		print_action(t_rules *rules, int id, char *str);
int			leave(t_rules *rules);

#endif

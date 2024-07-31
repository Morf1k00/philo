/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:00:36 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/31 13:44:30 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h> //gettimeofday
# include <unistd.h> //usleep, write, 
# include <string.h> //memset
# include <stdio.h> //printf
# include <stdlib.h> //malloc, free
# include <pthread.h> //pthread_create, pthread_detach, 
//pthread_join, pthread_mutex_init, pthread_mutex_destroy,
//pthread_mutex_lock, pthread_mutex_unlock
# include <stdint.h> //uint64_t

typedef struct s_param
{
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	int				time_to_die;
	int				philo_nbr;
	int				check_sum;
	int				eated;
	int				ready;
	int				over;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
}				t_param;

typedef struct s_philo
{
	int				id;
	int				iter;
	long int		start;
	long int		meal;
	pthread_t		thread;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_param			*param;
}				t_philo;

int			ft_atoi(const char *str);
uint64_t	current_time(void);
void		*routine(void *phil);
t_param		*parse_line(char **argv);
void		join_threads(t_philo *philo);
void		create_threads(t_philo *philo);
void		init_thread(t_philo *philo, t_param *param);
void		init_philos(t_philo *philo, t_param *param);
void		ft_eat(t_philo *p);
void		*routine(void *phil);
void		ft_usleep(long int time);
void		print(t_philo *p, int i);
int			check_death(t_philo *p);
void		check_threds(t_philo *p);
int			ft_isdigit(int c);
int			arg_nbr(char *str);
int			check_input(char **argv);
void		free_all(t_philo *philo);

#endif
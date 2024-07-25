/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:00:36 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/25 15:28:20 by rkrechun         ###   ########.fr       */
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

typedef struct	s_param
{
	int				eat_time;
	int				sleep_time;
	int				think_time;
	int				eat_count;
	int				time_to_die;
	int				philo_nbr;
	int				fork_nbr;
	int				check_sum;
	int				eated;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
}				t_param;

typedef struct	s_philo
{
	int				id;
	int				iter;
	int				last_eat;
	int				start;
	int				ready;
	int 			over;
	pthread_t		thread;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_param			*param;
}				t_philo;


// typedef struct s_philo
// {
// 	int				ph; // number of philosophers
// 	int				fork; // number of forks
// 	int				last_eat;
// 	int 			eat_count; // number of eat 
// 	int				time_to_die; // time to die
// 	int 			time_to_eat; // time to eat
// 	int 			time_to_sleep; // time to sleep
// 	pthread_t		thread;
// 	pthread_mutex_t	*forks; // threads for forks
// 	pthread_mutex_t	*think; // threads for think
// 	pthread_mutex_t	*sleep; // threads for sleep
// 	pthread_mutex_t	*dead; // threads for dead
// }				t_philo;

// typedef	struct s_param
// {
// 	int				id;
// 	pthread_mutex_t	*forkl; // left fork
// 	pthread_mutex_t	*forkr; // right fork
// 	pthread_mutex_t	*think;
// 	pthread_mutex_t	*sleep;
// 	pthread_mutex_t	*dead;
// 	t_philo			*phil;
// }				t_param;

void	*ft_calloc(size_t nmemb, size_t size);
int	ft_atoi(const char *str);
uint64_t get_time(void);
uint64_t current_time(void);
void *routine (void *phil);

#endif
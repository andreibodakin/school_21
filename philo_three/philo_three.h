/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:11:34 by klavada           #+#    #+#             */
/*   Updated: 2021/01/19 15:11:42 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <signal.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

# define SUCCESS	0
# define ERROR		1
# define TAKE		2
# define EAT		3
# define SLEEP		4
# define THINK	 	5
# define DIED		6

struct s_phils;

typedef struct	s_phil
{
	int				id;
	int				eating;
	int				eat_count;
	int				eat_max;
	int				stop;
	size_t			eat_time_limit;
	size_t			eat_time_last;
	struct s_phils	*phils;
	sem_t			*semp;
	sem_t			*full;
	pthread_t		thread;
	pid_t			pid;
}				t_phil;

typedef struct	s_phils
{
	int				phils_nums;
	int				eat_nums;
	int				full_phils;
	int				stop;
	size_t			eat_time;
	size_t			die_time;
	size_t			sleep_time;
	size_t			base_time;
	t_phil			*arr;
	sem_t			*write;
	sem_t			*dead;
	sem_t			*forks;
	pthread_t		threads;
}				t_phils;

size_t			ft_strlen(char *str);
int				ft_atoi(char *str);
char			*ft_strdup(char *str);
char			*ft_itoa(unsigned long n);
int				exit_msg(char *msg, int	status);
void			clear_leaks(t_phils *one);
void			ft_take(t_phil *phil);
void			ft_eat(t_phil *phil);
void			ft_sleep(t_phil *phil);
void			*eat_limit_thread(void *param);
void			*check_dead(void *param);
void			*live_thread(void *param);
int				start_simulation(t_phils *one);
char			*get_status(int status);
void			print_time(unsigned long base_time);
void			print_status(int status);
void			ft_talk(t_phil *phil, int status);
unsigned long	ft_time(void);
void			exit_fatal(void);

#endif

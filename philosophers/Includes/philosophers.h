/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:35:40 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:36:06 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <libft.h>

	//define satut
# define	ALIVE		0
# define	THINK		1
# define	OWN_FORK	2
# define	RIGHT_FORK	3
# define	EAT			4
# define	SLEEP		5
# define	DEAD		6
# define	DONE		7

typedef struct s_philo t_philo;

typedef struct s_global
{
	int				statut;
	int				number_of_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo			**philo;
	pthread_t		thread_id_health;
	pthread_t		thread_id_start;
	pthread_mutex_t	print;
	pthread_mutex_t	start;
}				t_global;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				philo_id;
	int				statut;
	pthread_mutex_t	fork;
	long long		last_meal_timestamp;
	t_global		*global;
}				t_philo;

	//1_init_global.c
int			init_philo(t_global **global);	
int			fill_data(char *argv);
int			init_global(t_global **global, char **argv);

	//2_start_philo.c
void		*loop_philo(void *philo_void);
void    	*start_philo(void *global_void);

	//3_utils_philo.c
void   		right_fork(t_global	*global, int philo_id);
void    	own_fork(t_global	*global, int philo_id);
void    	eat_philo(t_philo *philo);
void    	sleep_philo(t_philo *philo);
void    	free_fork(t_global	*global, int philo_id);

	//4_end_philo.c
void    	sleep_check(t_global	*global, int statut);
void    	*loop_healt(void *global_void);
int 		wait_philo(t_global *global);

	//5_put_philo.c
int			put_error(int flag);
int			put_philo(t_philo *philo, int flag);
int			free_philo(t_global	*global, int error);
int			free_philo_2(t_global *global, int flag);

#endif

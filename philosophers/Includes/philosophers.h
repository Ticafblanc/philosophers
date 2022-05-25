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

	//define put
# define	FORK	1
# define	EAT		2
# define	SLEEP	3
# define	THINK	4
# define	DIED	5

	//define satut
# define	ALIVE	0
# define	DEAD	1

typedef struct s_arg
{
	int				statut;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_t		thread_id_health;
	pthread_t		thread_id_start;
	pthread_mutex_t	print;
	pthread_mutex_t	health;
	pthread_mutex_t	*fork;
}				t_arg;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				philo_id;
	long long		last_meal_timestamp;
	t_arg			*arg;
}				t_philo;

typedef struct s_global
{
	
	t_philo			**philo;
	t_arg			*arg;
	
}				t_global;

	//1_init_global.c
int			init_philo(t_global **global);	
int			fill_data(char *argv);
int			init_global(t_global **global, char **argv);

	//3_start_philo.c
void		*loop_philo(void *philo_void);
void    	*start(void *philo_void);
void    	*loop_healt(void *global_void);
void    	*start_philo(void *global_void);

	//5_end_philo.c
int 		wait_philo(t_global *global);

	//6_put_philo.c
int			put_error(int flag);
int			put_philo(t_philo *philo, int flag);
int			put_success(int flag);

	//7_free_philo.c
int			free_philo(t_global	*global, int error);
int			free_philo_2(t_global *global, int flag);

#endif

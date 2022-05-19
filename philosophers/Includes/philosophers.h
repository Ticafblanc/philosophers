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

# define T

# include <stdbool.h>
# include <pthread.h>
# include <libft.h>

typedef struct s_philo
{
	pthread_t	thread_id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
}				t_philo;

typedef struct s_arg
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	t_philo	**philo;	
}				t_arg;

	//0_main.c
int			fill_data(char *argv);
int			init_arg(t_arg **arg, char **argv);
void		put_error(int i);

	//1_launch_philo.c


	//1-1_check.c


	//2_init.c


	//4_put.c


	//5_move.c


	//6_utils.c

#endif

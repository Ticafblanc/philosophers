/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:29:46 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:30:06 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{
	t_global	*global;
	int			flag;

	flag = 0;
	if (argc < 5 || argc > 6) 
		return (put_error(flag));
	flag = init_global(&global, argv);
	if (flag)
		return (free_philo(global, flag));
	pthread_create(&global->arg->thread_id_health, NULL, loop_healt, global);
	flag = wait_philo(global);
	return (free_philo(global, flag));
}
//printf("number_of_philosophers = %d\ntime_to_die = %d\n", global->number_of_philosophers, global->time_to_die);
//	printf("time_to_eat = %d\ntime_to_sleep = %d\n", global->time_to_eat, global->time_to_sleep);
//	printf("number_of_times_each_philosopher_must_eat = %d\n", global->number_of_times_each_philosopher_must_eat);
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

void	put_error(int i)
{
	if (i == 0)
	{
		ft_putstr_fd("erreur argument\n", 2);
		ft_putstr_fd("argument:	-number_of_philosophers\n", 2);
		ft_putstr_fd("		-time_to_die\n", 2);
		ft_putstr_fd("		-time_to_eat\n", 2);
		ft_putstr_fd("		-time_to_sleep\n", 2);
		ft_putstr_fd(" (option)	-number_of_times_each_philosopher_must_eat", 2);
	}
	if (i = 1)
		ft_putstr_fd("fail init philo", 2);
}
	if (i == 2)
		ft_putstr_fd("fail launch thread philo", 2);
}

int	main(int argc, char **argv)
{
	t_arg	*arg;
	int		i;

	i = 0;
	if ((argc == 5 || argc == 6) && init_arg(&arg, argv) > 0)
	{
		i = 1
		if (init_philo(arg) > 0)
		{
			i = ?????;
			if (i > 0)
				return (EXIT_SUCCESS);
			ft_free_pp(arg->philo);
		}
		free (arg);
	}
	put_error(i);
	return (EXIT_FAILURE);
}
//printf("number_of_philosophers = %d\ntime_to_die = %d\n", arg->number_of_philosophers, arg->time_to_die);
		//printf("time_to_eat = %d\ntime_to_sleep = %d\n", arg->time_to_eat, arg->time_to_sleep);
		//printf("number_of_times_each_philosopher_must_eat = %d\n", arg->number_of_times_each_philosopher_must_eat);
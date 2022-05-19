#include <philosophers.h>

int	init_philo(t_arg *arg)
{
	int	id;

	id = 0;
	arg->philo = (t_arg **)malloc(arg->number_of_philosophers * sizeof(t_philo *) + 1);
	if (!arg->philo)
		return (-1);
	arg->philo[arg->number_of_philosophers + 1] = NULL;
	id = arg->number_of_philosophers;
	while (--id >= 0)
	{
		arg->philo[id] = (t_philo *)malloc(sizeof(t_philo));
		if (!arg->philo)
			return (-1);
		arg->philo[id]->time_to_die = 0;
		arg->philo[id]->time_to_eat = 0;
		arg->philo[id]->time_to_sleep = 0;
		if (pthread_create(&arg->philo[id]->thread_id, NULL, loop_philo, arg->philo[id]))
			return (-1);
	}
	return (1);
}

int	fill_data(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			i++;
		else
			return (-1);
	}
	return (ft_atoi(argv));
}

int	init_arg(t_arg **arg, char **argv)
{
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if (!(*arg))
		return (-1);
	(*arg)->number_of_philosophers = fill_data(argv[1]);
	(*arg)->time_to_die = fill_data(argv[2]);
	(*arg)->time_to_eat = fill_data(argv[3]);
	(*arg)->time_to_sleep = fill_data(argv[4]);
	if (argv[5])
		(*arg)->number_of_times_each_philosopher_must_eat = fill_data(argv[5]);
	else
		(*arg)->number_of_times_each_philosopher_must_eat = 0;
	if ((*arg)->number_of_philosophers < 2 || (*arg)->time_to_die < 0
		|| (*arg)->time_to_eat < 0 || (*arg)->time_to_sleep < 0
		|| (*arg)->number_of_times_each_philosopher_must_eat < 0)
	{
		free (*arg);
		return (-1);
	}
	return (1);
}
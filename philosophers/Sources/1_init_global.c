#include <philosophers.h>

int	init_philo(t_global **global)
{
	int	id;

	id = 0;
	(*global)->philo = (t_philo **)malloc(((*global)->arg->number_of_philosophers) * sizeof(t_philo *));
	if (!(*global)->philo)
		return (3);
	(*global)->arg->fork = (pthread_mutex_t *)malloc(((*global)->arg->number_of_philosophers) * sizeof(pthread_mutex_t));
	if (!(*global)->arg->fork)
		return (4);
	while (id < (*global)->arg->number_of_philosophers)
	{
		(*global)->philo[id] = (t_philo *)malloc(sizeof(t_philo));
		if (!((*global)->philo[id]))
			return (4);
		if (pthread_mutex_init(&((*global)->arg->fork[id]), NULL))
			return (5);
		(*global)->philo[id]->philo_id = id;
		(*global)->philo[id]->arg = (*global)->arg;
		id++;
	}
	return (0);
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

int	init_global(t_global **global, char **argv)
{
	(*global) = (t_global *)malloc(sizeof(t_global));
	(*global)->arg = (t_arg *)malloc(sizeof(t_arg));
	if (!(*global) || !(*global)->arg)
		return (1);
	(*global)->arg->statut = ALIVE;
	(*global)->arg->number_of_philosophers = fill_data(argv[1]);
	(*global)->arg->time_to_die = fill_data(argv[2]);
	(*global)->arg->time_to_eat = fill_data(argv[3]);
	(*global)->arg->time_to_sleep = fill_data(argv[4]);
	if (argv[5])
		(*global)->arg->number_of_times_each_philosopher_must_eat = fill_data(argv[5]);
	else
		(*global)->arg->number_of_times_each_philosopher_must_eat = -1;
	if ((*global)->arg->number_of_philosophers < 1 || (*global)->arg->time_to_die < 0
		|| (*global)->arg->time_to_eat < 0 || (*global)->arg->time_to_sleep < 0)
		return (2);
	if (pthread_mutex_init(&((*global)->arg->print), NULL))
			return (5);
	if (pthread_mutex_init(&((*global)->arg->health), NULL))
			return (5);
	return (init_philo(global));
}

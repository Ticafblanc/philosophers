#include <philosophers.h>

int	put_philo(t_philo *philo, int flag)
{
	if (philo->arg->statut == DEAD)
		return (1);
	pthread_mutex_lock(&philo->arg->print);
	printf("\nPhilo number = %d\n",philo->philo_id);
	if (flag == 0)
		printf("%lld %d  numbers of philosophers ready\nsimulation start => press enter\n", timestamp(), philo->arg->number_of_philosophers);
	else if (flag == 1)
		printf("%lld %d has taken a fork\n", timestamp(), philo->philo_id);
	else if (flag == 2 )
		printf("%lld %d is eating\n", timestamp(), philo->philo_id);
	else if (flag == 3)
		printf("%lld %d is sleeping\n", timestamp(), philo->philo_id);
	else if (flag == 4)
		printf("%lld %d is thinking\n", timestamp(), philo->philo_id);
	pthread_mutex_unlock(&philo->arg->print);
	return (0);
}

int	put_success(int flag)
{
	if (flag == 7)
		ft_putstr_fd("a philo is dead !!", 1);
	if (flag == 8)
		ft_putstr_fd("all the philosophers did ate !!", 1);
	return (EXIT_SUCCESS);
}

int	put_error(int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd("erreur argument\n", 2);
		ft_putstr_fd("argument:	-number_of_philosophers\n", 2);
		ft_putstr_fd("		-time_to_die\n", 2);
		ft_putstr_fd("		-time_to_eat\n", 2);
		ft_putstr_fd("		-time_to_sleep\n", 2);
		ft_putstr_fd(" (option)	-number_of_times_each_philosopher_must_eat", 2);
	}
	if (flag == 1)
		ft_putstr_fd("fail init global", 2);
	if (flag == 3 || flag == 4)
		ft_putstr_fd("fail init philo", 2);
	if (flag == 5)
		ft_putstr_fd("fail init mutex", 2);
	if (flag == 6)
		ft_putstr_fd("fail init thread", 2);
	return (EXIT_FAILURE);
}


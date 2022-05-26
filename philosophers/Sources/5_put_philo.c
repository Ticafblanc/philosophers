#include <philosophers.h>

void    put_success(t_global *global, int statut)
{
    pthread_mutex_lock(&global->print);
    if (statut == DEAD)
        printf("🕛%lld ⚰️the king is dead !!\n", timestamp());
    else if (statut == DONE)
        printf("🙅they have full bellies !!\n");
	pthread_mutex_unlock(&global->print);
}

int	put_philo(t_philo *philo, int statut)
{
	if (philo->global->statut == DEAD || philo->global->statut == DONE)
	{
		pthread_mutex_unlock(&philo->global->print);
		return (0);
	}
	pthread_mutex_lock(&philo->global->print);
	if (statut == OWN_FORK || statut == RIGHT_FORK)
		printf("🕛%lld 🤬%d has taken a 🍴fork\n", timestamp(), philo->philo_id);
	else if (statut == EAT )
		printf("🕛%lld 🤤%d is 🍗_🍗_🍗eating\n", timestamp(), philo->philo_id);
	else if (statut == SLEEP)
		printf("🕛%lld 😴%d is 🛌🏿sleeping\n", timestamp(), philo->philo_id);
	else if (statut == THINK)
		printf("🕛%lld 🤯%d is thinking\n", timestamp(), philo->philo_id);
	pthread_mutex_unlock(&philo->global->print);
	return (0);
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

int	free_philo_2(t_global *global, int flag)
{
	if (flag >= 4)
	{
		ft_free_pp((void **)global->philo);
		free (global);
		return (put_error(flag));
	}
	if (flag == 7 || flag == 8)
	{
		ft_free_pp((void **)global->philo);
		free (global);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
	
int	free_philo(t_global *global, int flag)
{
	if (flag == 1)
		return (put_error(flag));
	if (flag == 2)
	{
		free (global);
		return (put_error(0));
	}
	if (flag == 3)
	{
		free (global);
		return (put_error(flag));
	}
	return (free_philo_2(global, flag));
}
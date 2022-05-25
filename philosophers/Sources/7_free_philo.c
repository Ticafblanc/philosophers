#include <philosophers.h>

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
		return (put_success(flag));
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
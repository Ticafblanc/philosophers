#include <philosophers.h>

void	*loop_philo(void *philo_void)
{
	t_philo		*philo;

    philo = philo_void;
    philo->last_meal_timestamp = timestamp();
    pthread_mutex_lock(&philo->global->start);
    usleep(100);
    pthread_mutex_unlock(&philo->global->start);
	while (philo->global->statut == ALIVE
            && philo->global->number_of_times_each_philosopher_must_eat != 0)
    {
        put_philo(philo, philo->statut);
        sleep_check(philo->global, philo->statut);
        if (philo->statut == THINK && philo->global->statut == ALIVE)
            own_fork(philo->global, philo->philo_id);
        else if (philo->statut == OWN_FORK && philo->global->statut == ALIVE)
            right_fork(philo->global, philo->philo_id);
        else if (philo->statut == RIGHT_FORK && philo->global->statut == ALIVE)
            eat_philo(philo);
        else if (philo->statut == EAT && philo->global->statut == ALIVE)
             sleep_philo(philo);
        else if (philo->statut == SLEEP && philo->global->statut == ALIVE)
            philo->statut = THINK;
    }
    free_fork(philo->global, philo->philo_id);
    return (0);
}

void    *start_philo(void *global_void)
{
    t_global		*global;
    t_philo         **philo;
    int id;

    global = global_void;
    philo = global->philo;
    id = 0;
    pthread_mutex_lock(&global->start);
    while (id < global->number_of_philosophers)
    {
        pthread_create(&(philo[id]->thread_id), NULL, loop_philo, philo[id]);
        pthread_detach(global->philo[id]->thread_id);
        id++;
    }
    pthread_mutex_unlock(&global->start);
    return (0);
}



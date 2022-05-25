#include <philosophers.h>



void	*loop_philo(void *philo_void)
{
	t_philo		*philo;

    philo = philo_void;
    philo->last_meal_timestamp = timestamp();
    pthread_mutex_lock(&philo->arg->health);
    usleep(100);
    pthread_mutex_unlock(&philo->arg->health);
	while (philo->arg->statut == ALIVE)
    {
         put_philo(philo, THINK);
        pthread_mutex_lock(&(philo->arg->fork[philo->philo_id]));
        put_philo(philo, FORK);
        pthread_mutex_lock(&(philo->arg->fork[philo->philo_id + 1]));
        put_philo(philo, FORK);
        put_philo(philo, EAT);
        philo->last_meal_timestamp = timestamp();
        usleep(philo->arg->time_to_eat / 1000);
        philo->arg->number_of_times_each_philosopher_must_eat--;
        pthread_mutex_unlock(&(philo->arg->fork[philo->philo_id]));
        pthread_mutex_unlock(&(philo->arg->fork[philo->philo_id + 1]));
        usleep(philo->arg->time_to_sleep / 1000);
        put_philo(philo, SLEEP);
    }
    return (0);
}

void    *start_philo(void *global_void)
{
    t_global		*global;
    int id;

    global = global_void;
    id = 0;
    while (id < global->arg->number_of_philosophers)
    {
        printf("\nthread = %d\n", global->philo[id]->philo_id);
        pthread_create(&(global->philo[id]->thread_id), NULL, loop_philo, global->philo[id]);
        pthread_detach(global->philo[id]->thread_id);
        id++;
    }
    return (0);
}

void    *loop_healt(void *global_void)
{
    t_global		*global;
    int id;

    global = global_void;
    pthread_mutex_lock(&global->arg->health);
    pthread_create(&global->arg->thread_id_start, NULL, start_philo, global);
    pthread_join(global->arg->thread_id_start, NULL);
    pthread_mutex_unlock(&global->arg->health);
    while (global->arg->statut == ALIVE)
    {
        id = 0;
        while (id < global->arg->number_of_philosophers)
        {
            //printf("\ntimestamp = %lld\n valeur = %lld", timestamp(), global->philo[id]->last_meal_timestamp);
            if ((global->philo[id]->last_meal_timestamp + global->arg->time_to_die) < timestamp()
            || global->arg->number_of_times_each_philosopher_must_eat == 0)
            {
                global->arg->statut = DEAD;
                break;
            }
            id++;
        }
    }
    return (0);
}

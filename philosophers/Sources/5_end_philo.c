#include <philosophers.h>

int wait_philo(t_global *global)
{
    int         id;

    id = 0;
    pthread_join(global->arg->thread_id_health, NULL);
    printf("the king is dead");
    while (id < global->arg->number_of_philosophers)
    {
        pthread_mutex_destroy(&(global->arg->fork[id]));
    }
    pthread_mutex_destroy(&global->arg->print);
    pthread_mutex_destroy(&global->arg->health);
    if (global->arg->number_of_times_each_philosopher_must_eat == 0)
        return (8);
    return (7);
}
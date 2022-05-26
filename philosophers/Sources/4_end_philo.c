#include <philosophers.h>

void    sleep_check(t_global	*global, int statut)
{
    long long   end_time;

    if (statut == EAT)
    {
        end_time = timestamp() + global->time_to_eat;
        while (global->statut == ALIVE && end_time > timestamp())
        {
            usleep(100);
        }   
    }
    else if (statut == SLEEP)
    {
        end_time = global->time_to_sleep + timestamp();
        while (global->statut == ALIVE && end_time > timestamp())
        {
            usleep(100);
        }
    }
}

void    *loop_healt(void *global_void)
{
    t_global		*global;
    int id;

    global = global_void;
    pthread_join(global->thread_id_start, NULL);
    while (global->statut != DONE && global->statut != DEAD)
    {
        //printf("\ntimestamp = %lld\n statut = %d", timestamp(), global->statut);
        usleep(100000);
        id = 0;
        while (id < global->number_of_philosophers)
        {
            //printf("\ntimestamp = %lld\n time  = %lld", timestamp(), global->philo[id]->last_meal_timestamp + global->time_to_die);
            if ((global->philo[id]->last_meal_timestamp + global->time_to_die) < timestamp())
            {
                global->statut = DEAD;
                put_success(global, global->statut);
                return (0);
            }
            else if (global->number_of_times_each_philosopher_must_eat == 0)
            {
                global->statut = DONE;
                put_success(global, global->statut);
                return (0);
            }
            id++;
        }       
    }
    return (0);
}

int wait_philo(t_global *global)
{
    int         id;
    t_philo     **philo;

    id = 0;
    philo = global->philo;
    pthread_join(global->thread_id_health, NULL);
    //printf("\n\nglobal->statut = %d\n\n", global->statut);
    while (id < global->number_of_philosophers)
    {
        pthread_mutex_destroy(&(philo[id]->fork));
        id++;
    }
    //printf("\n\nglobal->statut = %d\n\n", global->statut);
    pthread_mutex_destroy(&global->print);
    pthread_mutex_destroy(&global->start);
    if (global->number_of_times_each_philosopher_must_eat == 0)
        return (8);
    return (7);
}
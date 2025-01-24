/*
** EPITECH PROJECT, 2024
** Cuncurrent programming
** File description:
** Panoramix
*/

#include "../libs/panoramix.h"

void error(char *str)
{
    printf("%s\n", str);
    exit(84);
}

void start_panoramix(Info_t info)
{
    Shared_variables_t *shared = malloc(sizeof(Shared_variables_t));
    pthread_mutex_t pot_access = PTHREAD_MUTEX_INITIALIZER;

    shared->pot_access = pot_access;
    shared->pot = info.pot_size;
    sem_init(&shared->signal_villager, 0, 0);
    sem_init(&shared->signal_druid, 0, 0);
    create_druid_thread(shared, info);
    create_villager_threads(shared, info);
    sem_destroy(&shared->signal_druid);
    sem_destroy(&shared->signal_villager);
}

int main(int argc, char const *argv[])
{
    Info_t info;

    if (argc == 5) {
        info.nb_villagers = atoi(argv[1]);
        info.pot_size = atoi(argv[2]);
        info.nb_fights = atoi(argv[3]);
        info.nb_refills = atoi(argv[4]);
        if (info.nb_villagers <= 0 || info.pot_size <= 0 ||
            info.nb_fights <= 0 || info.nb_refills <= 0)
            error("Values must be > 0.\n");
        else
            start_panoramix(info);
    } else {
        exit(84);
    }
}

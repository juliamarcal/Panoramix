/*
** EPITECH PROJECT, 2024
** Cuncurrent programming
** File description:
** Panoramix
*/

#include "../../libs/panoramix.h"

void druid_thread(void *arg)
{
    int i;
    Druid_t pointer = *((Druid_t *)arg);
    Druid_t druid_info = {pointer.shared, pointer.info,
        pointer.nb_refils_left};

    druid_thread_starts_m();
    while (druid_info.nb_refils_left != 0) {
        sem_wait(&druid_info.shared->signal_druid);
        druid_info.shared->pot = druid_info.info.pot_size;
        druid_info.nb_refils_left = druid_info.nb_refils_left - 1;
        druid_refil_pot_m(druid_info.nb_refils_left);
        for (i = 0; i < druid_info.info.nb_villagers; i++) {
            sem_post(&druid_info.shared->signal_villager);
        }
    }
    druid_end_m();
}

void create_druid_thread(Shared_variables_t *shared, Info_t info)
{
    pthread_t thread;
    Druid_t *druid_info = malloc(sizeof(Druid_t));

    druid_info->shared = shared;
    druid_info->nb_refils_left = info.nb_refills;
    druid_info->info = info;
    if (pthread_create(&thread, NULL, (void *)druid_thread,
        (void *)druid_info) != 0) {
            fprintf(stderr, "Error creating thread for druid\n");
            exit(EXIT_FAILURE);
    }
}

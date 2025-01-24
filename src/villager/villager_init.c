/*
** EPITECH PROJECT, 2024
** Cuncurrent programming
** File description:
** Panoramix
*/

#include "../../libs/panoramix.h"

int check_pot_empty(int pot)
{
    return (pot == 0);
}

void villager_fight(Villager_t *villager_info)
{
    villager_info->nb_fights_left = villager_info->nb_fights_left - 1;
    villager_is_fighting_m(villager_info->id,
        villager_info->nb_fights_left);
}

void villager_thread(void *arg)
{
    Villager_t pointer = *((Villager_t *)arg);
    Villager_t villager_info = {pointer.shared, pointer.nb_fights_left,
        pointer.id};

    villager_thread_starts_m(villager_info.id);
    while (villager_info.nb_fights_left != 0) {
        pthread_mutex_lock(&villager_info.shared->pot_access);
        villager_try_potion_m(villager_info.id, villager_info.shared->pot);
        if (check_pot_empty(villager_info.shared->pot) != 0) {
            villager_call_druid_for_refil_m(villager_info.id);
            sem_post(&villager_info.shared->signal_druid);
            sem_wait(&villager_info.shared->signal_villager);
        }
        villager_info.shared->pot = villager_info.shared->pot - 1;
        pthread_mutex_unlock(&villager_info.shared->pot_access);
        villager_fight(&villager_info);
    }
    villager_done_with_fights_m(villager_info.id);
}

void create_villager_threads(Shared_variables_t *shared, Info_t info)
{
    pthread_t thread[info.nb_villagers];
    int i;
    Villager_t *villager_struct;

    for (i = 0; i < info.nb_villagers; i++) {
        villager_struct = malloc(sizeof(Villager_t));
        villager_struct->shared = shared;
        villager_struct->nb_fights_left = info.nb_fights;
        villager_struct->id = i;
        if (pthread_create(&thread[i], NULL, (void *)villager_thread,
            (void *)villager_struct) != 0) {
            fprintf(stderr, "Error creating thread for villager %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0; i < info.nb_villagers; i++) {
        pthread_join(thread[i], NULL);
    }
}

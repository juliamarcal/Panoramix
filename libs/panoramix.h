/*
** EPITECH PROJECT, 2024
** Cuncurrent programming
** File description:
** Panoramix
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#pragma once

// --------------------------- panoramix -------------------------- //
typedef struct Info_t {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} Info_t;

typedef struct Shared_variables_t {
    sem_t signal_villager;
    sem_t signal_druid;
    pthread_mutex_t pot_access;
    int pot;
} Shared_variables_t;

void start_panoramix(Info_t info);

// --------------------------- villager --------------------------- //
typedef struct Villager_t {
    Shared_variables_t *shared;
    int nb_fights_left;
    int id;
} Villager_t;

// functions
void create_villager_threads(Shared_variables_t *semaphore, Info_t info);

void villager_thread(void *arg);

// messages
void villager_call_druid_for_refil_m(int id);
void villager_is_fighting_m(int id, int fights_left);
void villager_done_with_fights_m(int id);
void villager_thread_starts_m(int id);
void villager_try_potion_m(int id, int num_servings);


// ---------------------------- druid ----------------------------- //
typedef struct Druid_t {
    Shared_variables_t *shared;
    Info_t info;
    int nb_refils_left;
} Druid_t;


// functions
void create_druid_thread(Shared_variables_t *shared, Info_t info);
void druid_thread(void *arg);

// messages
void druid_thread_starts_m(void);
void druid_refil_pot_m(int refils);
void druid_end_m(void);

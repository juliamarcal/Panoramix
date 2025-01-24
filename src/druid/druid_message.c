/*
** EPITECH PROJECT, 2024
** Cuncurrent programming
** File description:
** Panoramix
*/

#include "../../libs/panoramix.h"

void druid_thread_starts_m(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

void druid_refil_pot_m(int refils)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
    printf("Beware I can only make %i more refills after this one.\n", refils);
}

void druid_end_m(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}

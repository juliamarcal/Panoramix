/*
** EPITECH PROJECT, 2024
** Cuncurrent programming
** File description:
** Panoramix
*/

#include "../../libs/panoramix.h"

void villager_thread_starts_m(int id)
{
    printf("Villager %i: Going into battle!\n", id);
}

void villager_try_potion_m(int id, int num_servings)
{
    printf("Villager %i: I need a drink... I see %i servings left.\n",
        id, num_servings);
}

void villager_call_druid_for_refil_m(int id)
{
    printf("Villager %i: Hey Pano wake up! We need more potion.\n", id);
}

void villager_is_fighting_m(int id, int fights_left)
{
    printf("Villager %i: Take that roman scum! Only %i left.\n",
        id, fights_left);
}

void villager_done_with_fights_m(int id)
{
    printf("Villager %i: I'm going to sleep now.\n", id);
}

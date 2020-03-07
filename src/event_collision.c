/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include "my.h"
#include "duck_hunth.h"

void is_duck_collision(duck_t *duck, carrot_arr_t *carrot_arr)
{
    sfVector2f pos_carrot;
    int i = -1;

    while (++i < 5) {
        pos_carrot = sfSprite_getPosition(carrot_arr->carrot[i]->sprite);
        if (carrot_arr->carrot_status[i] == 2 &&
            pos_carrot.y < duck->pos.y + duck->rect.height &&
            pos_carrot.y > duck->pos.y &&
            ((pos_carrot.x < duck->pos.x + duck->rect.width &&
            pos_carrot.x > duck->pos.x && duck->speed > 0) ||
            (pos_carrot.x > duck->pos.x - duck->rect.width &&
            pos_carrot.x < duck->pos.x && duck->speed < 0))) {
            carrot_arr->carrot_status[i] = 1;
            reset_carrot(carrot_arr->carrot[i]);
            sfSound_play(duck->eat_sound);
            duck->gestation_time += 1;
        }
    }
}

void is_bird_collision(bird_t *bird, seed_arr_t *seed_arr)
{
    sfVector2f pos_seed;
    int i = -1;

    while (++i < 5) {
        pos_seed = sfSprite_getPosition(seed_arr->seed[i]->sprite);
        if (seed_arr->seed_status[i] == 2 &&
            pos_seed.y < bird->pos.y + bird->rect.height &&
            pos_seed.y > bird->pos.y &&
            ((pos_seed.x < bird->pos.x + bird->rect.width &&
            pos_seed.x > bird->pos.x && bird->speed > 0) ||
            (pos_seed.x > bird->pos.x - bird->rect.width &&
            pos_seed.x < bird->pos.x && bird->speed < 0))) {
            seed_arr->seed_status[i] = 1;
            reset_seed(seed_arr->seed[i]);
            sfSound_play(bird->eat_sound);
            bird->gestation_time += 1;
        }
    }
}

void is_collid_able(entity_t *entity, ammo_t *ammo)
{
    int i = -1;

    while (++i < entity->duck_arr->duck_nb) {
        if (entity->duck_arr->duck_status[i] == 1) {
            is_duck_collision(entity->duck_arr->duck[i],
                ammo->carrot_arr);
        }
    }
    i = -1;
    while (++i < entity->bird_arr->bird_nb) {
            if (entity->bird_arr->bird_status[i] == 1) {
                is_bird_collision(entity->bird_arr->bird[i],
                    ammo->seed_arr);
            }
        }
}
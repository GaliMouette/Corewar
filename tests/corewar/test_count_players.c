/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_count_players
*/

#include "corewar/init/count_players.h"
#include <criterion/criterion.h>

Test(count_players, game_With_Four_Players)
{
    init_t init = INIT;

    init.champs[0].path = "path";
    init.champs[1].path = "path";
    init.champs[2].path = "path";
    init.champs[3].path = "path";
    cr_assert_eq(count_players(&init), 4);
}

Test(count_players, game_With_Any_Player)
{
    init_t init = INIT;

    init.champs[0].path = NULL;
    init.champs[1].path = NULL;
    init.champs[2].path = NULL;
    init.champs[3].path = NULL;
    cr_assert_eq(count_players(&init), 0);
}

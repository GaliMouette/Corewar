/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_check_prog_overlap
*/

#include "corewar/init/adresses/check_prog_overlap.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(check_prog_overlap, any_Overlap)
{
    init_t init = INIT;

    init.champs[0].load_address = 0;
    init.champs[0].header.prog_size = 10;
    init.champs[0].path = "path";
    init.champs[1].load_address = 10;
    init.champs[1].header.prog_size = 10;
    init.champs[1].path = "path";
    init.champs[2].load_address = 20;
    init.champs[2].header.prog_size = 10;
    init.champs[2].path = "path";
    cr_assert_eq(check_prog_overlap(&init), 0);
}

Test(check_prog_overlap, overlap_Two_On_One, .init=redirect_all_stderr)
{
    init_t init = INIT;

    init.champs[0].load_address = 0;
    init.champs[0].header.prog_size = 10;
    init.champs[0].path = "path";
    init.champs[1].load_address = 1;
    init.champs[1].header.prog_size = 10;
    init.champs[1].path = "path";
    cr_assert_eq(check_prog_overlap(&init), 1);
}

Test(check_prog_overlap, overlap_One_On_Two, .init=redirect_all_stderr)
{
    init_t init = INIT;

    init.champs[0].load_address = 1;
    init.champs[0].header.prog_size = 10;
    init.champs[0].path = "path";
    init.champs[1].load_address = 0;
    init.champs[1].header.prog_size = 10;
    init.champs[1].path = "path";
    cr_assert_eq(check_prog_overlap(&init), 1);
}

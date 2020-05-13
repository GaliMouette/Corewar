/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** test_check_files
*/

#include "corewar/init/files/check_files.h"
#include <criterion/criterion.h>

void redirect_all_stderr(void);

Test(check_files, missing_Champion, .init=redirect_all_stderr)
{
    init_t init = INIT;

    init.champs[0].load_address = 3453;
    init.champs[0].number = 1;
    init.champs[1].load_address = 5421;
    init.champs[1].number = 2;
    cr_assert_eq(check_files(&init), 1);
}

Test(check_files, wrong_File_Format, .init=redirect_all_stderr)
{
    init_t init = INIT;

    init.champs[0].load_address = 3453;
    init.champs[0].number = 1;
    init.champs[0].path = "yes.c";
    init.champs[1].load_address = 5421;
    init.champs[1].number = 2;
    init.champs[1].path = "hello.cor";
    cr_assert_eq(check_files(&init), 1);
}

Test(check_files, good_Files)
{
    init_t init = INIT;

    init.champs[0].load_address = 3453;
    init.champs[0].number = 1;
    init.champs[0].path = "yes.cor";
    init.champs[1].load_address = 5421;
    init.champs[1].number = 2;
    init.champs[1].path = "hello.cor";
    cr_assert_eq(check_files(&init), 0);
}

Test(check_files, wrong_Format_With_More_Cor, .init=redirect_all_stderr)
{
    init_t init = INIT;

    init.champs[0].load_address = 3453;
    init.champs[0].number = 1;
    init.champs[0].path = "yes.cor.cor.c";
    init.champs[1].load_address = 5421;
    init.champs[1].number = 2;
    init.champs[1].path = "hello.cor";
    cr_assert_eq(check_files(&init), 1);
}

Test(check_files, test_If_Missing_Champs)
{
    init_t init = INIT;

    init.champs[0].number = 2;
    init.champs[0].path = "yes.cor";
    cr_assert_eq(check_files(&init), 0);
}

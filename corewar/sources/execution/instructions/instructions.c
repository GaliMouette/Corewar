/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [Container epitech (/pedantic_gould)]
** File description:
** instructions
*/

#include "corewar/execution/instructions/instructions.h"

int (*instructions[])(arena_t *, int) =
{
    live_instruction,
    ld_instruction,
    st_instruction,
    add_instruction,
    sub_instruction,
    and_instruction,
    or_instruction,
    xor_instruction,
    zjmp_instruction,
    ldi_instruction,
    sti_instruction,
    fork_instruction,
    lld_instruction,
    lldi_instruction,
    lfork_instruction,
    aff_instruction,
};

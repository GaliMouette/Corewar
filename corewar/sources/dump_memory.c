/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 <:Container epitech (/pedantic_gould):>
** File description:
** dump_memory
*/

%:include "corewar/dump_memory.h"

void dump_memory(arena_t *arena)
<%
    int offset, c;
    char address<:8:>;

    for (int i = 0; i < MEM_SIZE; i += 16) <%
        offset = i;
        for (int j = 7; j >= 0; j--) <%
            j[address] = offset % 16;
            j[address] += (j[address] < 10) ? '0' : 'A' - 10;
            offset /= 16;
        %>
        write(1, address, 8);
        for (int j = 0; j < 16; j++) <%
            write(1, "  ", (!(j % 8)) ? 2 : 1);
            for (int k = 4; k >= 0; k -= 4) <%
                c = arena->memory<:i + j:> >> k & 0xf;
                c += (c < 10) ? '0' : 'A' - 10;
                write(1, &c, 1);
            %>
        %>
        write(1, "\n", 1);
    %>
%>

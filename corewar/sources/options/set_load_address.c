/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** set_load_address
*/

#include "corewar/options/set_load_address.h"

int set_load_address(char const *arg, int *i, init_t *init, int index)
{
    if (check_error(arg, init, index)) {
        return 1;
    }
    init->champs[index].load_address = (int) my_strtol(arg, 16);
    *i += 1;
    return 0;
}

static int check_error(char const *arg, init_t *init, int index)
{
    if (-1 != init->champs[index].load_address) {
        write(2, "Multiple definition -a option.\n", 31);
        return 1;
    }
    if (!arg) {
        write(2, "Missing argument for -a option.\n", 32);
        return 1;
    }
    if (arg[0] == '-') {
        write(2, "Argument of -a option cannot be negative.\n", 42);
        return 1;
    }
    if (is_hex(arg)) {
        write(2, "Argument of -a option is not hexadecimal.\n", 42);
        return 1;
    }
    return 0;
}

static int is_hex(char const *arg)
{
    for (int i = 0; arg[i]; i++) {
        if (!('0' <= arg[i] && arg[i] <= '9')
        &&  !('A' <= arg[i] && arg[i] <= 'F')
        &&  !('a' <= arg[i] && arg[i] <= 'f')) {
            return 1;
        }
    }
    return 0;
}

/*
2j = 0 , 6144/2 //TODO
2j = x , 6144/2 + X //TODO
2j = x, y //TODO

3j = 0, 6144/3, 2(6144/3) //TODO
3j = x, 6144/3 + x, 2(6144/3) + x //TODO
3j = x, y, (y - x > x - y) ? x + (x - y) / 2 : y + (y - x) / 2
3j = x, y, z //TODO

4j = 0, 6144/4, 2(6144/4), 3(6144/4)//TODO
4j = x, 6144/4 + x, 2(6144/4) + x, 3(6144/4) + x //TODO
4j = x, y, (y - x > x - y) ? x + (x - y) / 2 : y + (y - x) / 2,
4j = x, y, z, x + (y - x)/2 | y + (z - y)/2 | z + (x - z)/2
4j = x, y, z, w //TODO
*/

/*
2j = 0 , 6144/2 //TODO
2j = x , 6144/2 + X //TODO
2j = x, y //TODO

3j = 0, 6144/3, 2(6144/3) //TODO
3j = x, 6144/3 + x, 2(6144/3) + x //TODO
3j = x, y, (y - x > (6144 - y + x)) ? x + (y - x) / 2 : y + (6144 - y + x) / 2 //TODO

3j = x, y, z //TODO

4j = 0, 6144/4, 2(6144/4), 3(6144/4)//TODO
4j = x, 6144/4 + x, 2(6144/4) + x, 3(6144/4) + x //TODO
4j = x, y , (y - x > (6144 - y + x)) ? x + (y - x) / 2 : y + (6144 - y + x) / 2
, if ((6144 - z + x) > ((y - x > (z - y)) ? x + (y - x) / 2 : y + (z - y) / 2))
        z + (6144 - z + x) / 2


4j = x, y, z, if ((6144 - z + x) > ((y - x > (z - y)) ? x + (y - x) / 2 : y + (z - y) / 2))
                    z + (6144 - z + x) / 2

choix = x > y ? x : y > z ? y : z;
((((choix == x) ? 6144 : 0) - x + y) > (((choix == y) ? 6144 : 0) - y + z)) ? x + (((choix == x) ? 6144 : 0) - x + y) / 2 : (z - y > (((choix == z) ? 6144 : 0) - z + x)) ?  y + (((choix == y) ? 6144 : 0) - y + z) / 2) : z + (((choix == z) ? 6144 : 0) - z + x) / 2
x %= 6144;
    y %= 6144;
    z %= 6144;
    int choix = (x > y) ? x : (y > z) ? y : z;
    int new = ((((choix == x) ? 6144 : 0) - x + y) > (((choix == y) ? 6144 : 0) - y + z)) ? x + (((choix == x) ? 6144 : 0) - x + y) / 2 : ((((choix == y) ? 6144 : 0) - y + z) > (((choix == z) ? 6144 : 0) - z + x)) ?  y + (((choix == y) ? 6144 : 0) - y + z) / 2 : z + (((choix == z) ? 6144 : 0) - z + x) / 2;
    printf("x = %d\ny = %d\nz = %d\nnew = %d\n", x, y, z, new);

4j = x, y, z, w //TODO
*/

//TODO appliqué le modulo dès le début

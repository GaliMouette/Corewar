/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** bswap.h
*/

#ifndef BSWAP_H_
#define BSWAP_H_

#include <stdint.h>

#define BSWAP_SHORT(x) \
((uint16_t) (((x >> 8) & 0xff) | ((x & 0xff) << 8)))


#define BSWAP_INT(x) \
((uint32_t) ((x & 0xff000000u) >> 24) | ((x & 0x00ff0000u) >> 8) \
| ((x & 0x0000ff00u) << 8) | ((x & 0x000000ffu) << 24))


#define BSWAP_LONG(x) \
((uint64_t) ((x & 0xff00000000000000ull) >> 56) \
| ((x & 0x00ff000000000000ull) >> 40) \
| ((x & 0x0000ff0000000000ull) >> 24) \
| ((x & 0x000000ff00000000ull) >> 8) \
| ((x & 0x00000000ff000000ull) << 8) \
| ((x & 0x0000000000ff0000ull) << 24) \
| ((x & 0x000000000000ff00ull) << 40) \
| ((x & 0x00000000000000ffull) << 56))

#endif /* !BSWAP_H_ */

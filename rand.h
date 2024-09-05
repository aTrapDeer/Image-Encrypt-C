#ifndef RAND_H
#define RAND_H

#include <stdint.h>

uint32_t rnd_get(const uint32_t y, const uint8_t i, const uint32_t m);
uint64_t generate_encrypted_value(uint32_t seed1, uint32_t seed2);

#endif

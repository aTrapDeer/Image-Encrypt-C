#include <stdio.h>
#include "rand.h"

static const uint32_t V0[] = { /* V0 array values */ };
static const uint32_t V1[] = { /* V1 array values */ };
static const uint32_t V2[] = { /* V2 array values */ };
static const uint32_t V3[] = { /* V3 array values */ };

uint32_t rnd_get(const uint32_t y, const uint8_t i, const uint32_t m)
{
    uint32_t v0, v1, v2, v3;
    uint8_t y0, y1, y2, y3;

    y0 = (uint8_t)(y);
    y1 = (uint8_t)(y >> 8);
    y2 = (uint8_t)(y >> 16);
    y3 = (uint8_t)(y >> 24);

    v0 = V0[y0 + i];
    v1 = V1[y1 + i];
    v2 = V2[y2 + i];
    v3 = V3[y3 + i];

    return (v0 ^ v1 ^ v2 ^ v3) % m;
}

uint64_t generate_encrypted_value(uint32_t seed1, uint32_t seed2)
{
    uint64_t result = 0;
    uint32_t temp;

    for (int i = 0; i < 5; i++) {
        temp = rnd_get(seed1, i, 100000);
        result = result * 100000 + temp;
        
        temp = rnd_get(seed2, i, 100000);
        result = result * 100000 + temp;
    }

    return result % 10000000000; // Ensure it's a 10-digit number
}

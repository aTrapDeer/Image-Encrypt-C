#include <stdio.h>
#include <stdint.h>
#include "rand.h"

int main() {
    uint32_t seed1, seed2;

    printf("Enter the first seed value (a positive integer): ");
    fflush(stdout);
    while (scanf("%u", &seed1) != 1) {
        printf("Invalid input. Please enter a valid positive integer: ");
        fflush(stdout);
        while (getchar() != '\n'); 
    }

    printf("Enter the second seed value (a positive integer): ");
    fflush(stdout);
    while (scanf("%u", &seed2) != 1) {
        printf("Invalid input. Please enter a valid positive integer: ");
        fflush(stdout);
        while (getchar() != '\n'); 
    }

    uint64_t encrypted_value = generate_encrypted_value(seed1, seed2);

    printf("Encrypted 10-digit value: %010llu\n", encrypted_value);

    printf("Press Enter to exit...");
    fflush(stdout);
    while (getchar() != '\n');
    getchar(); 

    return 0;
}

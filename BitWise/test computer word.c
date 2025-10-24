#include <stdio.h>

void showBit(int x) {
    unsigned int mask = 1U << (sizeof(x) * 8 - 1); // start with highest bit

    while (mask != 0) {
        if ((x & mask) != 0) {   // check if bit is 1
            printf("1");
        } else {
            printf("0");
        }
        mask = mask >> 1;         // move to next bit
    }
    printf("\n");
}

int main() {
    int num = 42;
    showBit(num);   // prints 32-bit binary
    return 0;
}


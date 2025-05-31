#include <stdio.h>

void print_high_low_bytes(unsigned short value) {
    unsigned char high = (value >> 8) & 0xFF;  // 8 bit cao
    unsigned char low = value & 0xFF;          // 8 bit thấp

    printf("High byte: %u (0x%02X)\n", high, high);
    printf("Low byte: %u (0x%02X)\n", low, low);
}

int main() {
    unsigned short number = 1234; 
    print_high_low_bytes(number);
    return 0;
}

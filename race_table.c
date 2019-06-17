#include <stdio.h>
#include "utils.h"

void pattern();

const unsigned char VALUES[] = {
    0x80, 
    0x80, 
    0x40, 
    0x40, 
    0x20, 
    0x20, 
    0x10, 
    0x10, 
    0x88, 
    0x48, 
    0x24,
    0x14, 
    0x0A, 
    0x06, 
    0x03, 
    0x01, 
};

int main() {
    printf("\e[?25l");
    while (1) {
        pattern();
    }
}

void pattern() {

    for (int i = 0; i<=15; i++) {
        output(VALUES[i]);
        delay(500000);
        //delay(50000000);
    }

}
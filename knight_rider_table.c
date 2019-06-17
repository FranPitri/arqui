#include <stdio.h>
#include "utils.h"

void pattern();

const unsigned char VALUES[] = {
    0x80,
    0x40,
    0x20,
    0x10,
    0x08,
    0x04,
    0x02,
    0x01,
};

int main() {
    printf("\e[?25l");
    while (1) {
        pattern();
    }
}

void pattern() {

    for (int i = 0; i<=7; i++) {
        output(VALUES[i]);
        delay(5000000);
    }

    for (int i = 7; i>=0; i--) {
        output(VALUES[i]);
        delay(5000000);
    }

}
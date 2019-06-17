#include <stdio.h>
#include "utils.h"

void pattern();

int main() {
    printf("\e[?25l");
    while (1) {
        pattern();
    }
}

void pattern() {

    /* for (int i = 0; i<=7; i++) {
        charToSequence(1 << i, 80000000);
    } */

}
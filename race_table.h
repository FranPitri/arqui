#include "utils.h"

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

void race_pattern() {
    
    while (1) {

        for (int i = 0; i<=15; i++) {
            if (pattern_controls())
                return;
            output(VALUES[i]);
            delay(global_speed);
        }

    }

}
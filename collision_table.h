#include "utils.h"

void pattern();

const unsigned char VALUES[] = {
    0x81,
    0x42,
    0x24,
    0x18,
};

void collision_pattern() {
    
    while (1) {

        for (int i = 0; i<=3; i++) {
            if (pattern_controls())
                return;
            output(VALUES[i]);
            delay(global_speed);
        }

        for (int i = 3; i>=0; i--) {
            if (pattern_controls())
                return;
            output(VALUES[i]);
            delay(global_speed);
        }

    }


}
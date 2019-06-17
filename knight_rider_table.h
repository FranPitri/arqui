#include "utils.h"

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

void kr_pattern() {

    while (1) {

        for (int i = 0; i<=7; i++) {
            if (pattern_controls())
                return;
            output(VALUES[i]);
            delay(global_speed);
        }

        for (int i = 7; i>=0; i--) {
            if (pattern_controls())
                return;
            output(VALUES[i]);
            delay(global_speed);
        }

    }

}
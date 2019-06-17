#include "utils.h"

void newton_pattern() {

    while (1) {

        for (int i = 0; i<=5; i++) {
            if (pattern_controls())
                return;
            unsigned char base = (i < 3) ? 0x18 : 0x30; 
            unsigned char mark = (i < 3) ? 0x80 : 0x8; 
            output(base | (mark >> i % 3));
            delay(global_speed);
        }

        for (int i = 0; i<=5; i++) {
            if (pattern_controls())
                return;
            unsigned char base = (i < 3) ? 0x30 : 0x18; 
            unsigned char mark = (i < 3) ? 0x1 : 0x20; 
            output(base | (mark << i % 3));
            delay(global_speed);
        }

    }

}
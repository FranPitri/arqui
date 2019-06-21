#include "utils.h"

void kr_pattern() {

    while (1) {

        for (int i = 0; i<=7; i++) {
            if (pattern_controls())
                return;
            output(1 << i);
            delayMillis(global_speed);
        }

        for (int i = 7; i>=0; i--) {
            if (pattern_controls())
                return;
            output(1 << i);
            delayMillis(global_speed);
        }
        
    }

}
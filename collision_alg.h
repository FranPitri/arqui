#include "utils.h"

void collision_pattern(){
    
    while (1){

        for(int i = 0; i < 4; i++){
            if (pattern_controls())
                return;
           output(0x80 >> i | 0x01 << i);
           delayMillis(global_speed);
        }

        for(int i = 3; i >= 0; i--){
            if (pattern_controls())
                return;
            output(0x01 << i | 0x80 >> i);
            delayMillis(global_speed);
        }   
    }
    
}
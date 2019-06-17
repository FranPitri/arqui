#include "utils.h"

void collision_pattern();

void collision_pattern(){
    while (1){
        for(int i = 0; i < 4; i++){
           output(0x80>>i | 0x01 << i);
           delay(global_speed);
        }
        for(int i = 3; i >= 0; i--){
            output(0x01<<i | 0x80>>i);
            delay(global_speed);
        }   
    }
}
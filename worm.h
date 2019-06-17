#include "utils.h"

unsigned char VALUES[] = {
    0x82, // 1
    0x42, // 2
    0x22, // 3
    0x12, // 4
    0xA,  // 5
    0x06, // 6 choque 
    0x06, // 7 
    0x03, // 8 Dando vueltas
    0x06, // 9  
    0x0C, // 10
    0x18, // 11
    0x30, // 12
    0x60, // 13
    0xC0, // 14 
    0x60, // 15 
    0x30, // 16 
    0x18, // 17 
    0x0C, // 18 
    0x06, // 19 
    0x03, // 20 Fin de dar vueltas
    0x43, // 21   
    0x46, // 22 
    0x4C, // 23
    0x58, // 24
    0x70, // 25 Choque
    0x70, // 26
    0xE0, // 27
    0x70, // 28
    0x38, // 29
    0x1C, // 30
    0xE,  // 31
    0x47, // 32
    0x4E, // 33
    0x5C, // 34 
    0x78, // 36 Choque
    0x78, // 37
    0xF0, // 38
    0x78, // 39
    0x3C, // 40
    0x1E, // 41
    0x8F, // 42
    0x9E, // 43 prendi otra
    0xBD, // 44
    0xF9, // 45 Choque
    0xF9, // 46
    0x7D, // 47
    0x3F, // 48 Choque
    0x3F, // 49
    0x7E, // 50
    0xFC, // 51
    0x7E, // 52
    0xBF, // 53
    0xFE, // 54 choque
    0xFE, // 55
    0xFE, // 56
    0xFF, // 57
    0x00, // 59
    0x00, // 60
    0xFF, // 61
    0xFF, // 62
};

void worm_pattern();

void worm_pattern(){
    while (1){
        for(int i = 0; i < 63; i++){
            output(VALUES[i]);
            delay(global_speed);
        }   
    }
}

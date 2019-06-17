#if !defined(UTILS_H)
#define UTILS_H

#include <stdio.h>
#include <ncurses.h>

unsigned int global_speed = 80000000;

void delay(int i) { while (i){ i--; } }

void output(unsigned char c) {
    for (int i = 7; i >= 0; --i) {
        char tmp = (c & (1 << i)) ? '*' : '_';
        addch(tmp);
        refresh();
    }
    int rows, cols;
    getyx(stdscr, rows, cols);
    move(rows, 0);
}

int pattern_controls() {
    switch (getch()) {
        case 'q':
            return 1;
        case KEY_UP:
            global_speed -= 10000000;
            break;
        case KEY_DOWN:
            global_speed += 10000000;
            break;
    }
    return 0;
}

#endif // UTILS_H
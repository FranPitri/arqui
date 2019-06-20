#if !defined(UTILS_H)
#define UTILS_H

#include <stdio.h>
#include <ncurses.h>
#include "EasyPIO.h"

unsigned int global_speed = 80000000;
const unsigned int min_speed_cap = 130000000;
const unsigned int max_speed_cap = 10000000;
const char led[] = {7, 8, 25, 24, 23, 18, 15, 14};
const char sw[] = {12, 16, 18, 20, 21};

void delay(int i) { while (i){ i--; } }

void addch_in_middle(WINDOW *win,
                    int starty,
                    int startx,
                    int width,
                    int length, 
                    int pos, 
                    char c) {	
    int x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
        width = getmaxx(stdscr);

	temp = ((width / 2) + (length / 2)) - pos;
	x = (int)temp;
	mvwprintw(win, y, x, "%C", c);
	refresh();
}

void output(unsigned char c) {
    for (int i = 7; i >= 0; --i) {
        char tmp = (c & (1 << i)) ? '*' : '_';
        int status = (c & (1 << i)) ? 0 : 1;
        digitalWrite(led[i], status);
        addch_in_middle(stdscr, LINES / 2, i, 0, 8, i+1, tmp);
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
            if (global_speed > max_speed_cap)
                global_speed -= 10000000;
            break;
        case KEY_DOWN:
            if (global_speed < min_speed_cap)
                global_speed += 10000000;
            break;
    }
    return 0;
}

#endif // UTILS_H
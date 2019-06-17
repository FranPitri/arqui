#include <string.h>
#include "utils.h"
#include "knight_rider_alg.h"
#include "collision_alg.h"
#include "snake_table.h"
#include <ncurses.h>

#define PASSWORD "robin"
#define PASSWORD_LENGTH 5
#define ATTEMPS_ALLOWED 3

int checkPassword(char *p) {
    return strcmp(p, PASSWORD) == 0 ? 1 : 0;
}

int login();
void menu();
void run(void (*fn)());


int main() {

    initscr();
    
    if (login())
        menu();

    endwin();
}

int login() {
    
    cbreak();
    noecho();

    int attempt = 0;
    char pass[PASSWORD_LENGTH];
    while (attempt < ATTEMPS_ALLOWED) {
        int index = 0;
        printw("Ingrese su contraseña: ");
        while (index < PASSWORD_LENGTH) {
            pass[index] = getch();
            if (pass[index] == 127) {
                if (index == 0) {
                    continue;
                }
                int rows, cols;
                getyx(stdscr, rows, cols);
                mvdelch(rows, cols - 1);
                index--;
                continue;
            }
            printw("*");
            index++;
        }
        if (checkPassword(pass)) {
            clear();
            printw("Bienvenido al sistema!\n");
            return 1;
        } 
        clear();
        printw("Contraseña erronea! Intente nuevamente.\n");
        attempt++;
    }
    return 0;
}

void menu() {
    
    nocbreak();
    echo();

    printw("Seleccione una opción para continuar.\n\n");
    printw("0. Salir\n");
    printw("1. El auto fantasmón\n");
    printw("2. Paul Walker\n");
    printw("3. Snake\n");
    printw("4. {}\n\n");
    int selection = -1;
    while (selection < 0 || selection > 4) {
        printw("Seleccione un patrón: ");
        scanw("%d", &selection);
    }
    switch (selection) {
        case 0:
            break;
        case 1:
            run(kr_pattern);
            break;
        case 2:
            run(collision_pattern);
            break;
        case 3:
            run(snake_pattern);
            break;
        default:
            printw("4\n");
    }

}

void run(void (*fn)()) {

    cbreak();
    noecho();
    
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    
    clear();
    printw("Presione 'q' para volver al modo de selección.\n");
    printw("Utilice las flechas arriba/abajo para manejar la velocidad del patrón.\n\n");
    
    fn();

    keypad(stdscr, FALSE);
    nodelay(stdscr, FALSE);
    curs_set(1);

    clear();
    menu();
};
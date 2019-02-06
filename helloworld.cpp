#include <ncurses.h>

int main()
{
    initscr(); // start ncurses mode
    printw("Hello world!\n"); // ncurses analog for printf
    refresh(); // refresh screen on changed areas
    getch();
    endwin(); // stop ncurses mode
    return 0;
}   

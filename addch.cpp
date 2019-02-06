#include <ncurses.h>
#include <cstring>

int main()
{
    initscr();

    // addch puts symbol with attributes
    addch('N' | A_NORMAL);  
    addch('S' | A_STANDOUT);
    addch('U' | A_UNDERLINE);
    addch('B' | A_BLINK);
    addch('D' | A_DIM);
    addch('B' | A_BOLD);

    // string in center of window
    const char *string = "String right in center of window";

    int rows, cols;
    getmaxyx(stdscr, rows, cols); // gets dimensions of window

    mvwprintw(stdscr, (rows - 1) / 2, (cols - strlen(string)) / 2, "%s", string); // move cursor and prints string

    // string with information of window dimensions
    mvwprintw(stdscr, rows - 1, 0, "(rows - %d, cols - %d)", rows, cols);

    refresh();
    getch();

    endwin();

    return 0;
}

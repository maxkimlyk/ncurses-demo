#include <ncurses.h>

int main()
{
    initscr();
    noecho(); // don't show input

    char string[128];
    printw("Enter secret string: ");
    scanw("%s", string);

    printw("You entered: %s", string);
    getch();

    endwin();

    return 0;
}

#include <ncurses.h>

int main()
{
    initscr();

    keypad(stdscr, true); // enable reading of functional keys (f1, f2, etc)
    halfdelay(100); // getch() wait time (in 0.1 seconds). Wait for 10 sec.
    noecho(); // don't show input

    printw("Press F10 to exit.\n");
    
    bool loop = true;
    while (loop)
    {
        int ch = getch();
        switch(ch)
        {
        case ERR: // time is up
            printw("I'm waiting...\n");
            break;

        case KEY_F(10):
            loop = false;
            break;

        default:
            printw("Pressed key with code %d\n", ch);
        }

        refresh();
    }

    endwin();

    return 0;
}

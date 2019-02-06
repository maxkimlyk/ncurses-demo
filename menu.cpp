#include <ncurses.h>

int main()
{
    initscr();

    curs_set(0); // don't show cursor
    keypad(stdscr, true); // allow reading keys like uparrow and downarrow with getch()

    size_t menu_items_num = 3;
    const char* menu[menu_items_num] = {
        "First item",
        "Second item",
        "Exit"
    };

    size_t selected = 0;

    bool loop = true;
    while (loop)
    {
        clear(); // clear the screen

        for (size_t i = 0; i < menu_items_num; ++i)
        {
            addch(i == selected ? '>' : ' ');
            printw("%s\n", menu[i]);
        }

        int ch = getch();
        switch( ch )
        {
        case KEY_UP:
            selected = selected == 0 ? menu_items_num -1 : selected - 1;
            break;

        case KEY_DOWN:
            selected = selected == menu_items_num - 1 ? 0 : selected + 1;
            break;

        case '\n':
            if (selected == menu_items_num - 1)
                loop = false;
            break;
        }
    }

    endwin();

    return 0;
}

#include <ncurses.h>
#include <string>

int main()
{
    initscr();
    noecho();     // do not print input
    halfdelay(1); // getch waiting time
    curs_set(0);  // do not show cursor

    const std::string info_str = "Press q or ESC to exit";
    const std::string window_info = "hello from window!";

    int term_rows, term_cols;
    getmaxyx(stdscr, term_rows, term_cols); // gets dimensions of terminal window

    const int height = term_rows / 2;
    const int width = term_cols / 2;
    const int y = (term_rows - height) / 2;
    const int x = (term_cols - width) / 2;
    
    WINDOW *win = newwin(height, width, y, x); // create new window

    // print info string at the bottom of the screen
    mvprintw(term_rows - 1, (term_cols - info_str.size()) / 2, info_str.c_str()); 

    int phase = 0;
    bool main_loop = true;
    while (key = getch(); key != 'q' && key != 27 /*ESC*/)
    {
        wclear(win); // clear window

        box(win, ' ', 0); // draw borders
        //            ^
        // zero means using default symbols for horizontal borders

        // print text into window
        mvwprintw(win, height / 2, (width - window_info.size()) / 2, window_info.c_str());

        srand(0);
        for (int i = 1; i < height - 1; ++i)
        {
            if (i == height/ 2)
                continue;
            mvwaddch(win, i, (rand() + phase) % (width * 3 / 2),  'o' + i); // add char into window
        }
        phase++;

	    wrefresh(win); // refresh window

        int key = getch();
        switch(key)
        {
            case (int)('q'):
            case 27: // esc
                main_loop = false;
                break;
        }
    }

    endwin();

    return 0;
}

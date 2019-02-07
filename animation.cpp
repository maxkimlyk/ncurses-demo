#include <ncurses.h>
#include <cstring>
#include <cmath>
#include <string>

const size_t HEIGHT = 11;
const size_t WIDTH = 11;

const int EXIT_KEY = 'x';
const std::string EXIT_STRING = 
    std::string("To exit print '") +
    std::string(1, static_cast<const char>(EXIT_KEY)) + 
    std::string("'");

const char pattern[HEIGHT][WIDTH+1] = {
    "     #     ",
    "     #     ",
    "     #     ",
    "     #     ",
    "     #     ",
    "###########",
    "     #     ",
    "     #     ",
    "     #     ",
    "     #     ",
    "     #     ",
};

void draw_pattern(int y0, int x0, float angle)
{
    for (int i = 0; i < (int)(HEIGHT); ++i)
        for (int j = 0; j < (int)(WIDTH); ++j)
        {
            if (pattern[i][j] != ' ')
            {
                int x = j - WIDTH / 2;
                int y = i - HEIGHT / 2;
                int newx = std::round(std::cos(angle) * x - std::sin(angle) * y);
                int newy = std::round(std::sin(angle) * x + std::cos(angle) * y);
                mvaddch(y0 + newy, x0 + newx, pattern[i][j]);
            }
        }
}

int main()
{
    initscr();
    halfdelay(1); // getch wait period

    int win_rows, win_cols;
    getmaxyx(stdscr, win_rows, win_cols); // gets dimensions of window

    float angle = 0.0;
    const float angle_speed = 0.4;

    bool loop = true;
    while (loop)
    {
        int ch = getch();
        if (ch == EXIT_KEY)
            loop = false;

        clear();   
        draw_pattern(win_rows / 2, win_cols / 4, angle);
        draw_pattern(win_rows / 2, win_cols * 3 / 4, angle);

        mvprintw(win_rows - 1, win_cols / 2 - EXIT_STRING.size() / 2, EXIT_STRING.c_str());

        refresh();

        angle += angle_speed;
    }

    endwin();

    return 0;
}

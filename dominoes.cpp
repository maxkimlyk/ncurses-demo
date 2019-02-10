#include <ncurses.h>
#include <cstdlib>
#include <clocale>

void add_utf8_ch(int utf8)
{
    cchar_t ch = {0};
    ch.chars[0] = utf8;
    add_wch(&ch);
}

void draw_tile(int y, int x, char first, char second)
{
    mvaddch(y, x, ACS_ULCORNER);
    mvaddch(y, x+1, ACS_HLINE);
    mvaddch(y, x+2, ACS_URCORNER);
    mvaddch(y+1, x, ACS_VLINE);
    mvaddch(y+1, x+1, first);    
    mvaddch(y+1, x+2, ACS_VLINE);
    mvaddch(y+2, x, ACS_VLINE);
    mvaddch(y+2, x+1, ACS_HLINE);
    mvaddch(y+2, x+2, ACS_VLINE);
    mvaddch(y+3, x, ACS_VLINE);
    mvaddch(y+3, x+1, second);
    mvaddch(y+3, x+2, ACS_VLINE);
    mvaddch(y+4, x, ACS_LLCORNER);
    mvaddch(y+4, x+1, ACS_HLINE);
    mvaddch(y+4, x+2, ACS_LRCORNER);
}

int main()
{
    setlocale(LC_ALL, "");

    initscr();
    noecho();

    for (int i = 0; i < 6; ++i)
        draw_tile(1, 1 + 3 * i, '0' + rand() % 7, '0' + rand() % 7);

    int row = 6;
    const int start_col = 1;

    move(row, start_col);
    for (int ch = 0x1f030, cnt = 1; ch <= 0x1f09f; ++ch, ++cnt)
    {
        add_utf8_ch(ch);
        if (cnt >= 10)
        {
            cnt = 0;
            move(++row, start_col);
        }
    }

    refresh();

    getch();

    endwin();
    return 0;
}
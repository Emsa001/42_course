#include "../lib.h"

void write_color(const char *color_code)
{
    write(STDOUT_FILENO, color_code, strlen(color_code));
}

void blue(void)
{
    write_color("\x1B[34m");
}

void gray(void)
{
    write_color("\033[30;1m");
}

void green(void)
{
    write_color("\x1B[32m");
}

void red(void)
{
    write_color("\x1B[31m");
}

void yellow(void)
{
    write_color("\x1B[33m");
}

void cyan(void)
{
    write_color("\x1B[36m");
}

void purple(void)
{
    write_color("\033[35m");
}

void white(void)
{
    write_color("\033[37m");
}

void black(void)
{
    write_color("\033[30m");
}

void bold(void)
{
    write_color("\033[1m");
}

void underline(void)
{
    write_color("\033[4m");
}

void blink(void)
{
    write_color("\033[5m");
}

void reverse(void)
{
    write_color("\033[7m");
}

void hide(void)
{
    write_color("\033[8m");
}

void clear_screen(void)
{
    write_color("\033[2J");
}

void clear_line(void)
{
    write_color("\033[K");
}

void reset(void)
{
    write_color("\x1B[0m");
}

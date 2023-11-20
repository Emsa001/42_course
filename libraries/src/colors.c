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

void reset(void)
{
    write_color("\x1B[0m");
}

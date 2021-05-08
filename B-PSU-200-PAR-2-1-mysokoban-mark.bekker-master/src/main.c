/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <socoban.h>
#include <ib.h>

void make_move(int key, int *dim, int **grid, int **cpy)
{
    int *pos = get_player_pos(dim, grid);

    if (key == KEY_RIGHT)
        check_right(pos, grid, cpy);
    if (key == KEY_LEFT)
        check_left(pos, grid, cpy);
    if (key == KEY_UP)
        check_up(pos, grid, cpy);
    if (key == KEY_DOWN)
        check_down(pos, grid, cpy);
}

bool launch_game(char *buff, int *dim, int **grid)
{
    int key[2] = {-1, 0};
    int **cpy = get_grid(buff);

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (key[0] != '\n') {
        if (key[0] == ' ')
            grid = get_grid(buff);
        make_move(key[0], dim, grid, cpy);
        put_grid(dim, grid);
        check_win(dim, grid, cpy, key);
        if (key[0] != '\n')
            key[0] = getch();
    }
    free(buff);
    endwin();
    return (key[1]);
}

char *read_file(int tmp, struct stat stats)
{
    char *buffer = malloc(sizeof(char) * stats.st_size + 2);
    int c[3] = {0, 0, 0};

    read(tmp, buffer, stats.st_size);
    for (int i = ib_strlen(buffer) - 1; buffer[i] != '#' && i > 0; i--)
        buffer[i] = '\0';
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '#'
        && buffer[i] != 'X' && buffer[i] != 'O' && buffer[i] != 'P') {
            free(buffer);
            return (NULL);
        }
        for (int t = 1; buffer[i] == 'X' && t; t--, c[0]++);
        for (int t = 1; buffer[i] == 'O' && t; t--, c[1]++);
        for (int t = 1; buffer[i] == 'P' && t; t--, c[2]++);
    }
    if (c[0] - c[1] != 0 || c[0] == 0 || c[2] != 1)
        buffer = NULL;
    return (buffer);
}

int main(int ac, char **av)
{
    struct stat stats;
    char *buff = NULL;
    int tmp = 0;

    if (ac != 2)
        return (84);
    if (ac == 2 && ib_strcmp(av[1], "-h"))
        ib_putstr("USAGE:\n    ./my_socoban map\n"
                "DESCRIPTION:\n    map  file representing the warehouse map"
                ", containing '#' for walls,\n         'P' for the player, "
                "'X' for boxes and 'O' for storage locations.\n");
    tmp = open(av[1], O_RDONLY);
    if (tmp < 0)
        return (84);
    stat(av[1], &stats);
    buff = read_file(tmp, stats);
    close(tmp);
    if (buff == NULL)
        return (84);
    return (launch_game(buff, get_grid_size(buff), get_grid(buff)));
}
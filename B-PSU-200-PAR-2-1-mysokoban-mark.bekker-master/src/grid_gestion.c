/*
** EPITECH PROJECT, 2021
** grid_gestion
** File description:
** manages grid's heigth length and data
*/

#include <stdlib.h>
#include <ncurses.h>
#include <ib.h>

int *get_grid_size(char *buff)
{
    int tmp = 0;
    int *dim = malloc(sizeof(int) * 2);

    dim[0] = 1;
    dim[1] = 0;
    for (int i = 0; buff[i] != '\0'; i++) {
        for (tmp = 0; buff[i] != '\n' && buff[i] != '\0'; i++, tmp++);
        if (tmp > dim[1])
            dim[1] = tmp;
    }
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n')
            dim[0]++;
    return (dim);
}

int **get_grid(char *buff)
{
    int *dim = get_grid_size(buff);
    int **grid = malloc(sizeof(int *) * dim[0]);
    int wdt = 0;

    for (int i = 0; i < dim[0]; i++)
        grid[i] = malloc(sizeof(int) * dim[1]);
    for (int i = 0; i < dim[0]; i++)
        for (int j = 0; j < dim[1]; j++)
            grid[i][j] = 1;
    for (int i = 0; buff[i] != '\0'; i++) {
        for (int j = 0; buff[i] != '\n' && buff[i] != '\0'; i++, j++)
            grid[wdt][j] = (int)buff[i] % 10;
        wdt++;
    }
    return (grid);
}

void put_grid(int *dim, int **grid)
{
    int len = LINES / 2 - dim[0] / 2;
    int wdt = COLS / 2 - dim[1] / 2;

    for (int i = 0; i < dim[0]; i++) {
        for (int j = 0; j < dim[1]; j++) {
            if (grid[i][j] == 5)
                mvprintw(len + i, wdt + j, "#");
            if (grid[i][j] == 0)
                mvprintw(len + i, wdt + j, "P");
            if (grid[i][j] == 9)
                mvprintw(len + i, wdt + j, "O");
            if (grid[i][j] == 8)
                mvprintw(len + i, wdt + j, "X");
            if (grid[i][j] == 2)
                mvprintw(len + i, wdt + j, " ");
        }
    }
    refresh();
}
/*
** EPITECH PROJECT, 2021
** check_loose
** File description:
** checks if a player has lost the game
*/

#include <stdbool.h>

bool next_box(int **grid, int i, int j, int tmp)
{
    int tmp_h = 0;
    int tmp_v = 0;

    for (; tmp_h == 0 && (tmp == 1 || tmp == 2); tmp_h = 1);
    for (; tmp_v == 0 && (tmp == 3 || tmp == 4); tmp_v = 1);
    if (tmp != 2 && (grid[i][j + 1] == 5 ||
        (grid[i][j + 1] == 8 && next_box(grid, i, j + 1, 1))))
        tmp_h++;
    if (tmp != 1 && (grid[i][j - 1] == 5 ||
        (grid[i][j - 1] == 8 && next_box(grid, i, j - 1, 2))))
        tmp_h++;
    if (tmp != 4 && (grid[i - 1][j] == 5 ||
        (grid[i - 1][j] == 8 && next_box(grid, i - 1, j, 3))))
        tmp_v++;
    if (tmp != 3 && (grid[i + 1][j] == 5 ||
        (grid[i + 1][j] == 8 && next_box(grid, i + 1, j, 4))))
        tmp_v++;
    if (tmp_h >= 1 && tmp_v >= 1)
        return (1);
    return (0);
}

bool check_box(int **grid, int i, int j)
{
    int tmp_h = 0;
    int tmp_v = 0;

    if (grid[i][j + 1] == 5 ||
        (grid[i][j + 1] == 8 && next_box(grid, i, j + 1, 1)))
        tmp_h++;
    if (grid[i][j - 1] == 5 ||
        (grid[i][j - 1] == 8 && next_box(grid, i, j - 1, 2)))
        tmp_h++;
    if (grid[i - 1][j] == 5 ||
        (grid[i - 1][j] == 8 && next_box(grid, i - 1, j, 3)))
        tmp_v++;
    if (grid[i + 1][j] == 5 ||
        (grid[i + 1][j] == 8 && next_box(grid, i + 1, j, 4)))
        tmp_v++;
    if (tmp_h >= 1 && tmp_v >= 1)
        return (1);
    return (0);
}

bool check_loose(int *dim, int **grid)
{
    for (int i = 0; i < dim[0]; i++)
        for (int j = 0; j < dim[1]; j++)
            if (grid[i][j] == 8 && !check_box(grid, i, j))
                return (0);
    return (1);
}
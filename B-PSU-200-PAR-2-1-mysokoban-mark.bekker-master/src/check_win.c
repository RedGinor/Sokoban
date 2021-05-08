/*
** EPITECH PROJECT, 2021
** check_win
** File description:
** checks if the player wins or not
*/

#include <stdlib.h>
#include <socoban.h>

int *get_player_pos(int *dim, int **grid)
{
    int *pos = malloc(sizeof(int) * 2);

    for (; pos[0] < dim[0]; pos[0]++)
        for (pos[1] = 0; pos[1] < dim[1]; pos[1]++)
            if (grid[pos[0]][pos[1]] == 0)
                return (pos);
    return (pos);
}

void check_win(int *dim, int **grid, int **cpy, int *key)
{
    int *pos = get_player_pos(dim, grid);
    int tmp = 0;

    for (int i = 0; i < dim[0]; i++)
        for (int j = 0; j < dim[1]; j++)
            if (grid[i][j] == 9)
                tmp++;
    if (cpy[pos[0]][pos[1]] != 9 && tmp == 0)
        key[0] = '\n';
    else if (check_loose(dim, grid)) {
        key[0] = '\n';
        key[1] = 1;
    }
}
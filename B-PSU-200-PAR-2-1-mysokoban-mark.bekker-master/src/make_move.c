/*
** EPITECH PROJECT, 2021
** make_move
** File description:
** checks the right movement
*/

void check_right(int *pos, int **grid, int **cpy)
{
    if (grid[pos[0]][pos[1] + 1] == 2 || grid[pos[0]][pos[1] + 1] == 9) {
        grid[pos[0]][pos[1]] = cpy[pos[0]][pos[1]];
        if (grid[pos[0]][pos[1]] == 0 || grid[pos[0]][pos[1]] == 8)
            grid[pos[0]][pos[1]] = 2;
        grid[pos[0]][pos[1] + 1] = 0;
    }
    if (grid[pos[0]][pos[1] + 1] == 8 &&
        (grid[pos[0]][pos[1] + 2] == 2 || grid[pos[0]][pos[1] + 2] == 9)) {
        grid[pos[0]][pos[1]] = cpy[pos[0]][pos[1]];
        if (grid[pos[0]][pos[1]] == 0 || grid[pos[0]][pos[1]] == 8)
            grid[pos[0]][pos[1]] = 2;
        grid[pos[0]][pos[1] + 1] = 0;
        grid[pos[0]][pos[1] + 2] = 8;
    }
}

void check_left(int *pos, int **grid, int **cpy)
{
    if (grid[pos[0]][pos[1] - 1] == 2 || grid[pos[0]][pos[1] - 1] == 9) {
        grid[pos[0]][pos[1]] = cpy[pos[0]][pos[1]];
        if (grid[pos[0]][pos[1]] == 0 || grid[pos[0]][pos[1]] == 8)
            grid[pos[0]][pos[1]] = 2;
        grid[pos[0]][pos[1] - 1] = 0;
    }
    if (grid[pos[0]][pos[1] - 1] == 8 &&
        (grid[pos[0]][pos[1] - 2] == 2 || grid[pos[0]][pos[1] - 2] == 9)) {
        grid[pos[0]][pos[1]] = cpy[pos[0]][pos[1]];
        if (grid[pos[0]][pos[1]] == 0 || grid[pos[0]][pos[1]] == 8)
            grid[pos[0]][pos[1]] = 2;
        grid[pos[0]][pos[1] - 1] = 0;
        grid[pos[0]][pos[1] - 2] = 8;
    }
}

void check_up(int *pos, int **grid, int **cpy)
{
    if (grid[pos[0] - 1][pos[1]] == 2 || grid[pos[0] - 1][pos[1]] == 9) {
        grid[pos[0]][pos[1]] = cpy[pos[0]][pos[1]];
        if (grid[pos[0]][pos[1]] == 0 || grid[pos[0]][pos[1]] == 8)
            grid[pos[0]][pos[1]] = 2;
        grid[pos[0] - 1][pos[1]] = 0;
    }
    if (grid[pos[0] - 1][pos[1]] == 8 &&
        (grid[pos[0] - 2][pos[1]] == 2 || grid[pos[0] - 2][pos[1]] == 9)) {
        grid[pos[0]][pos[1]] = cpy[pos[0]][pos[1]];
        if (grid[pos[0]][pos[1]] == 0 || grid[pos[0]][pos[1]] == 8)
            grid[pos[0]][pos[1]] = 2;
        grid[pos[0] - 1][pos[1]] = 0;
        grid[pos[0] - 2][pos[1]] = 8;
    }
}

void check_down(int *pos, int **grid, int **cpy)
{
    if (grid[pos[0] + 1][pos[1]] == 2 || grid[pos[0] + 1][pos[1]] == 9) {
        grid[pos[0]][pos[1]] = cpy[pos[0]][pos[1]];
        if (grid[pos[0]][pos[1]] == 0 || grid[pos[0]][pos[1]] == 8)
            grid[pos[0]][pos[1]] = 2;
        grid[pos[0] + 1][pos[1]] = 0;
    }
    if (grid[pos[0] + 1][pos[1]] == 8 &&
        (grid[pos[0] + 2][pos[1]] == 2 || grid[pos[0] + 2][pos[1]] == 9)) {
        grid[pos[0]][pos[1]] = cpy[pos[0]][pos[1]];
        if (grid[pos[0]][pos[1]] == 0 || grid[pos[0]][pos[1]] == 8)
            grid[pos[0]][pos[1]] = 2;
        grid[pos[0] + 1][pos[1]] = 0;
        grid[pos[0] + 2][pos[1]] = 8;
    }
}
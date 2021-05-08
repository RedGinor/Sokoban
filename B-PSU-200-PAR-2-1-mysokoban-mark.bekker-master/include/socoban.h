/*
** EPITECH PROJECT, 2021
** socoban
** File description:
** socoban headers
*/

#ifndef SOCOBAN_H
#define SOCOBAN_H

#include <stdbool.h>

int *get_grid_size(char *buff);
int **get_grid(char *buff);
int *get_player_pos(int *dim, int **grid);
void put_grid(int *dim, int **grid);
void check_right(int *pos, int **grid, int **cpy);
void check_left(int *pos, int **grid, int **cpy);
void check_up(int *pos, int **grid, int **cpy);
void check_down(int *pos, int **grid, int **cpy);
void check_win(int *dim, int **grid, int **cpy, int *key);
bool check_loose(int *dim, int **grid);

#endif

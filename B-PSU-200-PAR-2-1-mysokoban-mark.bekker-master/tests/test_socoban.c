/*
** EPITECH PROJECT, 2021
** test_socoban
** File description:
** test file for socoban
*/

#include <criterion/criterion.h>
#include <socoban.h>

Test(get_player_pos, normal_position_1)
{
    char *buff = "#######\n#     #\n# P  X#\n#    O#\n#######\n";
    int *dim = get_grid_size(buff);
    int **grid = get_grid(buff);
    int *pos = get_player_pos(dim, grid);

    cr_assert_eq(pos[0], 2);
    cr_assert_eq(pos[1], 2);
}

Test(get_grid_size, normal_size_1)
{
    char *buff = "#######\n#     #\n# P  X#\n#    O#\n#######\n";
    int *dim = get_grid_size(buff);

    cr_assert_eq(dim[0], 6);
    cr_assert_eq(dim[1], 7);
}
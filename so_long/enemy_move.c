#include "so_long.h"

void move_enemy(t_game *map_info)
{
    int x = map_info->enemy_position[1];
    int y = map_info->enemy_position[0];

    int new_x, new_y;
    do {
        // Generate a random direction
        int direction = rand() % 4;
        switch (direction) {
            case 0:  // Move up
                new_y = y - 1;
                new_x = x;
                break;
            case 1:  // Move down
                new_y = y + 1;
                new_x = x;
                break;
            case 2:  // Move left
                new_x = x - 1;
                new_y = y;
                break;
            case 3:  // Move right
                new_x = x + 1;
                new_y = y;
                break;
        }
    } while (new_x < 0 || new_x >= map_info->width || new_y < 0 || new_y >= map_info->height || 
             map_info->map[new_y][new_x] != '0' || 
             (new_x == map_info->player_position[1] && new_y == map_info->player_position[0]));

    // Update the position of the enemy
    map_info->enemy_position[1] = new_x;
    map_info->enemy_position[0] = new_y;
}
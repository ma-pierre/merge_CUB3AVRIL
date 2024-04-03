#define MINIMAP_TILE_SIZE 5  // Taille en pixels de chaque case sur la minimap
#define MAP_WIDTH 24         // Largeur de la carte
#define MAP_HEIGHT 24        // Hauteur de la carte

# include "cub3D.h"

void init_minimap(t_data *data) {
    int minimap_width = MAP_WIDTH * MINIMAP_TILE_SIZE;
    int minimap_height = MAP_HEIGHT * MINIMAP_TILE_SIZE;
    data->minimap_img = mlx_new_image(data->mlx, minimap_width, minimap_height);
    data->minimap_addr = mlx_get_data_addr(data->minimap_img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

void draw_minimap(t_data *data) {
    int x, y;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            int color = (worldMap[y][x] == 1) ? 0xFFFFFF : 0x000000; // Murs en blanc, espaces en noir
            for (int ty = 0; ty < MINIMAP_TILE_SIZE; ty++) {
                for (int tx = 0; tx < MINIMAP_TILE_SIZE; tx++) {
                    my_mlx_pixel_put(data, x * MINIMAP_TILE_SIZE + tx, y * MINIMAP_TILE_SIZE + ty, color);
                }
            }
        }
    }
}

void update_player_position_on_minimap(t_data *data) {
    int player_x = (int)data->posX * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE / 2;
    int player_y = (int)data->posY * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE / 2;
    my_mlx_pixel_put(data, player_x, player_y, 0xFF0000); // Rouge pour la position du joueur
}

void display_minimap(t_data *data) {
    draw_minimap(data);
    update_player_position_on_minimap(data);
    mlx_put_image_to_window(data->mlx, data->win, data->minimap_img, 10, 10); // Ajuste la position selon tes besoins
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char	*dst;

    dst = data->minimap_addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/////////////////
#include "../includes/cub.h"

#define MINIMAP_SCALE 5 // Exemple de facteur d'échelle pour la taille de la minimap
#define MINIMAP_SIZE 100 // Exemple de taille de la minimap (100x100 pixels)

void draw_minimap(t_data *data) {
    int x, y;
    for (y = 0; y < 24; y++) { // Pour chaque ligne de la carte
        for (x = 0; x < 24; x++) { // Pour chaque colonne de la carte
            int color = worldMap[y][x] > 0 ? 0xFFFFFF : 0x000000; // Blanc pour les murs, Noir pour l'espace vide
            mlx_draw_square(data->mlx, data->win, x * MINIMAP_SCALE, y * MINIMAP_SCALE, MINIMAP_SCALE, color);
        }
    }

    // Dessiner le joueur sur la minimap
    int player_x = (int)(data->posX * MINIMAP_SCALE);
    int player_y = (int)(data->posY * MINIMAP_SCALE);
    mlx_draw_square(data->mlx, data->win, player_x, player_y, MINIMAP_SCALE, 0xFF0000); // Rouge pour le joueur
}

void mlx_draw_square(void *mlx_ptr, void *win_ptr, int x, int y, int size, int color) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
        }
    }
}
*/
// Dans do_frame, appelez draw_minimap(data); après le rendu principal.

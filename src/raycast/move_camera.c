/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:55:41 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/02 05:17:56 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void init_player_direction(t_data *data)
{
    if (data->player_start_dir == 'N')
    {
        data->dirX = 0; data->dirY = -1;
        data->planeX = 0.66; data->planeY = 0;
    }
    else if (data->player_start_dir == 'S')
    {
        data->dirX = 0; data->dirY = 1;
        data->planeX = -0.66; data->planeY = 0;
    }
    else if (data->player_start_dir == 'E')
    {
        data->dirX = 1; data->dirY = 0;
        data->planeX = 0; 
        data->planeY = 0.66;
    }
    else if (data->player_start_dir == 'W')
    {
        data->dirX = -1; data->dirY = 0;
        data->planeX = 0; data->planeY = -0.66;
    }
}

void    camera_right(t_data *data)
{
    double current_DirX;
    double current_PlaneX;
    
    current_DirX = data->dirX;
    current_PlaneX = data->planeX;
	data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
	data->dirY = current_DirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
	data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
	data->planeY = current_PlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
}

void    camera_left(t_data *data)
{	    
    double current_DirX;
    double current_PlaneX;
    
    current_DirX = data->dirX;
    current_PlaneX = data->planeX;
	data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
	data->dirY = current_DirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
	data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
	data->planeY = current_PlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
}

/*void draw_square(t_data *data, int x, int y, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}*/
/*
// Ajoute cette fonction pour dessiner la minimap
void draw_minimap(t_data *data)
{
    int mapX, mapY; // Coordonnées dans la carte
    int pixelX, pixelY; // Coordonnées à l'écran pour la minimap
    int minimapSize = 200; // Taille de la minimap (200x200 pixels par exemple)
    int tileSize = minimapSize / 24; // Taille d'une case sur la minimap, ajuste selon ta carte

    // Parcours de la carte pour dessiner la minimap
    for (mapY = 0; mapY < 24; mapY++)
    {
        for (mapX = 0; mapX < 24; mapX++)
        {
            pixelX = mapX * tileSize;
            pixelY = mapY * tileSize;

            // Choisis une couleur pour les murs et une autre pour les espaces vides
            int color = worldMap[mapY][mapX] > 0 ? 0xFFFFFF : 0x000000; // Exemple : blanc pour les murs, noir pour les espaces

            // Dessine un carré pour chaque case de la carte sur la minimap
            draw_square(data, pixelX, pixelY, tileSize, color);
        }
    }

    // Dessine la position du joueur sur la minimap
    int playerX = (int)(data->posX * tileSize);
    int playerY = (int)(data->posY * tileSize);
    draw_square(data, playerX, playerY, tileSize, 0xFF0000); // Rouge pour la position du joueur
}

// Cette fonction est un exemple et doit être adaptée à ton code
// mlx_draw_square est une fonction hypothétique pour dessiner un carré, tu devras la remplacer par le code approprié pour dessiner avec MiniLibX
*/
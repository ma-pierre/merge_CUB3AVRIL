/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:55:35 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/03 00:38:31 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void    move_forward(t_data *data)
{
    if (data->WorldMap[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)] == '0')
			data->posX += data->dirX * data->moveSpeed;
	if (data->WorldMap[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)] == '0')
			data->posY += data->dirY * data->moveSpeed;
}

void    move_back(t_data *data)
{
    if (data->WorldMap[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)] == '0')
			data->posX -= data->dirX * data->moveSpeed;
	if (data->WorldMap[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)] == '0')
			data->posY -= data->dirY * data->moveSpeed;
}

void move_left(t_data *data)
{
    double  perpDirX;
    double  perpDirY;

    perpDirX = data->dirY;
    perpDirY = -data->dirX;   
    if (data->WorldMap[(int)(data->posX + perpDirX * data->moveSpeed)][(int)(data->posY)] == '0')
        data->posX += perpDirX * data->moveSpeed;
    if (data->WorldMap[(int)(data->posX)][(int)(data->posY + perpDirY * data->moveSpeed)] == '0')
        data->posY += perpDirY * data->moveSpeed;
}

void move_right(t_data *data)
{
    double  perpDirX;
    double  perpDirY;
    
    perpDirX = -data->dirY;
    perpDirY = data->dirX;
    if (data->WorldMap[(int)(data->posX + perpDirX * data->moveSpeed)][(int)(data->posY)] == '0')
        data->posX += perpDirX * data->moveSpeed;
    if (data->WorldMap[(int)(data->posX)][(int)(data->posY + perpDirY * data->moveSpeed)] == '0')
        data->posY += perpDirY * data->moveSpeed;
}
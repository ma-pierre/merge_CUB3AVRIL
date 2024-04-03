/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:40:55 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/03 01:15:55 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	open_for_the_xpm(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY | __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	open_for_the_map(t_map *map_struct)
{
	map_struct->fd = open(map_struct->map_name, O_RDONLY | __O_DIRECTORY);
	if (map_struct->fd > 0)
	{
		close(map_struct->fd);
		return (EXIT_FAILURE);
	}
	map_struct->fd = open(map_struct->map_name, O_RDONLY);
	if (map_struct->fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	alloc_and_stock_lines(t_map *map_struct)
{
	if (open_for_the_map(map_struct) == -1)
		return (EXIT_FAILURE);
	map_struct->map = ft_calloc(map_struct->y + 1, sizeof(char *));
	if (!map_struct->map)
	{
		close(map_struct->fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

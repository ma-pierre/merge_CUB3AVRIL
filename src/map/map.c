/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:52:20 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/03 01:33:33 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	nb_lines_and_col(t_map *map_struct)
{
	int	lines;
	int	nb_of_cols;

	nb_of_cols = 0;
	if (open_for_the_map(map_struct) == 1)
	{
		ft_putendl_fd_cub(INV_FILE_NOT_FOUND, 2);
		return (EXIT_FAILURE);
	}
	lines = 0;
	while (1)
	{
		map_struct->line = get_next_line(map_struct->fd);
		if (map_struct->line == NULL)
			break ;
		actualize_nb_of_col(map_struct->line, &nb_of_cols);
		free(map_struct->line);
		lines++;
	}
	close(map_struct->fd);
	map_struct->y = lines;
	map_struct->x = nb_of_cols;
	return (0);
}

char	**read_file_lines(t_map *map_struct)
{
	int	i;

	if (alloc_and_stock_lines(map_struct) == 1)
	{
		ft_putendl_fd_cub("Error\nAt read_file_lines", 2);
		return (NULL);
	}
	i = 0;
	while (i <= map_struct->y)
	{
		map_struct->line = get_next_line(map_struct->fd);
		if (!map_struct->line)
			break ;
		trim_new_line(map_struct->line);
		map_struct->map[i] = map_struct->line;
		i++;
	}
	map_struct->map[i] = NULL;
	close(map_struct->fd);
	return (map_struct->map);
}

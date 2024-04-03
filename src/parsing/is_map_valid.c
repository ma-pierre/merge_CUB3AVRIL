/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:57:11 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/03 16:22:05 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_integrity(t_map *map_struct, t_config *config)
{
	if (is_map_border_closed(map_struct, config, map_struct->map))
	{
		free_config(config);
		exit(EXIT_FAILURE);
	}
	if (under_the_map(config) == 1)
	{
		free_config(config);
		exit(EXIT_FAILURE);
	}
}

void	validate_map_characters_and_position(t_map *map_struct,
		t_config *config)
{
	int	i;
	int	j;

	j = 0;
	i = map_struct->i_end_of_tc - 1;
	while (map_struct->map[map_struct->i_end_of_tc])
	{
		while (map_struct->map[map_struct->i_end_of_tc][j] == ' ')
			j++;
		if ((map_struct->map[map_struct->i_end_of_tc][j] != '\0')
			&& (map_struct->map[map_struct->i_end_of_tc][j] != '\n'))
			break ;
		map_struct->i_end_of_tc++;
	}
	map_struct->j_end_of_tc = j;
	while (map_struct->map[i + 1])
	{
		j = 0;
		while (map_struct->map[i + 1][j])
		{
			if (is_valid_scene_character(map_struct->map[i + 1][j], map_struct))
			{
				printf(INVALID_CHAR_MSG, i, j);
				free_config(config);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	if (map_struct->flag_pos != 1)
	{
		ft_putendl_fd_cub(INVALID_POSITION, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
}

void	find_map_boundaries(t_map *map_struct, t_config *config)
{
	int	j;

	map_struct->i_begin_the_map = map_struct->i_end_of_tc;
	printf(" endo of texture and color + spaces : %s\n", map_struct->map[map_struct->i_end_of_tc]);
	printf(" endo of texture and color + spaces + 1: %s\n", map_struct->map[map_struct->i_end_of_tc + 1]);

	while (map_struct->map[map_struct->i_begin_the_map])
	{
		j = 0;
		while (map_struct->map[map_struct->i_begin_the_map][j] == ' '
				|| map_struct->map[map_struct->i_begin_the_map][j] == '\0'
				|| map_struct->map[map_struct->i_begin_the_map][j] == '\n')
			j++;
		if (map_struct->map[map_struct->i_begin_the_map][j] != '\0'
				|| map_struct->map[map_struct->i_begin_the_map][j] != '\n'
				|| map_struct->map[map_struct->i_begin_the_map][j] != ' ')
			break ;
			//incrementer que si au bout de la ligne 
		
		map_struct->i_begin_the_map++;
	}
	if (!map_struct->map[map_struct->i_begin_the_map])
	{
		ft_putendl_fd_cub(ERROR_MAP_EMPTY, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
}

void	validate_texture_files(t_config *config)
{
	if (check_if_xpm(config->north_texture)
		|| check_if_xpm(config->south_texture)
		|| check_if_xpm(config->east_texture)
		|| check_if_xpm(config->west_texture))
	{
		ft_putendl_fd_cub(INV_EXT_XPM, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	if (open_for_the_xpm(config->north_texture)
		|| open_for_the_xpm(config->south_texture)
		|| open_for_the_xpm(config->east_texture)
		|| open_for_the_xpm(config->west_texture))
	{
		ft_putendl_fd_cub(INV_XPM_FILE_NOT_FOUND, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
}

void	validate_texture_and_color(t_map *map_struct, t_config *config)
{
	int	i;

	i = 0;
	while (map_struct->map[i])
	{
		if (!check_texture_and_color(map_struct->map[i], config))
			error_exit(config, INVALID_TEXT_COL);
		if (config->flag == 6)
			break ;
		else
			i++;
	}
	if (config->flag != 6)
		error_exit(config, INVALID_TEXT_COL);
	map_struct->i_end_of_tc = i + 1;
}

void	setup_initial_config(t_config *config)
{
	config->ceiling_color = -1;
	config->floor_color = -1;
}

int	is_map_valid(t_map *map_struct, t_config *config)
{
	setup_initial_config(config);
	validate_texture_and_color(map_struct, config);
	validate_texture_files(config);
	find_map_boundaries(map_struct, config);
	validate_map_characters_and_position(map_struct, config);
	check_map_integrity(map_struct, config);
	print_the_map(map_struct->map);
	return (EXIT_SUCCESS);
}

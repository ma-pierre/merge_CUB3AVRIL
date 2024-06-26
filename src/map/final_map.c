/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:49:21 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/03 16:15:07 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**malloc_the_map(t_config *config, int i)
{
	int		j;
	char	**map_cpy;

	i = config->map_struct->end_i - config->map_struct->i_begin_the_map;
	map_cpy = ft_calloc((i + 2), sizeof(char *));
	if (map_cpy == NULL)
	{
		ft_putendl_fd_cub("Error\nMemory allocation failed.\n", 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (j <= config->map_struct->end_i - config->map_struct->i_begin_the_map)
	{
		map_cpy[j] = ft_calloc((config->map_struct->x + 1), sizeof(char));
		if (map_cpy[j] == NULL)
		{
			ft_putendl_fd_cub("Error\nMemory allocation failed.\n", 2);
			free_tab(map_cpy);
			free_config(config);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	return (map_cpy);
}

void	retrieve_the_final_map(t_map *map_struct, t_config *config)
{
	int		i;
	int		j;
	char	**map_final;
	int		i_final;

	i = 0;
	i_final = 0;
	map_final = malloc_the_map(config, i);
	i = map_struct->i_begin_the_map;
	printf("debut carte : %s\n", map_struct->map[map_struct->i_begin_the_map]);
	j = 0;
	while (i <= map_struct->end_i)
	{
		j = 0;
		while (map_struct->map[i][j])
		{
			if (map_struct->map[i][j] == ' ')
				map_final[i_final][j] = '0';
			else
				map_final[i_final][j] = map_struct->map[i][j];
			j++;
		}
		i++;
		i_final++;
	}
	free_tab(map_struct->map);
	map_struct->map = map_final;
}

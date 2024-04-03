/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:45:06 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/03 16:37:59 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_first_line(t_map *map_struct, t_config *config, char **map)
{
	int	i;
	int	j;

	while (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc])
	{
		if (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc] != '1')
		{
			printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc,
					map_struct->j_end_of_tc - 1);
			free_config(config);
			exit(EXIT_FAILURE);
		}
		map_struct->j_end_of_tc++;
	}
	i = map_struct->i_end_of_tc;
	j = map_struct->j_end_of_tc;
	while (map[i][j])
	{
		if (map[i][j] != '1')
		{
			printf(MAP_NOT_CLOSED, i, j - 1);
			free_config(config);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

int	check_player(char c)
{
	return ((c == FREE_WAY || c == PLAYER_NORTH || c == PLAYER_SOUTH
			|| c == PLAYER_EAST || c == PLAYER_WEST));
}

void	check_particular_cases(t_config *config, t_map *map_struct, char **map)
{
	if ((map_struct->j_end_of_tc >= ft_strlen_cub(map[map_struct->i_end_of_tc
				+ 1]))
		|| (map_struct->j_end_of_tc >= ft_strlen_cub(map[map_struct->i_end_of_tc
				- 1])))
	{
		printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc
				- 1);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	else if (map_struct->j_end_of_tc == 0)
	{
		printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc
				- 1);
		free_config(config);
		exit(EXIT_FAILURE);
	}
}

void	parsing_part(t_config *config, char *argv)
{
	config->map_struct = init_the_map_struct(argv);
	if (!config->map_struct)
	{
		ft_putendl_fd_cub(FAIL_INIT_STRUCT, 2);
		exit (EXIT_FAILURE);
	}
	if (check_if_dotcub(argv))
	{
		ft_putendl_fd_cub(INV_EXT, 2);
		free_config(config);
		exit (EXIT_FAILURE);
	}
	if (count_and_read(config->map_struct))
	{
		free_config(config);
		exit (EXIT_FAILURE);
	}
	if (parsing(config->map_struct, config))
	{
		free_config(config);
		exit (EXIT_FAILURE);
	}
	retrieve_the_final_map(config->map_struct, config);
	print_the_map(config->map_struct->map);
	close(config->map_struct->fd);
}

int	main(int argc, char *argv[])
{
	t_config	*config;
	t_data		data;

	config = ft_calloc(1, sizeof(t_config));
	if (!config)
		return (1);
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments.");
		return (EXIT_FAILURE);
	}
	parsing_part(config, argv[1]);
	////////////////////////////////
	print_the_map(config->map_struct->map);
	data.config = config;
	data.player_start_dir = config->map_struct->player_start_dir;
	data.game_map = config->map_struct->map;
	int i = 0;
	int j;
	while(data.game_map[i])
	{
			j = 0;
		while(data.game_map[i][j])
		{ 
			if (data.game_map[i][j] == data.player_start_dir)
			{
				data.pos_x = (double)j ;
				data.pos_y = (double)i ;
				data.game_map[i][j] = 0;
				printf(" i = %d j = %d \n", i , j);
			}
			j++;
		}
		i++;
	}
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		return (1);
	}
	init_player_direction(&data);
	data.move_speed = 0.04;
	data.rot_speed = 0.04;
	data.map_witdh = 0;
	data.map_height = 0;
	readtab(&data);
	
	init_keys(&data);
	data.win = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "eya et marine");
	mlx_hook(data.win, KEYPRESS, (1L<<0), key_press, &data);
	mlx_hook(data.win, KEYRELEASE, (1L<<1), key_release, &data);
	mlx_loop_hook(data.mlx, &do_frame, &data);
	mlx_hook(data.win, 17, 0, &clean_game, &data);
	mlx_loop(data.mlx);
	close(config->map_struct->fd);
	//free_config(config);	
	//free_config(config);
	return (0);
}

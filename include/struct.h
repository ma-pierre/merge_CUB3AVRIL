/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:05:10 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/03 02:17:59 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define	STRUCT_H


typedef struct s_map
{
	char	**map;
	int y;      // nb de lignes
	int x;      // nb de colonnes
	char *line; //line recuperee avec le gnl
	char	*col;
	char	*map_name;
	int		fd;
	int		i_end_of_tc;
	int		j_end_of_tc;
	int		i_begin_the_map;
	int		j_end_of_map;
	int		beg_index;
	int		end_i;
	int		end_j;
	char	player_start_dir;
	int		flag_pos;
}			t_map;

typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	int		flag;
	t_map	*map_struct;

}			t_config;

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_key
{
    int     s;
    int     w;
    int     d;
    int     a;
	int     esc;
    int     l_arrow;
    int     r_arrow;
}   			t_key;

typedef	struct s_raycast
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
//	int		hit;
//	int		side;
}				t_raycast;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct	s_data
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double	moveSpeed;
	double	rotSpeed;
	char	**WorldMap;
	char	player_start_dir;
	t_key   keys;
	void	*mlx;
	void	*win;
	t_config	*config;
	t_raycast	raycast_var;
}				t_data;

/*
typedef struct	s_data
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double	moveSpeed;
	double	rotSpeed;
	char	player_start_dir;
	    void    *minimap_img;  // Image de la minimap
    char    *minimap_addr;
	 int     bits_per_pixel;
    int     line_length;
    int     endian;

	t_key   keys;
	void	*mlx;
	void	*win;
}				t_data;
*/

#endif
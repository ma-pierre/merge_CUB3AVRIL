
#include "cub3D.h"
#include "struct.h"

t_map	*init_the_map_struct(char *filename)
{
	t_map	*map_struct;

	map_struct = ft_calloc(1, sizeof(t_map));
	if (!map_struct)
		return (NULL);
	map_struct->map_name = filename;
	return (map_struct);
}

int	count_and_read(t_map *map_struct)
{
	if (nb_lines_and_col(map_struct))
		return (EXIT_FAILURE);
	if (!read_file_lines(map_struct))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
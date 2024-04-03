/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:53:27 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/03 01:29:44 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_map *map_struct, t_config *config)
{
	if (map_empty(map_struct, config))
		return (EXIT_FAILURE);
	else if (is_map_valid(map_struct, config))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

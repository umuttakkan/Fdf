/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:33:42 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 13:38:28 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	stack_to_arrays(t_coord_val **coords, t_map *map)
{
	t_coord_val	*coord;
	size_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coord_arr = malloc(arr_size);
	map->colors_arr = malloc(arr_size);
	if (!map->colors_arr || !map->coord_arr)
		ft_printf("Error\n");
	i = map->width * map->height - 1;
	while (1)
	{
		if (!(*coords))
			break ;
		coord = pop(coords);
		map->coord_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
}

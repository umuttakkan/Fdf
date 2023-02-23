/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:07:06 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 14:46:46 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		i;

	i = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coord_arr[i];
	if (map->colors_arr[i] == -1)
		point.color = get_default_color(point.z, map);
	else
		point.color = map->colors_arr[i];
	return (point);
}

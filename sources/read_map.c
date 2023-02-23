/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:29:43 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 15:25:20 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord_val	*new_coord(char *coords_arr)
{
	t_coord_val		*coords_val;
	char			**line;

	coords_val = (t_coord_val *)malloc(sizeof(t_coord_val));
	if (!coords_val)
		ft_printf("Memmory Allocation Error\n");
	line = ft_split(coords_arr, ',');
	if (!line)
		ft_printf("Map Reading Error!\n");
	coords_val->z = ft_atoi(line[0]);
	if (line[1])
		coords_val->color = ft_atoi_base(line[1]);
	else
		coords_val->color = -1;
	coords_val->next = NULL;
	free_strsplit_addr(line);
	return (coords_val);
}

void	parse_line(t_coord_val **coords, t_map *map, char **coords_arr)
{
	int	width;

	width = 0;
	while (*coords_arr)
	{
		push(coords, new_coord(*(coords_arr++)));
		width++;
	}
	if (map->height == 0 || map->width != width)
		map->width = width;
	else if (map->width != width)
		ft_printf("Map Parsing Error!");
}

void	read_map(int fd, t_coord_val **coords, t_map *map)
{
	char	*line;
	char	**coords_arr;

	line = get_next_line(fd);
	while (line != NULL)
	{
		coords_arr = ft_split(line, ' ');
		if (!coords_arr)
			ft_printf("Map Reading Error!\n");
		parse_line(coords, map, coords_arr);
		map->height++;
		free_strsplit_addr(coords_arr);
		free(line);
		line = get_next_line(fd);
	}
}

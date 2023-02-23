/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:22:43 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 13:42:47 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		ft_printf("Error\n");
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_printf("Memmory Allocation Error!\n");
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "UMUT_FDF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->size_line, &fdf->endian);
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		ft_printf("Memmory Allocation Error!\n");
	return (fdf);
}

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->coord_arr = NULL;
	map->colors_arr = NULL;
	return (map);
}

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->projection = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_divisor = 1;
	camera->zoom = HEIGHT / fdf->map->height / 2;
	return (camera);
}

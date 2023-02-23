/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:41:16 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 13:40:29 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

double	norm(t_drawp delta)
{
	double	mag;

	mag = (delta.x * delta.x) + (delta.y * delta.y);
	mag = sqrt(mag);
	return (mag);
}

void	draw_line(t_point f, t_point s, t_fdf *fdf)
{
	t_drawp	delta;
	t_drawp	cur;
	t_point	cur_color;
	double	magnitude;

	delta.x = s.x - f.x;
	delta.y = s.y - f.y;
	if (delta.x == 0 && delta.y == 0)
		return ;
	magnitude = norm(delta);
	if (magnitude < 1)
		magnitude = 1;
	delta.x = delta.x / magnitude;
	delta.y = delta.y / magnitude;
	cur.x = 0;
	cur.y = 0;
	while (magnitude-- > 0)
	{
		cur_color.x = f.x + cur.x;
		cur_color.y = f.y + cur.y;
		put_pixel(fdf, cur.x + f.x, cur.y + f.y, get_color(cur_color, f, s));
		cur.x += delta.x;
		cur.y += delta.y;
	}
}

void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU_WIDTH)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				draw_line(project(new_point(x, y, map), fdf),
					project(new_point(x + 1, y, map), fdf), fdf);
			if (y != map->height - 1)
				draw_line(project(new_point(x, y, map), fdf),
					project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_menu(fdf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:44:11 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 15:26:05 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_macos.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_PLUS || key == MOUSE_SCROLL_UP)
		fdf->camera->zoom++;
	else if (key == MAIN_PAD_MINUS || key == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom--;
	if (fdf->camera->zoom < 1)
		fdf ->camera->zoom = 1;
	draw(fdf->map, fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_RIGHT)
		fdf->camera->x_offset += 10;
	if (key == ARROW_LEFT)
		fdf->camera->x_offset -= 10;
	if (key == ARROW_UP)
		fdf->camera->y_offset -= 10;
	if (key == ARROW_DOWN)
		fdf->camera->y_offset += 10;
	draw(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_2)
		fdf->camera->alpha += 0.05;
	if (key == MAIN_PAD_8)
		fdf->camera->alpha -= 0.05;
	if (key == MAIN_PAD_4)
		fdf->camera->beta -= 0.05;
	if (key == MAIN_PAD_6)
		fdf->camera->beta += 0.05;
	if (key == MAIN_PAD_1)
		fdf->camera->gamma += 0.05;
	if (key == MAIN_PAD_7)
		fdf->camera->gamma -= 0.05;
	draw(fdf->map, fdf);
}

void	flatten(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_LESS)
		fdf->camera->z_divisor -= 0.1;
	else if (key == MAIN_PAD_MORE)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	draw(fdf->map, fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == MAIN_PAD_I)
		fdf->camera->projection = ISO;
	else if (key == MAIN_PAD_P)
		fdf->camera->projection = PARALLEL;
	draw(fdf->map, fdf);
}

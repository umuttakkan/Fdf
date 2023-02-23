/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:47:37 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 13:44:44 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_macos.h"

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == MAIN_PAD_PLUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_DOWN || key == ARROW_UP)
		move(key, fdf);
	else if (key == MAIN_PAD_0 || key == MAIN_PAD_1
		|| key == MAIN_PAD_2 || key == MAIN_PAD_4
		|| key == MAIN_PAD_5 || key == MAIN_PAD_6
		|| key == MAIN_PAD_7 || key == MAIN_PAD_8)
		rotate(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, fdf);
	else if (key == MAIN_PAD_I || key == MAIN_PAD_P)
		change_projection(key, fdf);
	return (0);
}

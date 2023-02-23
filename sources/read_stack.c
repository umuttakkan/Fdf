/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:13:19 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 14:22:35 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	push(t_coord_val **coords, t_coord_val *new)
{
	if (!new)
		return ;
	new->next = *coords;
	*coords = new;
}

t_coord_val	*pop(t_coord_val **coordinate)
{
	t_coord_val	*data;

	data = NULL;
	if (*coordinate)
	{
		data = *coordinate;
		*coordinate = (*coordinate)->next;
	}
	return (data);
}

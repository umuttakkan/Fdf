/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:14:49 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/23 15:43:42 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*map;
	t_coord_val	*coords;
	t_fdf		*fdf;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			ft_printf("File Not Found\n");
		map = map_init();
		coords = NULL;
		read_map(fd, &coords, map);
		fdf = fdf_init(map);
		stack_to_arrays(&coords, map);
		fdf->camera = camera_init(fdf);
		draw(fdf->map, fdf);
		setup_controls(fdf);
		mlx_loop(fdf->mlx);
	}
	else
		ft_printf("%s", "Argument Error!\n");
	return (0);
}

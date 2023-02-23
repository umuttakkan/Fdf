/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:46:04 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 15:55:01 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT  1080
# define WIDTH  1920
# define MENU_WIDTH  250

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include "../ft_printf/ft_printf.h"	
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef enum s_projection
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct s_coord_val
{
	int					z;
	int					color;
	struct s_coord_val	*next;

}	t_coord_val;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_drawp
{
	double				x;
	double				y;
}	t_drawp;

typedef struct s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;			
}	t_camera;

typedef struct s_map
{
	int	width;
	int	height;
	int	*coord_arr;
	int	*colors_arr;
	int	z_min;
	int	z_max;
}	t_map;

typedef struct s_mouse
{
	char	is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_camera	*camera;
	t_map		*map;
	t_mouse		*mouse;
}	t_fdf;

t_map		*map_init(void);
t_fdf		*fdf_init(t_map *map);
t_camera	*camera_init(t_fdf *fdf);
t_point		project(t_point p, t_fdf *fdf);
t_point		new_point(int x, int y, t_map *map);
t_coord_val	*new_coord(char *coords_arr);
t_coord_val	*pop(t_coord_val **stack);
void		parse_line(t_coord_val **coords, t_map *map, char **coords_arr);
void		read_map(int fd, t_coord_val **coords, t_map *map);
void		stack_to_arrays(t_coord_val **coordinate, t_map *map);
void		draw_line(t_point f, t_point s, t_fdf *fdf);
void		draw_background(t_fdf *fdf);
void		draw(t_map *map, t_fdf *fdf);
int			key_press(int key, void *param);
int			mouse_move(int x, int y, void *param);
int			mouse_release(int button, int x, int y, void *param);
int			mouse_press(int button, int x, int y, void *param);
int			get_color(t_point current, t_point start, t_point end);
int			get_light(int start, int end, double percentage);
int			get_default_color(int z, t_map *map);
int			ft_atoi_base(const char *str);
int			ft_isdigit_base(char c);
void		setup_controls(t_fdf *fdf);
void		zoom(int key, t_fdf *fdf);
void		move(int key, t_fdf *fdf);
void		rotate(int key, t_fdf *fdf);
void		flatten(int key, t_fdf *fdf);
void		change_projection(int key, t_fdf *fdf);
void		print_menu(t_fdf *fdf);
void		free_strsplit_addr(char **data);
void		push(t_coord_val **stack, t_coord_val *new);
void		put_pixel(t_fdf *fdf, int x, int y, int color);
double		norm(t_drawp delta);
double		percent(int start, int end, int current);

#endif

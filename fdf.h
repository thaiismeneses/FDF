/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:02:15 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/09 17:53:53 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <math.h>

# define WIN_WIDTH  1920
# define WIN_HEIGHT 1080

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_map
{
	int		**matrix;
	int		height;
	int		width;
	int		z;
	int		z2;
	int		zoom;
	int		color;
	int		move_x;
	int		move_y;
	double	angle_x;
	double	angle_y;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_point	*point;
}	t_mlx;

void	init_mlx(t_mlx *data);
int		kill_fdf(t_mlx *data);
void	check_file(char *file);
int		get_height(char *file);
int		get_width(char *file);
void	malloc_matrix(t_map *map);
void	fill_matrix(int *z_line, char *line);
void	read_file(char *file, t_map *map);
void	free_map(t_map *map);
void	algorithm_brensenham(t_point point, float x2, float y2, t_mlx *data);
void	draw(t_mlx *data);
void	config_map(t_point *point, float *x2, float *y2, t_mlx *data);
void	config_zoom(t_point *point, float *x2, float *y2, t_mlx *data);
void	zoom(int keycode, t_mlx *data);
int		paint(int *z);
void	isometric(float *x, float *y, int z, t_mlx *data);
void	config_arrows(t_point *point, float *x2, float *y2, t_mlx *data);
void	init_map(t_map *map);
void	zoom(int keycode, t_mlx *data);
void	arrows(int keycode, t_mlx *data);
void	rotate(int keycode, t_mlx *data);
void	views(int keycode, t_mlx *data);
#endif

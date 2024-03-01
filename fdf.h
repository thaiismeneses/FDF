/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:31:29 by thfranco         #+#    #+#             */
/*   Updated: 2024/03/01 19:06:58 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>

# define WIN_WIDTH 650
# define WIN_HEIGHT 600

typedef struct s_mlx
{
	int		**z_matrix;
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		z;
	int		z2;
	float		x_increment;
	float		y_increment;
	float		x;
	float		y;
	void	*mlx;
	void	*win;
}			t_mlx;

int		key_board(int keycode, t_mlx *data);
int		arrow_control(int keycode, t_mlx *data);
int		get_height(char *file_name);
int		get_width(char *file_name);
void	fill_matrix(int *z_line, char *data);
void	read_file(char *file_name, t_mlx *data);
void	algorithm_brensenham(float x2, float y2, t_mlx *data);
void	draw(t_mlx *data);
int		paint(int z);
void	isometric(float *x, float *y, int z);
void	defaults(t_mlx *data);
#endif

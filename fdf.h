/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:31:29 by thafranco         #+#    #+#             */
/*   Updated: 2024/02/26 20:07:52 by thfranco         ###   ########.fr       */
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

# define WIN_WIDTH 1080
# define WIN_HEIGHT 1920

typedef struct s_mlx
{
	int		**z_matrix;
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx;
	void	*win;
}			t_mlx;

# define K_UP 0xff52
# define K_DOWN 0xff54
# define K_LEFT 0xff51
# define K_RIGHT 0xff53
# define K_Q 0x0071
# define K_E 0x0065
# define K_W 0x0077
# define K_S 0x0073
# define K_A 0x0061
# define K_D 0x0064
# define K_ESC 0xff1b

int		key_board(int keysym, t_mlx *data);
int		arrow_control(int key, t_mlx *data);
int		get_height(char *file_name);
int		get_width(char *file_name);
void	fill_matrix(int *z_line, char *data);
void	read_file(char *file_name, t_mlx *data);
void	algorithm_brensenham(float x, float y, float x2, float y2, t_mlx *data);
void	draw(t_mlx *data);
int		paint(int z);
void	isometric(float *x, float *y, int z);
#endif

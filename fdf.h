/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:31:29 by thafranco         #+#    #+#             */
/*   Updated: 2024/02/18 20:23:42 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WIN_WIDTH 600
# define WIN_HEIGHT 500

typedef struct s_mlx{
	int	**z_matrix;
	int	width;
	int	height;

	void	*mlx;
	void	*win;
}			t_mlx;

# ifdef __APPLE__
#	define K_UP 126
#	define K_DOWN 125
#	define K_LEFT 123
#	define K_RIGHT 124
#	define K_Q 12
#	define K_E 14
#	define K_W 13
#	define K_S 1
#	define K_A 0
#	define K_D 2
#	define K_ESC 53
# elif __linux__
#	define K_UP 65362
#	define K_DOWN 65364
#	define K_LEFT 65361
#	define K_RIGHT 65363
#	define K_Q 113
#	define K_E 101
#	define K_W 119
#	define K_S 115
#	define K_A 97
#	define K_D 100
#	define K_ESC 65307
# endif

int	key_board(int keysym, t_mlx *data);
int	get_height(char *file_name);
int get_width(char *file_name);
void	fill_matrix(int *zline, char *data);
void	read_file(char *file_name, t_mlx *data);


# endif 

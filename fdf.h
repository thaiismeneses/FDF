/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:02:15 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/03 21:24:32 by thfranco         ###   ########.fr       */
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

# define WIN_WIDTH 650
# define WIN_HEIGHT 600

typedef struct s_map
{	
	int	**matrix;
	int	height;
	int	width;
	
} t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
} t_mlx;

//window
void	init_mlx(t_mlx *data);
int	kill_fdf(t_mlx *data);

//file.fdf
int	get_height(char *file);
int 	get_width(char *file);
void	malloc_matrix(t_map *map);
void	fill_matrix(int *z_line, char *line);
void	read_file(char *file, t_map *map);
void	free_map(t_map *map);
// init variable
//void	init(t_map *map);
#endif

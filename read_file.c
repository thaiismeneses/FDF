/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:21:52 by thafranco         #+#    #+#             */
/*   Updated: 2024/03/01 18:12:44 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		exit(-1);
	height = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		exit(-1);
	width = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	width = ft_count_words(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}
void	malloc_matrix(t_mlx *data)
{
	int	i;

	i = 0;
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height));
	while (i < data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1)); 
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nbr;
	int		i;

	nbr = ft_split(line, ' ');
	i = 0;
	while (nbr[i])
	{
		z_line[i] = ft_atoi(nbr[i]);
		free(nbr[i]);
		i++;
	}
	free(nbr);
}

void	read_file(char *file, t_mlx *data)
{
	int		fd;
	int		i;
	char	*line;
	
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	data->height = get_height(file);
	data->width = get_width(file);
	malloc_matrix(data);
	i = 0;
	while (line)
	{
		fill_matrix(data->z_matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

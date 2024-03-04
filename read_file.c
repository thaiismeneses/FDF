/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:00:10 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/04 11:05:00 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include <stdio.h>

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

void	malloc_matrix(t_map *map)
{
	int	i;

	i = 0;
	map->matrix = (int **)malloc(sizeof(int *) * (map->height));
	while (i < map->height)
		map->matrix[i++] = (int *)malloc(sizeof(int) * (map->width + 1)); 
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

void	read_file(char *file, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	map->height = get_height(file);
	map->width = get_width(file);
	malloc_matrix(map);
	i = 0;
	while (line)
	{
		fill_matrix(map->matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

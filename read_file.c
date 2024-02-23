/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:21:52 by thafranco         #+#    #+#             */
/*   Updated: 2024/02/22 21:27:02 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int fd;
	int height;
	char *line;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int get_width(char *file_name)
{
	int fd;
	int width;
	char *line;

	fd = open(file_name, O_RDONLY, 0);
	width = 0;
	line = get_next_line(fd);
	width = ft_count_words(line, ' ');	
	//free(line);
	close(fd);
	return(width);
}

void	fill_matrix(int *z_line, char *line)
{
	char **nbr;
	int	i;

	nbr = ft_split(line, ' ');
	i = 0;
	while (nbr[i])
	{
		z_line[i] = ft_atoi(nbr[i]);
		free(nbr[i]);
		i++;
	}
	(nbr);
}

void	read_file(char *file_name, t_mlx *data)
{
	int	fd;
	char	*line;
	int	i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	if (!data->height || !data->width)
		return ;
	fd =  open(file_name, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line && i <= data->height)
	{
		fill_matrix(data->z_matrix[i], line);
//		free(line);
		i++;
		line = get_next_line(fd);
		//if (i > data->height)
		//	break;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}

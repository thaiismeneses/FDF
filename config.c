/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:22:33 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/04 14:09:21 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->matrix = NULL;
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->z2 = 0;
	map->x_increment = 0;
	map->y_increment = 0;
}

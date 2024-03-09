/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:09:36 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/09 17:55:30 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".fdf", 4))
		exit (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:01:39 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/09 19:00:07 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include <unistd.h>

int	check_directions(t_data data)
{
	int	result;

	result = 0;
	if (file_exits(data.north)
		&& file_exits(data.south)
		&& file_exits(data.west)
		&& file_exits(data.east))
		result = 1;
	else
		error(27, "checker/directions.c", "Texture file not found", NULL);
	return (result);
}

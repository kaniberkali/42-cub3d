/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:33:24 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 17:16:13 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"

static int	is_inside_map(t_data *data, int x, int y)
{
	t_point	size;

	size.y = data->map_height;
	if (x >= 0 && y >= 0 && y < size.y)
	{
		size.x = ft_strlen(data->map[y]);
		if (x < size.x)
			return (1);
	}
	return (0);
}

int	check_wall(t_data *data, int x, int y)
{
	t_point	size;

	size.y = data->map_height;
	if (is_inside_map(data, x, y) && data->map[y][x] != CONTROL
		&& data->map[y][x] != WALL)
	{
		size.x = ft_strlen(data->map[y]);
		if (data->map[y][x] == SPACE)
			return (error(40, "checker/wall.c", \
				"There is space in the map", NULL));
		if (x == 0 || y == 0 || size.x - 1 == x || size.y - 1 == y)
			return (error(43, "checker/wall.c", \
				"The map is not surrounded by walls", NULL));
		data->map[y][x] = CONTROL;
		if (!check_wall(data, x, y + 1)
			|| !check_wall(data, x + 1, y)
			|| !check_wall(data, x, y - 1)
			|| !check_wall(data, x - 1, y))
			return (0);
	}
	return (1);
}

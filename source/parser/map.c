/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:42:27 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/13 10:46:54 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"
#include <stdlib.h>

static t_point	pass_space(t_data data, t_point point)
{
	while (data.value[point.y][point.x] == SPACE)
		point.x++;
	return (point);
}

static t_point	get_map_start_point(t_data data)
{
	int		control;
	t_point	point;
	t_point	start;

	control = 0;
	ft_memset(&point, 0, sizeof(point));
	while (data.value[point.y])
	{
		start.y = point.y;
		start.x = point.x;
		point = pass_space(data, point);
		while (data.value[point.y][point.x] == WALL
				|| data.value[point.y][point.x] == ROAD)
		{
			point.x++;
			control = 1;
		}
		point = pass_space(data, point);
		if (data.value[point.y][point.x] == '\0' && control)
			return (start);
		point.y++;
	}
	start.x = -1;
	start.y = -1;
	return (start);
}

static	t_data	set_player_point(t_data data)
{
	t_point	point;

	ft_memset(&point, 0, sizeof(point));
	while (data.map[point.x])
	{
		point.y = 0;
		while (data.map[point.x][point.y])
		{
			if (data.map[point.x][point.y] == CHAR_NORTH
			|| data.map[point.x][point.y] == CHAR_SOUTH
			|| data.map[point.x][point.y] == CHAR_EAST
			|| data.map[point.x][point.y] == CHAR_WEST)
				data.player = point;
			point.y++;
		}
		point.x++;
	}
	data.map_height = point.x;
	return (data);
}

static	t_data	set_map_value(t_point start, t_data data)
{
	int		map_size;
	int		i;

	i = 0;
	map_size = 0;
	while (data.value[start.y + map_size])
		map_size++;
	data.map = (char **)malloc(sizeof(char *) * (map_size + 3));
	if (!data.map)
		return (data.map = NULL, data);
	data.map[i] = create_map_line(data, "");
	if (!data.map[i++])
		return (data.map = NULL, data);
	while (data.value[start.y])
	{
		data.map[i] = create_map_line(data, data.value[start.y++]);
		if (!data.map[i++])
			return (data.map = NULL, data);
	}
	data.map[i] = create_map_line(data, "");
	if (!data.map[i])
		return (data.map = NULL, data);
	data.map[i + 1] = NULL;
	return (data);
}

t_data	parse_map(t_data data)
{
	t_point	start;

	start = get_map_start_point(data);
	if (start.x == -1 && start.y == -1)
		return (data.map = NULL, data);
	data = set_map_value(start, data);
	if (!data.map)
		return (data);
	data = set_player_point(data);
	return (data);
}

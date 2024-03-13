/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:58:11 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 18:52:32 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"

static void	restore_map(t_data *data, char perspective)
{
	int	i;
	int	q;

	i = 0;
	while (data->map[i])
	{
		q = 0;
		while (data->map[i][q])
		{
			if (data->map[i][q] == CONTROL)
				data->map[i][q] = ROAD;
			q++;
		}
		i++;
	}
	data->map[data->player.x][data->player.y] = perspective;
}

int	checker(t_data data)
{
	char	perspective;
	int		is_check;

	if (!(data.map && data.value
			&& data.north && data.south
			&& data.east && data.west))
		return (0);
	perspective = data.map[data.player.x][data.player.y];
	is_check = check_directions(data);
	if (is_check)
		is_check = check_floor_and_ceiling(data);
	if (is_check)
		is_check = check_wall(&data, data.player.y, data.player.x);
	if (is_check)
		restore_map(&data, perspective);
	return (is_check);
}

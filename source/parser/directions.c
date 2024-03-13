/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:29 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/09 18:24:05 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/libft/libft.h"
#include "../library/cub3d.h"

t_data	parse_directions(t_data data)
{
	data.north = ft_strtrim(get_data_value(data, NORTH), " ");
	if (!data.north)
		error(20, "parser/directions.c",
			"Memory allocation failed", NULL);
	data.south = ft_strtrim(get_data_value(data, SOUTH), " ");
	if (!data.north)
		error(24, "parser/directions.c",
			"Memory allocation failed", NULL);
	data.east = ft_strtrim(get_data_value(data, EAST), " ");
	if (!data.north)
		error(28, "parser/directions.c",
			"Memory allocation failed", NULL);
	data.west = ft_strtrim(get_data_value(data, WEST), " ");
	if (!data.north)
		error(32, "parser/directions.c",
			"Memory allocation failed", NULL);
	return (data);
}

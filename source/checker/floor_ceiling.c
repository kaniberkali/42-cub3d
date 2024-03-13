/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:19:30 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/09 19:00:23 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include <unistd.h>

int	check_floor_and_ceiling(t_data data)
{
	int	result;

	result = 0;
	if (data.floor.r >= 0 && data.floor.r <= 255
		&& data.floor.g >= 0 && data.floor.g <= 255
		&& data.floor.b >= 0 && data.floor.b <= 255
		&& data.ceiling.r >= 0 && data.ceiling.r <= 255
		&& data.ceiling.g >= 0 && data.ceiling.g <= 255
		&& data.ceiling.b >= 0 && data.ceiling.b <= 255)
		result = 1;
	else
		error(29, "checker/floor_ceiling.c", "Color codes are not rgb", NULL);
	return (result);
}

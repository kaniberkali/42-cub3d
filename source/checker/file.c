/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:30:28 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 13:22:15 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"

int	check_file_name(char *map)
{
	int	result;

	result = 0;
	if (!ft_strcmp(&map[ft_strlen(map)-4], ".cub"))
		result = 1;
	else
		error(24, "checker/file.c", "File type is not supported", NULL);
	return (result);
}

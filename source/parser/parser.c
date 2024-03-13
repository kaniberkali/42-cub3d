/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:11:11 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 13:12:27 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"

t_data	parser(char	*file)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	data.value = ft_split(file, '\n');
	if (!data.value)
		return (error(23, "parser/parser.c",
				"Memory allocation failed", NULL), data);
	data = parse_directions(data);
	data = parse_floor_and_ceiling(data);
	data = parse_map(data);
	return (data);
}

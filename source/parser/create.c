/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:10:29 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 19:11:48 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"
#include <stdlib.h>

char	*create_map_line(t_data data, char *line)
{
	int		length;
	int		most_longer;
	int		i;
	char	*result;

	i = 0;
	result = ft_strdup(" ");
	if (!result)
		return (error(86, "parser/map.c", \
		"Memory allocation failed", NULL), NULL);
	result = ft_strjoin(result, line);
	if (!result)
		return (error(89, "parser/map.c", \
			"Memory allocation failed", NULL), NULL);
	most_longer = get_longer_line_length(data.value);
	length = ft_strlen(line);
	while (i < (most_longer - length) + 1)
	{
		result = ft_strjoin(result, " ");
		if (!result)
			return (error(89, "parser/map.c", \
					"Memory allocation failed", NULL), NULL);
		i++;
	}
	return (result);
}

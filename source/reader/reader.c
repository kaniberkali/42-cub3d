/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:14:09 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 12:54:08 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*reader(char *file)
{
	int		fd;
	int		status;
	char	*result;
	char	*map;

	status = 1;
	result = NULL;
	fd = open(file, O_RDONLY);
	map = (char *)malloc(sizeof(char) * 2);
	if (!map)
		exit(error(31, "reader/reader.c",
				"Memory allocation failed", NULL));
	if (fd == -1)
		exit(error(34, "reader/reader.c",
				"File could not be opened", map));
	while (status != 0)
	{
		status = read(fd, map, 1);
		map[1] = '\0';
		result = ft_strjoin(result, map);
		if (!result)
			exit(error(42, "reader/reader.c", \
					"Memory allocation failed", map));
	}
	return (close(fd), free(map), result);
}

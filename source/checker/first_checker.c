/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:48:17 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 14:46:37 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"

static int	is_line_field(char *line)
{
	return (!ft_strncmp(line, CHECK_NORTH, 3)
		|| !ft_strncmp(line, CHECK_SOUTH, 3)
		|| !ft_strncmp(line, CHECK_WEST, 3) || !ft_strncmp(line, CHECK_EAST, 3)
		|| !ft_strncmp(line, CHECK_FLOOR, 2)
		|| !ft_strncmp(line, CHECK_CEILING, 2));
}

static t_file_fields	file_fields_counter(char *line, t_file_fields fields)
{
	if (!ft_strncmp(line, CHECK_NORTH, 3))
		fields.north++;
	if (!ft_strncmp(line, CHECK_SOUTH, 3))
		fields.south++;
	if (!ft_strncmp(line, CHECK_WEST, 3))
		fields.west++;
	if (!ft_strncmp(line, CHECK_EAST, 3))
		fields.east++;
	if (!ft_strncmp(line, CHECK_FLOOR, 2))
		fields.floor++;
	if (!ft_strncmp(line, CHECK_CEILING, 2))
		fields.ceiling++;
	return (fields);
}

static int	get_after_fields_index(char *file)
{
	t_file_fields	fields;
	int				i;

	i = 0;
	ft_memset(&fields, 0, sizeof(fields));
	while (file[i])
	{
		if (is_line_field(&file[i]))
		{
			fields = file_fields_counter(&file[i], fields);
			while (file[i] && file[i] != '\n')
				i++;
			if (fields.north == 1 && fields.west == 1
				&& fields.east == 1 && fields.floor == 1
				&& fields.ceiling == 1 && fields.south == 1)
				return (i);
		}
		else if (file[i] != '\n')
			return (error(62, "checker/first_checker.c", \
				"Invalid character found", NULL));
		i++;
	}
	return (error(66, "checker/first_checker.c", \
		"Mandatory parameter missing in file", NULL));
}

static	int	check_alien_chars(char *file)
{
	int	start_counter;
	int	i;

	i = 0;
	while (file[i])
	{
		if (!(file[i] == SPACE || file[i] == ROAD
				|| file[i] == WALL || file[i] == CHAR_NORTH
				|| file[i] == CHAR_SOUTH || file[i] == CHAR_WEST
				|| file[i] == CHAR_EAST || file[i] == '\n'))
			return (error(82, "checker/first_checker.c", \
				"Invalid character found", NULL));
		i++;
	}
	start_counter = count_char_in_string(file, CHAR_NORTH);
	start_counter += count_char_in_string(file, CHAR_SOUTH);
	start_counter += count_char_in_string(file, CHAR_WEST);
	start_counter += count_char_in_string(file, CHAR_EAST);
	if (start_counter != 1)
		return (error(91, "checker/first_checker.c", \
			"Invalid character found", NULL));
	return (1);
}

int	first_checker(char *file)
{
	int	i;

	i = get_after_fields_index(file);
	if (!i || !check_alien_chars(&file[i]))
		return (0);
	while (file[i] && (file[i] != ' ' && file[i] != '1' && file[i] != '0'))
	{
		if (file[i] == '\n')
			i++;
		else
			return (error(108, "checker/first_checker.c", \
				"Invalid character found", NULL));
	}
	if (file[i])
	{
		while (file[i++])
			if (file[i] == '\n' && file[i + 1] == '\n')
				return (error(115, "checker/first_checker.c", \
					"There are places on the map", NULL));
	}
	else
		return (error(119, "checker/first_checker.c", \
			"No map found in file", NULL));
	return (1);
}

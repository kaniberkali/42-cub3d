/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:30:46 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 12:32:52 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"

char	*get_data_value(t_data data, char *field)
{
	int	i;

	i = 0;
	while (data.value[i][0])
	{
		if (!ft_strncmp(data.value[i], field, ft_strlen(field)))
			return (ft_strdup(&data.value[i][ft_strlen(field) + 1]));
		i++;
	}
	return (NULL);
}

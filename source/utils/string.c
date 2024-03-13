/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:53:45 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/13 11:37:00 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_char_in_string(char *str, char c)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == c)
			result++;
		i++;
	}
	return (result);
}

int	ft_strlen_2d(char **str)
{
	int	i;

	i = 0;
	while (!!str && str[i])
		i++;
	return (i);
}

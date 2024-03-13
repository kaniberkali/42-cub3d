/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:25:45 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/09 19:05:35 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	error(int line, char *file, char *error, char *str)
{
	if (str)
		free(str);
	printf("%s in source/%s on line %d Error\n", error, file, line);
	return (0);
}

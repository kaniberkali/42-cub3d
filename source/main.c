/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:14:13 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 19:26:58 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/libft/libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*file;
	t_game	game;

	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(game));
		if (check_file_name(argv[1]))
		{
			file = reader(argv[1]);
			if (first_checker(file))
			{
				game.data = parser(file);
				if (checker(game.data))
					minilibx(&game);
				free_data(game.data);
				free_game(&game);
			}
			free(file);
		}
	}
	else
		error(40, "main.c", \
		"You have to give correct two arguments on terminal", NULL);
	return (0);
}

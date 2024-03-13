/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:21:12 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 19:20:25 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/minilibx/mlx.h"
#include <stdlib.h>

void	key_update(t_game *game)
{
	move_vertical(game);
	move_horizontal(game);
	rotate_rigth(game);
	rotate_left(game);
}

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
		close_window(game);
	else if (key == K_W)
		game->key.w = TRUE;
	else if (key == K_A)
		game->key.a = TRUE;
	else if (key == K_S)
		game->key.s = TRUE;
	else if (key == K_D)
		game->key.d = TRUE;
	else if (key == K_AR_L)
		game->key.left = TRUE;
	else if (key == K_AR_R)
		game->key.right = TRUE;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == K_W)
		game->key.w = FALSE;
	else if (key == K_A)
		game->key.a = FALSE;
	else if (key == K_S)
		game->key.s = FALSE;
	else if (key == K_D)
		game->key.d = FALSE;
	else if (key == K_AR_L)
		game->key.left = FALSE;
	else if (key == K_AR_R)
		game->key.right = FALSE;
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_image(game->render.mlx, game->img.img);
	mlx_destroy_window(game->render.mlx, game->render.window);
	free_data(game->data);
	free_game(game);
	exit(1);
}

int	game_render(t_game *game)
{
	calc(game);
	draw(game);
	key_update(game);
	return (0);
}

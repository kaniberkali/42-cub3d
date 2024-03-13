/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:22:00 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 19:02:48 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"
#include "../library/minilibx/mlx.h"
#include <unistd.h>

static int	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(game->render.mlx, path,
			&img->img_width, &img->img_height);
	if (!img->img)
		return (error(26, "minilibx/image.c", "Loading textures", NULL));
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	if (!img->img)
		return (mlx_destroy_image(game->render.mlx, img->img),
			error(31, "minilibx/image.c",
				"Data address retrieval issue", NULL));
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	return (mlx_destroy_image(game->render.mlx, img->img), 1);
}

int	load_texture(t_game *game)
{
	t_img	img;

	return (load_image(game, game->texture[0], game->data.north, &img)
		&& load_image(game, game->texture[1], game->data.south, &img)
		&& load_image(game, game->texture[2], game->data.west, &img)
		&& load_image(game, game->texture[3], game->data.east, &img));
}

void	draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			game->img.data[y * WINDOW_WIDTH + x] = game->window[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->render.mlx, game->render.window,
		game->img.img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:24:55 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/10 12:51:15 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/cub3d.h"

static int	ray_get_texture_id(t_ray_casting ray)
{
	if (ray.side == 0 && ray.ray_dirx > 0)
		return (0);
	else if (ray.side == 0 && ray.ray_dirx < 0)
		return (1);
	else if (ray.side == 1 && ray.ray_diry > 0)
		return (2);
	else
		return (3);
}

static void	render_column(t_game *game, int x, t_ray_casting *ray)
{
	t_ray_casting	calc_vars;
	int				y;

	calc_vars.line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
	calc_vars.draw_start = set_draw_start(calc_vars.line_height);
	calc_vars.draw_end = set_draw_end(calc_vars.line_height);
	calc_vars.wall_x = set_wall_x(ray, game);
	calc_vars.tex_x = (int)(calc_vars.wall_x * (double)TEXTURE_WIDTH);
	calc_vars.step = 1.0 * TEXTURE_HEIGHT / calc_vars.line_height;
	calc_vars.tex_pos = (calc_vars.draw_start - WINDOW_HEIGHT / 2
			+ calc_vars.line_height / 2) * calc_vars.step;
	y = calc_vars.draw_start;
	while (y < calc_vars.draw_end)
	{
		calc_vars.tex_y = (int)calc_vars.tex_pos & (TEXTURE_HEIGHT - 1);
		calc_vars.tex_pos += calc_vars.step;
		calc_vars.color = game->texture[ray_get_texture_id(*ray)]
		[TEXTURE_HEIGHT * calc_vars.tex_y + calc_vars.tex_x];
		game->window[y][x] = calc_vars.color;
		y++;
	}
}

void	calc(t_game *game)
{
	t_ray_casting	ray;
	int				i;
	int				floor;
	int				ceiling;

	i = 0;
	floor = rgb_to_hex(game->data.floor);
	ceiling = rgb_to_hex(game->data.ceiling);
	set_floor_ceiling(game, floor, ceiling);
	while (i < WINDOW_WIDTH)
	{
		ray = initialize_ray(game, i);
		render_column(game, i, &ray);
		i++;
	}
}

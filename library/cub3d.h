/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:45:35 by akaniber          #+#    #+#             */
/*   Updated: 2024/03/13 11:31:01 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SPACE ' '
# define ROAD '0' 
# define WALL '1'
# define NORTH "NO"
# define SOUTH "SO"
# define EAST "EA"
# define WEST "WE"
# define FLOOR "F"
# define CEILING "C"
# define CHECK_NORTH "NO "
# define CHECK_SOUTH "SO "
# define CHECK_EAST "EA "
# define CHECK_WEST "WE "
# define CHECK_FLOOR "F "
# define CHECK_CEILING "C "
# define CHAR_NORTH 'N'
# define CHAR_SOUTH 'S'
# define CHAR_EAST 'E'
# define CHAR_WEST 'W'
# define CONTROL '!'
# define TRUE 1
# define FALSE 0
# define K_A 0
# define K_D 2
# define K_W 13
# define K_S 1
# define K_AR_L 123
# define K_AR_R 124
# define K_ESC 53
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 800
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.05

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_coordinate
{
	double	x;
	double	y;
}	t_coordinate;

typedef struct s_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_color	floor;
	t_color	ceiling;
	t_point	player;
	char	**map;
	int		map_height;
	char	**value;
}	t_data;

typedef struct s_ray_casting
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	double	camera_x;
	double	ray_dirx;
	double	ray_diry;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
}				t_ray_casting;

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_key
{
	int	a;
	int	w;
	int	s;
	int	d;
	int	esc;
	int	left;
	int	right;
}	t_key;

typedef struct s_render
{
	void	*mlx;
	void	*window;
}	t_render;

typedef struct s_game
{
	t_coordinate	player;
	t_coordinate	direction;
	t_coordinate	plane;
	t_render		render;	
	t_key			key;
	t_img			img;
	int				**window;
	int				**texture;
	double			move_speed;
	double			rotation_speed;
	t_data			data;
}	t_game;

typedef struct s_file_fields
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	floor;
	int	ceiling;
}	t_file_fields;

int				checker(t_data data);
int				check_directions(t_data data);
int				check_file_name(char *map);
int				first_checker(char *file);
int				check_floor_and_ceiling(t_data data);
int				check_wall(t_data *data, int x, int y);
int				create_window(t_game *game);
int				create_texture(t_game *game);
void			key_update(t_game *game);
int				key_press(int key, t_game *game);
int				key_release(int key, t_game *game);
int				close_window(t_game *game);
int				game_render(t_game *game);
int				load_texture(t_game *game);
void			draw(t_game *game);
void			minilibx(t_game *game);
void			move_vertical(t_game *game);
void			move_horizontal(t_game *game);
void			rotate_rigth(t_game *game);
void			rotate_left(t_game *game);
void			initialize_fov(t_game *game);
void			calc(t_game *game);
void			set_floor_ceiling(t_game *game, int floor, int ceiling);
int				set_draw_start(int line_height);
int				set_draw_end(int line_height);
double			set_wall_x(t_ray_casting *ray, t_game *game);
t_ray_casting	initialize_ray(t_game *game, int x);
char			*get_data_value(t_data data, char *field);
t_data			parse_directions(t_data data);
t_data			parse_floor_and_ceiling(t_data data);
t_data			parse_map(t_data data);
t_data			parser(char	*file);
char			*reader(char *file);
int				rgb_to_hex(t_color color);
int				error(int line, char *file, char *error, char *str);
int				file_exits(char *path);
void			free_data(t_data data);
void			free_game(t_game *game);
int				count_char_in_string(char *str, char c);
int				main(int argc, char **argv);
int				get_longer_line_length(char **map);
char			*create_map_line(t_data data, char *line);
int				ft_strlen_2d(char **str);

#endif
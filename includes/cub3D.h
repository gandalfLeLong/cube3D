/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:10:46 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 12:11:18 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <string.h>
# include <fcntl.h>

/*DEFINES*/
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 1200
# define MOVE_SPEED 0.2
# define ROT_SPEED 0.1
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define R_LEFT 123
# define R_RIGHT 124
# define ESC 53
# define RGB_RED 0xFF00FF
# define NORTH 0
# define SOUTH 1 
# define EAST 2
# define WEST 3
# define TEX_SIZE 64

/*STRUCT*/
typedef struct s_rgb
{
	char	*str;
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_assets
{
	char	*map_str;
	char	**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	t_img	textures[4];
	t_rgb	ceiling;
	t_rgb	floor;
}	t_assets;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
	t_img	mlx_img;
}	t_mlx;

typedef struct s_player
{
	int	move_right;
	int	move_left;
	int	move_up;
	int	move_down;
	int	rotate_left;
	int	rotate_right;
}	t_player;

typedef struct s_exec
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;

	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		orientation;

	double	move_speed;
	double	rotate_speed;
}	t_exec;

typedef struct s_wall
{
	int		height;
	int		start;
	int		end;
	int		tex_x;
	int		tex_y;
	int		pixel_index;
	double	x;
	double	step;
	double	tex_pos;
}	t_wall;

typedef struct s_data
{
	bool		running;
	t_assets	assets;
	t_mlx		mlx_assets;
	t_exec		rc_assets;
	t_wall		wall;
	t_player	player;
}	t_data;

/*FUNCTIONS*/

//parsing
int		check_args_valid(int ac, char **av);
int		parsing_file(char **av, t_data *game);
int		get_texture(t_data *game, char *str, int ret);
int		find_map(t_data *game, int fd, char *tmp);
int		parse_texture(t_data *game);
int		convert_to_image(t_data *game);
int		parse_rgb(t_data *game);
int		parse_map(t_data *game);
int		is_closed_map(char **map);

//exec
int		game_init(t_data *game);
int		init_mlx(t_mlx	*mlx_assets);
int		game_loop(t_data *game);
int		destroy_game(t_data *game);
int		key_press(int key, t_data *game);
int		key_release(int key, t_data *game);
int		get_rgb(int R, int G, int B);
void	get_player_input(t_data *game);
void	move_up(t_data *game);
void	move_down(t_data *game);
void	move_left(t_data *game);
void	move_right(t_data *game);
void	rotate_left(t_data *game);
void	rotate_right(t_data *game);
void	init_rc_assets(t_data *game);
void	init_rc_var(t_data *game, int x);
void	get_orientation(t_data *game, int side, int step_x, int step_y);
void	render_buffer(t_data *game, int x, uint32_t *buffer);
void	put_sky_n_floor(t_data *game);
void	ft_pixel_put(t_img *img, int x, int y, unsigned int color);

//utils
void	free_double_char(char **tab);
void	free_parsing_utils(t_data *game);

//error
int		msg_error(char *str);

#endif

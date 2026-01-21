/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:03:22 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 09:48:38 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_rc_assets(t_data *game)
{
	game->rc_assets.pos_x = 0.0;
	game->rc_assets.pos_y = 0.0;
	game->rc_assets.dir_x = 0.0;
	game->rc_assets.dir_y = 0.0;
	game->rc_assets.plane_x = 0.0;
	game->rc_assets.plane_y = 0.0;
	game->rc_assets.camera_x = 0.0;
	game->rc_assets.ray_dir_x = 0.0;
	game->rc_assets.ray_dir_y = 0.0;
	game->rc_assets.map_x = 0;
	game->rc_assets.map_y = 0;
	game->player.move_right = 0;
	game->player.move_left = 0;
	game->player.move_up = 0;
	game->player.move_down = 0;
	game->player.rotate_left = 0;
	game->player.rotate_right = 0;
}

void	add_player_data_2(t_data *game, int y, int x, char card)
{
	game->rc_assets.pos_x = (float)x + 0.5;
	game->rc_assets.pos_y = (float)y + 0.5;
	game->assets.map[y][x] = '0';
	if (card == 'E')
	{
		game->rc_assets.dir_x = 1.0;
		game->rc_assets.dir_y = 0.0;
		game->rc_assets.plane_x = 0.0;
		game->rc_assets.plane_y = 0.66;
	}
	if (card == 'W')
	{
		game->rc_assets.dir_x = -1.0;
		game->rc_assets.dir_y = 0.0;
		game->rc_assets.plane_x = 0.0;
		game->rc_assets.plane_y = -0.66;
	}
}

void	add_player_data(t_data *game, int y, int x, char card)
{
	game->rc_assets.pos_x = (float)x + 0.5;
	game->rc_assets.pos_y = (float)y + 0.5;
	game->assets.map[y][x] = '0';
	if (card == 'N')
	{
		game->rc_assets.dir_x = 0.0;
		game->rc_assets.dir_y = -1.0;
		game->rc_assets.plane_x = 0.66;
		game->rc_assets.plane_y = 0.0;
	}
	if (card == 'S')
	{
		game->rc_assets.dir_x = 0.0;
		game->rc_assets.dir_y = 1.0;
		game->rc_assets.plane_x = -0.66;
		game->rc_assets.plane_y = 0.0;
	}
}

void	get_player_position(t_data *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->assets.map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N')
				add_player_data(game, y, x, 'N');
			if (map[y][x] == 'S')
				add_player_data(game, y, x, 'S');
			if (map[y][x] == 'E')
				add_player_data_2(game, y, x, 'E');
			if (map[y][x] == 'W')
				add_player_data_2(game, y, x, 'W');
			x++;
		}
		y++;
	}
}

int	game_init(t_data *game)
{
	init_rc_assets(game);
	if (init_mlx(&game->mlx_assets))
		return (1);
	get_player_position(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:36 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 11:05:13 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_player_input(t_data *game)
{
	if (game->player.move_up)
		move_up(game);
	if (game->player.move_down)
		move_down(game);
	if (game->player.move_right)
		move_right(game);
	if (game->player.move_left)
		move_left(game);
	if (game->player.rotate_right)
		rotate_right(game);
	if (game->player.rotate_left)
		rotate_left(game);
}

void	move_up(t_data *game)
{
	t_exec	*ptr;

	ptr = &game->rc_assets;
	if (game->assets.map[(int)ptr->pos_y][(int)(ptr->pos_x + ptr->dir_x
		* (MOVE_SPEED + 0.01))] == '0')
		ptr->pos_x += ptr->dir_x * MOVE_SPEED;
	if (game->assets.map[(int)(ptr->pos_y + ptr->dir_y
			* (MOVE_SPEED + 0.01))][(int)ptr->pos_x] == '0')
		ptr->pos_y += ptr->dir_y * MOVE_SPEED;
}

void	move_down(t_data *game)
{
	t_exec	*ptr;

	ptr = &game->rc_assets;
	if (game->assets.map[(int)ptr->pos_y][(int)(ptr->pos_x - ptr->dir_x
		* (MOVE_SPEED + 0.01))] == '0')
		ptr->pos_x -= ptr->dir_x * MOVE_SPEED;
	if (game->assets.map[(int)(ptr->pos_y - ptr->dir_y
			* (MOVE_SPEED + 0.01))][(int)ptr->pos_x] == '0')
		ptr->pos_y -= ptr->dir_y * MOVE_SPEED;
}

void	move_right(t_data *game)
{
	t_exec	*ptr;

	ptr = &game->rc_assets;
	if (game->assets.map[(int)ptr->pos_y][(int)(ptr->pos_x + ptr->plane_x
		* (MOVE_SPEED + 0.01))] == '0')
		ptr->pos_x += ptr->plane_x * MOVE_SPEED;
	if (game->assets.map[(int)(ptr->pos_y + ptr->plane_y
			* (MOVE_SPEED + 0.01))][(int)ptr->pos_x] == '0')
		ptr->pos_y += ptr->plane_y * MOVE_SPEED;
}

void	move_left(t_data *game)
{
	t_exec	*ptr;

	ptr = &game->rc_assets;
	if (game->assets.map[(int)ptr->pos_y][(int)(ptr->pos_x - ptr->plane_x
		* (MOVE_SPEED + 0.01))] == '0')
		ptr->pos_x -= ptr->plane_x * MOVE_SPEED;
	if (game->assets.map[(int)(ptr->pos_y - ptr->plane_y
			* (MOVE_SPEED + 0.01))][(int)ptr->pos_x] == '0')
		ptr->pos_y -= ptr->plane_y * MOVE_SPEED;
}

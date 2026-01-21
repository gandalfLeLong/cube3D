/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:55:30 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/22 14:01:45 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int key, t_data *game)
{
	if (key == UP)
		game->player.move_up = 1;
	if (key == DOWN)
		game->player.move_down = 1;
	if (key == LEFT)
		game->player.move_left = 1;
	if (key == RIGHT)
		game->player.move_right = 1;
	if (key == R_LEFT || key == 12)
		game->player.rotate_left = 1;
	if (key == R_RIGHT || key == 14)
		game->player.rotate_right = 1;
	if (key == ESC)
		destroy_game(game);
	return (0);
}

int	key_release(int key, t_data *game)
{
	if (key == UP)
		game->player.move_up = 0;
	if (key == DOWN)
		game->player.move_down = 0;
	if (key == LEFT)
		game->player.move_left = 0;
	if (key == RIGHT)
		game->player.move_right = 0;
	if (key == R_LEFT || key == 12)
		game->player.rotate_left = 0;
	if (key == R_RIGHT || key == 14)
		game->player.rotate_right = 0;
	return (0);
}

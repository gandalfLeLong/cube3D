/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:52:36 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 09:53:19 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_data *game)
{
	double	old_dir_x;
	double	old_plane_x;
	t_exec	*ptr;

	old_dir_x = game->rc_assets.dir_x;
	old_plane_x = game->rc_assets.plane_x;
	ptr = &game->rc_assets;
	ptr->dir_x = ptr->dir_x * cos(-ROT_SPEED) - ptr->dir_y * sin(-ROT_SPEED);
	ptr->dir_y = old_dir_x * sin(-ROT_SPEED) + ptr->dir_y * cos(-ROT_SPEED);
	ptr->plane_x = ptr->plane_x * cos(-ROT_SPEED) - ptr->plane_y
		* sin(-ROT_SPEED);
	ptr->plane_y = old_plane_x * sin(-ROT_SPEED) + ptr->plane_y
		* cos(-ROT_SPEED);
}

void	rotate_right(t_data *game)
{
	double	old_dir_x;
	double	old_plane_x;
	t_exec	*ptr;

	old_dir_x = game->rc_assets.dir_x;
	old_plane_x = game->rc_assets.plane_x;
	ptr = &game->rc_assets;
	ptr->dir_x = ptr->dir_x * cos(ROT_SPEED) - ptr->dir_y * sin(ROT_SPEED);
	ptr->dir_y = old_dir_x * sin(ROT_SPEED) + ptr->dir_y * cos(ROT_SPEED);
	ptr->plane_x = ptr->plane_x * cos(ROT_SPEED) - ptr->plane_y
		* sin(ROT_SPEED);
	ptr->plane_y = old_plane_x * sin(ROT_SPEED) + ptr->plane_y * cos(ROT_SPEED);
}

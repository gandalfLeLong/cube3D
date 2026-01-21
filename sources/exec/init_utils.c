/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:21:04 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 12:14:51 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_step(t_exec *ptr)
{
	if (ptr->ray_dir_x < 0)
	{
		ptr->step_x = -1;
		ptr->side_dist_x = (ptr->pos_x - ptr->map_x) * ptr->delta_dist_x;
	}
	else
	{
		ptr->step_x = 1;
		ptr->side_dist_x = (ptr->map_x + 1.0 - ptr->pos_x) * ptr->delta_dist_x;
	}
	if (ptr->ray_dir_y < 0)
	{
		ptr->step_y = -1;
		ptr->side_dist_y = (ptr->pos_y - ptr->map_y) * ptr->delta_dist_y;
	}
	else
	{
		ptr->step_y = 1;
		ptr->side_dist_y = (ptr->map_y + 1.0 - ptr->pos_y) * ptr->delta_dist_y;
	}
}

void	get_orientation(t_data *game, int side, int step_x, int step_y)
{
	if (side)
	{
		if (step_y > 0)
			game->rc_assets.orientation = SOUTH;
		else
			game->rc_assets.orientation = NORTH;
	}
	else
	{
		if (step_x > 0)
			game->rc_assets.orientation = EAST;
		else
			game->rc_assets.orientation = WEST;
	}
}

void	init_rc_var(t_data *game, int x)
{
	t_exec	*ptr;

	ptr = &game->rc_assets;
	ptr->camera_x = 2 * x / (double)SCREEN_WIDTH - 1.0;
	ptr->ray_dir_x = ptr->dir_x + ptr->plane_x * ptr->camera_x;
	ptr->ray_dir_y = ptr->dir_y + ptr->plane_y * ptr->camera_x;
	ptr->hit = 0;
	ptr->map_x = (int)ptr->pos_x;
	ptr->map_y = (int)ptr->pos_y;
	if (ptr->ray_dir_x == 0)
		ptr->delta_dist_x = 1e30;
	else
		ptr->delta_dist_x = fabs(1.0 / ptr->ray_dir_x);
	if (ptr->ray_dir_y == 0)
		ptr->delta_dist_y = 1e30;
	else
		ptr->delta_dist_y = fabs(1.0 / ptr->ray_dir_y);
	calculate_step(ptr);
}

void	put_sky_n_floor(t_data *game)
{
	int	x;
	int	y;
	int	sky;
	int	floor;

	x = -1;
	sky = get_rgb(game->assets.ceiling.r, game->assets.ceiling.g,
			game->assets.ceiling.b);
	floor = get_rgb(game->assets.floor.r, game->assets.floor.g,
			game->assets.floor.b);
	while (++x < SCREEN_WIDTH)
	{
		y = -1;
		while (++y <= SCREEN_HEIGHT / 2)
			ft_pixel_put(&game->mlx_assets.mlx_img, x, y, sky);
		while (++y < SCREEN_HEIGHT)
			ft_pixel_put(&game->mlx_assets.mlx_img, x, y, floor);
	}
}

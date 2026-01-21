/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:43:54 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 11:07:55 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	do_dda(t_exec *ptr, char **map)
{
	while (ptr->hit == 0)
	{
		if (ptr->side_dist_x < ptr->side_dist_y)
		{
			ptr->side_dist_x += ptr->delta_dist_x;
			ptr->map_x += ptr->step_x;
			ptr->side = 0;
		}
		else
		{
			ptr->side_dist_y += ptr->delta_dist_y;
			ptr->map_y += ptr->step_y;
			ptr->side = 1;
		}
		if (map[ptr->map_y][ptr->map_x] == '1')
			ptr->hit = 1;
	}
	if (ptr->side)
		ptr->perp_wall_dist = ptr->side_dist_y - ptr->delta_dist_y;
	else
		ptr->perp_wall_dist = ptr->side_dist_x - ptr->delta_dist_x;
}

void	get_buffer_tex(t_data *game, uint32_t *buf)
{
	int				i;
	uint32_t		color;
	unsigned char	*pix;

	i = game->wall.start;
	while (i < game->wall.end)
	{
		game->wall.tex_y = (int)game->wall.tex_pos & (TEX_SIZE - 1);
		game->wall.tex_pos += game->wall.step;
		game->wall.pixel_index = (game->wall.tex_y * TEX_SIZE
				+ game->wall.tex_x) * (game->assets.textures[game->rc_assets
				.orientation].bpp / 8);
		pix = (unsigned char *)&game->assets.textures
		[game->rc_assets.orientation].addr[game->wall.pixel_index];
		color = (pix[2] << 16 | pix[1] << 8 | pix[0]);
		buf[i] = color;
		i++;
	}
}

void	get_texture_line(t_data *game, int x)
{
	t_exec			*ptr;
	uint32_t		buffer[SCREEN_HEIGHT];

	memset(buffer, 0, SCREEN_HEIGHT);
	ptr = &game->rc_assets;
	if (ptr->side)
		game->wall.x = ptr->pos_x + ptr->perp_wall_dist * ptr->ray_dir_x;
	else
		game->wall.x = ptr->pos_y + ptr->perp_wall_dist * ptr->ray_dir_y;
	game->wall.x -= floor(game->wall.x);
	game->wall.tex_x = (int)(game->wall.x * (double)TEX_SIZE);
	if (ptr->side == 0 && ptr->ray_dir_x > 0)
		game->wall.tex_x = TEX_SIZE - game->wall.tex_x - 1;
	if (ptr->side == 1 && ptr->ray_dir_y < 0)
		game->wall.tex_x = TEX_SIZE - game->wall.tex_x - 1;
	game->wall.step = 1.0 * (double)TEX_SIZE / game->wall.height;
	game->wall.tex_pos = (game->wall.start - SCREEN_HEIGHT / 2
			+ game->wall.height / 2) * game->wall.step;
	get_buffer_tex(game, buffer);
	render_buffer(game, x, buffer);
}

void	draw_line(t_data *game, int x)
{
	t_exec	*ptr;

	ptr = &game->rc_assets;
	game->wall.height = (int)(SCREEN_HEIGHT / ptr->perp_wall_dist);
	game->wall.start = (-game->wall.height / 2) + (SCREEN_HEIGHT / 2);
	if (game->wall.start < 0)
		game->wall.start = 0;
	game->wall.end = (game->wall.height / 2) + (SCREEN_HEIGHT / 2);
	if (game->wall.end >= SCREEN_HEIGHT)
		game->wall.end = SCREEN_HEIGHT - 1;
	get_orientation(game, ptr->side, ptr->step_x, ptr->step_y);
	get_texture_line(game, x);
}

int	game_loop(t_data *game)
{
	int	x;

	x = 0;
	mlx_destroy_image(game->mlx_assets.mlx, game->mlx_assets.mlx_img.img);
	game->mlx_assets.mlx_img.img = NULL;
	game->mlx_assets.mlx_img.img = mlx_new_image(game->mlx_assets.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	put_sky_n_floor(game);
	while (x < SCREEN_WIDTH)
	{
		init_rc_var(game, x);
		do_dda(&game->rc_assets, game->assets.map);
		draw_line(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_assets.mlx, game->mlx_assets.mlx_window,
		game->mlx_assets.mlx_img.img, 0, 0);
	get_player_input(game);
	return (0);
}

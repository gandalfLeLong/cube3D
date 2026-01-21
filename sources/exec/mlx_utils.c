/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:29:44 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 12:12:00 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_mlx(t_mlx *mlx_assets)
{
	if (mlx_assets->mlx == NULL)
		return (1);
	mlx_assets->mlx_window = mlx_new_window(mlx_assets->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3D");
	mlx_assets->mlx_img.img = mlx_new_image(mlx_assets->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	mlx_assets->mlx_img.addr = mlx_get_data_addr(mlx_assets->mlx_img.img,
			&mlx_assets->mlx_img.bpp, &mlx_assets->mlx_img.line_length,
			&mlx_assets->mlx_img.endian);
	return (0);
}

void	render_buffer(t_data *game, int x, uint32_t *buffer)
{
	while (game->wall.start < game->wall.end)
	{
		ft_pixel_put(&game->mlx_assets.mlx_img, x, game->wall.start,
			buffer[game->wall.start]);
		game->wall.start++;
	}
}

int	get_rgb(int R, int G, int B)
{
	return (R << 16 | G << 8 | B);
}

void	ft_pixel_put(t_img	*img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

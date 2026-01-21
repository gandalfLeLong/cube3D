/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:42:10 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/27 14:47:50 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_destroy_image(t_data *game)
{
	if (game->assets.textures[0].img)
		mlx_destroy_image(game->mlx_assets.mlx, game->assets.textures[0].img);
	if (game->assets.textures[1].img)
		mlx_destroy_image(game->mlx_assets.mlx, game->assets.textures[1].img);
	if (game->assets.textures[2].img)
		mlx_destroy_image(game->mlx_assets.mlx, game->assets.textures[2].img);
	if (game->assets.textures[3].img)
		mlx_destroy_image(game->mlx_assets.mlx, game->assets.textures[3].img);
}

static int	verif_texture(t_data *game)
{
	if (!game->assets.textures[0].img || !game->assets.textures[1].img
		|| !game->assets.textures[2].img || !game->assets.textures[3].img)
	{
		ft_destroy_image(game);
		return (1);
	}
	game->assets.textures[0].addr = mlx_get_data_addr(game->assets.textures[0]
			.img, &game->assets.textures[0].bpp, &game->assets.textures[0]
			.line_length, &game->assets.textures[0].endian);
	game->assets.textures[1].addr = mlx_get_data_addr(game->assets.textures[1]
			.img, &game->assets.textures[1].bpp, &game->assets.textures[1]
			.line_length, &game->assets.textures[1].endian);
	game->assets.textures[2].addr = mlx_get_data_addr(game->assets.textures[2]
			.img, &game->assets.textures[2].bpp, &game->assets.textures[2]
			.line_length, &game->assets.textures[2].endian);
	game->assets.textures[3].addr = mlx_get_data_addr(game->assets.textures[3]
			.img, &game->assets.textures[3].bpp, &game->assets.textures[3]
			.line_length, &game->assets.textures[3].endian);
	return (0);
}

int	convert_to_image(t_data *game)
{
	int	height;
	int	width;

	game->mlx_assets.mlx = mlx_init();
	game->assets.textures[0].img = mlx_xpm_file_to_image(game->mlx_assets.mlx,
			game->assets.no, &width, &height);
	game->assets.textures[1].img = mlx_xpm_file_to_image(game->mlx_assets.mlx,
			game->assets.so, &width, &height);
	game->assets.textures[2].img = mlx_xpm_file_to_image(game->mlx_assets.mlx,
			game->assets.ea, &width, &height);
	game->assets.textures[3].img = mlx_xpm_file_to_image(game->mlx_assets.mlx,
			game->assets.we, &width, &height);
	if (verif_texture(game))
		return (1);
	return (0);
}

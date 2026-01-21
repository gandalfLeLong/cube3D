/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:19:44 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 12:42:53 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	destroy_game(t_data *game)
{
	free_map(game->assets.map);
	mlx_destroy_image(game->mlx_assets.mlx, game->assets.textures[0].img);
	mlx_destroy_image(game->mlx_assets.mlx, game->assets.textures[1].img);
	mlx_destroy_image(game->mlx_assets.mlx, game->assets.textures[2].img);
	mlx_destroy_image(game->mlx_assets.mlx, game->assets.textures[3].img);
	if (game->mlx_assets.mlx_img.img)
		mlx_destroy_image(game->mlx_assets.mlx, game->mlx_assets.mlx_img.img);
	mlx_destroy_window(game->mlx_assets.mlx, game->mlx_assets.mlx_window);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:09:22 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/27 14:15:12 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	game;

	if (check_args_valid(ac, av))
		return (1);
	if (parsing_file(av, &game))
		return (free_parsing_utils(&game), 1);
	if (game_init(&game))
		return (1);
	mlx_hook(game.mlx_assets.mlx_window, 17, 0, destroy_game, &game);
	mlx_hook(game.mlx_assets.mlx_window, 2, 0, &key_press, &game);
	mlx_hook(game.mlx_assets.mlx_window, 3, 0, &key_release, &game);
	mlx_loop_hook(game.mlx_assets.mlx, game_loop, &game);
	mlx_loop(game.mlx_assets.mlx);
	return (0);
}

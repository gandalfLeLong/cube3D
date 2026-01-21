/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:38:55 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 12:14:15 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_len(char **tab)
{
	if (ft_strlen(tab[0]) > 3)
		return (1);
	if (ft_strlen(tab[1]) > 3)
		return (1);
	if (ft_strlen(tab[2]) > 3)
		return (1);
	return (0);
}

static int	get_ceiling(t_data *game, int i)
{
	char	**tmp;

	tmp = ft_split(game->assets.ceiling.str, ',');
	if (!tmp || !tmp[i])
		return (free_double_char(tmp), 1);
	while (tmp[i])
		i++;
	if (i != 3)
		return (free_double_char(tmp), 1);
	if (check_len(tmp))
		return (free_double_char(tmp), 1);
	game->assets.ceiling.r = ft_atoi(tmp[0]);
	if (game->assets.ceiling.r < 0 || game->assets.ceiling.r > 255)
		return (free_double_char(tmp), 1);
	game->assets.ceiling.g = ft_atoi(tmp[1]);
	if (game->assets.ceiling.g < 0 || game->assets.ceiling.g > 255)
		return (free_double_char(tmp), 1);
	game->assets.ceiling.b = ft_atoi(tmp[2]);
	if (game->assets.ceiling.b < 0 || game->assets.ceiling.b > 255)
		return (free_double_char(tmp), 1);
	free_double_char(tmp);
	return (0);
}

static int	get_floor(t_data *game, int i)
{
	char	**tmp;

	tmp = ft_split(game->assets.floor.str, ',');
	if (!tmp || !tmp[i])
		return (free_double_char(tmp), 1);
	while (tmp[i])
		i++;
	if (i != 3)
		return (free_double_char(tmp), 1);
	if (check_len(tmp))
		return (free_double_char(tmp), 1);
	game->assets.floor.r = ft_atoi(tmp[0]);
	if (game->assets.floor.r < 0 || game->assets.floor.r > 255)
		return (free_double_char(tmp), 1);
	game->assets.floor.g = ft_atoi(tmp[1]);
	if (game->assets.floor.g < 0 || game->assets.floor.g > 255)
		return (free_double_char(tmp), 1);
	game->assets.floor.b = ft_atoi(tmp[2]);
	if (game->assets.floor.b < 0 || game->assets.floor.b > 255)
		return (free_double_char(tmp), 1);
	free_double_char(tmp);
	return (0);
}

int	parse_rgb(t_data *game)
{
	if (get_floor(game, 0))
		return (msg_error("invalid floor data"));
	if (get_ceiling(game, 0))
		return (msg_error("invalid ceiling data"));
	return (0);
}

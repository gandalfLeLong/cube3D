/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:36:39 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/27 14:38:01 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == '\t')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	else
		return (1);
}

int	verif_char(char **map, int i, int j)
{
	int	player;

	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (valid_char(map[i][j]))
				return (1);
			if (is_player(map[i][j]))
			{
				if (player > 0)
					return (msg_error("2 players"));
				player++;
			}
		}
	}
	if (player == 0)
		return (msg_error("no player"));
	return (0);
}

int	parse_map(t_data *game)
{
	game->assets.map = ft_split(game->assets.map_str, '\n');
	if (verif_char(game->assets.map, -1, -1))
		return (msg_error("invalid character map"));
	if (is_closed_map(game->assets.map))
		return (msg_error("map not closed"));
	return (0);
}

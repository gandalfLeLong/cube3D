/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:30:52 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/27 14:34:29 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_around(char **map, int i, int j)
{
	if (!map[i - 1] || !map[i + 1])
		return (0);
	if (!map[i][j - 1] || map[i][j + 1] == '\0')
		return (0);
	if (!check_char(map[i - 1][j], "01NSEW") ||
		!check_char(map[i + 1][j], "01NSEW") ||
		!check_char(map[i][j - 1], "01NSEW") ||
		!check_char(map[i][j + 1], "01NSEW"))
		return (0);
	return (1);
}

static int	is_edge(char **map, int i, int j)
{
	if (i == 0 || j == 0 || !map[i + 1] || map[i][j + 1] == '\0')
		return (1);
	if (!check_around(map, i, j))
		return (1);
	return (0);
}

int	is_closed_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_char(map[i][j], "0NSEW"))
			{
				if (is_edge(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

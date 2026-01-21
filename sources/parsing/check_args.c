/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:29:44 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/28 12:12:45 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_args_valid(int ac, char **av)
{
	int	len;

	len = 0;
	if (ac != 2)
		return (msg_error("wrong number arg"));
	len = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + len - 4, ".cub", 5))
		return (msg_error("invalid map file"));
	return (0);
}

static void	init_assets(t_assets *assets)
{
	assets->no = NULL;
	assets->so = NULL;
	assets->ea = NULL;
	assets->we = NULL;
	assets->ceiling.str = NULL;
	assets->floor.str = NULL;
	assets->ceiling.r = -1;
	assets->ceiling.g = -1;
	assets->ceiling.b = -1;
	assets->floor.r = -1;
	assets->floor.g = -1;
	assets->floor.b = -1;
	assets->map = NULL;
	assets->map_str = NULL;
}

static int	read_file(t_data *game, char *file, int fd, int text_find)
{
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		return (msg_error("failed file opening"));
	tmp = get_next_line(fd);
	while (tmp && text_find != 6)
	{
		if (tmp[0] != '\0' && tmp[0] != '\n')
		{
			if (get_texture(game, tmp, 1))
			{
				free(tmp);
				return (1);
			}
			text_find++;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (find_map(game, fd, tmp));
}

static int	parse_data(t_data *game)
{
	if (parse_texture(game))
		return (1);
	if (parse_rgb(game))
		return (1);
	if (parse_map(game))
		return (1);
	return (0);
}

int	parsing_file(char **av, t_data *game)
{
	init_assets(&game->assets);
	if (read_file(game, av[1], 0, 0))
		return (1);
	if (parse_data(game))
		return (1);
	free_parsing_utils(game);
	return (0);
}

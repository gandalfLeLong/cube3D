/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:41:07 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/27 14:41:10 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_exist(t_data *game)
{
	if (game->assets.no == NULL)
		return (1);
	if (game->assets.so == NULL)
		return (1);
	if (game->assets.ea == NULL)
		return (1);
	if (game->assets.we == NULL)
		return (1);
	return (0);
}

static int	is_xpm(t_data *game)
{
	int	len;

	len = ft_strlen(game->assets.no);
	if (ft_strncmp(game->assets.no + len - 4, ".xpm", 5))
		return (1);
	len = ft_strlen(game->assets.so);
	if (ft_strncmp(game->assets.so + len - 4, ".xpm", 5))
		return (1);
	len = ft_strlen(game->assets.ea);
	if (ft_strncmp(game->assets.ea + len - 4, ".xpm", 5))
		return (1);
	len = ft_strlen(game->assets.we);
	if (ft_strncmp(game->assets.we + len - 4, ".xpm", 5))
		return (1);
	return (0);
}

static int	is_real_file(t_data *game, int fd)
{
	fd = open(game->assets.no, O_RDONLY);
	if (fd < 1)
		return (1);
	close(fd);
	fd = open(game->assets.so, O_RDONLY);
	if (fd < 1)
		return (1);
	close(fd);
	fd = open(game->assets.ea, O_RDONLY);
	if (fd < 1)
		return (1);
	close(fd);
	fd = open(game->assets.we, O_RDONLY);
	if (fd < 1)
		return (1);
	close(fd);
	return (0);
}

int	parse_texture(t_data *game)
{
	if (is_exist(game))
		return (msg_error("invalid texture"));
	if (is_xpm(game))
		return (msg_error("invalid extension"));
	if (is_real_file(game, 0))
		return (msg_error("invalid texture file"));
	if (convert_to_image(game))
		return (msg_error("image conversion failed"));
	return (0);
}

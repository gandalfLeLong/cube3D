/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_capture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:34:42 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/27 14:36:10 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	read_map(t_data *game, char *tmp, int fd)
{
	if (!tmp)
		return (msg_error("no map"));
	game->assets.map_str = ft_strdup(tmp);
	while (tmp && tmp[0] != '\n')
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp && tmp[0] != '\n')
			game->assets.map_str = ft_strjoin(game->assets.map_str, tmp);
	}
	if (tmp != NULL)
	{
		while (tmp && tmp[0] == '\n')
		{
			free(tmp);
			tmp = get_next_line(fd);
		}
		if (tmp)
			return (find_map(game, fd, tmp));
	}
	if (tmp)
		free(tmp);
	close(fd);
	return (0);
}

int	find_map(t_data *game, int fd, char *tmp)
{
	while (tmp && tmp[0] == '\n')
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (game->assets.map_str)
		free(game->assets.map_str);
	return (read_map(game, tmp, fd));
}

int	get_texture_data(t_data *game, char *str, int dir)
{
	if (dir == 1)
	{
		if (game->assets.no != NULL)
			return (msg_error("duplicate data"));
		game->assets.no = ft_substr(str, 0, ft_strlen(str) - 1);
	}
	else if (dir == 2)
	{
		if (game->assets.so != NULL)
			return (msg_error("duplicate data"));
		game->assets.so = ft_substr(str, 0, ft_strlen(str) - 1);
	}
	else if (dir == 3)
	{
		if (game->assets.ea != NULL)
			return (msg_error("duplicate data"));
		game->assets.ea = ft_substr(str, 0, ft_strlen(str) - 1);
	}
	else if (dir == 4)
	{
		if (game->assets.we != NULL)
			return (msg_error("duplicate data"));
		game->assets.we = ft_substr(str, 0, ft_strlen(str) - 1);
	}
	return (0);
}

int	get_fc(t_data *game, char *str, int i)
{
	if (i == 1)
	{
		if (game->assets.floor.str != NULL)
			return (msg_error("duplicate data"));
		game->assets.floor.str = ft_substr(str, 0, ft_strlen(str) - 1);
	}
	else
	{
		if (game->assets.ceiling.str != NULL)
			return (msg_error("duplicate data"));
		game->assets.ceiling.str = ft_substr(str, 0, ft_strlen(str) - 1);
	}
	return (0);
}

int	get_texture(t_data *game, char *str, int ret)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	if (!tmp)
		return (msg_error("malloc failed"));
	if (tmp[1])
	{
		if (!ft_strncmp(tmp[0], "NO", 3))
			ret = get_texture_data(game, tmp[1], 1);
		else if (!ft_strncmp(tmp[0], "SO", 3))
			ret = get_texture_data(game, tmp[1], 2);
		else if (!ft_strncmp(tmp[0], "EA", 3))
			ret = get_texture_data(game, tmp[1], 3);
		else if (!ft_strncmp(tmp[0], "WE", 3))
			ret = get_texture_data(game, tmp[1], 4);
		else if (!ft_strncmp(tmp[0], "F", 2))
			ret = get_fc(game, tmp[1], 1);
		else if (!ft_strncmp(tmp[0], "C", 2))
			ret = get_fc(game, tmp[1], 2);
		else
			return (free_double_char(tmp), msg_error("invalid file"));
	}
	else
		return (free_double_char(tmp), msg_error("invalid file"));
	return (free_double_char(tmp), ret);
}

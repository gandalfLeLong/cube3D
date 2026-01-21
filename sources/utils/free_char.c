/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:49:21 by cmathot           #+#    #+#             */
/*   Updated: 2024/11/27 14:49:24 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_double_char(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		if (tab[i])
		{
			while (tab[i])
			{
				free(tab[i]);
				i++;
			}
		}
		free(tab);
	}
}

void	free_parsing_utils(t_data *game)
{
	if (game->assets.no)
		free(game->assets.no);
	if (game->assets.so)
		free(game->assets.so);
	if (game->assets.ea)
		free(game->assets.ea);
	if (game->assets.we)
		free(game->assets.we);
	if (game->assets.floor.str)
		free(game->assets.floor.str);
	if (game->assets.ceiling.str)
		free(game->assets.ceiling.str);
}

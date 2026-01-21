/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:32:02 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/09 16:16:08 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	checker;
	void	*res;
	char	*res_cpy;

	checker = count * size;
	if (count != 0 && checker / count != size)
		return (NULL);
	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	res_cpy = res;
	i = 0;
	while (i < count * size)
		res_cpy[i++] = 0;
	return (res);
}

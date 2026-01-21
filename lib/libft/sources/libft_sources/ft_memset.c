/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:38:05 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/09 16:10:33 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	if (!b)
		return (NULL);
	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

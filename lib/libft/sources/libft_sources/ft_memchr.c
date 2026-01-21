/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:17:30 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/09 16:12:55 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (!s)
		return (NULL);
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
			return (str + i);
		i++;
	}
	return (0);
}

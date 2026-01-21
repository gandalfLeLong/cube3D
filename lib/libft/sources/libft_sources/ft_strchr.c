/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:38:44 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/09 15:10:45 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	uc;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	uc = c;
	res = (char *) s;
	while (res[i])
	{
		if (res[i] == uc)
			return (res + i);
		i++;
	}
	if (uc == 0)
		return (res + i);
	return (NULL);
}

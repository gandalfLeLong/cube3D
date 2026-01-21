/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:04:22 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/09 15:11:10 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	unsigned char	uc;

	if (!s)
		return (NULL);
	res = (char *)s + ft_strlen(s);
	uc = (unsigned char) c;
	if (!s)
		return (NULL);
	while (res >= s)
	{
		if (*res == uc)
			return (res);
		res--;
	}
	return (NULL);
}

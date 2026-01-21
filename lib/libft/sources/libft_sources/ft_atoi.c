/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot < cmathot@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:48:33 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/09 16:03:18 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

long	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	prev_res;

	res = 0;
	sign = 1;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		prev_res = res;
		res = (res * 10) + *str++ - '0';
		if (prev_res > res)
			return (0);
	}
	return (res * sign);
}

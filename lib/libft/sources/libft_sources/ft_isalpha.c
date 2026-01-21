/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot < cmathot@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:59:31 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/09 13:24:04 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}

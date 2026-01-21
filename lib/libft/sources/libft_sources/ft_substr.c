/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:50:25 by cmathot           #+#    #+#             */
/*   Updated: 2024/07/08 12:08:11 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	if (s[0] == '\0' || start >= ft_strlen(s))
		return (ft_strdup(""));
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	i = start;
	j = 0;
	while (s[i] && (j < len))
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}

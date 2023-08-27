/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:02:34 by jucalder          #+#    #+#             */
/*   Updated: 2023/03/07 21:09:01 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	if (!dst && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	dest_len = 0;
	src_len = 0;
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len] && (dest_len + src_len + 1) < size)
	{
		dst[dest_len + src_len] = src[src_len];
		src_len++;
	}
	if (dest_len < size)
		dst[dest_len + src_len] = '\0';
	return (dest_len + ft_strlen(src));
}

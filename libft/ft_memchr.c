/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:32:25 by jucalder          #+#    #+#             */
/*   Updated: 2023/02/28 22:04:36 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *) ptr;
	i = 0;
	while (i < num)
	{
		if (p[i] == (unsigned char) value)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}

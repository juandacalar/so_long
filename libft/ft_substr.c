/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <jucalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:55:58 by jucalder          #+#    #+#             */
/*   Updated: 2023/03/07 19:56:14 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*empty;
	char	*sub;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		empty = (char *)malloc(sizeof(char));
		empty[0] = '\0';
		return (empty);
	}
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

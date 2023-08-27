/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:29:49 by jucalder          #+#    #+#             */
/*   Updated: 2023/03/03 20:18:58 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			result = (char *)&str[i];
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (result);
}

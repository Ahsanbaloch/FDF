/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:43:48 by ahsalam           #+#    #+#             */
/*   Updated: 2023/06/05 16:31:13 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (!ch)
		return ((char *)s);
	return (NULL);
}

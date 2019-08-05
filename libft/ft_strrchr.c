/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:54:36 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 14:55:02 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int strlen;

	strlen = ft_strlen(s) + 1;
	while (*s)
		s++;
	while (strlen--)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:56:28 by yxie              #+#    #+#             */
/*   Updated: 2019/05/29 15:35:21 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	count;

	count = ft_strlen(haystack);
	if (count < (int)ft_strlen(needle))
		return (NULL);
	count = len - ft_strlen(needle) + 1;
	if (*needle == '\0')
		return ((char *)haystack);
	if (count > 0)
	{
		while (count--)
		{
			if (ft_memcmp(haystack, needle, ft_strlen(needle)))
				haystack++;
			else
				return ((char *)haystack);
		}
	}
	return (NULL);
}

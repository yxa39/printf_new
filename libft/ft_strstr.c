/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:55:18 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 14:56:20 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *tmp_haystack;
	const char *first_needle;

	first_needle = needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack++ != *needle)
			continue;
		tmp_haystack = --haystack;
		while (1)
		{
			if (*needle == 0)
				return ((char *)haystack);
			if (*tmp_haystack++ != *needle++)
				break ;
		}
		needle = first_needle;
		haystack++;
	}
	return (NULL);
}

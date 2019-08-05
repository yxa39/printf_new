/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:22:49 by yxie              #+#    #+#             */
/*   Updated: 2018/12/07 10:08:52 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char *ptr_s1;

	ptr_s1 = (char *)s1;
	while (*ptr_s1)
		ptr_s1++;
	while (*s2 && n--)
		*ptr_s1++ = *s2++;
	*ptr_s1 = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:16:34 by yxie              #+#    #+#             */
/*   Updated: 2019/05/29 11:45:00 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr_s;

	ptr_s = (unsigned char *)s;
	while (n--)
	{
		if (*ptr_s == (unsigned char)c)
			return (ptr_s);
		ptr_s++;
	}
	return (NULL);
}

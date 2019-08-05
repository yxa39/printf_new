/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:59:05 by yxie              #+#    #+#             */
/*   Updated: 2019/05/29 14:47:09 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*ptr_dst;
	char	*ptr_src;

	if (dst == NULL && src == NULL)
		return (dst);
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	while (n--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}

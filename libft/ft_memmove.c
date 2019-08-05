/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:15:13 by yxie              #+#    #+#             */
/*   Updated: 2019/05/29 14:42:03 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	if (dst == NULL && src == NULL)
		return (dst);
	tmp = dst;
	if (tmp > src)
		while (len--)
			*(char *)(tmp + len) = *(char *)(src + len);
	else
		while (len--)
			*(char *)tmp++ = *(char *)src++;
	return (dst);
}

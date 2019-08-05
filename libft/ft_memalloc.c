/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:04:57 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 15:06:21 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*pointer;

	pointer = (void *)malloc(sizeof(*pointer) * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, size);
	return (pointer);
}

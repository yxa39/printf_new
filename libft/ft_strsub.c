/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:12:56 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 15:13:11 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*tmp;

	if (!s)
		return (NULL);
	while (start--)
		s++;
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	tmp = new;
	while (len--)
		*new++ = *s++;
	return (tmp);
}

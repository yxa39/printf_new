/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:10:06 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 15:10:28 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*tmp;

	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	tmp = new;
	if (!new)
		return (NULL);
	while (*s)
	{
		*new++ = f((char)*s++);
	}
	return (tmp);
}

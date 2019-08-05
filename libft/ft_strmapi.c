/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:11:03 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 15:11:44 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*tmp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	tmp = new;
	if (!new)
		return (NULL);
	while (*s)
		*new++ = f(i++, *s++);
	return (tmp);
}

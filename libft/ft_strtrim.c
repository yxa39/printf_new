/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:13:49 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 16:09:18 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(char const *s)
{
	int	count;
	int	len;

	len = ft_strlen(s);
	count = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		s++;
		count++;
	}
	if (*s == '\0')
		return (count);
	while (*s)
		s++;
	while (*s == '\0' || *s == ' ' || *s == '\t' || *s == '\n')
	{
		s--;
		count++;
	}
	return (len - count + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	char	*tmp;
	int		len;

	if (!s)
		return (NULL);
	len = getlen(s);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	tmp = new;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (len--)
		*new++ = *s++;
	return (tmp);
}

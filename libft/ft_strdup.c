/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:18:52 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 15:30:39 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

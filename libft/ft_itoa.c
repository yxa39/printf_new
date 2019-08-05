/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:16:23 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 15:16:47 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_strlen(int n)
{
	int	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	new_n;

	len = get_strlen(n);
	new_n = n;
	if (n < 0)
	{
		new_n = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		*str = '-';
	str[--len] = new_n % 10 + '0';
	while (new_n /= 10)
		str[--len] = new_n % 10 + '0';
	return (str);
}

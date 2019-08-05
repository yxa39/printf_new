/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:58:51 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 14:59:12 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	count;

	num = 0;
	sign = 1;
	count = 0;
	while (*str == '\n' || *str == '\t' ||
		*str == '\r' || *str == '\v' ||
		*str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*(str++) - '0');
		count++;
	}
	if (count >= 20 && sign == -1)
		return (0);
	if (count >= 20 && sign == 1)
		return (-1);
	return (num * sign);
}

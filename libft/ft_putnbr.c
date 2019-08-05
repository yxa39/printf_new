/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:20:20 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 15:21:26 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	new_n;

	new_n = n;
	if (n < 0)
	{
		ft_putchar('-');
		new_n = -n;
	}
	if (new_n >= 10)
	{
		ft_putnbr(new_n / 10);
		ft_putnbr(new_n % 10);
	}
	else
		ft_putchar(new_n + '0');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:23:59 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 15:24:28 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new_n;

	new_n = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		new_n = -n;
	}
	if (new_n >= 10)
	{
		ft_putnbr_fd(new_n / 10, fd);
		ft_putnbr_fd(new_n % 10, fd);
	}
	else
		ft_putchar_fd(new_n + '0', fd);
}

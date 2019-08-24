/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:21:00 by yxie              #+#    #+#             */
/*   Updated: 2019/07/18 13:01:22 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void funct(void *a, int z)
{
    if(z==1)
        printf("%d",*(int*)a); // If user inputs 1, then he means the data is an integer and type  casting is done accordingly.
    else if(z==2)
        printf("%c",*(char*)a); // Typecasting for character pointer.
    else if(z==3)
        printf("%f",*(float*)a); // Typecasting for float pointer
}

int	main()
{
	int a = 123;

	//funct(&a, 1);
	ft_printf("%06+s\n", "abc");
	printf("%06+s\n", "abc");
	ft_printf("%09 -10s\n", "abc");
	printf("%09 -10s\n", "abc");
	printf("%d\n", printf("%06s\n", NULL));
	printf("%d\n", ft_printf("%06s\n", NULL));
	ft_printf("%.2 04s\n", NULL);
	ft_printf("%-011 .2  .3s\n", "abc");
	printf("%-011 .2 .1 .3s\n", "abc");
	ft_printf("%- 0 12 23 .12c\n", 'x');
	printf("%- 0 12 23 .12c\n", 'x');
	ft_printf("%.2d\n", 123);
	ft_printf("%010d\n", 123);
	ft_printf("new:\n");
	ft_printf("%0 -10.5d\n", 123456);
	printf("%0 -10.5d\n", 123456);
	ft_printf("%05s\n", "-12");
	printf("%05s\n", "-12");
	ft_printf("%lld\n", 9223372036854775809);
	printf("%lld\n", 9223372036854775809);
	return (0);
}

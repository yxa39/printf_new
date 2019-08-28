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
	ft_printf("%\n");
	printf("%\n");
	return (0);
}

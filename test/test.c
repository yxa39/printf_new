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
printf("len: %d\n", printf("%12#4bcd"));
printf("len: %d\n",ft_printf("%12#4bcd"));
ft_printf("@moulitest: %.d %.0d\n", 42, 43);
printf("@moulitest: %.d %.0d\n", 42, 43);
printf("str: %+-05s\n", "a");
ft_printf("str: %+-05s\n", "a");
  ft_printf("%-5.2s is a string\n", "");
  printf("%-5.2s is a string\n", "");
printf("len: %d\n",printf("or:%jd\n", 123));
printf("len: %d\n",ft_printf("ft:%jd\n", 123));
printf("%jx\n", 4294967296);
ft_printf("%jx\n", 4294967296);
ft_printf("ft:%U\n", 4294967295);
printf("or:%U\n", 4294967295);
  ft_printf("ft:%05c\n", 42);
  printf("or:%05c\n", 42);
    ft_printf("ft:%ll#x\n", 922337203);
  printf("or:%ll#x\n", 922337203);

printf("%zd\n", -1);
ft_printf("%zd\n", -1);
  ft_printf("%zhd\n", 4294967296);
  printf("%zhd\n", 4294967296);
  ft_printf("%jhd\n", 9223372036854775807);
  printf("%jhd\n", 9223372036854775807);
  ft_printf("%hU\n", 4294967296);
  printf("%hU\n", 4294967296);
printf("%f\n", 23.00041);
ft_printf("%Lf\n", -985.765426499L);
printf("%Lf\n", -985.765426499L);
ft_printf("{%f}{%lf}{%Lf}\n", -1.42, -1.42, -1.42l);
printf("{%f}{%lf}{%Lf}\n", -1.42, -1.42, -1.42l);
printf("adding:%f\n", 1.5 + 0.5);
ft_printf("ft:% -5.0f\n", -3.85);
printf("or:% -5.0f\n", -3.85);
ft_printf("str:%5.2s\n", "ab");
ft_printf("str:%5.2s\n", "ab");
ft_printf("0: %f", (double)-0);
return (0);
}

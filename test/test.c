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
	printf("ft_printf:\n");
	ft_printf("%# 0100d+-", 123);
	ft_printf("aa%saa%sd\n", "bb", "cc");
	printf("aa%saa%sd\n\n", "bb", "cc");
	ft_printf("abc%cd\n", 'c');
	printf("abc%cd\n\n", 'c');
	ft_printf("abc%pd\n", "abc");
	printf("abc%pd\n\n", "abc");
	ft_printf("abc%dd\n", -11111111);
	printf("abc%dd\n\n", -11111111);
	ft_printf("abc%od\n", -111111111);
	printf("abc%od\n\n", -111111111);
	ft_printf("abc%ud\n", -111111);
	printf("abc%ud\n\n", -111111);
	ft_printf("abc%xd\n", -111111);
	printf("abc%xd\n\n", -111111);
	ft_printf("abc%Xd\n", -111111);
	printf("abc%Xd\n\n", -111111);
	ft_printf("abc%hhdd\n", 257);
	printf("abc%hhdd\n\n", (unsigned char)257);
	ft_printf("abc%hdd\n", 25722222222);
	printf("abc%hdd\n\n", (short)25722222222);
	ft_printf("abc%ldd\n", 25722222222);
	printf("abc%ldd\n\n", (long)25722222222);
	ft_printf("abc%lldd\n", (long long)-2572222222222222222);
	printf("abc%lldd\n\n", (long long)-2572222222222222222);
	ft_printf("abc%fd\n", -1234.560);
	printf("abc%fd\n\n", -1234.560);
	ft_printf("abc%Lfd\n", -1234.5601233331232);
	printf("abc%Lfd\n\n", -1234.5601232123123L);
	ft_printf("ft:abc%%%Lfd\n", -1234.5601233331232);
	printf("abc%%%Lfd\n\n", -1234.5601232123123L);

	ft_printf("%lc\n", 'c');
	ft_printf("no percent \n");
	printf("%%10ld:%10ld\n", (long)-1234);
	printf("%% ld:% ld\n", (long)1234);
	printf("%%   ld:%   ld\n", (long)1234);
	printf("%% ld:% ld\n", (long)-1234);
	printf("%%+ld:%+ld\n", (long)1234);
	printf("%%+++ld:%+++ld\n", (long)1234);
	printf("%%#x:%#x\n", 1234);
	printf("%%x:%x\n", 1234);
	printf("invalid: %%+#x\n");
	printf("%%#12x:%#12x\n", 1234);
	printf("invalid:%%12#x\n");
	printf("%%+12d:%+12d\n", 1234);
	printf("invalid: %%12+d\n");
	printf("%%-12x:%-12d\n", 1234);
	printf("invalid:%%12-x\n");
	printf("%%012x:%012d\n", 1234);
	printf("%%120x:%120d\n", 1234);
	ft_printf("no percent \n");
	ft_printf("\n");
	printf("abc" "test\n");
	ft_printf("abc" "test\n");
	ft_printf("%lld\n", (long)1234);
	ft_printf("%%%d%d\n", 123, 456);
	printf("%%%  %d%d\n", 123);
	ft_printf("%%%  %d%d\n", 123);
	printf("%%%###x\n", 123);
	printf("%%%--+12d\n", 123);
	printf("%%%---#x\n", 123);
	printf("%%% 012d\n", 456);
	printf("%%12c: %12c\n", 'a');
	ft_printf("%%12c: %12c\n", 'a');
	printf("%%12s: %12s\n", "abc");
	ft_printf("%%12s: %12s\n", "abc");
	printf("%12d\n", 123);
	ft_printf("%12d\n", 123);
	printf("%12x\n", 123);
	ft_printf("%12x\n", 123);
	printf("%-16f\n", (float)123);
	ft_printf("%-16f\n", (float)456);
	printf("%-5d\n", 123);
	ft_printf("%-5d\n", 123);
	printf("%-5%eee\n");
	ft_printf("%-5%eee\n");
	printf("len: %d\n", printf("%012d\n", 123));
	printf("len: %d\n", ft_printf("%012d\n", 123));
	printf("%012x\n", 123);
	ft_printf("%012x\n", 123);
	printf("%%d:% d\n", -123);
	ft_printf("%%d:+%d\n", 123);
	printf("%#x\n", 0);
	ft_printf("%#x\n", 0);
	printf("%d\n",ft_printf("%hhd\n", -128));
	printf("%d\n",printf("%hhd\n", -128));
	ft_printf("%-05o\n", 2500);
	printf("%-05o\n", 2500);
	printf("%10s %s\n", NULL, "string");
	ft_printf("%10s %s\n", NULL, "string");
	ft_printf("%llu\n", (long long int)-42);
	printf("%llu\n", (long long int)-42);
	ft_printf("%ld\n", (long)-42);
	printf("%ld\n", (long)-42);
	ft_printf("%x\n", -42);
	printf("%x\n", -42);
	printf("%12.4d\n", 12);
	ft_printf("ft:%12.4d\n", 12);
	ft_printf("ft:%04c\n", 'c');
	printf("none:%04c\n", 'c');
	ft_printf("%12.0c\n", 'c');
	printf("%12.0c\n", 'c');
	ft_printf("%-5%\n");
	printf("%-5%\n");
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("%5.0d\n", 0);
	printf("%5.0d\n", 0);
	printf("@moulitest: %#.o %#.0o", 0, 0);
	ft_printf("%.2s\n", "abcd");
	ft_printf("%#.5\n", 123);
	printf("%#.5\n", 123);
	ft_printf("%10s is a string\n", "this");
	printf("%10s is a string\n", "this");
	ft_printf("%5.6x\n", 5427);
	printf("%5.6x\n", 5427);
	ft_printf("%5.3x\n", 5427);
	printf("%5.3x\n", 5427);
	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	printf("@moulitest: %#.o %#.0o\n", 0, 0);
	ft_printf("@moulitest: %#.xaa\n", 0);
	printf("@moulitest: %#.xaa\n", 0);
	ft_printf("%lld\n", 9223372036854775808);
	printf("%lld\n", 9223372036854775808);

	return (0);
}

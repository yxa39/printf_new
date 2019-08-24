/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:21:27 by yxie              #+#    #+#             */
/*   Updated: 2019/08/05 12:15:09 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int main()
{
	printf("%07.s\n", "a");
	printf("%07.0x\n",12);
	printf("%07.0u\n",12);
	printf("%07.4d\n",12);
	printf("%07.4i\n",12);
	printf("%07 012 18o\n",12);
	printf("% o\n",12);
	printf("% i\n",12);
	printf("% s\n", "s");
	printf("%07  .03 .04  07 -18X\n",12);
	printf("%012.5.06 -018f\n", 1.0);
	printf("%03.3-018 f\n", 2.0);
	printf("%012  -18f\n", 3.0);
	printf("%20-18-19 20f\n", 3.0);
	printf("%012 f\n", 3.0);
	printf("%012 18f\n", 4.0);
	printf("%18 012d\n", 4);
	printf("%012+ 18d\n", 4);
	printf("%12-d\n", 1);
	printf("%-12d\n", 2);
	printf("%-012d\n", 3);
	printf("%12d\n", 4);
	printf("c:%0 3 12c\n", 'a');
	printf("c:%-15 0 3 12.2d\n", 1);
	printf("c:%01 .0 + 5c\n", 'a');
	printf("%0+ 0.2 18f\n", 1.0);
	printf("%0 .3 .2 9 s\n", "abc");
	printf("%09 .3 .2 d\n", 1 );
	printf("%09 #X\n", 20);
	printf("%09s\n", "abc");
	int a = 12;
	printf("%020p\n", &a);
	printf("%+012d\n", 123);
	printf("%012d\n", 123);
	printf("%08.2d\n", 123456);
	printf("%h02d\n", 123456);
	printf("%02hd\n", 123456);
	printf("%010.5hd\n", 123);

}

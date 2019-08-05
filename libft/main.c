/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:31:34 by yxie              #+#    #+#             */
/*   Updated: 2019/07/15 10:10:09 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	printargs(int arg1, ...)
{
	va_list	ap;
	double		i;

	va_start(ap, arg1);
	for (i = arg1; i >= 0; i = va_arg(ap, double))
		printf("%f ", i);
	va_end(ap);
	putchar('\n');
}
/*
**comments 
*/
int		main(void)
{
	wchar_t* wide_str = L"A";
	char	*str = "A";
	printf( "%5ls\n", wide_str );
	printf( "%5s\n", str );
	printf("printargs:\n");
//	printargs(5, 2, -20, 14, 84, 97.0, 15.0, 24, 48, -1);
	printf("minimum width:\n");
	printf("%20d\n", 123456789);
	printf("%-20d\n", 123456789);
	printf("%10d\n", -10);
	printf("%-1d\n", -10);
	printf("Flags:\nPound Sign #:\n");
	printf("%#x\n", 12);
	printf("%x\n", 12);
	printf("%#o\n", 12);
	printf("%o\n", 12);
	printf( "|%%-5d|%%-5d|: |%-5d|%-5d|\n", 1, 2 );
	printf( "|%%5d|%%5d|: |%5d|%5d|\n", 1, 2 );
	printf("|%10f|\n", (double)1.234);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_diouxx_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:41:53 by yxie              #+#    #+#             */
/*   Updated: 2019/09/09 10:53:14 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int			convert_int_type(long long int num, t_param *param)
{
	if (param->len_field == 0)
		num = (int)num;
	else if (param->len_field == 1)
		num = (char)num;
	else if (param->len_field == 2)
		num = (short int)num;
	else if (param->len_field == 3)
		num = (long int)num;
	return (num);
}

unsigned long long int	convert_un_type(long long int num, t_param *param)
{
	if (param->len_field == 0)
		num = (unsigned int)num;
	else if (param->len_field == 1)
		num = (unsigned char)num;
	else if (param->len_field == 2)
		num = (unsigned short int)num;
	else if (param->len_field == 3)
		num = (unsigned long int)num;
	return (num);
}

void					get_di_str(long long int num, t_param *param)
{
	*(param->flag_field + 4) = 0;
	if (num + 1 == -9223372036854775807)
		param->str = ft_strdup(MIN);
	else if (num - 1 == 9223372036854775806)
		param->str = ft_strdup(MAX);
	else if (num == 0 && *(param->flag_field + 5) == 1 && param->precision == 0)
		param->str = ft_strnew(0);
	else
		param->str = ft_llitoa(num);
	if (param->str[0] == '-')
	{
		*(param->flag_field + 1) = 0;
		*(param->flag_field + 2) = 0;
		*(param->flag_field + 6) = 1;
		param->str = ft_strdup(++(param->str));
	}
	if (*(param->flag_field + 5) == 1)
	{
		*(param->flag_field + 3) = 1;
		add_zero(param, param->precision, 'd');
		*(param->flag_field + 3) = 0;
	}
	else if (*(param->flag_field) == 0)
		add_zero(param, param->width, 'd');
	add_sign_prefix(param, 'd');
}

void					get_ouxx_str(unsigned long long int num,
		t_param *param, char format)
{
	int	base;

	if (format == 'o')
		base = 8;
	if (format == 'u' || format == 'U')
		base = 10;
	if (format == 'x' || format == 'X')
		base = 16;
	param->str = ft_un_llitoa(num, base, format);
	if (ft_strcmp(param->str, "0") == 0)
		*(param->flag_field + 4) = 0;
	if (ft_strcmp(param->str, "0") == 0 && *(param->flag_field + 5) == 1 &&
	param->precision == 0)
		param->str = ft_strnew(0);
	*(param->flag_field + 1) = 0;
	*(param->flag_field + 2) = 0;
	if (*(param->flag_field + 5) == 1)
	{
		*(param->flag_field + 3) = 1;
		add_zero(param, param->precision, format);
	}
	else if (*(param->flag_field) == 0)
		add_zero(param, param->width, format);
}

void					get_diouxx(char format, va_list *ap, t_param *param)
{
	long long int	num;

	if (format == 'd' || format == 'i')
	{
		num = convert_int_type(va_arg(*ap, long long int), param);
		get_di_str(num, param);
	}
	if (ft_strchr("ouUxX", format))
	{
		if (format == 'U')
			param->len_field = 3;
		num = convert_un_type(va_arg(*ap, long long int), param);
		if (*(param->flag_field + 5) == 1 && *(param->flag_field + 4) == 1
				&& num == 0 && param->precision == 0 && format == 'o')
		{
			free(param->str);
			param->str = ft_strnew(1);
			param->str[0] = '0';
		}
		else
		{
			get_ouxx_str(num, param, format);
			add_sign_prefix(param, format);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:06:49 by yxie              #+#    #+#             */
/*   Updated: 2019/09/09 10:53:10 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*get_decimal(long double num, int precision)
{
	int		prec;
	char	*str;
	int		i;
	int		precision_copy;
	char	*dec_str;

	precision_copy = precision;
	if (num < 0)
		num *= -1;
	prec = 1;
	i = 0;
	str = ft_strnew(precision + 1);
	str[i++] = '.';
	while (precision-- > 0)
		prec *= 10;
	dec_str = ft_llitoa((int)((num - (int)num) * prec));
	while ((int)ft_strlen(dec_str) < precision_copy--)
		str[i++] = '0';
	while (*dec_str)
		str[i++] = *dec_str++;
	str[i] = '\0';
	return (str);
}

long double	convert_float(va_list *ap, t_param *param)
{
	if (param->len_field == 5)
		return (va_arg(*ap, long double));
	else
		return ((long double)va_arg(*ap, double));
}

long double	rounding(long double num, t_param *param)
{
	long double	tens;
	int			precision;

	precision = param->precision;
	tens = 1;
	while (precision-- != 0)
		tens *= 10;
	if (num > 0)
		num = ((num * tens) + 0.5) / tens;
	else
		num = ((num * tens) - 0.5) / tens;
	return (num);
}

void		get_float(va_list *ap, t_param *param)
{
	long double	num;

	num = convert_float(ap, param);
	if (*(param->flag_field + 5) == 0)
		param->precision = 6;
	if (num > -1.0 && num < 0.0)
		*(param->flag_field + 6) = 1;
	num = rounding(num, param);
	param->str = ft_llitoa((long long int)num);
	if (param->precision != 0)
		param->str = ft_strcat(param->str, get_decimal((long double)(num -
						(long long int)num), param->precision));
	if (*(param->flag_field + 4) == 1 && *(param->flag_field + 5) ==
			1 && param->precision == 0)
		param->str = ft_strcat(param->str, ".");
	if (param->str[0] == '-')
	{
		param->str = ft_strdup(++param->str);
		*(param->flag_field + 6) = 1;
		*(param->flag_field + 2) = 0;
		*(param->flag_field + 1) = 0;
	}
	if (*(param->flag_field + 3) == 1)
		add_zero(param, param->width, 'f');
	add_sign_prefix(param, 'f');
}

void		get_percent(t_param *param)
{
	param->str = ft_strnew(1);
	param->str[0] = '%';
	add_zero(param, param->width, '%');
}

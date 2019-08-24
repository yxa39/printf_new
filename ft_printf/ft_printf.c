/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:00:07 by yxie              #+#    #+#             */
/*   Updated: 2019/08/05 12:15:44 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

void	init_param(t_param *param)
{
	int	i;

	param->len_field = 0;
	i = 0;
	while (i <= 6)
	{
		*(param->flag_field + i) = 0;
		i++;
	}
	param->width = 0;
	param->precision = 0;
	param->len = 0;
}

int		get_width(char **format)
{
	int width;

	width = 0;
	if (ft_strchr("123456789", **format))
	{
		width = **format - '0';
		(*format)++;
	}
	//printf("first digit: %d\n", width);
	while (ft_strchr("0123456789", **format))
	{
		width = (**format - '0') + width * 10;
		(*format)++;
	}
//	printf("width: %d\n", width);
	return (width);
}

void	get_flag_field(char **format, t_param *param)
{
	if (ft_strchr("-+ 0#.", **format))
	{
		if (**format == '-')
			*(param->flag_field) = 1;
		if (**format == '+')
			*(param->flag_field + 1) = 1;
		if (**format == ' ')
			*(param->flag_field + 2) = 1;
		if (**format == '0')
			*(param->flag_field + 3) = 1;
		if (**format == '#')
			*(param->flag_field + 4) = 1;
		if (**format == '.')
		{
			*(param->flag_field + 5) = 1;
			(*format)++;
			param->precision = get_width(format);
			(*format)--;
		}
		(*format)++;
	}
}

void	print(t_param *param)
{
	param->len = (int)ft_strlen(param->str);
	if (*(param->flag_field + 3) == 0 && *(param->flag_field) == 0 && param->width - (int)ft_strlen(param->str) > 0)
	{
		param->len = param->width;
		while ((param->width - (int)ft_strlen(param->str)) > 0)
		{
			ft_putchar(' ');
			param->width--;
		}
	}
	ft_putstr(param->str);
	if (*(param->flag_field) == 1 && param->width - (int)ft_strlen(param->str) > 0)
	{
		param->len = param->width;
		while (param->width - (int)ft_strlen(param->str) > 0)
		{
			ft_putchar(' ');
			param->width--;
		}
	}
}

void	add_sign_prefix(t_param *param, char format)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(param->str);
	i = *(param->flag_field + 1) + *(param->flag_field + 4) + *(param->flag_field + 1) + *(param->flag_field + 6);
	if (i > 0)
	{
		free(param->str);
		param->str = ft_strnew((int)ft_strlen(tmp) + i);
	}
	i = 0;
	if (*(param->flag_field + 1) == 1)
		param->str[i++] = '+';
	if (*(param->flag_field + 6) == 1)
		param->str[i++] = '-';
	if (*(param->flag_field + 2) == 1 && *(param->flag_field + 1) == 0)
		param->str[i++] = ' ';
	if (*(param->flag_field + 4) == 1 && ft_strchr("o", format))
		param->str[i++] = '0';
	if (*(param->flag_field + 4) == 1 && ft_strchr("xX", format))
	{
		param->str[i++] = '0';
		param->str[i++] = format;
	}
	while(*tmp)
		param->str[i++] = *(tmp++);
}

void	get_len_field(char **format, t_param *param)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		param->len_field = 1;
		(*format) += 2;
	}
	else if (**format == 'h' && *(*format + 1) != 'h')
	{
		param->len_field = 2;
		*format = *format + 1;
	}
	else if (**format == 'l' && *(*format + 1) != 'l')
	{
		param->len_field = 3;
		*format = *format + 1;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		param->len_field = 4;
		*format = *format + 2;
	}
	else if (**format == 'L')
		(*format)++;
}

void	get_param(char **format, t_param *param)
{
	init_param(param);
	while (!ft_strchr("cspdiouxX", **format))
	{
		get_flag_field(format, param);
		if (ft_strchr("123456789", **format))
			param->width = get_width(format);
		get_len_field(format, param);
	}
}
void	add_zero(t_param *param, int width)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(param->str);
	tmp = ft_strdup(param->str);
	i = 0;
	j = *(param->flag_field + 1) + *(param->flag_field + 4) + *(param->flag_field + 1);
	if (*(param->flag_field + 3) == 1 && *(param->flag_field) == 0)
	{
		if (width - len - j > 0)
		{
			free(param->str);
			param->str = ft_strnew(width + 1);
			while (width - len - j > 0)
			{
				param->str[i++] = '0';
				width--;
			}
			while (*tmp)
				param->str[i++] = *(tmp++);
		}
	}
}

void	str_to_str(char *str, t_param *param)
{
	int		len;
	int		i;

	if (str == NULL)
		param->str = ft_strdup("(null)");
	else
	{
		len = (int)ft_strlen(str);
		if (param->precision < len && *(param->flag_field + 5) == 1)
		{
			len = param->precision;
			free(param->str);
			param->str = ft_strnew(len);
			i = 0;
			while (param->precision-- > 0)
				param->str[i++] = *str++;
			param->str[i] = '\0';
		}
		else
			param->str = ft_strdup(str);
	}
	add_zero(param, param->width);
}

void	get_csp(char format, va_list *ap, t_param *param)
{
	if (format == 'c')
	{
		param->precision = 0;
		param->str = ft_strnew(1);
		*(param->str) = (char)va_arg(*ap, int);
		add_zero(param, param->width);
	}
	if (format == 's')
		str_to_str(va_arg(*ap, char *), param);
	if (format == 'p')
		;
}

long long int	convert_int_type(long long int num, t_param *param)
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

void	get_int_str(long long int num, t_param *param)
{
	*(param->flag_field + 4) = 0;
	if (num + 1 == -9223372036854775807)
		param->str = ft_strdup(MIN);
	else if (num - 1 == 9223372036854775806)
		param->str = ft_strdup(MAX);
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
		add_zero(param, param->precision);
		*(param->flag_field + 3) = 0;
	}
	else
		add_zero(param, param->width);
	add_sign_prefix(param, 'd');
}

void	get_diouxX(char format, va_list *ap, t_param *param)
{
	long long int	num;

	num = convert_int_type(va_arg(*ap, long long int), param);
	if (format == 'd' || format == 'i')
		get_int_str(num, param);
	param->len = ft_strlen(param->str);
}

void	get_float(va_list *ap, t_param *param)
{
	double	num;

	num = va_arg(*ap, double);
	param->str = ft_llioat(num);
}

int		what_to_print(char **format, va_list *ap)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	get_param(format, param);
	if (ft_strchr("csp", **format))
		get_csp(**format, ap, param);
	else if (ft_strchr("diouxX", **format))
		get_diouxX(**format, ap, param);
	else if (ft_strchr("f", **format))
		get_float(ap, param);
//	if (**format == '%')
//		get_percent(param);
	print(param);
	return (param->len);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += what_to_print(&format, &ap);
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	printf("len: %d\n", len);
	return (len);
}


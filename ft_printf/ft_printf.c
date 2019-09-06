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
#include <stdio.h>

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
	param->error = 0;
	param->c = '\0';
	param->str = ft_strnew(0);
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
	while (**format && ft_strchr("0123456789", **format))
	{
		width = (**format - '0') + width * 10;
		(*format)++;
	}
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

void	print(t_param *param, char format)
{
	int	int_len;

	if (format == 'c')
		param->len = 1 + (int)ft_strlen(param->str);
	else
		param->len = (int)ft_strlen(param->str);
	int_len = param->len;
	if (*(param->flag_field) == 0 && param->width - int_len > 0)
	{
		param->len = param->width;
		while ((param->width - int_len) > 0)
		{
			ft_putchar(' ');
			param->width--;
		}
	}
	ft_putstr(param->str);
	if (format == 'c')
		ft_putchar(param->c);
	if (*(param->flag_field) == 1 && param->width - int_len > 0)
	{
		param->len = param->width;
		while (param->width - int_len > 0)
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
	i = *(param->flag_field + 1) + *(param->flag_field + 4) * 2 + *(param->flag_field + 6);
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
	if (*(param->flag_field + 4) == 1 && ft_strchr("o", format) && param->precision == 0)
		param->str[i++] = '0';
	if (*(param->flag_field + 4) == 1 && ft_strchr("xX", format))
	{
		param->str[i++] = '0';
		param->str[i++] = format;
	}
	while(*tmp)
		param->str[i++] = *(tmp++);
	param->str[i] = '\0';
}

void	get_len_field(char **format, t_param *param)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		param->len_field = 1;
		(*format)++;
	}
	else if ((**format == 'h' && *(*format + 1) != 'h') && param->len_field < 3)
		param->len_field = 2;
	else if ((**format == 'l' && *(*format + 1) != 'l') || **format == 'z')
		param->len_field = 3;
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		param->len_field = 4;
		(*format)++;
	}
	else if (**format == 'j')
		param->len_field = 4;
	else if (**format == 'L')
		param->len_field = 5;
	(*format)++;
}

void	get_param(char **format, t_param *param)
{
	init_param(param);
	if (**format && ft_strchr("-+ 0#.hlL123456789jzt", **format))
	{
		while (!ft_strchr("csSpdiouUxXf%", **format))
		{
			if (!ft_strchr("-+ 0#.hlL123456789jzt", **format))
				break;
			if (**format && ft_strchr("-+ 0#.", **format))
				get_flag_field(format, param);
			if (**format && ft_strchr("123456789", **format))
				param->width = get_width(format);
			if (**format && ft_strchr("hlLjzt", **format))
				get_len_field(format, param);
		}
	}
}

void	add_zero(t_param *param, int width, char format)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	if (format == 'c')
		len = 1;
	else
		len = (int)ft_strlen(param->str);
	tmp = ft_strdup(param->str);
	i = 0;
	j = *(param->flag_field + 1) + *(param->flag_field + 4) + *(param->flag_field + 6);
	if (*(param->flag_field + 2) == 1 && *(param->flag_field + 1) == 0)
		j++;
	if (*(param->flag_field + 4) == 1 && ft_strchr("xX", format))
		j++;
	if (*(param->flag_field + 5) != 1)
		len += j;
	if ((*(param->flag_field + 3) == 1 && *(param->flag_field) == 0) || *(param->flag_field + 5) == 1)
	{
		if (width - len > 0)
		{
			free(param->str);
			param->str = ft_strnew(width);
			while (width - len > 0)
			{
				param->str[i++] = '0';
				width--;
			}
			while (*tmp)
				param->str[i++] = *(tmp++);
		}
	}
}

void	get_s_str(char *str, t_param *param)
{
	int		len;
	int		i;

	if (str == 0)
		str = ft_strdup("(null)");
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
	if (*(param->flag_field + 3) == 1)
		add_zero(param, param->width, 's');
}

void	get_c_str(char ch, t_param *param)
{
	param->precision = 0;
	param->c = (char)ch;
	param->str = ft_strnew(0);
	add_zero(param, param->width, 'c');
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


void	get_di_str(long long int num, t_param *param)
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

void	get_ouxX_str(unsigned long long int num, t_param *param, char format)
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
	if (ft_strcmp(param->str, "0") == 0 && *(param->flag_field + 5) == 1 && param->precision == 0)
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

void	get_csp(char format, va_list *ap, t_param *param)
{
	if (format == 'c')
		get_c_str(va_arg(*ap, int), param);
	if (format == 's')
		get_s_str(va_arg(*ap, char *), param);
	if (format == 'S')
		get_s_str(va_arg(*ap, char *), param);
	if (format == 'p')
	{
		get_ouxX_str((unsigned long long)va_arg(*ap, void *), param, 'x');
		*(param->flag_field + 4) = 1;
		add_sign_prefix(param, 'x');
	}
}

void	get_diouxX(char format, va_list *ap, t_param *param)
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
		if (*(param->flag_field + 5) == 1 && *(param->flag_field + 4) == 1 && num == 0 && param->precision == 0 && format == 'o')
		{
			free(param->str);
			param->str = ft_strnew(1);
			param->str[0] = '0';
		}
		else
		{
			get_ouxX_str(num, param, format);
			add_sign_prefix(param, format);
		}
	}
}

char	*get_decimal(double num, int precision)
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
	str = ft_strnew(precision);
	str[i++] = '.';
	while (precision-- > 0)
		prec *= 10;
	dec_str = ft_llitoa((int)(float)((num - (int)num) * prec));
	while ((int)ft_strlen(dec_str) < precision_copy--)
		str[i++] = '0';
	while (*dec_str)
		str[i++] = *dec_str++;
	str[i] = '\0';
	return (str);
}

long double convert_float(va_list *ap, t_param *param)
{
	if (param->len_field == 5)
		return (va_arg(*ap, long double));
	else
		return ((long double)va_arg(*ap, double));
}

void	get_float(va_list *ap, t_param *param)
{
	long double	num;

	num = convert_float(ap, param);
	if (*(param->flag_field + 5) == 0)
		param->precision = 6;
	param->str = ft_llitoa((long long int)(float)num);
	if (param->precision != 0)
		param->str = ft_strcat(param->str, get_decimal((long double)(float)(num - (long long int)num), param->precision));
	if (num > -1.0 && num < 0.0)
		*(param->flag_field + 6) = 1;
	add_zero(param, param->width, 'f');
	add_sign_prefix(param, 'f');
}

void	get_percent(t_param *param)
{
	param->str = ft_strnew(1);
	param->str[0] = '%';
	add_zero(param, param->width, '%');
}

int		what_to_print(char **format, va_list *ap)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	get_param(format, param);
	if (**format == '\0')
		param->error = 2;
	else if (ft_strchr("cspS", **format))
		get_csp(**format, ap, param);
	else if (ft_strchr("diouUxX", **format))
		get_diouxX(**format, ap, param);
	else if (ft_strchr("f", **format))
		get_float(ap, param);
	else if (**format == '%')
		get_percent(param);
	else
	{
		param->error = 1;
		param->width--;
	}
	if (param->error != 2)
	{
		print(param, **format);
		if (param->error == 1)
		{
			ft_putchar(**format);
			param->len++;
		}
		(*format)++;
	}
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
			if (*format && ft_strchr("-+ 0#.hlL123456789csSpdiouUxXf%jzt", *format))
				len += what_to_print(&format, &ap);
		}
		else if (*format && *format != '%')
		{
			ft_putchar(*format);
			len++;
			format++;
		}
	}
	va_end(ap);
	return (len);
}

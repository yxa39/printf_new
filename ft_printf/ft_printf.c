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
		{
			*(param->flag_field + 4) = 1;
			if (*(param->flag_field + 5) == 1 || param->width != 0 || param->len_field != 0)
				param->error = 1;
		}
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

	param->len = (int)ft_strlen(param->str);
	int_len = param->len;
	if (format == 'c')
	{
		int_len = 1;
		param->len = 1;
	}
//	printf("param->len: %d\n", param->len);
//	printf("width: %d\n", param->width);
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
	{
		param->len_field = 5;
		(*format)++;
	}
}

void	get_param(char **format, t_param *param)
{
	init_param(param);
	while (**format && !ft_strchr("cspdiouxXf%", **format))
	{
		if (!ft_strchr("-+ 0#.hlL123456789", **format))
		{
			param->error = 1;
			(*format)++;
		}
		get_flag_field(format, param);
		if (ft_strchr("123456789", **format))
			param->width = get_width(format);
		get_len_field(format, param);
	}
}

void	add_zero(t_param *param, int width, char format)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(param->str);
	tmp = ft_strdup(param->str);
	i = 0;
	j = *(param->flag_field + 1) + *(param->flag_field + 4) + *(param->flag_field + 6);
	if (*(param->flag_field + 2) == 1 && *(param->flag_field + 1) == 0)
		j++;
	if (*(param->flag_field + 4) == 1 && ft_strchr("xX", format))
		j++;
	if (*(param->flag_field + 5) != 1)
		len += j;
	if (*(param->flag_field + 3) == 1)
	{
		if (width - len > 0)
		{
			free(param->str);
			param->str = ft_strnew(width + 1);
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
	add_zero(param, param->width, 's');
}

void	get_c_str(char ch, t_param *param)
{
	param->precision = 0;
	*(param->flag_field + 3) = 0;
	param->c = (char)ch;
	add_zero(param, param->width, 'c');
}

void	get_csp(char format, va_list *ap, t_param *param)
{
	if (format == 'c')
		get_c_str(va_arg(*ap, int), param);
	if (format == 's')
		get_s_str(va_arg(*ap, char *), param);
	if (format == 'p')
		exit(0);
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
	if (format == 'u')
		base = 10;
	if (format == 'x' || format == 'X')
		base = 16;
	if (num == 0 && *(param->flag_field + 5) == 1 && param->precision == 0)
		param->str = ft_strnew(0);
	else
		param->str = ft_un_llitoa(num, base, format);
	*(param->flag_field + 1) = 0;
	*(param->flag_field + 2) = 0;
	if (num == 0)
		*(param->flag_field + 4) = 0;
	if (*(param->flag_field + 5) == 1)
	{
		*(param->flag_field + 3) = 1;
		add_zero(param, param->precision, format);
	}
	else if (*(param->flag_field) == 0)
		add_zero(param, param->width, format);
	add_sign_prefix(param, format);
}

void	get_diouxX(char format, va_list *ap, t_param *param)
{
	long long int	num;

	if (format == 'd' || format == 'i')
	{
		num = convert_int_type(va_arg(*ap, long long int), param);
		get_di_str(num, param);
	}
	if (ft_strchr("ouxX", format))
	{
		num = convert_un_type(va_arg(*ap, long long int), param);
		if (*(param->flag_field + 5) == 1 && *(param->flag_field + 4) == 1 && num == 0 && param->precision == 0 && format == 'o')
		{
			free(param->str);
			param->str = ft_strnew(1);
			param->str[0] = '0';
		}
		else
			get_ouxX_str(num, param, format);
	}
}

char	*get_decimal(double num, int precision)
{
	int		prec;
	float	dec;
	char	*str;
	int		i;
	char	*dec_str;

	prec = 1;
	i = 0;
	str = ft_strnew(precision + 1);
	str[i++] = '.';
	while (precision > 0)
	{
		prec *= 10;
		precision--;
	}
	dec = (float)((num - (int)num) * prec);
	dec_str = ft_llitoa((int)dec);
	while (*dec_str)
		str[i++] = *dec_str++;
	str[i] = '\0';
	return (str);
}

void	get_float(va_list *ap, t_param *param)
{
	double	num;

	num = va_arg(*ap, double);
	param->str = ft_llitoa((int)num);
	if (*(param->flag_field + 5) == 0)
		param->precision = 6;
	if (param->precision != 0)
		param->str = ft_strcat(param->str, get_decimal(num - (double)(int)num, param->precision));
	add_zero(param, param->width, 'f');
	add_sign_prefix(param, 'f');
}

void	get_percent(t_param *param)
{
	init_param(param);
	param->str = ft_strnew(1);
	param->str[0] = '%';
	param->str[1] = '\0';
}

int		what_to_print(char **format, va_list *ap)
{
	t_param	*param;
	char	*copy;

	copy = *format;
	param = (t_param *)malloc(sizeof(t_param));
	get_param(format, param);
	if (ft_strchr("csp", **format))
		get_csp(**format, ap, param);
	else if (ft_strchr("diouxX", **format))
		get_diouxX(**format, ap, param);
	else if (ft_strchr("f", **format))
		get_float(ap, param);
	else if (**format == '%')
		get_percent(param);
	else
	{
		param->len = -1;
		init_param(param);
	}
	if (param->error == 1)
		ft_putstr(--copy);
	else
		print(param, **format);
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
//	printf("len: %d\n", len);
	return (len);
}


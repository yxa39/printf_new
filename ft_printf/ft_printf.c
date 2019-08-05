/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:00:07 by yxie              #+#    #+#             */
/*   Updated: 2019/08/05 11:57:47 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

void	init_field(t_field *field)
{
	int	i;

	field->len_field = 0;
	i = 0;
	while (i < 6)
		*(field->flag_field + i++) = 0;
	field->width = 0;
	field->precision = 0;
}

void	get_flag_field(char **format, t_field *field)
{
	while(ft_strchr("-+ 0#", **format))
	{
		if (**format == '-')
			*(field->flag_field) = 1;
		if (**format == '+')
			*(field->flag_field + 1) = 1;
		if (**format == ' ')
			*(field->flag_field + 2) = 1;
		if (**format == '0')
			*(field->flag_field + 3) = 1;
		if (**format == '#')
			*(field->flag_field + 4) = 1;
		(*format)++;
	}
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

void	get_precision_field(char **format, t_field *field)
{
	if (**format == '.')
	{
		*(flag_field + 5) = 1;
		(*format)++;
	}
}

int		get_len_field(char **format)
{
	int	type;

	type = 0;
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		type = 1;
		*format = *format + 2;
	}
	else if (**format == 'h' && *(*format + 1) != 'h')
	{
		type = 2;
		*format = *format + 1;
	}
	else if (**format == 'l' && *(*format + 1) != 'l')
	{
		type = 3;
		*format = *format + 1;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		type = 4;
		*format = *format + 2;
	}
	else if (**format == 'L')
		(*format)++;
	return (type);
}

void	get_field(char **format, t_field *field)
{
	init_field(field);
	get_flag_field(format, field);
	field->width = get_width(format);
	get_precision_field(format, field);
	field->precision = get_width(format);
	field->len_field = get_len_field(format);
}

void	init_value(t_value *value)
{
	value->len = 0;
	value->spaces = 0;
	value->hash = 0;
	value->width = 0;
}

int		get_spaces(int len, t_field *field)
{
	int	num;
	
	num = 0;
	if (width > len && *flag_field == 0 && (*(flag_field + 3) == 0 || *(flag_field + 5) == 1) && *(flag_field + 5) == 0)
	{
		while (width-- > len)
			num++;
	}
	if (*flag_field == 0 && *(flag_field + 5) == 1 && width > (len > precision ? precision : len) && (*(flag_field + 3) == 0 || *(flag_field + 5) == 1))
	{
		while (width-- > (len > precision ? precision : len))
			num++;
	}
	return (num);
}

int		ft_putstr_len(char *str, int width, int *flag_field, int precision)
{
	int	len;

	if (str == NULL)
		len = ft_strlen("(null)");
	else
		len = (int)ft_strlen(str);
//	printf("%d\n", width);
//	printf("%d\n", len);
//	printf("%d\n", precision);
	print_spaces(width, len, flag_field, precision);
	if (str == NULL)
		ft_putstr("(null)");
	else if (precision < len && *(flag_field + 5) == 1)
	{
		len = precision;
		while (precision-- > 0)
			ft_putchar(*(str++));
	}
	else
		ft_putstr(str);
	return (len);
}

int		print_zeros(t_field field, int adjust)
{
	int	tmp;

	if (width > len && *(flag_field + 3) == 1 && *flag_field == 0 && *(flag_field + 5) == 0)
	{
		tmp = width;
		while (width-- > len)
			ft_putchar('0');
		len = tmp;
	}
	if (precision > (len - hash_len)  && *(flag_field + 5) == 1)
	{
		tmp = precision;
		while (precision > (len - hash_len))
		{
			ft_putchar('0');
			precision--;
		}
		len = tmp;
	}
	return (len);
}

int		get_csp(char *format, va_list *ap, t_field *field, t_value value)
{
	if (*format == 'c')
	{
		value->
		value->spaces = get_spaces(value->len, field);
		field->precision = 0;
		value->zeros = print_zeros(field);
		ft_putchar(va_arg(*ap, int));
		return (len);
	}
	if (*format == 's')
		return ft_putstr_len(va_arg(*ap, char *), width, flag_field, precision);
	if (*format == 'p')
		return ft_printf("%#lx", (long)va_arg(*ap, void *));
	return (0);
}

int		what_to_print(char **format, va_list *ap)
{
	t_field	*field;
	t_value	*value;

	get_field(format, field);
	init_value(value);
	if (ft_strchr("csp", **format))
		get_csp(*format, ap, field, value);
	else if (ft_strchr("diouxX", **format))
		get_diouxX(*format, ap, field, value);
	else if (ft_strchr("f", **format))
		get_float(ap, field, value);
	if (**format == '%')
	{
		get_percent(field, value);
		*format++;
	}
	print(value);
	return (value->len);
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
	return (len);
}


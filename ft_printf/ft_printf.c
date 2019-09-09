/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:00:07 by yxie              #+#    #+#             */
/*   Updated: 2019/09/09 11:11:10 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	prep_print(char **format, t_param *param)
{
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
		get_diouxx(**format, ap, param);
	else if (ft_strchr("f", **format))
		get_float(ap, param);
	else if (**format == '%')
		get_percent(param);
	else
	{
		param->error = 1;
		param->width--;
	}
	prep_print(format, param);
	free(param->str);
	return (param->len);
}

int		ft_printf(char *format, ...)
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
			if (*format && ft_strchr("-+ 0#.hlL123456789csSpdiouUxXf%jzt",
			*format))
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

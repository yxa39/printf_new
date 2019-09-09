/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 09:59:37 by yxie              #+#    #+#             */
/*   Updated: 2019/09/09 10:53:32 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	get_param(char **format, t_param *param)
{
	init_param(param);
	if (**format && ft_strchr("-+ 0#.hlL123456789jzt", **format))
	{
		while (!ft_strchr("csSpdiouUxXf%", **format))
		{
			if (!ft_strchr("-+ 0#.hlL123456789jzt", **format))
				break ;
			if (**format && ft_strchr("-+ 0#.", **format))
				get_flag_field(format, param);
			if (**format && ft_strchr("123456789", **format))
				param->width = get_width(format);
			if (**format && ft_strchr("hlLjzt", **format))
				get_len_field(format, param);
		}
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

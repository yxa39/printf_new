/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:01:49 by yxie              #+#    #+#             */
/*   Updated: 2019/09/09 10:47:00 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_j(char format, t_param *param)
{
	int	j;

	j = *(param->flag_field + 1) + *(param->flag_field + 4) +
		*(param->flag_field + 6);
	if (*(param->flag_field + 2) == 1 && *(param->flag_field + 1) == 0)
		j++;
	if (*(param->flag_field + 4) == 1 && ft_strchr("xX", format))
		j++;
	return (j);
}

void	add_zero(t_param *param, int width, char format)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	if (format == 'c')
		len = 1;
	else
		len = (int)ft_strlen(param->str);
	tmp = ft_strdup(param->str);
	if (*(param->flag_field + 5) != 1 || format == 'f')
		len += get_j(format, param);
	if ((*(param->flag_field + 3) == 1 && *(param->flag_field) == 0) ||
			*(param->flag_field + 5) == 1)
	{
		if (width - len > 0)
		{
			free(param->str);
			param->str = ft_strnew(width);
			while (width-- - len > 0)
				param->str[i++] = '0';
			while (*tmp)
				param->str[i++] = *(tmp++);
		}
	}
}

void	add_sign_prefix(t_param *param, char format)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(param->str);
	i = *(param->flag_field + 1) + *(param->flag_field + 4) * 2 +
		*(param->flag_field + 6);
	param->str = ft_strnew((int)ft_strlen(tmp) + i);
	i = 0;
	if (*(param->flag_field + 1) == 1)
		param->str[i++] = '+';
	if (*(param->flag_field + 6) == 1)
		param->str[i++] = '-';
	if (*(param->flag_field + 2) == 1 && *(param->flag_field + 1) == 0)
		param->str[i++] = ' ';
	if (*(param->flag_field + 4) == 1 && ft_strchr("o", format) &&
			param->precision == 0)
		param->str[i++] = '0';
	if (*(param->flag_field + 4) == 1 && ft_strchr("xX", format))
	{
		param->str[i++] = '0';
		param->str[i++] = format;
	}
	while (*tmp)
		param->str[i++] = *(tmp++);
	param->str[i] = '\0';
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
		while ((param->width-- - int_len) > 0)
			ft_putchar(' ');
	}
	ft_putstr(param->str);
	if (format == 'c')
		ft_putchar(param->c);
	if (*(param->flag_field) == 1 && param->width - int_len > 0)
	{
		param->len = param->width;
		while (param->width-- - int_len > 0)
			ft_putchar(' ');
	}
}

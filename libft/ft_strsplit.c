/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:14:43 by yxie              #+#    #+#             */
/*   Updated: 2019/01/05 16:10:17 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(const char *s, char c)
{
	int	str_len;

	str_len = 0;
	while (*s != c && *s)
	{
		str_len++;
		s++;
	}
	return (str_len);
}

static int	get_array_len(const char *s, char c)
{
	int	array_len;

	array_len = 0;
	while (*s)
	{
		if (*s != c)
		{
			array_len++;
			while (*s != c)
			{
				s++;
				if (*s == '\0')
					return (array_len);
			}
		}
		s++;
	}
	return (array_len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	while (*s == c && *s)
		s++;
	if (!(array = (char **)malloc(sizeof(*array) * (get_array_len(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		j = 0;
		array[++i] = ft_strnew(get_word_len(s, c));
		if (!*array)
			return (NULL);
		while (*s != c && *s)
			array[i][j++] = *s++;
		while (*s == c)
			s++;
	}
	array[++i] = NULL;
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:20:10 by yxie              #+#    #+#             */
/*   Updated: 2019/07/03 10:05:21 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		save_new_line(char **str, char **line)
{
	char	*tmp;
	int		len;
	int		i;

	if (ft_strchr(*str, '\n'))
	{
		len = 0;
		while ((*str)[len] != '\n')
			len++;
		*line = ft_strnew(len);
		tmp = *line;
		i = 0;
		while ((*str)[i] != '\n')
			*tmp++ = (*str)[i++];
		*tmp = '\0';
		tmp = ft_strdup(*str + len + 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	else
		return (0);
}

void	append_buff_to_str(char **str, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin((char const *)*str, (char const *)buff);
	free(*str);
	*str = tmp;
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			nbread;
	static char	*str;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!str)
		str = ft_strnew(0);
	if (save_new_line(&str, line))
		return (1);
	ft_bzero(buff, BUFF_SIZE + 1);
	nbread = read(fd, buff, BUFF_SIZE);
	if (nbread > 0)
	{
		append_buff_to_str(&str, buff);
		return (get_next_line(fd, line));
	}
	if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		ft_strdel(&str);
		return (1);
	}
	ft_strdel(&str);
	return (nbread);
}

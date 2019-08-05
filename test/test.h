/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:22:21 by yxie              #+#    #+#             */
/*   Updated: 2019/07/18 12:44:08 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
#include<libc.h>

typedef struct		s_list
{
	void			*content;
}					t_list;

int	ft_printf(const char * restrict format, ...);
#endif

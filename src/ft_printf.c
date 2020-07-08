/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:41:29 by qdang             #+#    #+#             */
/*   Updated: 2020/07/06 20:56:28 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	clean_flag(t_info *s)
{
	s->flag[MINUS] = '0';
	s->flag[ZERO] = '0';
	s->flag[HASH] = '0';
	s->flag[SPACE] = '0';
	s->flag[PLUS] = '0';
}

int		ft_printf(const char *restrict format, ...)
{
	t_info	*s;
	int		len;

	s = (t_info *)ft_memalloc(sizeof(t_info));
	va_start(s->ap, format);
	s->fm = format;
	while (*s->fm)
	{
		s->signal = 0;
		while (*s->fm && *s->fm != '%')
		{
			ft_putchar(*s->fm);
			s->len++;
			s->fm++;
		}
		if (*s->fm && *s->fm == '%')
			s = deal_input(s);
	}
	va_end(s->ap);
	len = s->len;
	free(s);
	return (len);
}

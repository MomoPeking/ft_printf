/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:41:29 by qdang             #+#    #+#             */
/*   Updated: 2020/04/27 13:03:29 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

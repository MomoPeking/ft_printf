/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 13:01:25 by Amber             #+#    #+#             */
/*   Updated: 2020/04/27 13:46:05 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info			*deal_width(t_info *s)
{
	s->mfw = 0;
	if (*s->fm == '*')
	{
		s->mfw = va_arg(s->ap, int);
		if (s->mfw < 0)
		{
			s->mfw *= -1;
			s->flag[MINUS] = '1';
		}
		s->fm++;
	}
	if (*s->fm >= '0' && *s->fm <= '9')
		s->mfw = ft_strnbr((char *)s->fm);
	while (*s->fm >= '0' && *s->fm <= '9')
		s->fm++;
	return (s);
}

t_info			*deal_precision(t_info *s)
{
	s->prec = 0;
	s->point = 0;
	if (*s->fm == '.')
	{
		s->point = 1;
		s->fm++;
		if (*s->fm == '*')
		{
			s->prec = va_arg(s->ap, int);
			if (s->prec < 0)
			{
				s->prec = 0;
				s->point = 0;
			}
			s->fm++;
		}
		if (*s->fm >= '0' && *s->fm <= '9' && s->prec == 0)
			s->prec = ft_strnbr((char *)s->fm);
		while (*s->fm >= '0' && *s->fm <= '9')
			s->fm++;
		if (s->prec > 0)
			s->point = 2;
	}
	return (s);
}

#if BONUS == 0

static t_info	*deal_flag(t_info *s)
{
	while (*s->fm == '-' || *s->fm == '0')
	{
		if (*s->fm == '-')
			s->flag[MINUS] = '1';
		if (*s->fm == '0')
			s->flag[ZERO] = '1';
		s->fm++;
	}
	return (s);
}

static t_info	*deal_conversion_specifier(t_info *s)
{
	if (*s->fm == 'c' && s->signal == 0)
		s = deal_char(s);
	if (*s->fm == 's' && s->signal == 0)
		s = deal_string(s);
	if (*s->fm == 'p' && s->signal == 0)
		s = deal_pointer(s);
	if ((*s->fm == 'i' || *s->fm == 'd') && s->signal == 0)
		s = deal_decimal_integer(s);
	if (*s->fm == 'u' && s->signal == 0)
		s = deal_unsigned_int(s);
	if ((*s->fm == 'x' || *s->fm == 'X') && s->signal == 0)
		s = deal_hexadecimal(s);
	if (*s->fm == '%' && s->signal == 0)
		s = deal_percentage(s);
	return (s);
}

t_info			*deal_input(t_info *s)
{
	s->fm++;
	s = deal_flag(s);
	s = deal_width(s);
	s = deal_precision(s);
	s = deal_conversion_specifier(s);
	return (s);
}

#endif

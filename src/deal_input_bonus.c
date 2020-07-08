/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 08:03:13 by Amber             #+#    #+#             */
/*   Updated: 2020/07/06 20:56:22 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_info	*deal_length(t_info *s)
{
	if (*s->fm == 'h' && *(s->fm + 1) == 'h')
		s->length[CHAR] = '1';
	if (*s->fm == 'h' && *(s->fm + 1) != 'h')
		s->length[SHORT] = '1';
	if (*s->fm == 'l' && *(s->fm + 1) != 'l')
		s->length[LONG] = '1';
	if (*s->fm == 'l' && *(s->fm + 1) == 'l')
		s->length[LONGLONG] = '1';
	while (*s->fm == 'h' || *s->fm == 'l')
		s->fm++;
	return (s);
}

#if BONUS == 1

static t_info	*deal_flag(t_info *s)
{
	clean_flag(s);
	while (*s->fm == '-' || *s->fm == '0' || *s->fm == '#' ||
		*s->fm == ' ' || *s->fm == '+')
	{
		if (*s->fm == '-')
			s->flag[MINUS] = '1';
		if (*s->fm == '0')
			s->flag[ZERO] = '1';
		if (*s->fm == '#')
			s->flag[HASH] = '1';
		if (*s->fm == ' ')
			s->flag[SPACE] = '1';
		if (*s->fm == '+')
			s->flag[PLUS] = '1';
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
	if (*s->fm == 'f' && s->signal == 0)
		s = deal_float(s);
	return (s);
}

t_info			*deal_input(t_info *s)
{
	s->fm++;
	s = deal_flag(s);
	s = deal_width(s);
	s = deal_precision(s);
	s = deal_length(s);
	s = deal_conversion_specifier(s);
	return (s);
}

#endif

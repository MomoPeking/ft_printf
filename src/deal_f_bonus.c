/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_f_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 08:13:12 by Amber             #+#    #+#             */
/*   Updated: 2020/07/06 20:06:26 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		fl_length(t_info *s, double nbr)
{
	int		nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (s->point == 1 && s->flag[HASH] == '1')
		nbrlen++;
	if (s->point != 1)
	{
		if (s->prec == 0)
			nbrlen += 7;
		else
			nbrlen += s->prec + 1;
	}
	if (s->flag[PLUS] == '1' && nbr >= 0)
		nbrlen++;
	if (s->flag[SPACE] == '1' && s->flag[PLUS] == '0' && nbr >= 0)
		nbrlen++;
	if (nbr < 0)
		nbrlen++;
	return (nbrlen);
}

static void		fl_minus(t_info *s, double nbr, int nbrlen)
{
	if (s->flag[PLUS] == '1' && nbr >= 0)
		ft_putchar('+');
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
	{
		ft_putchar(' ');
		s->mfw--;
	}
	if (nbr < 0)
		ft_putchar('-');
	ft_putf(s, nbr, nbrlen);
	if (s->mfw > nbrlen)
		while (--s->mfw > nbrlen)
			ft_putchar(' ');
}

static void		fl_width(t_info *s, double nbr, int nbrlen)
{
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
		s->mfw--;
	if (s->flag[ZERO] == '1')
	{
		if (s->flag[PLUS] == '1' && nbr >= 0)
			ft_putchar('+');
		if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
			ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
		while (--s->mfw > nbrlen)
			ft_putchar('0');
	}
	else
	{
		while (--s->mfw > nbrlen)
			ft_putchar(' ');
		if (s->flag[PLUS] == '1' && nbr >= 0)
			ft_putchar('+');
		if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
			ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
	}
	ft_putf(s, nbr, nbrlen);
}

static void		fl_nonminus(t_info *s, double nbr, int nbrlen)
{
	if (s->mfw > nbrlen)
		fl_width(s, nbr, nbrlen);
	else
	{
		if (s->flag[PLUS] == '1' && nbr >= 0)
			ft_putchar('+');
		if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
			ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
		ft_putf(s, nbr, nbrlen);
	}
}

t_info			*deal_float(t_info *s)
{
	double	nbr;
	int		nbrlen;

	nbr = va_arg(s->ap, double);
	nbrlen = fl_length(s, nbr);
	if (s->mfw > nbrlen)
	{
		s->len += s->mfw - nbrlen;
		s->mfw++;
	}
	s->flag[MINUS] == '1' ? fl_minus(s, nbr, nbrlen) :
		fl_nonminus(s, nbr, nbrlen);
	s->len += nbrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}

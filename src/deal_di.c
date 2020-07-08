/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:08:12 by Amber             #+#    #+#             */
/*   Updated: 2020/05/28 17:49:07 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		di_length(t_info *s, long long nbr)
{
	int		nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (s->point == 1 && nbr == 0)
		nbrlen--;
	if (s->flag[PLUS] == '1' && nbr >= 0)
		nbrlen++;
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
		nbrlen++;
	if (nbr < 0)
		nbrlen++;
	return (nbrlen);
}

static void		di_minus(t_info *s, long long nbr, int nbrlen, int z)
{
	if (s->flag[PLUS] == '1' && nbr >= 0)
		ft_putchar('+');
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
		ft_putchar(' ');
	if (nbr < 0)
		ft_putchar('-');
	ft_putnchar('0', z);
	if (s->point != 1 || nbr != 0)
		ft_putll(nbr);
	if (s->mfw > nbrlen)
		while (--s->mfw > nbrlen + z)
			ft_putchar(' ');
}

static void		di_nonminus(t_info *s, long long nbr, int nbrlen, int z)
{
	if (s->mfw > nbrlen)
		di_width(s, nbr, nbrlen, z);
	else
	{
		if (s->flag[PLUS] == '1' && nbr >= 0)
			ft_putchar('+');
		if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
			ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
		ft_putnchar('0', z);
		if (s->point != 1 || nbr != 0)
			ft_putll(nbr);
	}
}

t_info			*deal_decimal_integer(t_info *s)
{
	long long	nbr;
	int			nbrlen;
	int			z;

	nbr = trans_ll(s, va_arg(s->ap, long long));
	nbrlen = di_length(s, nbr);
	z = s->prec - ft_nbrlen(nbr);
	if (z < 0)
		z = 0;
	if (s->mfw <= s->prec)
		s->len += z;
	if (s->mfw > nbrlen && s->mfw > s->prec)
	{
		s->len += s->mfw - nbrlen;
		s->mfw++;
	}
	s->flag[MINUS] == '1' ? di_minus(s, nbr, nbrlen, z) :
		di_nonminus(s, nbr, nbrlen, z);
	s->len += nbrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}

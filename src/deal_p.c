/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:56:48 by Amber             #+#    #+#             */
/*   Updated: 2020/05/28 17:50:02 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		output(t_info *s, unsigned long long ptr, int ptrlen, int z)
{
	if (s->flag[MINUS] == '1' || (s->flag[ZERO] == '1' && z == 0))
	{
		ft_putstr("0x");
		ft_putnchar('0', z);
	}
	if (s->flag[MINUS] == '1' && (ptr != 0 || s->point != 1))
		ft_puthex(ptr, 'x');
	if (s->mfw > ptrlen && s->mfw > s->prec)
	{
		s->len += s->mfw - ptrlen;
		s->mfw++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1' && z != 0)
			while (--s->mfw > ptrlen)
				ft_putchar('0');
		else
			while (--s->mfw > ptrlen + z)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1' && (s->flag[ZERO] != '1' || z != 0))
	{
		ft_putstr("0x");
		ft_putnchar('0', z);
	}
	if (s->flag[MINUS] != '1' && (ptr != 0 || s->point != 1))
		ft_puthex(ptr, 'x');
}

t_info			*deal_pointer(t_info *s)
{
	unsigned long long	ptr;
	unsigned long long	temp;
	int					ptrlen;
	int					z;

	ptr = (unsigned long long)va_arg(s->ap, void *);
	temp = ptr;
	ptrlen = 2;
	if (temp == 0 && s->point != 1)
		ptrlen++;
	while (temp > 0)
	{
		ptrlen++;
		temp /= 16;
	}
	z = s->prec - ptrlen + 2;
	if (z < 0)
		z = 0;
	if (s->mfw <= s->prec && z != 0)
		s->len += z;
	output(s, ptr, ptrlen, z);
	s->len += ptrlen;
	s->fm++;
	s->signal = 1;
	return (s);
}

t_info			*deal_percentage(t_info *s)
{
	if (s->flag[MINUS] == '1')
		ft_putchar('%');
	if (s->mfw > 1)
	{
		s->len += s->mfw - 1;
		s->mfw++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
			while (--s->mfw > 1)
				ft_putchar('0');
		else
			while (--s->mfw > 1)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1')
		ft_putchar('%');
	s->len++;
	s->fm++;
	s->signal = 1;
	return (s);
}

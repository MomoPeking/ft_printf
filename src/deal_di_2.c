/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_di_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 22:25:03 by qdang             #+#    #+#             */
/*   Updated: 2020/04/23 22:04:57 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		di_width_2(t_info *s, long long nbr)
{
	if (s->flag[PLUS] == '1' && nbr >= 0)
		ft_putchar('+');
	if (s->flag[SPACE] == '1' && s->flag[PLUS] != '1' && nbr >= 0)
		ft_putchar(' ');
	if (nbr < 0)
		ft_putchar('-');
}

void			di_width(t_info *s, long long nbr, int nbrlen, int z)
{
	if (s->flag[ZERO] == '1' && z == 0)
	{
		if (s->point != 0)
			while (--s->mfw > nbrlen)
				ft_putchar(' ');
		di_width_2(s, nbr);
		if (s->point == 0)
			while (--s->mfw > nbrlen)
				ft_putchar('0');
	}
	else
	{
		while (--s->mfw > nbrlen + z)
			ft_putchar(' ');
		di_width_2(s, nbr);
	}
	ft_putnchar('0', z);
	if (s->point != 1 || nbr != 0)
		ft_putll(nbr);
}

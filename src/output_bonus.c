/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:40:59 by Amber             #+#    #+#             */
/*   Updated: 2020/04/27 13:41:57 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

double		round_up(double nbr, int declen)
{
	double		temp;
	double		i;
	int			power;

	temp = nbr - (int)nbr;
	if (declen == 0 && temp * 10 >= 5)
		nbr += 1;
	if (declen != 0)
	{
		power = declen;
		while (--declen >= 0)
			temp = temp * 10 - (int)(temp * 10);
		i = 1;
		if (temp >= 0.5 && temp <= 0.9)
			while (--power >= 0)
				i *= 0.1;
		if (temp > 0.9 && temp < 1)
			while (--power >= -1)
				i *= 0.1;
		if (temp >= 0.5 && temp < 1)
			nbr += i;
	}
	return (nbr);
}

void		ft_putf(t_info *s, double nbr, int nbrlen)
{
	double	decnbr;
	double	temp;
	int		declen;

	declen = 0;
	if (s->flag[PLUS] == '1' || nbr < 0)
		declen = -1;
	if (nbr < 0)
		nbr *= -1;
	declen += nbrlen - ft_nbrlen(nbr);
	if (s->flag[HASH] == '1' || s->point != 1)
		declen--;
	nbr = round_up(nbr, declen);
	decnbr = nbr - (long long)nbr;
	ft_putll(nbr);
	if (s->flag[HASH] == '1' || s->point != 1)
		ft_putchar('.');
	while (declen > 0 && s->point != 1)
	{
		temp = decnbr * 10;
		decnbr = temp - (long long)temp;
		ft_putnbr((long long)temp);
		declen--;
	}
}

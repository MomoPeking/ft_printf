/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:52:40 by Amber             #+#    #+#             */
/*   Updated: 2020/04/26 20:27:26 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info			*deal_char(t_info *s)
{
	char	c;

	c = (char)va_arg(s->ap, int);
	if (s->flag[MINUS] == '1')
		ft_putchar(c);
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
		ft_putchar(c);
	s->len++;
	s->fm++;
	s->signal = 1;
	return (s);
}

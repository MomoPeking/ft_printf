/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:54:00 by Amber             #+#    #+#             */
/*   Updated: 2020/05/28 17:50:05 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_info	*deal_string_2(t_info *s, char *str, char *temp, int strlen)
{
	if (s->flag[MINUS] == '1' && s->point != 1)
		ft_putstr(str);
	if (s->mfw > strlen)
	{
		s->len += s->mfw - strlen;
		s->mfw++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
			while (--s->mfw > strlen)
				ft_putchar('0');
		else
			while (--s->mfw > strlen)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1' && s->point != 1)
		ft_putstr(str);
	s->len += strlen;
	s->fm++;
	s->signal = 1;
	free(str);
	if (ft_strcmp(temp, "(null)") == 0)
		free(temp);
	return (s);
}

t_info			*deal_string(t_info *s)
{
	char	*str;
	char	*temp;
	int		strlen;

	temp = va_arg(s->ap, char *);
	if (temp == NULL)
	{
		temp = ft_strnew(6);
		ft_strcpy(temp, "(null)");
	}
	if (s->prec == 0)
	{
		str = ft_strnew(ft_strlen(temp));
		ft_strcpy(str, temp);
	}
	else
	{
		str = ft_strnew(s->prec);
		ft_strncpy(str, temp, s->prec);
	}
	if (s->point != 1)
		strlen = ft_strlen(str);
	else
		strlen = 0;
	return (deal_string_2(s, str, temp, strlen));
}

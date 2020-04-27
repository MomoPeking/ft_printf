/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:41:28 by qdang             #+#    #+#             */
/*   Updated: 2020/04/23 22:05:24 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_puthex(unsigned long long i, char c)
{
	if (i > 15)
	{
		ft_puthex(i / 16, c);
		ft_puthex(i % 16, c);
	}
	else
	{
		if (i <= 9)
			ft_putchar(i + '0');
		else
			c == 'x' ? ft_putchar(i - 10 + 'a') : ft_putchar(i - 10 + 'A');
	}
}

void	ft_putll(long long i)
{
	if ((unsigned long long)i == -9223372036854775808U)
		ft_putstr("9223372036854775808");
	else if (i < 0)
		ft_putll(i * -1);
	else if (i >= 0 && i <= 9)
		ft_putchar('0' + i);
	else
	{
		ft_putll(i / 10);
		ft_putll(i % 10);
	}
}

void	ft_putui(unsigned long long i)
{
	if (i > 9)
	{
		ft_putui(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
}

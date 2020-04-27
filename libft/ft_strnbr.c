/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:36:59 by qdang             #+#    #+#             */
/*   Updated: 2020/04/23 12:32:23 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts the first number in a string to int and returns it.
*/

#include "libft.h"

int		ft_strnbr(char *sp)
{
	int		nb;
	int		flag;

	nb = 0;
	flag = 0;
	while (*sp)
	{
		while (*sp >= '0' && *sp <= '9')
		{
			flag = 1;
			nb = nb * 10 + *sp - '0';
			sp++;
		}
		if (flag == 1)
			break ;
		sp++;
	}
	return (nb);
}

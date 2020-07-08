/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:27:34 by qdang             #+#    #+#             */
/*   Updated: 2020/07/06 20:59:29 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"

int		main(void)
{
	int		a;
	int		b;

	a = ft_printf("%.5x", 21);
	printf("Return Value of ft_printf: %d\n", a);
	b = printf("%.5x", 21);
	printf("Return Value of printf: %d\n", b);
	return (0);
}

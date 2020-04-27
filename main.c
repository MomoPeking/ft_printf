/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:27:34 by qdang             #+#    #+#             */
/*   Updated: 2020/04/27 13:54:56 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"

int     main()
{
    int     a;
    int     b;

    a = ft_printf("%-10d, %.*f\n", 23, 5, 4.4399);
    printf("Return Value of ft_printf: %d\n", a);
    b = printf("%-10d, %.*f\n", 23, 5, 4.4399);
    printf("Return Value of printf: %d\n", b);

    return (0);
}
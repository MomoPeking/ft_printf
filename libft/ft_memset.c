/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:49:11 by qdang             #+#    #+#             */
/*   Updated: 2020/04/23 12:11:26 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tab;

	tab = b;
	i = 0;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 08:54:12 by qdang             #+#    #+#             */
/*   Updated: 2020/05/28 17:50:57 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*new1;
	unsigned char	*new2;

	i = 0;
	new1 = (unsigned char *)s1;
	new2 = (unsigned char *)s2;
	while (new1[i] && new2[i] && (new1[i] - new2[i] == 0))
		i++;
	if (!new1[i] && new2[i])
		return (-1);
	else if (new1[i] && !new2[i])
		return (1);
	else if (!new1[i] && !new2[i])
		return (0);
	else
		return (new1[i] - new2[i]);
}

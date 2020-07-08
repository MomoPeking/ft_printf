/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:39:48 by qdang             #+#    #+#             */
/*   Updated: 2020/07/07 17:31:30 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define BONUS		0

# define MINUS		0
# define ZERO		1
# define HASH		2
# define SPACE		3
# define PLUS		4

# define CHAR		0
# define SHORT		1
# define LONG		2
# define LONGLONG	3

typedef	struct		s_info
{
	va_list		ap;
	int			len;
	const char	*fm;
	int			mfw;
	int			prec;
	char		flag[5];
	char		length[4];
	int			signal;
	int			point;
}					t_info;

int					ft_printf(const char *restrict format, ...);
t_info				*deal_input(t_info *s);
t_info				*deal_width(t_info *s);
t_info				*deal_precision(t_info *s);
t_info				*deal_char(t_info *s);
t_info				*deal_string(t_info *s);
t_info				*deal_pointer(t_info *s);
t_info				*deal_decimal_integer(t_info *s);
t_info				*deal_unsigned_int(t_info *s);
t_info				*deal_hexadecimal(t_info *s);
t_info				*deal_percentage(t_info *s);
void				clean_flag();
void				di_width(t_info *s, long long nbr, int nbrlen, int z);
void				ft_putll(long long i);
void				ft_putui(unsigned long long i);
void				ft_puthex(unsigned long long i, char c);
unsigned long long	trans_ull(t_info *s, unsigned long long nbr);
long long			trans_ll(t_info *s, long long nbr);

# if BONUS == 1

t_info				*deal_float(t_info *s);
double				round_up(double nbr, int declen);
void				ft_putf(t_info *s, double nbr, int nbrlen);

# endif

#endif

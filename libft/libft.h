/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:04:30 by qdang             #+#    #+#             */
/*   Updated: 2020/05/28 17:51:18 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/*
** memory
*/

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);

/*
** string
*/

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);

/*
** number
*/

int		ft_nbrlen(long long nbr);

/*
** output
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putnchar(char c, int n);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);

/*
** convert
*/

int		ft_strnbr(char *sp);

#endif

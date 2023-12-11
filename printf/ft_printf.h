/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:05:57 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/25 11:05:59 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_c(int c);
int				ft_s(char *str);
int				ft_p(unsigned long long n);
int				ft_i(int n);
int				ft_u(unsigned int n);
int				ft_lower_x(unsigned int n);
int				ft_upper_x(unsigned int n);
int				ft_count(unsigned int n);
int				ft_putstr(char *str);
int				ft_putnbr(long int n);
int				ft_count_dix(long int n);
#endif

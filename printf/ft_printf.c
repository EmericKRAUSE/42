/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:59:40 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/25 10:59:42 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char c, int *count, va_list args)
{
	if (c == 'c')
		return (*count += ft_c(va_arg(args, int)));
	else if (c == 's')
		return (*count += ft_s(va_arg(args, char *)));
	else if (c == 'p')
		return (*count += ft_p(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (*count += ft_i(va_arg(args, int)));
	else if (c == 'u')
		return (*count += ft_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (*count += ft_lower_x(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (*count += ft_upper_x(va_arg(args, unsigned int)));
	else if (c == '%')
		return (*count += ft_c('%'));
	else
	{
		if (ft_c('%') == -1)
			return (-1);
		if (ft_c(c) == -1)
			return (-1);
		*count += 2;
		return (0);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_check(*format, &count, args) == -1)
				return (-1);
		}
		else
			count += ft_c(*format);
		format++;
	}
	va_end(args);
	return (count);
}

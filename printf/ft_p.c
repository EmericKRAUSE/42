/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:49:01 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/25 10:49:03 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned long long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_p(unsigned long long n)
{
	char				*hex;
	char				*result;
	int					len;
	int					i;

	if (!n)
		return (ft_putstr("0x0"));
	hex = "0123456789abcdef";
	len = count(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (-1);
	result[len] = '\0';
	i = 1;
	while (n != 0)
	{
		result[len - i++] = hex[n % 16];
		n /= 16;
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	if (ft_putstr(result) == -1)
		return (-1);
	free(result);
	return (len + 2);
}

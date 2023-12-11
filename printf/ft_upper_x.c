/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_X.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:29:55 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/25 10:29:57 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upper_x(unsigned int n)
{
	char			*hex;
	char			*result;
	int				len;
	int				i;

	if (n == 0)
		return (ft_c('0'));
	hex = "0123456789ABCDEF";
	len = ft_count(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	i = 1;
	while (n != 0)
	{
		result[len - i++] = hex[n % 16];
		n /= 16;
	}
	if (ft_putstr(result) == -1)
		len = -1;
	free(result);
	return (len);
}

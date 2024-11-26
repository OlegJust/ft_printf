/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:50:00 by opidhorn          #+#    #+#             */
/*   Updated: 2024/11/26 13:06:49 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int n)
{
	if (n > 9)
		return (ft_put_unsigned(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}

int	ft_puthex(unsigned int n, char format)
{
	char	*hex;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		return (ft_puthex(n / 16, format) + ft_putchar(hex[n % 16]));
	return (ft_putchar(hex[n]));
}

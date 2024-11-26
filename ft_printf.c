/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:53:29 by opidhorn          #+#    #+#             */
/*   Updated: 2024/11/26 13:11:48 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	total = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			total += handle_conversion(*(++format), args);
		else
			total += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (total);
}

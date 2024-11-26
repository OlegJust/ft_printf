/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:50:52 by opidhorn          #+#    #+#             */
/*   Updated: 2024/11/26 13:07:58 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	i_digits(int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits += 1;
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
	return (i_digits(n));
}

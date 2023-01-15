/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:19:28 by vvu               #+#    #+#             */
/*   Updated: 2022/12/13 11:25:57 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_check(va_list args, char const str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (str == 's')
		len += ft_put_str(va_arg(args, char *));
	else if (str == 'd' |\ str == 'i')
		len += ft_put_nbr(va_arg(args, int));
	else if (str == 'p')
		len += ft_put_ptr(va_arg(args, unsigned long long));
	else if (str == 'u')
		len += ft_put_unsigned(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_put_hex(va_arg(args, unsigned int), str);
	else if (str == '%')
		len += ft_put_percent();
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int	len;
	int	i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args);
	while(str[i])
	{
		if (str[i] == '%')
			len += ft_check(args, str);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}


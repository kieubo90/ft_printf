/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:40:34 by vvu               #+#    #+#             */
/*   Updated: 2022/12/13 14:32:13 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_put_str(char *str)
{
	int	len;

	len = 0;
	while(*str)
	{
		write(1, str++, 1);
		len++;
	}
	return (len);
}

int	ft_put_nbr(int c)
{
	int	i;

	i = 0;
	if (c == -2147483648)
	{
		i += ft_putchar(45);
		i += ft_putchar(48 + 2);
		i += ft_put_nbr(147483648);
	}
	if (c < 0)
	{
		i += ft_putchar(45);
		i += ft_put_nbr(c *= -1);
	}
	else if (c > 9)
	{
		i += ft_put_nbr(c / 10);
		i += ft_putchar(c % 10 + 48);
	}
	else if (c <= 9)
		i += ft_putchar(c + 48);
	return(i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:36:23 by vvu               #+#    #+#             */
/*   Updated: 2022/12/13 11:40:27 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int c)
{
	int	len;

	len = 0;
	while (c)
	{
		c /= 16;
		len++;
	}
	return (len);
}

int	ft_hex_check(unsigned int c, char const str)
{
	if (c >= 16)
	{
		ft_hex_check(c / 16, str);
		ft_hex_check(c % 16, str);
	}
	else
	{
		if (c <= 9)
			ft_putchar(c + 48);
		else
		{
			if (str == 'x')
				ft_putchar(c - 10 + 'a');
			else if (str == 'X')
				ft_putchar(c - 10 + 'A');
		}
	}
}

int	ft_put_hex(unsigned int c, char const str)
{
	int	len;

	len = 0;
	if (!c)
		return(write(1, "0", 1));
	else
		ft_hex_check(c, str);
	len += ft_hex_len(c);
	return (len);
}

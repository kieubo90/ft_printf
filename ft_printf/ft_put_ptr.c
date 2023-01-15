/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:25 by vvu               #+#    #+#             */
/*   Updated: 2022/12/13 11:36:16 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long c)
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

void	ft_ptr_check(unsigned long long c)
{
	if (c >= 16)
	{
		ft_ptr_check(c / 16);
		ft_ptr_check(c % 16);
	}
	else
	{
		if (c <= 9)
			ft_putchar(c + 48);
		else
			ft_putchar(c - 10 + 'a');
	}
}

int	ft_put_ptr(unsigned long long c)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (!c)
		len += write(1, "0", 1);
	else
		ft_ptr_check(c);
	len += ft_ptr_len(c);
	return (len);
}	

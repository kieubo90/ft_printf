/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:26:10 by vvu               #+#    #+#             */
/*   Updated: 2022/12/13 11:32:18 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int c)
{
	int	len;

	len = 0;
	while(c)
	{
		c /= 10;
		len++;
	}
	return (len);
}

char	*ft_unsigned_check(unsigned int c)
{
	int	len;
	char	*num;

	len = ft_unsigned_len(c);
	num = malloc(sizeof(char) * (ft_unsigned_len(c) + 1));
	if (!num)
		return (NULL);
	c[len] = '\0';
	while (c)
	{
		c[len - 1] = c % 10 + 48;
		len--;
		c /= 10;
	}
	return (num);
}

int	ft_put_unsigned(unsigned int c)
{
	int	len;
	char	*num;

	if (!c)
		return(writ(1, "0", 1));
	num = ft_unsigned_check(c);
	len = ft_put_str(num);
	free(num);
	return (len);
}

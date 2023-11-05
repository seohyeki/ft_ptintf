/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:47:57 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/06 00:06:41 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned long long n, char c)
{
	char	*hexchar;
	char	*hexlchar;
	int		hex;

	hexchar = "0123456789abcdef";
	hexlchar = "0123456789ABCDEF";
	if (n < 16)
	{
		if (c == 'x' || c == 'p')
			write(1, &hexchar[n], 1);
		else if (c == 'X')
			write(1, &hexlchar[n], 1);
	}
	else
	{
		hex = n % 16;
		print_hex(n / 16, c);
		if (c == 'x' || c == 'p')
			write (1, &hexchar[hex], 1);
		else if (c == 'X')
			write (1, &hexlchar[hex], 1);
	}
}

int	conv_p(unsigned long long num)
{
	int	len;

	write(1, "0x", 2);
	print_hex(num, 'p');
	len = 2;
	if (num == 0)
		len++;
	else
	{
		while (num)
		{
			num /= 16;
			len++;
		}
	}
	return (len);
}

int	conv_x(unsigned int num, char c)
{
	int	len;

	print_hex(num, c);
	len = 0;
	if (num == 0)
		len++;
	else
	{
		while (num)
		{
			num /= 16;
			len++;
		}
	}
	return (len);
}

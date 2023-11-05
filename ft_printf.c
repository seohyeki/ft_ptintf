/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:07:25 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/06 00:06:16 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chk_conv(va_list *ap, char c)
{
	int	len;

	if (c == 'c')
		len = conv_c(va_arg(*ap, int));
	else if (c == 's')
		len = conv_s(va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		len = conv_dni(va_arg(*ap, int));
	else if (c == 'u')
		len = conv_u(va_arg(*ap, unsigned int));
	else if (c == 'p')
		len = conv_p(va_arg(*ap, unsigned long long));
	else if (c == 'x' || c == 'X')
		len = conv_x(va_arg(*ap, unsigned int), c);
	else if (c == '%')
	{
		write(1, "%", 1);
		len = 1;
	}
	else
		len = -1;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(ap, format);
	while (format[i] != 0)
	{
		if (format[i] == '%' && format[i + 1])
		{
			len = chk_conv(&ap, format[i + 1]);
			if (len == -1)
				return (total_len);
			total_len += len;
			i++;
		}
		else
			total_len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (total_len);
}

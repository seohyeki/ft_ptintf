/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:42:35 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/06 00:31:43 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	conv_s(char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
	}
	return (len);
}

int	conv_dni(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	conv_u(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_uitoa(num);
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:18:20 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/06 10:09:18 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ui_size(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_uitoa(unsigned int num)
{
	int			size;
	char		*num_str;

	size = count_ui_size(num);
	num_str = (char *)malloc(sizeof(char) * (size + 1));
	if (num_str == 0)
		return (NULL);
	num_str[size] = '\0';
	while (--size)
	{
		num_str[size] = num % 10 + '0';
		num /= 10;
	}
	if (num >= 0)
		num_str[size] = num + '0';
	return (num_str);
}

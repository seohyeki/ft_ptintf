/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:27:19 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/07 20:21:17 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int is_specifier(char c)
{
	char	*spec;
	int		i;

	spec = "cspdiuxX%";
	i = 0;
	while (spec[i])
	{
		if (c == spec[i])
			return (1);
	}
	return (0);
}

int is_flag(char c)
{
	char	*flag;
	int		i;

	flag = "#0-+ ";
	i = 0;
	while (flag[i])
	{
		if (c == flag[i])
			return (i + 1);
	}
	return (0);
}

int	is_digit(int c)
{
	if ('1' < c && c <= '9')
		return (1);
	return (0);
}


int	chk_flag(const char *format, t_flag *flags)
{
	size_t i;
	int flag_idx;

	i = 0;
	while (!is_specifier(format[i]) && !is_digit(format[i]) && format[i] != '.' && format[i]) //형식지정자가 아니고 1~9도 아니고 .도 아니고 '\0'도 아니라면
	{
		if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == ' ')
			flags->blank = 1;
		else
			return (-1);
		i++;
	}
}

int	chk_specifier(va_list *ap, char c)
{
	int	len;

	if (c == 'c')
		
	else if (c == 's')
		
	else if (c == 'd' || c == 'i')
		
	else if (c == 'u')
		
	else if (c == 'p')
		
	else if (c == 'x' || c == 'X')
		
	else if (c == '%')

	else

	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	flags;
	size_t	i;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			//t_flag 초기값을 다 0으로 만들고 시작
			chk_flag(&format[i + 1], &flags); //flag체크 순서: (-+ #0) > . > 숫자
			//형식자 자리로 주소 옮겨줘야 할듯
			chk_specifier(&ap, format[i]); //type에 따라 출력하기
		}
		else
			total_len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (total_len);
}
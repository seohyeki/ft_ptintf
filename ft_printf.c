/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:27:19 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/08 17:45:22 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"


int is_flag(char c)
{
	char	*flag;
	int		i;

	flag = "#0-+ ";
	i = 0;
	while (flag[i])
	{
		if (c == flag[i])
			return (1);
		i++;
	}
	return (0);
}

int	chk_flag(const char **format, t_flag *flags) //플래그인 동안 만난 플래그 1로 바꾸면서 플래그 아닐때 주소값옮기기
{
	size_t	i;

	i = 0;
	ft_memset(flags, 0, sizeof(t_flag)); //구조체 멤버변수 0으로 초기화
	while (is_flag((*format)[i])) //플래그라면 해당 플래그 켜기
	{
		if ((*format)[i] == '#')
			flags->hash = 1;
		else if ((*format)[i] == '0')
			flags->zero = 1;
		else if ((*format)[i] == '-')
			flags->left = 1;
		else if ((*format)[i] == '+')
			flags->sign = 1;
		else if ((*format)[i] == ' ')
			flags->blank = 1;
		i++;
	}
	while (ft_isdigit((*format)[i])) //숫자면 atoi
	{
		flags->width = flags->width * 10 + (*format)[i] - '0';
		i++;
	}
	if ((*format)[i] == '.')
		i++;
	while (ft_isdigit((*format)[i])) //숫자면 atoi
	{
		flags->precision = flags->precision * 10 + (*format)[i] - '0';
		i++;
	}
	return (i);
}

void	chk_specifier(va_list *ap, t_flag *flags, char c, int *total_len) //write든 malloc이든 오류나면 total_len -1
{
	int	len;

	if (c == 'c')
		len = print_char(flags, va_arg(*ap, int));
	else if (c == 's')
		len = print_str(flags, va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		len = print_demical(flags, va_arg(*ap, int));
	else if (c == 'u')
		len = print_unsigned_demical(flags, va_arg(*ap, unsigned int));
	else if (c == 'p')
		len = print_ptr(flags, va_arg(*ap, unsigned long long));
	else if (c == 'x' || c == 'X')
		len = print_hex(flags, va_arg(*ap, unsigned int), c);
	else if (c == '%')
		len = print_percent(flags);
	else
	 	len = -1;
	if (len == -1)
		*total_len = -1;
	else
	 	*total_len += len;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	flags;
	int		total_len;

	total_len = 0;
	va_start(ap, format);
	while (*format && total_len != -1)
	{
		if (*format == '%' && *format + 1 != '\0')
		{
			format += chk_flag(&format, &flags); //flag체크하기
			chk_specifier(&ap, &flags, *format, &total_len); //type에 따라 출력해주기
		}
		else
		{
			if (write(1, &format[0], 1) == -1)
				total_len = -1;
			else
				total_len++;
		}
		format++;
	}
	va_end(ap);
	return (total_len);
}
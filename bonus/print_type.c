/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:06:18 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/08 17:05:55 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_flag *flags, int c)
{
	//1. width만큼 malloc (precision은 안먹음)
	//2. flag에 따라서 채워넣기
	//3. write하기
	//4. write한 길이 리턴하기
	return (0);
}

int	print_str(t_flag *flags, char *str)
{
	return (0);
}

int	print_demical(t_flag *flags, int num)
{
	//1. num자리수 구하기 && itoa하기 (malloc실패 -1)
	//2. width/precision/자리수 가지고 malloc사이즈 구하고 malloc하기 (malloc실패 -1)
	//3. 채워넣기 --> 여기가 문제야...ㅠ
	//4. write한번에 하기(write error나면 -1, free 잘 챙기기)
	return (0);
}

int	print_unsigned_demical(t_flag *flags, unsigned int num)
{
	return (0);
}

int	print_ptr(t_flag *flags, unsigned long long num)
{
	return (0);
}

int	print_hex(t_flag *flags, unsigned int num, char c)
{
	return (0);
}

int	print_percent(t_flag *flags)
{
	return (0);
}
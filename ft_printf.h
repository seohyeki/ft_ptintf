/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:26:42 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/08 15:58:44 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag{
	int sign;
	int left;
	int blank;
	int hash;
	int zero;
	int width;
	int precision;
	//플래그 만난거 저장해두기
} t_flag;

int	print_char(t_flag *flags, int c);
int	print_str(t_flag *flags, char *str);
int	print_demical(t_flag *flags, int num);
int	print_unsigned_demical(t_flag *flags, unsigned int num);
int	print_ptr(t_flag *flags, unsigned long long num);
int	print_hex(t_flag *flags, unsigned int num, char c);
int	print_percent(t_flag *flags);
int	ft_printf(const char *format, ...);

#endif
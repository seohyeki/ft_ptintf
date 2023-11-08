/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:26:42 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/06 00:19:26 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*utils*/
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int num);
void	print_hex(unsigned long long n, char c);
/*type*/
int		conv_c(int c);
int		conv_s(char *s);
int		conv_dni(int n);
int		conv_u(unsigned int num);
int		conv_p(unsigned long long num);
int		conv_x(unsigned int num, char c);
/*ft_printf*/
int		chk_conv(va_list *ap, char c);
int		ft_printf(const char *format, ...);

#endif

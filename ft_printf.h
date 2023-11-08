/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:26:42 by seohyeki          #+#    #+#             */
/*   Updated: 2023/11/07 15:38:27 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag{
	int plus;
	int minus;
	int blank;
	int hash;
	int zero;
	int width;
	int precision;
	//플래그 만난거 저장해두기
} t_flag;

#endif
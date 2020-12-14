/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:24:41 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 16:24:37 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct DataValues
{
    int     print;
    int     zero;
    int     star;
    int     minus;
    int     dot;
    int     width;
    char    type;
    int     len;
    int     i;
    char    *tmp;
} Data;

int     ft_printf(const char *str, ...);
void    ft_print_struct(Data *Values);
void    ft_struct_init(Data *Values);
void    ft_pars(Data *Values, va_list ap, char *str);
void    ft_struct_reinit(Data *Values);
int     ft_init_dot(char *str, Data *Values, va_list ap);
void	ft_init_star(va_list ap, Data *Values);
void    ft_init_digit(char c, Data *Values);
void	ft_analyse(Data *Values, va_list ap);
void    ft_print_c(Data *Values, char c);
void    ft_width(int width, int i, int zero, Data *Values);
void    ft_print_pourcent(Data *Values);
void    ft_print_str(Data *Values, char *str);
void    ft_putstr_l(char *str, int lengt);

#endif
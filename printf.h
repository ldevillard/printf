/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:24:41 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/11 10:41:43 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct DataValues
{
    int     print;
    char    flags[3];
    int     prec;
    int     width;
    char    type;
    int     len;
    int     i;
} Data;

int     ft_printf(const char *str, ...);
void    ft_print_struct(Data *Values);
void    ft_struct_init(Data *Values);
void    ft_pars(Data *Values, va_list ap, char *str);

#endif
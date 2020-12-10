/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:24:41 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/10 16:23:14 by ldevilla         ###   ########lyon.fr   */
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
    int     len;
    int     index;
    bool    flag_0;
    bool    flag_minus;
    bool    flag_point;
    bool    flag_star;
    char    type;
} Data;

int     ft_printf(const char *str, ...);
void    print_struct(Data *Values);
char    *analyse(char *str, va_list ap);
char    *pars(char *flags, va_list ap, Data *Values);
char    *set_c(va_list ap, char *dest);
char    *set_s(va_list ap, char *dest);
char    *set_d(va_list ap, char *dest);

#endif
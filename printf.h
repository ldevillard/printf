/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:24:41 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/10 15:00:46 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdbool.h>

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

#endif
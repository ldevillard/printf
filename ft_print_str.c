/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:23:35 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 14:56:01 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_print_str(Data *Values, char *str)
{
    if (Values->dot >= 0 && (size_t)Values->dot > ft_strlen(str))
        Values->dot = ft_strlen(str);
    if (Values->minus)
    {
        if (Values->dot)
        {
            ft_putstr_l(str, Values->dot);
            ft_width(Values->width, Values->dot, 0, Values);
            Values->print += Values->dot;
        }
        else
        {
            ft_putstr(str);
            ft_width(Values->width, ft_strlen(str), 0, Values);
            Values->print += ft_strlen(str);
        }
    }
    else if (Values->dot)
    {
        ft_width(Values->width, Values->dot, 0, Values);
        ft_putstr_l(str, Values->dot);
        Values->print += Values->dot;
    }
    else
    {
        ft_width(Values->width, ft_strlen(str), 0, Values);
        ft_putstr(str);
        Values->print += ft_strlen(str);
    }
    Values->i++;
}
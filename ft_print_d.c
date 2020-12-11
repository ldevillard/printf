/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:27:55 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/11 13:41:07 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_print_d(Data *Values, va_list ap)
{
    char    *tmp;
    int i;

    tmp = ft_itoa(va_arg(ap, int));
    i = ft_strlen(tmp) - Values->width;
    if (ft_ccheck(Values->flags, '-'))
    {
        ft_putstr(tmp);
        while (i++ < 0)
            ft_putchar(' ');    
    }
    else if (ft_ccheck(Values->flags, '0'))
    {
        while (i++ < 0)
            ft_putchar('0');
        ft_putstr(tmp);   
    }
    free(tmp);
}
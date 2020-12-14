/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:40:42 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 12:04:02 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_print_c(Data *Values, char c)
{
    if (Values->minus)
    {
        ft_putchar(c);
        Values->print++;
        Values->i++;
    }
    ft_width(Values->width, 1, 0, Values);
    if (!Values->minus)
    {
        ft_putchar(c);
        Values->print++;
        Values->i++;
    }
}
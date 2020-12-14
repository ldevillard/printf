/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:16:52 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 13:20:40 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_print_pourcent(Data *Values)
{
    if (Values->minus)
    {
        ft_putchar('%');
        Values->print++;
        Values->i++;
    }
    ft_width(Values->width, 1, 0, Values);
    if (!Values->minus)
    {
        ft_putchar('%');
        Values->print++;
        Values->i++;
    }
}
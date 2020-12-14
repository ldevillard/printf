/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:45:25 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 16:46:17 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_init_dot(char *str, Data *Values, va_list ap)
{
    int i;

    i = 1;
    if (str[i] == '*')
    {
        Values->dot = va_arg(ap, int);
        i++;
    }
    else
    {
        Values->dot = 0;
        while (ft_isdigit(str[i]))
        {
			Values->dot = (Values->dot * 10) + (str[i] - '0');
            i++;
        }
    }

    return (i);
}

void		ft_init_star(va_list ap, Data *Values)
{
	Values->star = 1;
	Values->width = va_arg(ap, int);
	if (Values->width < 0)
	{
		Values->minus = 1;
		Values->width *= -1;
	}
}

void    ft_init_digit(char c, Data *Values)
{
    if (Values->star == 1)
        Values->width = 0;
    Values->width = Values->width * 10 + (c - '0');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:11:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/11 13:04:57 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_print_struct(Data *Values)
{
    ft_putchar('\n');
    ft_putstr("PRINTED : ");
    ft_putnbr(Values->print);
    ft_putchar('\n');
    ft_putstr("FLAGS : ");
    ft_putstr(Values->flags);
    ft_putchar('\n');
    ft_putstr("PRECISION : ");
    ft_putnbr(Values->prec);
    ft_putchar('\n');
    ft_putstr("WIDTH : ");
    ft_putnbr(Values->width);
    ft_putchar('\n');
    ft_putstr("TYPE : ");
    ft_putchar(Values->type);
    ft_putchar('\n');
    ft_putstr("LEN : ");
    ft_putnbr(Values->len);
    ft_putchar('\n');
    ft_putstr("i : ");
    ft_putnbr(Values->i);
    ft_putchar('\n');
    ft_putstr("TMP : ");
    ft_putstr(Values->tmp);
    ft_putchar('\n');
}
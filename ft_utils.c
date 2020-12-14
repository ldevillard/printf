/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:11:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 15:39:57 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print_struct(Data *Values)
{
    ft_putchar('\n');
    ft_putstr("PRINTED : ");
    ft_putnbr(Values->print);
    ft_putchar('\n');
    ft_putstr("PRECISION : ");
    ft_putnbr(Values->dot);
    ft_putchar('\n');
    ft_putstr("WIDTH : ");
    ft_putnbr(Values->width);
    ft_putchar('\n');
    ft_putstr("TYPE : ");
    ft_putchar(Values->type);
    ft_putchar('\n');
    ft_putstr("STAR : ");
    ft_putnbr(Values->star);
    ft_putchar('\n');
    ft_putstr("ZERO : ");
    ft_putnbr(Values->zero);
    ft_putchar('\n');
    ft_putstr("MINUS : ");
    ft_putnbr(Values->minus);
    ft_putchar('\n');
    ft_putstr("i : ");
    ft_putnbr(Values->i);
    ft_putchar('\n');
    ft_putstr("TMP : ");
    ft_putstr(Values->tmp);
    ft_putchar('\n');
}

void    ft_putstr_l(char *str, int lengt)
{
    int i;

    i = 0;
    while (str[i] && i < lengt)
        ft_putchar(str[i++]);
}
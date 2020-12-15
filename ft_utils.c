/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:11:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/15 13:35:50 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_struct(t_struct *t_values)
{
	ft_putchar('\n');
	ft_putstr("PRINTED : ");
	ft_putnbr(t_values->print);
	ft_putchar('\n');
	ft_putstr("PRECISION : ");
	ft_putnbr(t_values->dot);
	ft_putchar('\n');
	ft_putstr("HAS DOT : ");
	ft_putnbr(t_values->has_dot);
	ft_putchar('\n');
	ft_putstr("WIDTH : ");
	ft_putnbr(t_values->width);
	ft_putchar('\n');
	ft_putstr("TYPE : ");
	ft_putchar(t_values->type);
	ft_putchar('\n');
	ft_putstr("STAR : ");
	ft_putnbr(t_values->star);
	ft_putchar('\n');
	ft_putstr("ZERO : ");
	ft_putnbr(t_values->zero);
	ft_putchar('\n');
	ft_putstr("MINUS : ");
	ft_putnbr(t_values->minus);
	ft_putchar('\n');
	ft_putstr("i : ");
	ft_putnbr(t_values->i);
	ft_putchar('\n');
	ft_putstr("TMP : ");
	ft_putstr(t_values->tmp);
	ft_putchar('\n');
}

void	ft_putstr_l(char *str, int lengt)
{
	int i;

	i = 0;
	while (str[i] && i < lengt)
		ft_putchar(str[i++]);
}

void	ft_putchar_print(char c, t_struct *t_values)
{
	write(1, &c, 1);
	t_values->print++;
}

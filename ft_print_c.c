/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:40:42 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/15 10:10:09 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(t_struct *t_values, char c)
{
	if (t_values->minus)
	{
		ft_putchar(c);
		t_values->print++;
		t_values->i++;
	}
	ft_width(t_values->width, 1, 0, t_values);
	if (!t_values->minus)
	{
		ft_putchar(c);
		t_values->print++;
		t_values->i++;
	}
}

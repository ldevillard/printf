/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:16:52 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/15 10:11:12 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pourcent(t_struct *t_values)
{
	if (t_values->minus)
	{
		ft_putchar('%');
		t_values->print++;
		t_values->i++;
	}
	ft_width(t_values->width, 1, 0, t_values);
	if (!t_values->minus)
	{
		ft_putchar('%');
		t_values->print++;
		t_values->i++;
	}
}

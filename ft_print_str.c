/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:23:35 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/16 08:23:26 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_put_dot(t_struct *t_values, char *str)
{
	if (t_values->minus)
	{
		ft_putstr_l(str, t_values->dot);
		ft_width(t_values->width, t_values->dot, 0, t_values);
		t_values->print += t_values->dot;
	}
	else
	{
		ft_width(t_values->width, t_values->dot, 0, t_values);
		ft_putstr_l(str, t_values->dot);
		t_values->print += t_values->dot;
	}
}

void			ft_print_str(t_struct *t_values, char *str)
{
	if (!str)
		str = "(null)";
	if (t_values->dot >= 0 && (size_t)t_values->dot > ft_strlen(str))
		t_values->dot = ft_strlen(str);
	if (t_values->minus)
	{
		if (t_values->dot >= 0 && t_values->has_dot == 1)
			ft_put_dot(t_values, str);
		else
		{
			ft_putstr(str);
			ft_width(t_values->width, ft_strlen(str), 0, t_values);
			t_values->print += ft_strlen(str);
		}
	}
	else if (t_values->dot >= 0 && t_values->has_dot == 1)
		ft_put_dot(t_values, str);
	else
	{
		ft_width(t_values->width, ft_strlen(str), 0, t_values);
		ft_putstr(str);
		t_values->print += ft_strlen(str);
	}
	t_values->i++;
}

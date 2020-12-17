/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:16:32 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/17 13:25:28 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_d_utils_minus(t_struct *t_values, char *tmp)
{
	if ((int)ft_strlen(tmp) > t_values->dot)
	{
		ft_putstr(tmp);
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		t_values->print += ft_strlen(tmp);
	}
	else
	{
		ft_putchar_print('-', t_values);
		ft_width(t_values->dot, ft_strlen(tmp) - 1, 1, t_values);
		ft_putstr(tmp + 1);
		if (t_values->dot)
			ft_width(t_values->width, t_values->dot + 1, 0, t_values);
		else
			ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		t_values->print += ft_strlen(tmp) - 1;
	}
}

static	void	ft_print_d_dot(t_struct *t_values, char *tmp)
{
	if (t_values->width > t_values->dot && t_values->dot > 0)
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
	else if (t_values->zero)
	{
		ft_putchar_print('-', t_values);
		ft_width(t_values->width, ft_strlen(tmp), 1, t_values);
		ft_putstr(tmp + 1);
		t_values->print += ft_strlen(tmp + 1);
		return ;
	}
	else
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
	ft_putstr(tmp);
	t_values->print += ft_strlen(tmp);
}

void			ft_print_d_utils(t_struct *t_values, char *tmp)
{
	if ((int)ft_strlen(tmp) > t_values->dot)
		ft_print_d_dot(t_values, tmp);
	else
	{
		if (t_values->dot)
			ft_width(t_values->width, t_values->dot + 1, 0, t_values);
		else
			ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		ft_putchar_print('-', t_values);
		ft_width(t_values->dot, ft_strlen(tmp) - 1, 1, t_values);
		ft_putstr(tmp + 1);
		t_values->print += ft_strlen(tmp) - 1;
	}
}

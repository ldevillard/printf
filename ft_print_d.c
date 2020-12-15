/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:09:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/15 12:17:57 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_d(t_struct *t_values, int nbr)
{
	char	*tmp;
	int		i;

	tmp = ft_itoa(nbr);
	i = ft_strlen(tmp) - t_values->width;
	if (t_values->dot && (int)ft_strlen(tmp) < t_values->dot)
	{
		if (ft_strlen(tmp) == 1)
		{
			ft_width(t_values->dot, ft_strlen(tmp), 1, t_values);
			ft_putstr(tmp);
			ft_width(t_values->width, t_values->dot, 0, t_values);
			t_values->print += ft_strlen(tmp);
		}
		else if (nbr < 0)
		{
			ft_width(t_values->width, t_values->dot + 1, 0, t_values);
			ft_putchar_print('-', t_values);
			ft_width(t_values->dot, ft_strlen(tmp) - 1, 1, t_values);
			ft_putstr(tmp + 1);
			t_values->print += ft_strlen(tmp) - 1;
		}
		else
		{
			ft_width(t_values->width, t_values->dot, 0, t_values);
			ft_width(t_values->dot, ft_strlen(tmp), 1, t_values);
			ft_putstr(tmp);
			t_values->print += ft_strlen(tmp);
		}
	}
	else if (t_values->minus)
	{
		ft_putstr(tmp);
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		t_values->print += ft_strlen(tmp);
	}
	else if (t_values->zero)
	{
		if (nbr < 0)
		{
			ft_putchar_print('-', t_values);
			ft_width(t_values->width, ft_strlen(tmp), 1, t_values);
			ft_putstr(tmp + 1);
			t_values->print += ft_strlen(tmp) - 1;
		}
		else
		{
			ft_width(t_values->width, ft_strlen(tmp), 1, t_values);
			ft_putstr(tmp);
			t_values->print += ft_strlen(tmp);
		}
	}
	else
	{
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		ft_putstr(tmp);
		t_values->print += ft_strlen(tmp);
	}
	t_values->i++;
	free(tmp);
}
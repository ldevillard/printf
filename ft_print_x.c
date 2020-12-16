/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:01:14 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/16 12:21:16 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_print_u_utils(t_struct *t_values, char *tmp)
{
	if (t_values->minus)
	{
		ft_putstr(tmp);
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		t_values->print += ft_strlen(tmp);
	}
	else if (t_values->zero && !(t_values->has_dot))
	{
		ft_width(t_values->width, ft_strlen(tmp), 1, t_values);
		ft_putstr(tmp);
		t_values->print += ft_strlen(tmp);
	}
	else
	{
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		ft_putstr(tmp);
		t_values->print += ft_strlen(tmp);
	}
}

static void		ft_minus(t_struct *t_values, char *tmp, unsigned int nbr)
{
	if (t_values->has_dot)
	{
		if (!(t_values->dot) && nbr == 0)
			ft_width(t_values->width, t_values->dot, 0, t_values);
		else
		{
			ft_width(t_values->dot, ft_strlen(tmp), 1, t_values);
			ft_putstr(tmp);
			if ((int)ft_strlen(tmp) < t_values->dot)
				ft_width(t_values->width, t_values->dot, 0, t_values);
			else
				ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
			t_values->print += ft_strlen(tmp);
		}
	}
	else
		ft_print_u_utils(t_values, tmp);
}

void	ft_print_x(t_struct *t_values, unsigned int nbr)
{
	char *tmp;

	tmp = ft_convert_base(nbr, 16);
	if (t_values->minus)
		ft_minus(t_values, tmp, nbr);
	else
	{
		if (!(t_values->dot) && t_values->has_dot && nbr == 0)
			ft_width(t_values->width, t_values->dot, 0, t_values);
		else if (t_values->dot)
		{
			if ((int)ft_strlen(tmp) < t_values->dot)
				ft_width(t_values->width, t_values->dot, 0, t_values);
			else
				ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
			ft_width(t_values->dot, ft_strlen(tmp), 1, t_values);
			ft_putstr(tmp);
			t_values->print += ft_strlen(tmp);
		}
		else
			ft_print_u_utils(t_values, tmp);
	}
	t_values->i++;
	free(tmp);
}
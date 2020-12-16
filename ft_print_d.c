/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:09:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/16 10:34:30 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_utils(t_struct *t_values, char *tmp)
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

static	void	ft_d_zero(t_struct *t_values, int nbr, char *tmp)
{
	if (nbr < 0)
	{
		if (t_values->has_dot)
		{
			ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
			ft_putstr(tmp);
			t_values->print += ft_strlen(tmp);
		}
		else
		{
			ft_putchar_print('-', t_values);
			ft_width(t_values->width, ft_strlen(tmp), 1, t_values);
			ft_putstr(tmp + 1);
			t_values->print += ft_strlen(tmp) - 1;
		}
	}
	else
		ft_utils(t_values, tmp);
}

static	void	ft_d_minus(t_struct *t_values, int nbr, char *tmp)
{
	if (!(t_values->dot) && nbr == 0)
		ft_width(t_values->width, t_values->dot, 0, t_values);
	else if (nbr < 0)
		ft_print_d_utils_minus(t_values, tmp);
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

static	void	ft_d(t_struct *t_values, char *tmp, int nbr)
{
	if (nbr < 0)
		ft_print_d_utils(t_values, tmp);
	else
	{
		if ((int)ft_strlen(tmp) < t_values->dot)
			ft_width(t_values->width, t_values->dot, 0, t_values);
		else
			ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		ft_width(t_values->dot, ft_strlen(tmp), 1, t_values);
		ft_putstr(tmp);
		t_values->print += ft_strlen(tmp);
	}
}

void			ft_print_d(t_struct *t_values, int nbr)
{
	char	*tmp;

	tmp = ft_itoa(nbr);
	if (t_values->minus)
	{
		if (t_values->has_dot)
			ft_d_minus(t_values, nbr, tmp);
		else
			ft_utils(t_values, tmp);
	}
	else
	{
		if (!(t_values->dot) && t_values->has_dot && nbr == 0)
			ft_width(t_values->width, t_values->dot, 0, t_values);
		else if (t_values->dot)
			ft_d(t_values, tmp, nbr);
		else if (t_values->zero)
			ft_d_zero(t_values, nbr, tmp);
		else
			ft_utils(t_values, tmp);
	}
	t_values->i++;
	free(tmp);
}

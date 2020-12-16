/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:45:25 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/16 08:23:35 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_init_dot(char *str, t_struct *t_values, va_list ap)
{
	int i;

	i = 1;
	t_values->has_dot = 1;
	if (str[i] == '*')
	{
		t_values->dot = va_arg(ap, int);
		i++;
	}
	else
	{
		t_values->dot = 0;
		while (ft_isdigit(str[i]))
		{
			t_values->dot = (t_values->dot * 10) + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

void		ft_init_minus(t_struct *t_values)
{
	t_values->minus = 1;
	t_values->zero = 0;
}

void		ft_init_star(va_list ap, t_struct *t_values)
{
	t_values->star = 1;
	t_values->width = va_arg(ap, int);
	if (t_values->width < 0)
	{
		t_values->minus = 1;
		t_values->width *= -1;
	}
}

void		ft_init_digit(char c, t_struct *t_values)
{
	if (t_values->star == 1)
		t_values->width = 0;
	t_values->width = t_values->width * 10 + (c - '0');
}

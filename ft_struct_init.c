/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:10:06 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/15 10:15:58 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_struct *t_values)
{
	t_values->print = 0;
	t_values->dot = 0;
	t_values->zero = 0;
	t_values->minus = 0;
	t_values->star = 0;
	t_values->width = 0;
	t_values->type = 0;
	t_values->len = 0;
	t_values->i = 0;
	t_values->has_dot = 0;
}

void	ft_struct_reinit(t_struct *t_values)
{
	t_values->dot = 0;
	t_values->zero = 0;
	t_values->minus = 0;
	t_values->star = 0;
	t_values->width = 0;
	t_values->type = 0;
	t_values->len = 0;
	t_values->has_dot = 0;
}

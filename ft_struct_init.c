/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:10:06 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 08:39:41 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_struct_init(Data *Values)
{
    Values->print = 0;
    Values->dot = 0;
    Values->zero = 0;
    Values->minus = 0;
    Values->star = 0;
    Values->width = 0;
    Values->type = 0;
    Values->len = 0;
    Values->i = 0;
}

void    ft_struct_reinit(Data *Values)
{
    Values->dot = 0;
    Values->zero = 0;
    Values->minus = 0;
    Values->star = 0;
    Values->width = 0;
    Values->type = 0;
    Values->len = 0;
}